package com.example.examcountsemaphore;

import Controller.Controller;
import Exceptions.ADTException;
import Model.PrgState;
import Model.adt.*;
import Model.statement.IStmt;
import Model.value.Value;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.util.Pair;

import java.net.URL;
import java.util.*;
import java.util.stream.Collectors;


public class ProgramController implements Initializable {

    private Controller ctrl;

    private PrgState selectedPrg;

    List<PrgState> listPrg;

    @FXML
    private TextField nrProgramStatesTextField;

    @FXML
    private TableView<Pair<Integer, Value>> heapTableView;

    @FXML
    private TableColumn<Pair<Integer, Value>, Integer> addressColumn;

    @FXML
    private TableColumn<Pair<Integer, Value>, String> valueColumn;

    @FXML
    private ListView<String> outputList;

    @FXML
    private ListView<String> filesList;

    @FXML
    private ListView<Integer> prgStateIdList;

    @FXML
    private TableView<Pair<String, Value>> symTableView;

    @FXML
    private TableColumn<Pair<String, Value>, String> varNameColumn;

    @FXML
    private TableColumn<Pair<String, Value>, String> varValueColumn;

    @FXML
    private ListView<String> exeStackList;

    @FXML
    private TableView<Map.Entry<Integer, javafx.util.Pair<Integer, List<Integer>>>> semaphoreTableView;

    @FXML
    private TableColumn<Map.Entry<Integer, javafx.util.Pair<Integer, List<Integer>>>, Integer> indexSemaphoreColumn;

    @FXML
    private TableColumn<Map.Entry<Integer, javafx.util.Pair<Integer, List<Integer>>>, Integer> valueSemaphoreColumn;

    @FXML
    private TableColumn<Map.Entry<Integer, javafx.util.Pair<Integer, List<Integer>>>, List<Integer>> listSemaphoreColumn;

    @FXML
    private Button runOneStepButton;

    public void setController(Controller ctr) throws ADTException {
        ctrl=ctr;
        listPrg=ctrl.getPrgStatesList();
        populateFields();

    }

    @FXML
    public void setSelectedProgram(MouseEvent event) throws ADTException {
        populateExecutionStackListView();
        populateSymbolTableView();
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        this.prgStateIdList.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        prgStateIdList.getSelectionModel().selectIndices(0);
        prgStateIdList.getFocusModel().focus(1);

        addressColumn.setCellValueFactory(p->new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        valueColumn.setCellValueFactory(p->new SimpleStringProperty(p.getValue().getValue().toString()));
        varNameColumn.setCellValueFactory(p->new SimpleStringProperty(p.getValue().getKey()));
        varValueColumn.setCellValueFactory(p->new SimpleStringProperty(p.getValue().getValue().toString()));

        indexSemaphoreColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        valueSemaphoreColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue().getKey()).asObject());
        listSemaphoreColumn.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getValue().getValue()));

    }

    private PrgState getCurrentProgramState() {
        if (ctrl.getPrgStatesList().size() == 0)
            return null;
        else {
            int currentId = prgStateIdList.getSelectionModel().getSelectedIndex();
            if (currentId == -1)
                return ctrl.getPrgStatesList().get(0);
            else
                return ctrl.getPrgStatesList().get(currentId);
        }
    }


    public void onRunOneStepButton(ActionEvent event) throws ADTException, InterruptedException {
        if (ctrl!= null) {
            try {
                List<PrgState> programStates = Objects.requireNonNull(ctrl.getPrgStatesList());
                if (programStates.size() > 0) {
                    ctrl.oneStep();
                    populateFields();
                    programStates = ctrl.removeCompletedPrg(ctrl.getPrgStatesList());
                    ctrl.setPrgStatesList(programStates);
                    populateProgramStateIdentifiersListView();
                } else {
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error!");
                    alert.setHeaderText("An error has occured!");
                    alert.setContentText("There is nothing left to execute!");
                    alert.showAndWait();
                }
            } catch (InterruptedException e) {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Execution error!");
                alert.setHeaderText("An execution error has occured!");
                alert.setContentText(e.getMessage());
                alert.showAndWait();
            }
        } else {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occured!");
            alert.setContentText("No program selected!");
            alert.showAndWait();
        }
    }



    private void populateFields() throws ADTException {
        populateNumberOfProgramStatesTextField();
        populateHeapTableView();
        populateOutputListView();
        populateFileTableListView();
        populateProgramStateIdentifiersListView();
        populateSymbolTableView();
        populateExecutionStackListView();
        populateSemaphoreTableView();
    }


    private void populateSemaphoreTableView() {
        PrgState programState = getCurrentProgramState();
        MyISemaphore semaphoreTable = Objects.requireNonNull(programState).getSemaphoreTable();
        List<Map.Entry<Integer, javafx.util.Pair<Integer, List<Integer>>>> semaphoreList = new ArrayList<>();
        for (Map.Entry<Integer, javafx.util.Pair<Integer, List<Integer>>> entry: semaphoreTable.getSemaphoreTable().entrySet()) {
            semaphoreList.add(entry);
        }
        semaphoreTableView.setItems(FXCollections.observableArrayList(semaphoreList));
        semaphoreTableView.refresh();
    }



    private void populateNumberOfProgramStatesTextField() {
        List<PrgState> programStates = ctrl.getPrgStatesList();
        nrProgramStatesTextField.setText(String.valueOf(programStates.size()));
    }


    private void populateProgramStateIdentifiersListView() {
        List<PrgState> programStates = ctrl.getPrgStatesList();
        List<Integer> idList = programStates.stream().map(PrgState::getId).collect(Collectors.toList());
        prgStateIdList.setItems(FXCollections.observableList(idList));
        populateNumberOfProgramStatesTextField();
    }

    private void populateHeapTableView() {
        PrgState programState = getCurrentProgramState();
        MyIHeap heap = Objects.requireNonNull(programState).getHeap();
        ArrayList<Pair<Integer, Value>> heapEntries = new ArrayList<>();
        for(Map.Entry<Integer, Value> entry: heap.getContent().entrySet()) {
            heapEntries.add(new Pair<>(entry.getKey(), entry.getValue()));
        }
        heapTableView.setItems(FXCollections.observableArrayList(heapEntries));

    }

    private void populateSymbolTableView() {
        PrgState programState = getCurrentProgramState();
        MyIDictionary<String, Value> symbolTable = Objects.requireNonNull(programState).getSymTable();
        ArrayList<Pair<String, Value>> symbolTableEntries = new ArrayList<>();
        if (symbolTable != null) {
            for (Map.Entry<String, Value> entry : symbolTable.getContent().entrySet()) {
                symbolTableEntries.add(new Pair<>(entry.getKey(), entry.getValue()));
            }
        }
        symTableView.setItems(FXCollections.observableArrayList(symbolTableEntries));
    }


    private void populateExecutionStackListView() throws ADTException {
        PrgState programState = getCurrentProgramState();
        List<String> executionStackToString = new ArrayList<>();
        if (programState != null)
            for (IStmt statement: programState.getExeStk().getReversed()) {
                executionStackToString.add(statement.toString());
            }
        exeStackList.setItems(FXCollections.observableList(executionStackToString));
    }


    private void populateFileTableListView() {
        PrgState programState = getCurrentProgramState();
        filesList.getItems().setAll(String.valueOf(Objects.requireNonNull(programState).getFileTable().getContent().keySet()));
    }

    private void populateOutputListView() {
        PrgState programState = getCurrentProgramState();
        List<String> output = new ArrayList<>();
        List<Value> outList = Objects.requireNonNull(programState).getOut().getList();
        int index;
        for (index = 0; index < outList.size(); index++){
            output.add(outList.get(index).toString());
        }
        outputList.setItems(FXCollections.observableArrayList(output));
    }
}

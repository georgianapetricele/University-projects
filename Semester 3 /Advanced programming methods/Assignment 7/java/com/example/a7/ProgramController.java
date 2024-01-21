package com.example.a7;

import Controller.Controller;
import Exceptions.ADTException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.*;
import Model.statement.IStmt;
import Model.value.StringValue;
import Model.value.Value;
import Repository.IRepository;
import Repository.Repository;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.util.Pair;

import java.net.Inet4Address;
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
    private Button runOneStepButton;

    public void setController(Controller ctr) throws ADTException {
        ctrl = ctr;
        listPrg = ctrl.getPrgStatesList();
        System.out.println(this.ctrl.getPrgStatesList());
        selectedPrg = ctrl.getPrgStatesList().get(0);
        populateFields();

    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        if (prgStateIdList != null) {
            this.prgStateIdList.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
            prgStateIdList.getSelectionModel().selectIndices(0);
            prgStateIdList.getFocusModel().focus(1);

            addressColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
            valueColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getValue().toString()));
            varNameColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getKey()));
            varValueColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getValue().toString()));
        }
    }


    public void onRunOneStepButton(ActionEvent event) throws ADTException, InterruptedException {

        if(prgStateIdList.getSelectionModel().getSelectedIndex()==-1)
        {
            if(!ctrl.getPrgStatesList().isEmpty())
            {
                selectedPrg=ctrl.getPrgStatesList().get(0);
                populateExecutionStackListView();
            }
        }

        if (ctrl == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error encountered!");
            alert.setContentText("Please select a program to execute");
            alert.showAndWait();
        }
        if (selectedPrg.getStk() == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error encountered!");
            alert.setContentText("Current program is finished.Please select a new program to execute");
            alert.showAndWait();
        }
        try {
            List<PrgState> programStates = Objects.requireNonNull(ctrl.getPrgStatesList());
            if (programStates.size() > 0) {
                ctrl.oneStep();
                populateFields();
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
    }

    @FXML
    public void setSelectedProgram() throws ADTException {

        if(prgStateIdList.getSelectionModel().getSelectedIndex()>=0 && prgStateIdList.getSelectionModel().getSelectedIndex()<=this.ctrl.getRepo().getPrgList().size()){
            selectedPrg=ctrl.getRepo().getPrgList().get(prgStateIdList.getSelectionModel().getSelectedIndex());
            populateFields();
        }
        else
            if(!ctrl.getPrgStatesList().isEmpty())
            {
                selectedPrg=ctrl.getPrgStatesList().get(1);
                populateExecutionStackListView();
            }
    }


    private void populateFields() throws ADTException {
        if (listPrg != null) {
            Integer newSize = listPrg.size();
            nrProgramStatesTextField.setText(newSize.toString());
        } else
            nrProgramStatesTextField.setText("0");
        populateHeapTableView();
        populateOutputListView();
        populateFileTableListView();
        populateProgramStateIdentifiersListView();
        populateSymbolTableView();
        populateExecutionStackListView();
    }

    private void populateProgramStateIdentifiersListView() {
        List<Integer> idList = this.ctrl.getPrgStatesList().stream()
                .map(PrgState::getId)
                .collect(Collectors.toList());

        ObservableList<Integer> idListobs = FXCollections.observableArrayList(idList);
        this.prgStateIdList.setItems(idListobs);
    }

    private void populateHeapTableView() {
        MyIHeap heap = selectedPrg.getHeap();
        ArrayList<Pair<Integer, Value>> heapEntries = new ArrayList<>();
        for (Map.Entry<Integer, Value> entry : heap.getContent().entrySet()) {
            heapEntries.add(new Pair<>(entry.getKey(), entry.getValue()));
        }
        heapTableView.setItems(FXCollections.observableArrayList(heapEntries));
        heapTableView.refresh();

    }

    private void populateSymbolTableView() {
        MyIDictionary<String, Value> symTable = selectedPrg.getSymTable();
        ArrayList<Pair<String, Value>> entries = new ArrayList<>();
        for (Map.Entry<String, Value> entry : symTable.getContent().entrySet()) {
            entries.add(new Pair<>(entry.getKey(), entry.getValue()));
        }
        symTableView.setItems(FXCollections.observableArrayList(entries));
        symTableView.refresh();
    }


    private void populateExecutionStackListView() throws ADTException {
        System.out.println(selectedPrg.toString());
        List<String> executionStackList = selectedPrg.getStk().getContent().stream().map(IStmt::toString).collect(Collectors.toList());
        Collections.reverse(executionStackList);
        exeStackList.setItems(FXCollections.observableArrayList(executionStackList));
    }


    private void populateFileTableListView() {
        filesList.getItems().setAll(String.valueOf(selectedPrg.getFileTable().getContent().keySet()));
    }

    private void populateOutputListView() {
        outputList.getItems().setAll(String.valueOf(selectedPrg.getOut()));
    }


}

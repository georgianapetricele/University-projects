package com.example.examcountsemaphore;

import Controller.Controller;
import Exceptions.ADTException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.*;
import Model.expression.*;
import Model.statement.*;
import Model.type.BoolType;
import Model.type.IntType;
import Model.type.RefType;
import Model.type.StringType;
import Model.value.BoolValue;
import Model.value.IntValue;
import Model.value.StringValue;
import Repository.IRepository;
import Repository.Repository;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;

import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;

public class ListController implements Initializable {

    private ProgramController programController;

    @FXML
    private ListView<IStmt> programsListView = new ListView<>();

    @FXML
    private Label label=new Label();

    @FXML
    private Button runButton =new Button();

    public void setProgramController(ProgramController programController)
    {
        this.programController=programController;
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        programsListView.setItems(getProgramsListView());
        // To set selection model
        programsListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        // Select item at index = 1
        programsListView.getSelectionModel().selectIndices(0);
        label.setText("CURRENT PROGRAM: " + programsListView.getSelectionModel().getSelectedItem().toString());
        // Focus
        programsListView.getFocusModel().focus(1);

        selectionChanged();
    }

    @FXML
    private void selectionChanged(){
        programsListView.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<IStmt>() {
            @Override
            public void changed(ObservableValue<? extends IStmt> observableValue, IStmt oldValue, IStmt newValue) {
                label.setText("CURRENT PROGRAM: " + newValue.toString());
            }
        });
    }

    @FXML
    public void onRunButton(ActionEvent event) {

        IStmt currentProgram = programsListView.getSelectionModel().getSelectedItem();
        int id= programsListView.getSelectionModel().getSelectedIndex();
        id+=1;

        try {
            currentProgram.typeCheck(new MyDictionary<>());
            PrgState prg = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), new MySemaphore(),currentProgram);
            IRepository repo = new Repository(prg, "src/main/java/log" + id +".txt");
            Controller ctr= new Controller(repo);

            try {
                programController.setController(ctr);
            } catch (Exception e) {
                e.printStackTrace();
            }

        }catch (MyException | ADTException e) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error encountered!");
            alert.setContentText(e.getMessage());
            alert.showAndWait();
        }
    }



    private ObservableList<IStmt> getProgramsListView(){
        List<IStmt> programs = new ArrayList<>();

        IStmt ex1 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(2))),
                        new PrintStmt(new VarExp("v"))));

        IStmt ex2 = new CompStmt(new VarDeclStmt("a", new BoolType()),
                new CompStmt(new VarDeclStmt("b", new IntType()),
                        new CompStmt(new AssignStmt("a", new ArithExp('+', new ValueExp(new IntValue(2)), new
                                ArithExp('*', new ValueExp(new IntValue(3)), new ValueExp(new IntValue(5))))),
                                new CompStmt(new AssignStmt("b", new ArithExp('+', new VarExp("a"), new ValueExp(new
                                        IntValue(1)))), new PrintStmt(new VarExp("b"))))));

        IStmt ex3 = new CompStmt(new VarDeclStmt("a", new BoolType()),
                new CompStmt(new VarDeclStmt("v", new IntType()),
                        new CompStmt(new AssignStmt("a", new ValueExp(new BoolValue(true))),
                                new CompStmt(new IfStmt(new VarExp("a"), new AssignStmt("v", new ValueExp(new
                                        IntValue(2))), new AssignStmt("v", new ValueExp(new IntValue(3)))), new PrintStmt(new
                                        VarExp("v"))))));

        IStmt ex4 = new CompStmt(new VarDeclStmt("varf", new StringType()),
                new CompStmt(new AssignStmt("varf", new ValueExp(new StringValue("src/main/java/test.in"))),
                        new CompStmt(new OpenRFileStmt(new VarExp("varf")),
                                new CompStmt(new VarDeclStmt("varc", new IntType()),
                                        new CompStmt(new ReadFileStmt(new VarExp("varf"), "varc"),
                                                new CompStmt(new PrintStmt(new VarExp("varc")),
                                                        new CompStmt(new ReadFileStmt(new VarExp("varf"), "varc"),
                                                                new CompStmt(new PrintStmt(new VarExp("varc")),
                                                                        new CloseRfileStmt(new VarExp("varf"))))))))));

        //Ref int v;new(v,20);Ref Ref int a; new(a,v);print(v);print(a)
        IStmt ex5=new CompStmt(new VarDeclStmt("v",new RefType(new IntType())),
                new CompStmt(new NewHeapStmt("v",new ValueExp(new IntValue(20))),
                        new CompStmt(new VarDeclStmt("a",new RefType(new RefType(new IntType()))),
                                new CompStmt(new NewHeapStmt("a",new VarExp("v")),
                                        new CompStmt(new PrintStmt(new VarExp("v")),new PrintStmt(new VarExp("a")))))));

        IStmt ex6=new CompStmt(new VarDeclStmt("v",new RefType(new IntType())),
                new CompStmt(new NewHeapStmt("v",new ValueExp(new IntValue(20))),
                        new CompStmt(new VarDeclStmt("a",new RefType(new RefType(new IntType()))),
                                new CompStmt(new NewHeapStmt("a",new VarExp("v")),
                                        new CompStmt(new PrintStmt(new readHExp(new VarExp("v"))),
                                                new PrintStmt(new ArithExp('+',new readHExp(new readHExp(new VarExp("a"))), new ValueExp(new IntValue(5)))))))));

        IStmt ex7=new CompStmt(new VarDeclStmt("v",new RefType(new IntType())),
                new CompStmt(new NewHeapStmt("v",new ValueExp(new IntValue(20))),
                        new CompStmt(new PrintStmt(new readHExp(new VarExp("v"))),
                                new CompStmt(new writeHStmt("v",new ValueExp(new IntValue(30))),
                                        new PrintStmt(new ArithExp('+',new readHExp(new VarExp("v")),new ValueExp(new IntValue(5))))))));

        //Ref int v;new(v,20);Ref Ref int a; new(a,v); new(v,30);print(rH(rH(a)))
        IStmt ex8=new CompStmt(new VarDeclStmt("v",new RefType(new IntType())),
                new CompStmt(new NewHeapStmt("v",new ValueExp(new IntValue(20))),
                        new CompStmt(new VarDeclStmt("a",new RefType(new RefType(new IntType()))),
                                new CompStmt(new NewHeapStmt("a",new VarExp("v")),
                                        new CompStmt(new NewHeapStmt("v",new ValueExp(new IntValue(30))),
                                                new PrintStmt(new readHExp(new readHExp(new VarExp("a")))))))));

        IStmt ex9=new CompStmt(new VarDeclStmt("v",new IntType()),
                new CompStmt(new AssignStmt("v",new ValueExp(new IntValue(4))),
                        new CompStmt(new WhileStmt(
                                new RelationalExp(">",new VarExp("v"),new ValueExp(new IntValue(0))),
                                new CompStmt(new PrintStmt(new VarExp("v")),
                                        new AssignStmt("v",new ArithExp('-',new VarExp("v"),new ValueExp(new IntValue(1)))))),
                                new PrintStmt(new VarExp("v")))));

        //int v; Ref int a; v=10;new(a,22);
        // fork(wH(a,30);v=32;print(v);print(rH(a)));
        // print(v);print(rH(a))
        IStmt ex10=new CompStmt(new VarDeclStmt("v",new IntType()),
                new CompStmt(new VarDeclStmt("a",new RefType(new IntType())),
                        new CompStmt(new AssignStmt("v",new ValueExp(new IntValue(10))),
                                new CompStmt(new NewHeapStmt("a",new ValueExp(new IntValue(22))),
                                        new CompStmt(new ForkStmt(new CompStmt(new writeHStmt("a",new ValueExp(new IntValue(30))),
                                                new CompStmt(new AssignStmt("v",new ValueExp(new IntValue(32))),
                                                        new CompStmt(new PrintStmt(new VarExp("v")),new PrintStmt(new readHExp(new VarExp("a"))))))),
                                                new CompStmt(new PrintStmt(new VarExp("v")),new PrintStmt(new readHExp(new VarExp("a"))))
                                        )
                                )
                        )
                )
        );

        IStmt ex11 = new CompStmt(new VarDeclStmt("a", new IntType()),
                new CompStmt(new VarDeclStmt("b", new IntType()),
                        new CompStmt(new VarDeclStmt("c", new IntType()),
                                new CompStmt(new AssignStmt("a", new ValueExp(new IntValue(1))),
                                        new CompStmt(new AssignStmt("b", new ValueExp(new IntValue(2))),
                                                new CompStmt(new AssignStmt("c", new ValueExp(new IntValue(5))),
                                                        new CompStmt(new SwitchStmt(
                                                                new ArithExp('*', new VarExp("a"), new ValueExp(new IntValue(10))),
                                                                new ArithExp('*', new VarExp("b"), new VarExp("c")),
                                                                new CompStmt(new PrintStmt(new VarExp("a")), new PrintStmt(new VarExp("b"))),
                                                                new ValueExp(new IntValue(10)),
                                                                new CompStmt(new PrintStmt(new ValueExp(new IntValue(100))), new PrintStmt(new ValueExp(new IntValue(200)))),
                                                                new PrintStmt(new ValueExp(new IntValue(300)))
                                                        ), new PrintStmt(new ValueExp(new IntValue(300))))))))));


        IStmt ex12 = new CompStmt(
                new VarDeclStmt("v1", new RefType(new IntType())),
                new CompStmt(
                        new VarDeclStmt("cnt", new IntType()),
                        new CompStmt(
                                new NewHeapStmt("v1", new ValueExp(new IntValue(1))),
                                new CompStmt(
                                        new CreateSemaphoreStmt("cnt", new readHExp(new VarExp("v1"))),
                                        new CompStmt(
                                                new ForkStmt(
                                                        new CompStmt(
                                                                new AcquireStmt("cnt"),
                                                                new CompStmt(
                                                                        new writeHStmt("v1", new ArithExp('*', new readHExp(new VarExp("v1")), new ValueExp(new IntValue(10)))),
                                                                        new CompStmt(
                                                                                new PrintStmt(new readHExp(new VarExp("v1"))),
                                                                                new ReleaseStmt("cnt")
                                                                        )
                                                                )
                                                        )
                                                ),
                                                new CompStmt(
                                                        new ForkStmt(
                                                                new CompStmt(
                                                                        new AcquireStmt("cnt"),
                                                                        new CompStmt(
                                                                                new writeHStmt("v1", new ArithExp('*',  new readHExp(new VarExp("v1")), new ValueExp(new IntValue(10)))),
                                                                                new CompStmt(
                                                                                        new writeHStmt("v1", new ArithExp('*',  new readHExp(new VarExp("v1")), new ValueExp(new IntValue(2)))),
                                                                                        new CompStmt(
                                                                                                new PrintStmt(new readHExp(new VarExp("v1"))),
                                                                                                new ReleaseStmt("cnt")
                                                                                        )
                                                                                )
                                                                        )
                                                                )
                                                        ),
                                                        new CompStmt(
                                                                new AcquireStmt("cnt"),
                                                                new CompStmt(
                                                                        new PrintStmt(new ArithExp('-', new readHExp(new VarExp("v1")), new ValueExp(new IntValue(1)))),
                                                                        new ReleaseStmt("cnt")
                                                                )
                                                        )
                                                )
                                        )
                                )
                        )
                )
        );



        programs.add(ex1);
        programs.add(ex2);
        programs.add(ex3);
        programs.add(ex4);
        programs.add(ex5);
        programs.add(ex6);
        programs.add(ex7);
        programs.add(ex8);
        programs.add(ex9);
        programs.add(ex10);
        programs.add(ex11);
        programs.add(ex12);


        ObservableList<IStmt> programsListObs = FXCollections.observableArrayList(programs);
        return programsListObs;
    }

}

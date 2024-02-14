package View;

import Controller.Controller;
import Exceptions.ADTException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyDictionary;
import Model.adt.MyHeap;
import Model.adt.MyList;
import Model.adt.MyStack;
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

public class Interpreter {


    public static void main(String[] args) {
        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));

        IStmt ex1 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(2))),
                        new PrintStmt(new VarExp("v"))));

        IStmt ex2 = new CompStmt(new VarDeclStmt("a", new IntType()),
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
                new CompStmt(new AssignStmt("varf", new ValueExp(new StringValue("test.in"))),
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

        try{
            ex1.typeCheck(new MyDictionary<>());
            PrgState prg1 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),ex1);
            IRepository repo1 = new Repository(prg1, "log4.txt");
            Controller ctr1;
            ctr1 = new Controller(repo1);
            menu.addCommand(new RunExample("1", ex1.toString(), ctr1));
        } catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try{
            ex2.typeCheck(new MyDictionary<>());
            PrgState prg2 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(),new MyHeap(), ex2);
            IRepository repo2 = new Repository(prg2, "log2.txt");
            Controller ctr2 = new Controller(repo2);
            menu.addCommand(new RunExample("2", ex2.toString(), ctr2));
        } catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try {
            ex3.typeCheck(new MyDictionary<>());
            PrgState prg3 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex3);
            IRepository repo3 = new Repository(prg3, "log3.txt");
            Controller ctr3 = new Controller(repo3);
            menu.addCommand(new RunExample("3", ex3.toString(), ctr3));
        }catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try {
            ex4.typeCheck(new MyDictionary<>());
            PrgState prg4 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex4);
            IRepository repo4 = new Repository(prg4, "log4.txt");
            Controller ctr4 = new Controller(repo4);
            menu.addCommand(new RunExample("4", ex4.toString(), ctr4));
        }catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try {
            ex5.typeCheck(new MyDictionary<>());
            PrgState prg5 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex5);
            IRepository repo5 = new Repository(prg5, "log5.txt");
            Controller ctr5 = new Controller(repo5);
            menu.addCommand(new RunExample("5", ex5.toString(), ctr5));
        }catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try {
            ex6.typeCheck(new MyDictionary<>());
            PrgState prg6 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex6);
            IRepository repo6 = new Repository(prg6, "log6.txt");
            Controller ctr6 = new Controller(repo6);
            menu.addCommand(new RunExample("6", ex6.toString(), ctr6));
        }catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try {
            ex7.typeCheck(new MyDictionary<>());
            PrgState prg7 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex7);
            IRepository repo7 = new Repository(prg7, "log7.txt");
            Controller ctr7 = new Controller(repo7);
            menu.addCommand(new RunExample("7", ex7.toString(), ctr7));
        }catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try {
            ex8.typeCheck(new MyDictionary<>());
            PrgState prg8 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex8);
            IRepository repo8 = new Repository(prg8, "log8.txt");
            Controller ctr8 = new Controller(repo8);
            menu.addCommand(new RunExample("8", ex8.toString(), ctr8));
        }catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try {
            ex9.typeCheck(new MyDictionary<>());
            PrgState prg9 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex9);
            IRepository repo9 = new Repository(prg9, "log9.txt");
            Controller ctr9 = new Controller(repo9);
            menu.addCommand(new RunExample("9", ex9.toString(), ctr9));
        }catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        try {
            ex10.typeCheck(new MyDictionary<>());
            PrgState prg10 = new PrgState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex10);
            IRepository repo10 = new Repository(prg10, "log10.txt");
            Controller ctr10 = new Controller(repo10);
            menu.addCommand(new RunExample("10", ex10.toString(), ctr10));
        }catch (MyException | ADTException e) {
            System.out.println(e.getMessage());
        }

        menu.show();
    }
}
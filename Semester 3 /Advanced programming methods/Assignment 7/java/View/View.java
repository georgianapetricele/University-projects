//package View;
//
//import Controller.Controller;
//import Exceptions.ADTException;
//import Exceptions.ExprException;
//import Exceptions.MyException;
//import Exceptions.StmtException;
//import Model.PrgState;
//import Model.adt.*;
//import Model.expression.ArithExp;
//import Model.expression.ValueExp;
//import Model.expression.VarExp;
//import Model.statement.*;
//import Model.type.BoolType;
//import Model.type.IntType;
//import Model.value.BoolValue;
//import Model.value.IntValue;
//import Model.value.StringValue;
//import Model.value.Value;
//import Repository.IRepository;
//import Repository.Repository;
//
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.util.Scanner;
//
//public class View {
//
//    private void showMenu(){
//        System.out.println("Choose your option:\n");
//        System.out.println("0. Exit");
//        System.out.println("1. Run program 1: int v; v=2;Print(v)");
//        System.out.println("2. Run program 2: int a;int b; a=2+3*5;b=a+1;Print(b)");
//        System.out.println("3. Run program 3: bool a; int v; a=true;(If a Then v=2 Else v=3);Print(v)");
//
//    }
//    public void view() throws ExprException, MyException, StmtException, ADTException {
//        while(true){
//            showMenu();
//            Scanner input= new Scanner(System.in);
//            System.out.println("Enter your option: ");
//            int inp=input.nextInt();
//            if(inp == 0)
//                break;
//            else if(inp==1)
//                runProgram1();
//            else if(inp==2)
//                runProgram2();
//            else if(inp==3)
//                runProgram3();
//        }
//    }
//
//    private void runProgram1() throws ExprException, ADTException, StmtException,MyException{
//        //1: int v; v=2;Print(v)
//        IStmt ex1 = new CompStmt(new VarDeclStmt("v", new IntType()),
//                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(2))),
//                        new PrintStmt(new VarExp("v"))));
//
//        runStatement(ex1);
//    }
//
//    private void runProgram2() throws ExprException, ADTException, StmtException,MyException{
//        //2: int a; int b; a=2+3*5;b=a+1;Print(b)
//        IStmt ex2 = new CompStmt( new VarDeclStmt("a",new IntType()),
//                new CompStmt(new VarDeclStmt("b",new IntType()),
//                        new CompStmt(new AssignStmt("a", new ArithExp('+',new ValueExp(new IntValue(2)),new
//                                ArithExp('*',new ValueExp(new IntValue(3)), new ValueExp(new IntValue(5))))),
//                                new CompStmt(new AssignStmt("b",new ArithExp('+',new VarExp("a"), new ValueExp(new
//                                        IntValue(1)))), new PrintStmt(new VarExp("b"))))));
//        runStatement(ex2);
//    }
//
//    private void runProgram3() throws ExprException, ADTException, StmtException,MyException {
//        //3: bool a; int v; a=true;(If a Then v=2 Else v=3);Print(v)
//        IStmt ex3 = new CompStmt(new VarDeclStmt("a",new BoolType()),
//                new CompStmt(new VarDeclStmt("v", new IntType()),
//                        new CompStmt(new AssignStmt("a", new ValueExp(new BoolValue(true))),
//                                new CompStmt(new IfStmt(new VarExp("a"),new AssignStmt("v",new ValueExp(new
//                                        IntValue(2))), new AssignStmt("v", new ValueExp(new IntValue(3)))), new PrintStmt(new
//                                        VarExp("v"))))));
//
//        runStatement(ex3);
//    }
//
//
//    private void runStatement(IStmt stmt) throws ExprException, ADTException, StmtException,MyException{
//        MyIStack<IStmt> exeStack = new MyStack<>();
//        MyIDictionary<String, Value> symTable = new MyDictionary<>();
//        MyIList<Value> output = new MyList<>();
//        MyIDictionary<StringValue, BufferedReader> fileTable = new MyDictionary<>();
//        MyIHeap heap = new MyHeap();
//        PrgState state = new PrgState(exeStack,symTable,output,fileTable,heap,stmt);
//        System.out.println("Enter the path for the log file: ");
//        Scanner log = new Scanner(System.in);
//        String logFile=log.next();
//        IRepository repo = new Repository(state,logFile);
//        Controller controller = new Controller(repo);
//
//        System.out.println("Do you want to display the steps?[true/false]");
//        Scanner readOption = new Scanner(System.in);
//        boolean option = readOption.nextBoolean();
//        controller.setDisplayFlag(option);
//
//        /*String varf;
//        varf="test.in";
//        OpenRFileStmt of = new OpenRFileStmt(new ValueExp(new StringValue(varf)));
//        of.execute(state);
//        int varc;
//        ReadFileStmt rf = new ReadFileStmt(new ValueExp(new StringValue(varf)),"varc");
//        readFile(varf,varc);
//        print(varc);
//        readFile(varf,varc);
//        print(varc)
//        closeRFile(varf);*/
//        try{
//            controller.allSteps();
//            System.out.println("Result is " + state.getOut().toString());
//        }
//        catch(ADTException | StmtException | ExprException | MyException | IOException | InterruptedException e)
//        {
//            System.out.println(e.getMessage());
//        }
//    }
//}

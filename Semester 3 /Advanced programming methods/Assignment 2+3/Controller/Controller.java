package Controller;

import Model.PrgState;
import Model.adt.MyIStack;
import Model.statement.IStmt;
import Repository.IRepository;
import Exceptions.*;

import java.io.IOException;

public class Controller {
    IRepository repo;
    boolean displayFlag;

    public Controller(IRepository repo)
    {
        this.repo=repo;
        this.displayFlag=false;
    }

    public void setDisplayFlag(boolean value){
        this.displayFlag=value;
    }

    public PrgState oneStep(PrgState state) throws MyException,ADTException,ExprException,StmtException{
        MyIStack<IStmt> stk=state.getStk();
        if(stk.isEmpty())
            throw new MyException("Prgstate stack is empty");
        IStmt crtStmt = stk.pop();
        return crtStmt.execute(state);
    }

    public void allSteps() throws MyException, ADTException, ExprException, StmtException, IOException {
        PrgState prg = repo.getPrgCrt(); // repo is the controller field of type MyRepoInterface
        //here you can display the prg state
        if(displayFlag)
            //System.out.println(prg.toString());
            repo.logPrgStateExec(prg);
        while (!prg.getStk().isEmpty()){
            oneStep(prg);
            //here you can display the prg state
            if(displayFlag)
                //System.out.println(prg.toString());
                repo.logPrgStateExec(prg);
        }}
}

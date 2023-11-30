package Repository;

import Exceptions.MyException;
import Model.PrgState;
import Model.statement.*;
import Model.expression.*;
import Model.value.*;
import Model.type.*;
import java.util.*;
import java.io.*;
public class Repository implements IRepository{

    List<PrgState> states;
    private final String logFilePath;

    public Repository(PrgState state,String logFilePath){

        states = new ArrayList<>();
        addProgram(state);
        this.logFilePath=logFilePath;
    }

    @Override
    public void addProgram(PrgState program) {
        this.states.add(program);
    }

    @Override
    public void logPrgStateExec(PrgState prg) throws MyException,IOException {

        BufferedReader br=null;
        PrintWriter logFile=null;
        try{
            logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
            logFile.println(prg.toString());
        }
        catch(IOException e)
        {
            throw new MyException(e.getMessage());
        }
        finally {
            logFile.close();
        }
    }

    @Override
    public PrgState getPrgCrt() {
        PrgState state=states.get(0);
        states.remove(0);
        return state;
    }

}

package Repository;

import Exceptions.MyException;
import Model.PrgState;

import java.io.IOException;
import java.util.List;

public interface IRepository {
    //public PrgState getPrgCrt();

    public List<PrgState> getPrgList();

    public void setPrgList(List<PrgState> list);

    public void addProgram(PrgState program);

    void logPrgStateExec(PrgState prg) throws MyException, IOException;

}

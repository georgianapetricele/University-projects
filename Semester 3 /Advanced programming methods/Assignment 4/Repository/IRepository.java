package Repository;
import Exceptions.*;
import Model.PrgState;

import java.io.IOException;

public interface IRepository {
    public PrgState getPrgCrt();
    public void addProgram(PrgState program);

    void logPrgStateExec(PrgState prg) throws MyException, IOException;

}

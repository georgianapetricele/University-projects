// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import View.View;

public class Main {
    public static void main(String[] args) throws ExprException, MyException, StmtException, ADTException {
        View ui =new View();
        ui.view();

    }
}
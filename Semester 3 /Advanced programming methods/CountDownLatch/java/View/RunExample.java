package View;

import Controller.Controller;
import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;

import java.io.IOException;
import java.util.Scanner;

public class RunExample extends Command {
    private Controller ctr;
    public RunExample(String key, String desc,Controller ctr){
        super(key, desc);
        this.ctr=ctr;
    }
    @Override
    public void execute() {
        try{

            System.out.println("Do you want to display the steps?[true/false]");
            Scanner readOption = new Scanner(System.in);
            boolean option = readOption.nextBoolean();
            ctr.setDisplayFlag(option);
            ctr.allSteps();
        }
        catch(ADTException | StmtException | ExprException | MyException | IOException | InterruptedException e)
        {
            System.out.println(e.getMessage());
        }//here you must treat the exceptions that can not be solved in the controller
    }
}
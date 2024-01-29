package com.example.examcountsemaphore;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application{

    @Override
    public void start(Stage primaryStage) throws IOException {

        FXMLLoader programListLoader = new FXMLLoader(getClass().getResource("ListWindow.fxml"));
        Parent programListRoot = programListLoader.load();
        Scene programListScene = new Scene(programListRoot, 700, 500);
        ListController listController= programListLoader.getController();
        primaryStage.setTitle("Select a program");
        primaryStage.setScene(programListScene);
        primaryStage.show();

        FXMLLoader loader = new FXMLLoader(getClass().getResource("ProgramWindow.fxml"));
        Parent interpreterView = loader.load();
        ProgramController controller = loader.getController();
        listController.setProgramController(controller);
        Stage stage = new Stage();
        stage.setTitle("Main Window");
        stage.setScene(new Scene(interpreterView));
        stage.showAndWait();

    }

    public static void main(String[] args) {
        launch(args);
    }
}

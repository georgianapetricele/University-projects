module com.example.examsemaphore {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.examsemaphore to javafx.fxml;
    exports com.example.examsemaphore;
}
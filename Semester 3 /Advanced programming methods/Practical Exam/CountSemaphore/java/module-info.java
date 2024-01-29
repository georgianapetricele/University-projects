module com.example.examcountsemaphore {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.examcountsemaphore to javafx.fxml;
    exports com.example.examcountsemaphore;
}
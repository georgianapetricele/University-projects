module com.example.examcyclicbarrier {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.examcyclicbarrier to javafx.fxml;
    exports com.example.examcyclicbarrier;
}
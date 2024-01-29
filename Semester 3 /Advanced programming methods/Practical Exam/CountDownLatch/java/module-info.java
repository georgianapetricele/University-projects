module com.example.examcountdownlatch {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.examcountdownlatch to javafx.fxml;
    exports com.example.examcountdownlatch;
}
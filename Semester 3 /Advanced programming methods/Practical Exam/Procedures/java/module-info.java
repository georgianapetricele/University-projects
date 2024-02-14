module com.example.examprocedures {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.examprocedures to javafx.fxml;
    exports com.example.examprocedures;
}
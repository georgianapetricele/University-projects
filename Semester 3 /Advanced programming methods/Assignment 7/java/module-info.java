module com.example.a7 {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.a7 to javafx.fxml;
    exports com.example.a7;
}
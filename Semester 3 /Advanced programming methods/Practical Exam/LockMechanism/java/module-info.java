module com.example.examlockmechanism {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.examlockmechanism to javafx.fxml;
    exports com.example.examlockmechanism;
}
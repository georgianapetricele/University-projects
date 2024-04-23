<?php
class DBConnection {
    private $servername = "localhost";
    private $username = "root";
    private $password = ""; 
    private $dbname = "logreports"; //the database name
    private $conn;

    public function __construct() {
        // Create a new mysqli object, which represents the connection to the MySQL database.
        $this->conn = new mysqli($this->servername, $this->username, $this->password, $this->dbname);

        // Check the connection
        if ($this->conn->connect_error) {
            die("The connection failed: " . $this->conn->connect_error);
        }
    }
    
    public function selectAllLogs() {
        $sql = "SELECT * FROM logs";
        $result = $this->conn->query($sql);
        if ($result->num_rows > 0) {
            $rows = array();
            while($row = $result->fetch_assoc()) {
                $rows[] = $row;
            }
            return $rows;
        } else {
            return array();
        }
    }

    public function selectLogsBySeverity($severity) {
        $sql = "SELECT * FROM logs WHERE severity = ?";
        $statement = $this->conn->prepare($sql);
        $statement->bind_param("s", $severity);
        $statement->execute();
        $result = $statement->get_result();
        $rows = $result->fetch_all(MYSQLI_ASSOC);
        $statement->close();
        return $rows;
    }

    public function selectLogsByUser($username) {
        $sql = "SELECT * FROM logs WHERE user = ?";
        $statement = $this->conn->prepare($sql);
        $statement->bind_param("s", $username);
        $statement->execute();
        $result = $statement->get_result();
        $rows = $result->fetch_all(MYSQLI_ASSOC);
        $statement->close();
        return $rows;
    }

    public function selectLogsByType($type) {
        $sql = "SELECT * FROM logs WHERE type = ?";
        $statement = $this->conn->prepare($sql);
        $statement->bind_param("s", $type);
        $statement->execute();
        $result = $statement->get_result();
        $rows = $result->fetch_all(MYSQLI_ASSOC);
        $statement->close();
        return $rows;
    }

    public function insertLog($type, $severity, $date, $username, $logtext) {
        $sql = "INSERT INTO logs (type, severity, date, user, logtext) VALUES (?, ?, ?, ?, ?)";
        $statement = $this->conn->prepare($sql);
        $statement->bind_param("sssss", $type, $severity, $date, $username, $logtext);
        $result = $statement->execute();
        $statement->close();
        return $result;
    }

    public function deleteLog($id, $username) {
        $sql = "DELETE FROM logs WHERE id = ? AND user = ?";
        $statement = $this->conn->prepare($sql);
        $statement->bind_param("is", $id, $username);
        $result = $statement->execute();
        $statement->close();
        return $result;
    }

    public function selectUserByUsername($username) {
        $sql = "SELECT * FROM users WHERE username = ?";
        $statement = $this->conn->prepare($sql);
        $statement->bind_param("s", $username);
        $statement->execute();
        $result = $statement->get_result();
        $rows = $result->fetch_all(MYSQLI_ASSOC);
        $statement->close();
        return $rows;
    }

    public function show($value) {
        echo json_encode($value);
    }

    public function run() {
        if (isset($_GET['action']) && !empty($_GET['action'])) {
            switch ($_GET['action']) {
                case 'selectAllLogs':
                    session_start();
                    $result = $this->selectAllLogs();
                    $this->show($result);
                    break;
                case 'selectLogsByUser':
                    session_start();
                    $user = $_SESSION['username'];
                    $result = $this->selectLogsByUser($user);
                    $this->show($result);
                    break;
                case 'selectLogsBySeverity':
                    session_start();
                    $severity = $_GET['severity'];
                    $result = $this->selectLogsBySeverity($severity);
                    $this->show($result);
                    break;
                case 'selectLogsByType':
                    session_start();
                    $type = $_GET['type'];
                    $result = $this->selectLogsByType($type);
                    $this->show($result);
                    break;
                case 'addLog':
                    session_start();
                    $user = $_SESSION['username'];
                    $type = $_GET['logType'];
                    $severity = $_GET['severity'];
                    $date = $_GET['date'];
                    $log = $_GET['log'];
                    $result = $this->insertLog($type, $severity, $date, $user, $log);
                    $this->show($result);
                    break;
                case 'removeLog':
                    session_start();
                    $user = $_SESSION['username'];
                    $id = $_GET['id'];
                    $result = $this->deleteLog($id, $user);
                    $this->show($result);
                    break;
                }
        }
    }
}
$conn = new DBConnection();
$conn->run();
?>

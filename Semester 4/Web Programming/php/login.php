<?php 
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST, GET');
session_start();
$conn = new mysqli("localhost", "root", "", "logreports");
if ($conn->connect_error)
{
    die("Connection failed: " . $conn->connect_error);
}
$username = "";
$password = "";
if (isset($_GET['username']) && isset($_GET['password'])) {
    $username = $_GET['username'];
    $password = $_GET['password'];
    $query = "SELECT U.username FROM users U WHERE U.username = ? AND U.password = ?";
    $statement = $conn->prepare($query);
    $statement->bind_param("ss", $username, $password); // Assuming password is stored in plain text for demonstration
    $statement->execute();
    $queryResult = $statement->get_result();
    if($queryResult) {
        $row = $queryResult->fetch_row();
        if (!(is_null($row))) {
            echo json_encode($row[0]);
        } else {
            echo json_encode("");
        }
    } else {
        echo json_encode("");
    }
}
?>
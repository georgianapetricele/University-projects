<?php
header('Access-Control-Allow-Origin: *');

session_start();
$conn = new mysqli("localhost", "root", "", "logreports");
if ($conn->connect_error)
{
    die("Connection failed: " . $conn->connect_error);
}

$type = $_GET["type"];
$severity = $_GET["severity"];

if ($type == "") {
    $query = "SELECT * FROM logreports.logs WHERE severity = ?";
    $statement = $conn->prepare($query);
    $statement->bind_param("s", $severity);
    $statement->execute();
    $queryResult = $statement->get_result();
}
elseif ($severity == "") {
    $query = "SELECT * FROM logreports.logs WHERE type = ?";
    $statement = $conn->prepare($query);
    $statement->bind_param("s", $type);
    $statement->execute();
    $queryResult = $statement->get_result();
}
else {
    $query = "SELECT * FROM logreports.logs WHERE type = ? AND severity = ?";
    $statement = $conn->prepare($query);
    $statement->bind_param("ss", $type, $severity);
    $statement->execute();
    $queryResult = $statement->get_result();
}

$logs = array();


$logs = array();

while($row = $queryResult->fetch_assoc()) {
    $log = array(
        "id" => $row["id"],
        "type" => $row["type"],
        "severity" => $row["severity"],
        "date" => $row["date"],
        "user" => $row["user"],
        "logtext" => $row["logtext"]
    );
    array_push($logs, $log);
}

echo json_encode($logs);

$conn->close();

?>
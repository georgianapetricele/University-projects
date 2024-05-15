<?php

header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST, GET');
$conn = new mysqli("localhost", "root", "", "logreports");
if ($conn->connect_error)
{
    die("Connection failed: " . $conn->connect_error);
}
$query = "SELECT * FROM logreports.logs";
$statement = $conn->prepare($query);
$statement->execute();
$queryResult = $statement->get_result();

$logs = array();

while($row = $queryResult->fetch_assoc()) {
    $log = array();
    array_push($log, $row["id"]);
    array_push($log, $row["type"]);
    array_push($log, $row["severity"]);
    array_push($log, $row["date"]);
    array_push($log, $row["user"]);
    array_push($log, $row["logtext"]);

    array_push($logs, $log);
}

echo json_encode($logs);

$conn->close();

?>
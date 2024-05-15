<?php
header('Access-Control-Allow-Origin: *');
$conn = new mysqli("localhost", "root", "", "logreports");
if ($conn->connect_error)
{
    die("Connection failed: " . $conn->connect_error);
}

$user = $_GET["user"];
$query = "SELECT * FROM logreports.logs WHERE user = ?";
$statement = $conn->prepare($query);
$statement->bind_param("s", $user);
$statement->execute();
$queryResult = $statement->get_result();
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
<?php
session_start();
if (!isset($_SESSION['username'])) {
    header('Location: login.php');
}
if (isset($_POST['viewAllButton'])) {
    header('Location: view_all_logs.php');
}
if (isset($_POST['returnButton'])) {
    header('Location: user_page.php');
}
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
        <link rel="stylesheet" href="style.css">
        <title>Add a log</title> 
    </head>
    <body style="background-color:antiquewhite">
        <div class="container text-center" id="removeFormDiv">
            <br><br>
        <h3>List of logs</h3>
            <div class="container" id="showLogs">
                <table class="logTable table">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Type</th>
                            <th>Severity</th>
                            <th>Date</th>
                            <th>Username</th>
                            <th>Log</th>
                        </tr>
                    </thead>
                    <tbody>
                    </tbody>
                </table>
            </div>
            <button type="button" id="previousButton" class="btn btn-info">Previous</button>
            <button id="nextButton" type="button" class="btn btn-info">Next</button>
            <div id="removeForm">
                <br><br>
                <h5>Remove a log</h5>
                <div class="mb-1"><label for="idField" class="form-label">ID: </label><input type="text" id="idField" class="form-control"></div>
                <div class="mb-1"><label for="typeField" class="form-label">Type: </label><input type="text" id="typeField" class="form-control"></div>
                <div class="mb-1"><label for="severityField" class="form-label">Severity: </label><input type="text" id="severityField" class="form-control"></div>
                <div class="mb-1"><label for="dateField" class="form-label">Date: </label><input type="text" id="dateField" class="form-control"></div>
                <div class="mb-1"><label for="userField" class="form-label">Username: </label><input type="text" id="userField" class="form-control"></div>
                <div class="mb-1"><label for="logField" class="form-label">Log: </label><input type="text" id="logField" class="form-control"></div>
                <button id="removeLogButton" type="button" class="btn btn-info">Remove Log</button>
            </div>
            <form method="post">
                <br><br>
                <input type="submit" class="btn btn-info" name="viewAllButton" value="View all log reports">
                <input type="submit" class="btn btn-info" name="returnButton" value="Return to main page">
            </form>
            <br><br>
        </div>  
    </body>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
    <script src="remove_script.js"></script>
</html>
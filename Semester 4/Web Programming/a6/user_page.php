<?php
session_start();
if (isset($_SESSION['username'])) {
    $username = $_SESSION['username'];
} else {
    header('Location: login.php');
    die();
}
if (isset($_POST['viewAllButton'])) {
    header('Location: view_all_logs.php');
}
if (isset($_POST['logoutButton'])){
    session_unset();
    session_destroy();
    header('Location: login.php');
}
if(isset($_POST['addLogButton'])) {
    header('Location: add_log.php');
}
if(isset($_POST['removeLogButton'])) {
    header('Location: remove_log.php');
}
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="style.css">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
        <title>Main page</title> 
    </head>
    <body style="display:flex; align-items:center; justify-content:center; margin:200px 800px; background-color:antiquewhite">
        <div class="container">
            <div class="form-container" >
                <h1>Welcome, <?php echo $username;?>!</h1>
                <form method="post">
                    <br>
                    <input type="submit" class="btn btn-info" name="viewAllButton" value="View all log reports">
                    <br><br>
                    <input type="submit" class="btn btn-info" name="addLogButton" value="Add a log report">
                    <br><br>
                    <input type="submit" class="btn btn-info" name="removeLogButton" value="Remove a log report">
                    <br><br>
                    <input type="submit" class="btn btn-info" name="logoutButton" value="Log out">
                </form>
            </div>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
        <script src="add_script.js" type="text/javascript"></script>
        <script src="remove_script.js" type="text/javascript"></script>
        <script src="logs_script.js" type="text/javascript"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
</html>

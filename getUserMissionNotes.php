<?php 

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "userdb";
$dbUserTable = "users";
$dbMissionLogsTable = "mission_logs";
$dbUserNotesTable = "user_notes";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
header('Content-Type: application/json');
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
$str = "";
// Get the UserID from C++
$UserID =  $_GET["data"];

// Query database
$sql = "SELECT note_id, title, body, date_create FROM  ". $dbUserNotesTable ." WHERE user_id = '$UserID'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
       $str.=  $row["title"]. "<br> " . $row["body"]. "<br>";
    }
} else {
    echo "No mission logs found.";
	$str = "No mission logs found.";
}

	$theVar = array('customData' => $str);
	$encoded = json_encode($theVar);
// Return the data wrapped in JSON
    echo $encoded;
$conn->close();

?>


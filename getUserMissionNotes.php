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
// Decode JSON
//$data= json_decode(file_get_contents('php://input'), true);
$UserID =  $_GET["data"];
//$UserID = $data['UserID'];

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
    echo $encoded;
$conn->close();

?>


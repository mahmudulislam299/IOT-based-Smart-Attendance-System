<!--
 * Mahmudul Islam
 * EEE,Bangladesh University of Engineering and Technology (BUET)
 * Email: mahmudulislam299@gmail.com
 *
 -->
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="refresh" content="6">
<!meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" type="text/css" href="css/header.css">

</head>
<header>
<div class="header"> 
	<div class="logo"><img src="logo.png" alt="Smiley face" style="float:right;width:120px;height:120px;">
		<a>Student Attendance System</a>
	</div>
</div>
<div class="topnav" id="myTopnav">
	
    <a href="studentdata.php">Student data</a>
    <a href="view.php">View attendence</a>
    <a href="javascript:void(0);" class="icon" onclick="navFunction()">
	  <i class="fa fa-bars"></i></a>
</div>

</header>
<?php
	$servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "studentattendance";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

// sql to delete a record
$sql = "DELETE FROM logs WHERE id >10";

if ($conn->query($sql) === TRUE) {
    echo "Record deleted successfully";
} else {
    echo "Error deleting record: " . $conn->error;
}

$conn->close();
?>
</body>
</html>
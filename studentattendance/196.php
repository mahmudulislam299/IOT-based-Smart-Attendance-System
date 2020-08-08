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
	<div class="logo"> <img src="logo.png" alt="Smiley face" style="float:left;width:150px;height:150px;">
		<a>Student Attendance System</a>
	</div>
</div>
<div class="topnav" id="myTopnav">
	<a href="delete.php">delete data</a>
    <a href="studentdata.php">Student data</a>
    <a href="view.php">View attendence</a>
    <a href="javascript:void(0);" class="icon" onclick="navFunction()">
	  <i class="fa fa-bars"></i></a>
</div>


</header>
<body>
<style>
/* Style the element with the id "myHeader" */
#myHeader {
  background-color: lightblue;
  color: black;
  padding: 40px;
  text-align: center;
}

/* Style all elements with the class name "city" */
.city {
  background-color:White;
  color: white;
  padding: 10px;
} 
</style>
</head>
<body>



<!-- A unique element -->
<h1 id="myHeader">Sheikh Tabrej Alam</h1>
<img src="196.png" alt="photo" style="float:right;">

<!-- Multiple similar elements -->
<h2><pre>
			Department of Electrical and Electronic Engineering<br>
			Student No : 1506196<br>
			Level: 4 <br>
			Term : I<br>
			Session: 2018-19<br>
			Hall: Dr. M A Rashid Hall<br>
			
   </pre>
<h2>




<?php
    //Connect to database and create table
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "studentattendance";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Database Connection failed: " . $conn->connect_error);
        echo "<a href='install.php'>If first time running click here to install database</a>";
    }
	
?> 

</body>
</html>



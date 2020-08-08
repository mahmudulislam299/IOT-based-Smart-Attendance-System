<!--
 * Mahmudul Islam
 * EEE,Bangladesh University of Engineering and Technology (BUET)
 * Email: mahmudulislam299@gmail.com
 *
 -->
<?php
//Creates new record as per request
    //Connect to database
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "studentattendance";
	$n=0;
    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Database Connection failed: " . $conn->connect_error);
    }
	
    //Get current date and time
    date_default_timezone_set('Asia/dhaka');
    $d = date("Y-m-d");
    //echo " Date:".$d."<BR>";
    $t = date("H:i:s");
	$dep="EEE";
	
	$namedata=array("khali","Ordatun Jannat","Rahad Arman Nabid","Nafhatul Zinan Shifa","Naima Tasnim","Mahmudul Islam","Sheikh Tabrej Alam","TRACY","JIMMY","DANIEL");
	$siddata=array("1506100","1506139","1506142","1506143","1506144","1506155","1506196","1506107","1506108","1506109");
	
    if(!empty($_POST['sid']) && !empty($_POST['name']) && !empty($_POST['state'])  )
    {
		
    	$sid = $_POST['sid'];
    	$name = $_POST['name'];
		$state=$_POST['state'];
		//$student = $_POST['student'];
		$n=$sid;
		

	    $sql = "INSERT INTO logs (name,sid, dept,state, Date, Time)
		
		 VALUES ('".$namedata[$n]."', '".$siddata[$n]."','".$dep."','".$state."', '".$d."', '".$t."')";

		if ($conn->query($sql) === TRUE ) {
		    echo "$n";//OK
		} else {
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
		
		

	}

	$conn->close();
?>
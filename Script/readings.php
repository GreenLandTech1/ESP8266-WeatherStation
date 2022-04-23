<?php
/* Database connection settings */
	
	   $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "myDatabase";
    
	$conn = mysqli_connect($servername, $username, $password, $dbname);
	
	if ($conn->connect_error) {
        die("Database Connection failed: " . $conn->connect_error);
    }

// sql to create table
$sql = "CREATE TABLE Notifications (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
Temperature VARCHAR(30) NOT NULL,
Humidity VARCHAR(30) NOT NULL,
Light_Intensity VARCHAR(30) NOT NULL,
bmp_temperature VARCHAR(30) NOT NULL,
Pressure VARCHAR(30) NOT NULL,
Altitude VARCHAR(30) NOT NULL,
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)";

if ($conn->query($sql) === TRUE) {
  echo "Table WeightReadings created successfully";
} else {
 // echo "Error creating table: " . $conn->error;
}

$s1 = $_GET['temp'];
$s2 = $_GET['hum'];
$s3 = $_GET['lux'];
$s4 = $_GET['bmptemp'];
$s5 = $_GET['pressure'];
$s6 = $_GET['alt'];
$sql = "INSERT INTO Notifications(Temperature,Humidity,Light_Intensity,bmp_temperature,Pressure,Altitude)  VALUES ('".$s1."','".$s2."','".$s3."','".$s4."','".$s5."','".$s6."')";
//('".$val."','".$val2."', '".$d."', '".$t."')"; 
if ($conn->query($sql) === TRUE) {
  echo "ok";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();



?>
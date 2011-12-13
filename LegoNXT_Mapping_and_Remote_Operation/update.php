<html>
<title>NXT Control</title>
<body>

<?php

$file = fopen("C:\\update.txt", "w+");
$value = $_GET['action'];
//$value = 'coord';
$time = time();
$writethis = 'Error in php update.txt';

if ($value == "Up") //find which button was pushed and create the new output
	{
	$directions = '1000';
	$coords = ' 00 00 ';
	$comments = '(UP, DOWN, LEFT, RIGHT | X,Y COORD)';
	$writethis = $directions . $coords . $comments . $time;
	}
elseif ($value == "Down")
	{
	$directions = '0001';
	$coords = ' 00 00 ';
	$comments = '(UP, DOWN, LEFT, RIGHT | X,Y COORD)';
	$writethis = $directions . $coords . $comments . $time;
	}
elseif ($value == "Left")
	{
	$directions = '0100';
	$coords = ' 00 00 ';
	$comments = '(UP, DOWN, LEFT, RIGHT | X,Y COORD)';
	$writethis = $directions . $coords . $comments . $time;
	}
elseif ($value == "Right")
	{
	$directions = '0010';
	$coords = ' 00 00 ';
	$comments = '(UP, DOWN, LEFT, RIGHT | X,Y COORD)';
	$writethis = $directions . $coords . $comments . $time;
	}	
elseif ($value == "coord")
	{
	$X = $_POST['X']; //get X and Y inputs
	$Y = $_POST['Y'];	
	
	if (strlen($X) == 1) $X = ("0" . $X); //make sure the number has 2 digits
	if (strlen($X) > 2)
		{
		$length = strlen($X);
		$X = $X($length-2) . $X($length-1);
		}
		
	if (strlen($Y) == 1) $Y = ("0" . $Y);
	if (strlen($Y) > 2)
		{
		$length = strlen($Y);
		$Y = $Y($length-2) . $Y($length-1); // /keep digits
		}
	
	$directions = '0000 ';
	$coords = $X . ' ' . $Y . ' ';
  $comments = '(UP, DOWN, LEFT, RIGHT | X,Y COORD)';
	$writethis = $directions . $coords . $comments . $time;  
  }
else 
	{
	echo "no action data";
	}
	
	
fwrite($file, $writethis);
fclose($file);


header("location: nxtControl.php"); 

?>
</body>
</html>
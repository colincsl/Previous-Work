<html>

 <meta http-equiv="Pragma" content="no-cache">
 <meta http-equiv="Cache-Control" content="no-cache">
 <meta http-equiv="Expires" content="Sat, 01 Dec 2001 00:00:00 GMT">
   
<title>NXT Control</title>
<body>
<body bgcolor = "Gray">
<table>

<td>
<center>
<table>
<form action='update.php?action=Up' method = "post">
<input type="submit" value="Up">
</form>

<td>
<form action='update.php?action=Left'method = "post">
<input type="submit" value="   Left  ">
</form>
 </td>
 <td> </td>
<td>
<form action='update.php?action=Right'method = "post">
<input type="submit" value="Right">
</form>
</td>

<tr>
<td>
<td>
<form action='update.php?action=Down' method = "post">
<input type="submit" value="Down">
</form>
</tr></td>
</table>
<br>

<form action='update.php?action=coord' method="post">
X: 
<input type="text" name="X" value="15" size=3>
Y:
<input type="text" name="Y" value="20" size=3>
<input type="submit" value = "Point Find">
</form>
</center>
</td><td>

<img src='map.jpg?r=1' width=600 height=450>

<script language="Javascript">


function reloadPage()
	{
	document.images[0].src="map_old.jpg";
	document.images[0].src="map.jpg?r=2";

	}

setTimeout('reloadPage()', 2000);
</script>



</td></table>
</center>
</body>
</html>
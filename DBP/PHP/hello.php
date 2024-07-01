<!DOCTYPE html>
<html>
<head>
<style>
* {
padding: 0;
 margin: 0;
}
</style>
</head>
<body>
<center>

<strong><h1>Tabla de numero naturlaes</h1></strong>

</center>
<center>
<table>
<tbody>

<th>
<?php
$num = 10;

for ($i=0; $i<$num; $i++) {
    if ($i % 2 == 1) {
        echo "<td style=\"outline: 1px solid black; padding: 10px;\">".$i."  "."</td>";
    }
    else {
        echo "<td style=\"color: red; outline: 1px solid black; padding: 10px;\";>".$i."  "."</td>";

    }
}
?>
</th>
</tbody>
</table></center>;

</body>
</html>

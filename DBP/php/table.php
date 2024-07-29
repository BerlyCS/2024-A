<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Tabla de Números</title>
    <style>
        .par {
            color: red;
        }
    </style>
</head>
<body>
    <table border="1">
        <tr>
        <?php
        for ($i = 1; $i <= 10; $i++) {
            // Determinar si el número es par o impar
            $clase = ($i % 2 == 0) ? 'par' : '';
            echo "<td class='$clase'>$i</td>";
        }
        ?>
        </tr>
    </table>
</body>
</html>

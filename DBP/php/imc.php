<!DOCTYPE html>
<html>
<head>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">

</head>
<body>
    <header class="m-3 justify-align-center">
        <h2>Calcular indice de masa corporal</h2>
    </header>
    <form method="get" class="container p-5" style="background-color: cyan;
    border-radius: 5px;">
        <p>Peso:</p>
        <input type="number" id="peso" name="peso" required>
        <br>
        <p>Talla:</p>
        <input type="text" id="talla" name="talla" required>
        <p>Perimetro:</p>
        <input type="number" id="perimetro" name="perimetro" required>
        <p>Genero:</p>
    <select class="" id="genero" name="genero">
        <option value="#" class="disabled">Seleccionar</option>
        <option value="Masculino">Masculino</option>
        <option value="Femenino">Femenino</option>
    </select>
        <button type="submit" class="btn btn-primary">Enviar</button>

    </form>
<?php
$talla = $_GET["talla"];
$peso = $_GET["peso"];
$genero = $_GET["genero"];
$imc = $peso / ($talla*$talla);
echo "<h4>";
echo $imc;
echo "</h4>";
if ($imc < 18.5) {
    echo "Bajo peso";
}
else if ( $imc < 24.9 ) {
    echo "Normal";
}
else if ( $imc < 29.9 ) {
    echo "Sobrepeso";
}
else if ( $imc < 34.9 ) {
    echo "Obesidad I";
}
else if ( $imc < 39.9 ) {
    echo "Obesidad II";
}
else {
    echo "Obesidad III";
}

$perimetro = $_GET["perimetro"];
if ($genero == "Masculino") {
    if ( $perimetro < 94 ) {
        echo "Normal";
    }
    else if ( $perimetro < 102 ) {
        echo "Aumento del riesgo de problemas";
}   
    else {
        echo "riesgo elevado";
}
}
else if ($genero == "Femenino") {
    if ( $perimetro < 80 ) {
        echo "Normal";
}
else if ( $perimetro < 88 ) {
        echo "Riesgo";
}
else {
echo "riego elevado";
}
}
?>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
</body>
</html>

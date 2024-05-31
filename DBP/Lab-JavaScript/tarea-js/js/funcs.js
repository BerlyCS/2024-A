function getAge(birthday) {
    let cumpleaños = new Date(birthday);
    let hoy = new Date();
    let edad = hoy.getFullYear() - cumpleaños.getFullYear();
    let mes = hoy.getMonth() - cumpleaños.getMonth();
    if (mes < 0) {
        edad--;
    }
    return edad;
}

function escribir() {
    let nombre =  document.getElementById('nombre1').value + 
    ' ' + document.getElementById('nombre2').value;
    let apellido = document.getElementById('apellido1').value +
    ' ' + document.getElementById('apellido2').value ;
    let dni = document.getElementById('dni').value;
    let fecha = document.getElementById('fecha').value;

    let nombre_completo = nombre + ' ' + apellido;
    let edad = getAge(fecha);

    console.log(nombre_completo);
    console.log(dni);
    console.log(fecha);
    alert("...");

    document.getElementById('nombrePlace').innerHTML = nombre_completo;
    document.getElementById('dniPlace').innerHTML = dni.substr(-1);
    document.getElementById('edadPlace').innerHTML = edad;
}


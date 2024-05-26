function escribir() {
    let name = document.getElementById('nombre').value;
    let apellido = document.getElementById('apellido').value;
    let dni = document.getElementById('dni').value;
    let ciudad = document.getElementById('region').value;
    console.log(name);
    console.log(apellido);
    console.log(dni);
    console.log(ciudad);
    alert("...");

    document.getElementById('namePlace').innerHTML = name;
    document.getElementById('apellidoPlace').innerHTML = apellido;
}

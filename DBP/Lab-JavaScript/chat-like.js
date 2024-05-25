function displayInput() {
    // Obtener el valor del input
    const userInput = document.getElementById('userInput').value;
    
    // Crear un nuevo elemento de párrafo
    const newParagraph = document.createElement('p');
    newParagraph.textContent = userInput;
    newParagraph.className = "color-text";
    
    // Añadir el nuevo párrafo al área de salida
    const outputArea = document.getElementById('outputArea');
    outputArea.appendChild(newParagraph);
    
    // Limpiar el campo del formulario
    document.getElementById('myForm').reset();

}


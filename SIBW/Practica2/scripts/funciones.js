function mostrarComentarios() {
    var popup = document.getElementById("comentarios");
    popup.classList.toggle("show");
}


function campoRequerido() {
    var x = document.forms["myForm"]["fname"].value;
    if (x == "") {
        alert("Este campo es obligatorio");
        return false;
    }
}

document.getElementById('toggle-button').addEventListener('click', function () {
    toggle(document.querySelectorAll('.target'));
});

function toggle (elements, specifiedDisplay) {
  var element, index;

  elements = elements.length ? elements : [elements];
  for (index = 0; index < elements.length; index++) {
    element = elements[index];

    if (isElementHidden(element)) {
      element.style.display = '';

      // If the element is still hidden after removing the inline display
      if (isElementHidden(element)) {
        element.style.display = specifiedDisplay || 'block';
      }
    } else {
      element.style.display = 'none';
    }
  }


function validar(nombreFormulario) {
    var formulario = document.forms[nombreFormulario],
        validado = true,
        elemento,
        regExp,
        i;
    
    for (i = 0; i < formulario.elements.length; i += 1) {
        elemento = formulario.elements[i];
        
        if (elemento.type === "text" || elemento.type === "textarea") { // Elemento de texto o área de texto
            if (elemento.value === "") { // Campo vacío
                //alert("Debe rellenar el campo: " + elemento.name);
                elemento.setAttribute("class", "error");
                validado = false;
            } else {
                elemento.setAttribute("class", "valido");
            }
            
            if (elemento.name === "telefono") { // Campo telefónico
                regExp = /([0-9]{9})/;
                if (!elemento.value.match(regExp)) { // Teléfono incorrecto
                    //alert("Introduzca un telefono valido.");
                    elemento.setAttribute("class", "error");
                    validado = false;
                } else {
                    elemento.setAttribute("class", "valido");
                }
            }
        }
        
        if (elemento.type === "email") { // Campo de email
            regExp = /([a-z\-_0-9]+@[a-z\-]*\.?[a-z]+\.[a-z\-]+)/;
            if (!elemento.value.match(regExp)) { // email incorrecto
                //alert("Introduzca un email valido.");
                elemento.setAttribute("class", "error");
                validado = false;
            } else {
                elemento.setAttribute("class", "valido");
            }
        }
        
    }
    
    if (validado) {
        alert("El formulario se ha enviado correctamente");
        validado = false; // Se pone el valor a false par que no salga mensaje de error al no tener script de envío
        
    }
    
    return validado;
}

  function isElementHidden (element) {
    return window.getComputedStyle(element, null).getPropertyValue('display') === 'none';
  }
}

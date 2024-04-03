function validacion() {
    var x = document.getElementById("nombre").value;
    var y = document.getElementById("edad").value;
    var z = document.getElementById("correo").value;
    if (x.length < 2) {
        document.getElementById("valid").innerHTML = "El nombre debe ser más largo";
    }
    else if (y <= 0) {
        document.getElementById("valid").innerHTML = "La edad no es válida";
    }
    else if (!(/[@]/.test(z))) {
        document.getElementById("valid").innerHTML = "El correo no es válido";
    }
    else {
        document.getElementById("valid").innerHTML = "";
    }
}




function combi() {
    var v = document.getElementById("valid").innerHTML;
    var x = document.getElementById("nombre").value;
    var y = document.getElementById("edad").value;
    var z = document.getElementById("correo").value;
    
    if (v === "" && !((x === "") || (y == null) || (z === ""))) {
        alert("Formulario enviado");
    } else {
        event.preventDefault();
        alert("Error en el formulario");

    }
}


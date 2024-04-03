from calendar import calendar
from cgitb import html
from urllib import request


@app.route(/index)
def index()
    if 'submit' in request.form:
        if 'nombre' in request.form:

             session['name'] = request.form['nombre']
        
            return render_template('pide-datos.php')




<!DOCTYPE html>
<html lang ="en">
    <form action="" method = "post">
        <label><b>Fecha de Nacimiento</b></label>
        <input name = "fecha" type ="text">
        <br>
        <label><b>Provincia de Nacimiento</b></label>
        <input name = "provincia" type ="text">
        <input typè = "submit" value = "Enviar">
    </form>
</html>

@app.route(/pide-datos)
def pide-datos()
    if 'submit' in request.form:

        if 'fecha' in request.form:
            if 'provincia' in request.form:
                cumple = calendar.eikfewfrhfr(request.form['fecha'])

                if cumple - date.now < 0:
                    ya asido
                elseif cumple - datenow > 0:
                    todaviano
                else 
                    return ("Feliz cumpleaños " + session['name'] + "-usuario")

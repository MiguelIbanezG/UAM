
mongosh << EOF
use unis;
db.createCollection("publicas");

db.publicas.insertMany([\
    {\
        "nombre" : "Universidad Complutense de Madrid",\
        "cp" : 28040,\
        "telefono" : 914520400,\
        "email" : "infocom@ucm.es",\
        "web" : "https://www.ucm.es/",\
        "centros" : [{"nombre": "Facultad de Ciencias", "alumnos" : 12387 },\
        {"nombre": "Facultad de Ciencias Económicas y Empresariales", "alumnos" : 12387 },\
        {"nombre": "Facultad de Filosofía y Letras", "alumnos" : 12387 },\
        {"nombre": "Facultad de Formación del Profesorado y Educación", "alumnos" : 12387 },\
        {"nombre": "Escuela Politécnica Superior", "alumnos" : 12387 }\
        ]\
    },\
    {\
        "nombre" : "Universidad Autónoma de Madrid",\
        "cp" : 28049,\
        "telefono" : 914975000,\
        "email" : "uamcutre@uam.es",\
        "web" : "https://www.uam.es/",\
        "centros" : [{"nombre": "Facultad de Ciencias", "alumnos" : 12387 },\
        {"nombre": "Facultad de Ciencias Económicas y Empresariales", "alumnos" : 12387 },\
        {"nombre": "Facultad de Derecho", "alumnos" : 12387 },\
        {"nombre": "Facultad de Filosofía y Letras", "alumnos" : 12387 },\
        {"nombre": "Facultad de Formación del Profesorado y Educación", "alumnos" : 12387 },\
        {"nombre": "Escuela Politécnica Superior", "alumnos" : 12387 }\
        ]\
    },\
    {\
        "nombre" : "Universidad Politécnica de Madrid",\
        "cp" : 28040,\
        "telefono" : 913366000,\
        "email" : "universidad@upm.es",\
        "web" : "https://www.upm.es/",\
        "centros" : [{"nombre": "Facultad de Ciencias", "alumnos" : 12387 },\
        {"nombre": "Facultad de Ciencias Económicas y Empresariales", "alumnos" : 12387 },\
        {"nombre": "Facultad de Filosofía y Letras", "alumnos" : 12387 },\
        {"nombre": "Facultad de Formación del Profesorado y Educación", "alumnos" : 12387 },\
        {"nombre": "Escuela Politécnica Superior", "alumnos" : 12387 }\
        ]}]);

EOF
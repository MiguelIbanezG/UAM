match='$match'
project='$project'
sum='$sum'
centros='$centros'
exists='$exists'
nombre='$nombre'
mongosh << EOF
use unis;
db.publicas.aggregate({ $match : {"nombre" : {$exists: true}}}, \
{ "$project": { "_id": 0, "nombre": "$nombre", "total": {$sum : "$centros.alumnos"}}} \
);
EOF
regex='$regex'
match='$match'

mongosh << EOF
use unis;
db.publicas.find( {"centros.nombre" :  {"$regex": 'Derecho'}  },{_id:0});
EOF
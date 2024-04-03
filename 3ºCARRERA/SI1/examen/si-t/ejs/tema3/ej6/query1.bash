mongosh << EOF 
use unis;
db.publicas.find({"nombre":"Universidad Autónoma de Madrid"},{"centros":1,_id:0});
EOF


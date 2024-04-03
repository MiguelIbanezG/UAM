dropdb -U alumnodb siej2
createdb -U alumnodb siej2
gunzip -c script.sql.gz | psql siej2 alumnodb

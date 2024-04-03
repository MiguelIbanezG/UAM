dropdb -U alumnodb siej
createdb -U alumnodb siej
gunzip -c script.sql.gz | psql siej alumnodb

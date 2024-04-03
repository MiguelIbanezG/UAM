explain SELECT * FROM muchasPeliculas where titulo = 'REQUIEM TYCOONv236'; 

explain SELECT * FROM muchasPeliculas where id_pelicula = 235719;

EXPLAIN SELECT id, COUNT(*) FROM muchasPeliculas GROUP BY id;

EXPLAIN SELECT puntuacion, COUNT(*) FROM muchasPeliculas GROUP BY puntuacion;

explain SELECT * FROM muchaspeliculas;

explain SELECT * FROM muchasPeliculas where titulo LIKE 'REQUIEM %';

explain SELECT * FROM muchasPeliculas where agno = 1995;
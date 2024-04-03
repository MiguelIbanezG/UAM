CREATE TABLE muchasPeliculas(
ID INTEGER, -- Identificador único
TITULO CHAR(128), -- Título de la película
AGNO DECIMAL(4), -- Año de estreno
PUNTUACION FLOAT, -- Puntuación media
VOTOS INTEGER -- Número de votos
);





DO $$
DECLARE 
maxID INT := 1;
i INT := 1;
BEGIN
SELECT max(p.id) as mid INTO maxID FROM pelicula p;
WHILE i < 4500 loop
INSERT INTO muchasPeliculas
(ID, TITULO, AGNO, PUNTUACION, VOTOS)
(SELECT ((i-1)*maxID) + ID,
CONCAT(TITULO, ' v', i),
AGNO,
RANDom()*10,
FLOOR(RANDom()*1000)
FROM PELICULA);
i := i + 1;
END loop;
end;
$$
LANGUAGE 'plpgsql';

ALTER TABLE muchasPeliculas ADD PRIMARY KEY(ID);

CREATE INDEX idx_id_pelis ON muchasPeliculas(ID);

CREATE INDEX idx_agno ON muchasPeliculas(agno);
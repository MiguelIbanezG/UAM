CREATE OR REPLACE FUNCTION update_top()
RETURNS trigger 
AS $$
BEGIN
    CREATE VIEW top_artist
AS 
    select a.id, a.nombre, count (r.ord) as n_prota from reparto r join actor a 
    on a.id = r.actor_id 
    join pelicula p on p.id = r.pelicula_id 
    where r.ord = 1 and p.agno >= 1980 and p.agno <= 1999
    group by a.id order by n_prota desc limit 10;
END;
$$
LANGUAGE 'plpgsql';

CREATE TRIGGER upd_protas
BEFORE UPDATE ON reparto
FOR EACH ROW EXECUTE
PROCEDURE update_top();


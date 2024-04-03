CREATE OR REPLACE FUNCTION actores_prota() 
    RETURNS TABLE(nombre character (35), agno numeric(4,0))
   AS
$$
BEGIN
    RETURN QUERY 
    select t5.nombre, t5.agno from (
        select distinct on (t4.nombre, t4.n_prota) * from (
            select t3.nombre, t3.n_prota, p.agno,  count(*) as prota from pelicula p join reparto r
            on p.id = r.pelicula_id join (
                select * from actor a natural join (
                    Select a.id, a.nombre, count(r.ord) as n_coprota from actor a 
                    join reparto r on a.id = r.actor_id 
                    where r.ord = 2
                    group by a.id
                    order by n_coprota desc) as t1
                natural join (
                    Select a.id, a.nombre, count(r.ord) as n_prota from actor a 
                    join reparto r on a.id = r.actor_id 
                    where r.ord = 1
                    group by a.id
                    order by n_prota desc) as t2
                where t2.n_prota > t1.n_coprota
                order by t2.n_prota desc
            ) as t3 on r.actor_id = t3.id
            group by t3.nombre, p.agno, t3.n_prota
            having count(p.agno) >= 1 
            order by t3.n_prota desc,  t3.nombre asc,  prota desc) as t4 
        order by t4.n_prota desc) as t5;
   
END;
$$
  LANGUAGE 'plpgsql';
  
 
select * from actores_prota();
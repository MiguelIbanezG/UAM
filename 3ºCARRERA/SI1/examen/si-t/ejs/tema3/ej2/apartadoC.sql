
CREATE OR REPLACE FUNCTION busqueda(ciudad text) 
    RETURNS TABLE(id_c character varying(15), nombre character varying(15), calle_cliente character varying(15))
   AS
$$
BEGIN
    RETURN QUERY SELECT c.id, c.nombre_cliente, c.calle_cliente from cliente c
                 join cliente_cuenta cc on c.id = cc.id_cliente natural join cuenta c2 
                 join sucursal s on c2.nombre_sucursal = s.nombre_sucursal 
                 where c.ciudad_cliente <> s.ciudad_sucursal and s.ciudad_sucursal = ciudad;
END;
$$
  LANGUAGE 'plpgsql';
  
 
 select * from busqueda('Brooklyn');
 
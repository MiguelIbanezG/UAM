select nombre_cliente from cliente c
where id in (
    select id_cliente from cliente_prestamo
	natural join prestamo
	where nombre_sucursal = 'Perryridge'
    and id_cliente not in (
        select id_cliente from cliente_cuenta
        natural join cuenta 
        where nombre_sucursal = 'Perryridge'
    )
);
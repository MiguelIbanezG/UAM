DO $$
DECLARE 
_id int :=0;
maximum int :=0;
int_var int :=0;
valor1 int := 0;
valor2 int := 1000;
begin
	select into maximum count(*)  from prestamo;
	WHILE _id < maximum loop
	WITH params AS (
            SELECT _id AS rownumber 
    )
	
	 SELECT INTO int_var count(cantidad) FROM prestamo 
		where cantidad >= valor1 and cantidad < valor2;
       RAISE NOTICE '% - %: %', valor1, valor2, int_var; 
	_id := _id + int_var;
	valor1 := valor2;
	valor2 := valor1 +1000;
	
	END LOOP;
end $$;
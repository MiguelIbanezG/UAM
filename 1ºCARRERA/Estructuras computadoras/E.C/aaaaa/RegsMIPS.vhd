architecture Practica of RegsMIPS is

	-- Tipo para almacenar los registros
	type regs_t is array (0 to 31) of signed(31 downto 0);

	-- Esta es la señal que contiene los registros. El acceso es de la
	-- siguiente manera: regs(i) acceso al registro i, donde i es
	-- un entero. Para convertir del unsigned a entero se  hace de la 
	-- siguiente manera: to_integer(us), donde us es un elemento de tipo unsigned

	-- Registros inicializados a '0' 
	signal regs : regs_t;

begin  -- PRACTICA
	regs(0)<=(others=>'0');
	------------------------------------------------------
	-- Escritura del registro RD
	------------------------------------------------------
	-- Escribe el contenido de Wd3 en el registro indicado
	-- por A3 cuando hay flanco de subida de reloj y
	-- la señal de habilitación de escritura We3 está activa.
	-- Tiene reset asíncrono. Si está habilitado el reset, 
	-- todos los registros se inicializan a valor 0
	process(all)
	begin
		if NRst = '0' then
			for i in 0 to 31 loop 
				regs(i)<=(others => '0');

			end loop;
		elsif rising_edge(CLK) and We3='1' and to_integer(A3)/=0 then
			regs(to_integer(A3)) <= Wd3;
		end if;
	end process;
	------------------------------------------------------
	-- Lectura del registro Rd1
	------------------------------------------------------
	-- Lee en Rd1 el registro indicado por A1. 
	-- La lectura del registro R0 siempre devuelve 0.
	Rd1 <= regs(to_integer(A1));
	------------------------------------------------------
	-- Lectura del registro Rd2
	------------------------------------------------------
	-- Lee en Rd2 el registro indicado por A2. 
	-- La lectura del registro R0 siempre devuelve 0.
	Rd2 <= regs(to_integer(A2));
 
end Practica;

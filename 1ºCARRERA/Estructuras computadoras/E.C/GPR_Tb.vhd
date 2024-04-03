----------------------------------------------------------------------------------
----------------------------------------------------------------------------------
-- Asignatura: Estructura de computadores
-- Fichero: GPR_Tb.vhd
-- Descripción: Archivo de simuación del banco de registros propuesto en el examen
-- Fichero de apoyo para la evaluación de la práctica 2. MODELO A
----------------------------------------------------------------------------------
----------------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity GPR_Tb is
end GPR_Tb;

architecture Examen of GPR_Tb is

component GPR
	port (
		Clk : in std_logic; 
		Reset : in std_logic; 
		R : in unsigned(3 downto 0); 
		Leer : out signed(23 downto 0); 
		-- Un puerto de escritura		
		W : in unsigned(3 downto 0); 
		Escribir : in signed(23 downto 0); 
		We : in std_logic 
	); 
end component;

	-- Constantes
	constant INSTANTE : time := 10 ns;
	constant PERIOD   : time := 20 ns;       -- Periodo de la senal de reloj

	-- Señales
	signal leer, escribir : signed(23 downto 0):=(others=>'0');
	signal r, w : unsigned(3 downto 0):= (others=>'0');
	signal clk, we, reset : std_logic;
	signal endSim : boolean := false;    -- Senal para parar el reloj

begin  -- Practica

	-- Instanciar el banco de registros
	UUT : GPR port map (
		Clk => clk,
		Reset=> reset,
		R => r,
		Leer => leer,		
		W => w,
		Escribir => escribir,
		We => we );


	-- Proceso de reloj. Se para cuando la senal endSim se pone a TRUE
	process
	begin
		while not endSim loop
			clk <= '0';
			wait for PERIOD/2;
			clk <= '1';
			wait for PERIOD/2;
		end loop;
		wait;
	end process;

	-----------------------------------------------------------------------------
	-- Proceso principal de pruebas
	-----------------------------------------------------------------------------
	process
	begin
		---------------------------------------------------------------------------
		-- Prueba de reset. Todos los registros deben tener el valor de 0
		---------------------------------------------------------------------------
		
		-- Primero probamos a resetear mientras solicitamos una escritura
		
		reset <= '1';
		we <= '1';
		r <= (others => '0');		
		w <= (others => '0');
		escribir <= x"FFFFFF" ;
		
		wait until rising_edge(clk);
		
		-- Se comprueba que no se ha escrito nada en ningun registro:
		for i in 0 to 15 loop
			r <= to_unsigned(i,4);
			wait for INSTANTE;
			-- Comprueba la salida de la señal leer
			assert leer = x"000000"
				report "Error en el reset con escritura activa"
					severity WARNING;
		end loop;  

		-- Poner ahora todas las senales a '0' y despues liberar reset
		we <= '0';
		r <= (others => '0');		
		w <= (others => '0');
		escribir <= (others => '0');
		reset <= '1';
		wait for INSTANTE;
		reset <= '0';
		-- Volver a comprobar que todos los registros tienen el valor de 0

		for i in 0 to 15 loop
			r <= to_unsigned(i,4);
			wait for INSTANTE;
			-- Comprobar la salida de Lect
			assert leer = x"000000"
				report "Error en el reset"
					severity WARNING;
		end loop;  
	
		---------------------------------------------------------------------------
		-- Prueba de escritura puerto W. En cada registro se escribe el valor de su direccion +8
		---------------------------------------------------------------------------
			-- Indicar que queremos escribir
			we <= '1';
		for i in 0 to 15 loop
			-- Colocar la direccion destino
			w <= to_unsigned(i,4);
			-- Colocar el dato a escribir en el GPR
			escribir <= to_signed(i+8,24);
			-- Esperar un flanco de subida de reloj, que es donde se hace la escritura
			wait until rising_edge(clk);
		end loop;  
		---------------------------------------------------------------------------
		-- Pruebas de lectura. Se lee por la senal de leer. Se recorre la memoria en sentido ascendente		
		---------------------------------------------------------------------------
		we <= '0';
		wait for INSTANTE;

		for i in 1 to 15 loop
			-- En a1 se colocan las direcciones ascendentes
			r <= to_unsigned(i,4);

			wait for INSTANTE;
			
			-- Comprobar la salida de rd1
			assert leer = to_signed(i+8,24)
				report "Error en la lectura de Lect"
					severity WARNING;
			end loop;  

		-- Comprobar que del registro 0 se lee '0'
		r <= (others => '0');
		wait for INSTANTE;

		-- Comprobar registro rd1
		assert leer = x"000000"
			report "Error. Al leer registro 0 por lect no se obtiene 0"
				severity WARNING;

	
		-- Comprueba que cambie rd1 cuando cambia
		-- el valor del registro manteniéndose la misma dirección

		for i in 1 to 15 loop
			r <= to_unsigned(i,4);			
			w <= to_unsigned(i,4);
			wait for INSTANTE;
			-- Cambia el valor del registro sin cambiar la dirección
			escribir <= x"0F0F0F";
			we <= '1';
			wait until rising_edge(clk);
			wait for INSTANTE;
			assert leer = x"0F0F0F" 
				report "Error. Salida lect no cambia cuando varía contenido de registro pero no su dirección."
					severity WARNING;  
		end loop;
		
		-- Comprueba la escritura en R0
		we <= '1';
		escribir <= x"FABADA";
		w <= "0000";		
		r <= "0000";
		wait until rising_edge(clk);
		wait for INSTANTE;
		assert leer = x"000000"
			report "Error. No se está bloqueando la escritura en R0"
				severity WARNING;

		-- Comprueba el Write Enable
		we <= '1';
		escribir <= x"FABADA";
		w <= "0001";	
		r <= "0001";
		wait until rising_edge(clk); --Escritura para que haya un dato conocido en R1
		wait for INSTANTE;
		we <= '0';		
		escribir <= x"CAFECA";
		wait until rising_edge(clk);
		wait for INSTANTE;
		assert leer = x"FABADA"  -- Se comprueba que R1 no cambia si We='0'
			report "Error. No está funcionando el Write Enable"
				severity WARNING;
	  
		report "SIMULACION COMPLETADA. Compruebe los errores cometidos y proceda a corregirlos" severity note;
		endSim <= TRUE;
		wait;
	end process;


end examen;

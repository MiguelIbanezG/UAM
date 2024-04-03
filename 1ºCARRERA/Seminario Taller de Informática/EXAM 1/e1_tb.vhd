library ieee;
use ieee.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use IEEE.numeric_std.all;
library UNISIM;
use UNISIM.Vcomponents.all;



entity e1_tb_profesores is
end e1_tb_profesores;



architecture behavioral of e1_tb_profesores is

	component e1
	port( 
		A : in std_logic;
		B : in std_logic;
		C : in std_logic;
		D : in std_logic;
		Z : out std_logic
	);
	end component;
	
	signal a, b, c, d, z : std_logic;
	signal Error_number: integer := 0;
	signal input1 : std_logic_vector(3 downto 0);
	signal lut : std_logic_vector(0 to 15):= "0110111100001100" ;
	constant instante : time := 10 ns;
	
begin
	
   uut: e1
	port map(
		A => a,
		B => b,
		C => c,
		D => d,
		Z => z		
   );

   test : process
   begin
		for i in 0 to 15 loop
			input1 <= conv_std_logic_vector(i,4);
			wait for instante;
			assert std_match(z,lut(i))
				report "Error in the case " & integer'image(i) 
					severity warning;
			
			if not std_match(z,lut(i)) then
				Error_number <= Error_number + 1;
			end if;			
		end loop;
			wait for instante;
		report "¡¡simulation is done!!";
		report "Number of errors: " & integer'image(Error_number) severity note;
			wait; 
	end process test;
	
	a <= input1(3);
	b <= input1(2);
	c <= input1(1);
	d <= input1(0);	

end;

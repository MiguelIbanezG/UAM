
#include <avr/io.h>
#include "ayBot/ConfigPlaca.h"

int main(void)
{
	iniciarRobot(false); 
	while (1)
	{	

		while (true)
		{
			LED1_off();
			LED2_off();

			if ((SensoresLuz_led_izquierdo() == 0) && (SensoresLuz_led_derecho() == 0))
			{
				Motores_retrocede(30);
				_delay_ms(20); 
			}

			else if ((SensoresLuz_led_izquierdo() == 1) && (SensoresLuz_led_derecho() == 1))
			{
				LED1_on(); 
				LED2_on(); 
				Motores_avanza(30);
				_delay_ms(20);
			}

			else if ((SensoresLuz_led_izquierdo() == 0) && (SensoresLuz_led_derecho() == 1))
			{
				LED2_on(); 
				Motores_gira_der(30);
				_delay_ms(20);
				Motores_avanza(30);
			}

			else if ((SensoresLuz_led_izquierdo() == 1) && (SensoresLuz_led_derecho() == 0))
			{
				LED1_on();
				Motores_gira_izq(30);
				_delay_ms(20); 
				Motores_avanza(30);
			}
		}
	}
}



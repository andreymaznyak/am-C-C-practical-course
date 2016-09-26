#include <avr/io.h>
#include <util/delay.h>
#define Digit0 ~0B00111111
#define Digit1 ~0B00100100
#define Digit2 ~0B01011101
#define Digit3 ~0B01101101
#define Digit4 ~0B01100110
#define Digit5 ~0B01101011
#define Digit6 ~0B01111011
#define Digit7 ~0B00100101
#define Digit8 ~0B01111111
#define Digit9 ~0B01101111

char print (char a)
{
	switch(a)
	{
		case 0: return Digit0;
		case 1: return Digit1;
		case 2: return Digit2;
		case 3: return Digit3;
		case 4: return Digit4;
		case 5: return Digit5;
		case 6: return Digit6;
		case 7: return Digit7;
		case 8: return Digit8;
		case 9: return Digit9;
	}
}

int main(void)
{
	DDRD=0xFF;
	DDRC=0xFF;
	DDRB=0;
	char a=0;
    while (1)
    {
		for(int i=0; i<=9; i++)
		{
			for(int j=0; j<=9; j++)
			{
				for(int z=0; z<=9; z++)
				{
					for(int u=0; u<=9; u++)
					{
						PORTC=0B00001000;
						PORTD=print(u);
						_delay_ms(8);
						PORTC=0B00000100;
						PORTD=print(z);
						_delay_ms(8);
						PORTC=0B00000010;
						PORTD=print(j);
						_delay_ms(8);
						PORTC=0B00000001;
						PORTD=print(i);
						_delay_ms(8);
					}
				}
			}
		}
    }
}

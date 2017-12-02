/*
 * GccApplication1.c
 *
 * Created: 11/25/2017 8:20:59 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define baud 9600
#define F_CPU 14745600UL //Clock speed - to be set seeing value of crystal
#define UBRR ( F_CPU/16*baud - 1 )

void uart_init ()
{
	UBRRH = (unsigned char)(95>>8); //shifts the register right by 8 bits
	UBRRL = (unsigned char) 95;
	UCSRB = (1<<RXEN)|(1<<TXEN);            //Enable receiver and transmitter  
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0); 
	/* if URSEL is set to 1, it can be used as UCSRC 
	   if USBS = 1, 2 bit stopper
	   UCSZ0 set no. of data bit to 8 */   
}

void uart_transmit(unsigned char data)
{
	while (!( UCSRA & (1<<UDRE)));
	/* UCSRA & (1<<UDRE) gives current value. UDRE = zero - indicates that buffer is empty */
	UDR = data; //data is now in buffer
}

unsigned char uart_receive( void )
{
	while (!(UCSRA & (1<<RXC))); 
	/* RXC = 0 - indicates data is being received and stops program as long as data is being received */
	return UDR; //return data received in buffer
}

int main(void)
{
  
 uart_init();
    while (1) 
    {
	 uart_transmit('1'); 
	 _delay_ms(1000);
	 _delay_ms(1000);
     uart_transmit('0'); 
	  _delay_ms(1000);
	  _delay_ms(1000);
     uart_transmit('1'); 
	   _delay_ms(1000);
	   _delay_ms(1000);
	   _delay_ms(1000);
	   _delay_ms(1000);
	   _delay_ms(1000);
	  uart_transmit('0');
	  _delay_ms(1000);
	  _delay_ms(1000);
	   _delay_ms(1000);
	   _delay_ms(1000);
	   _delay_ms(1000);
    }
}



/*watch*/
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "USART_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "LED_interface.h"
#include <util/delay.h>

/*pins
 * 			D0  RX input
 * 			D1  TX output
 * 			D2  int0 input / pullup switch*/

void isr(void);

void main (void)
{
	PORT_voidInit();
	EXTI_u8Int0SetCallBack(isr);
	EXTI_voidInt0Init();
	USART_voidInit();
	GIF_voidEnable();
	while(1)
	{

	}
}
/*this function will call when switch on*/
void isr (void)
{

	/*open led to indicate the function is call*/
	LED_voidTurnOn(DIO_u8PORTA,DIO_u8PIN0);

	/*read from GPS send to mobile app */
	for(;;)
	{

	USART_voidSend(USART_u8Receive());

	}


	/*closed led to indicate the function is finshed*/
	_delay_ms(50);
	LED_voidTurnOff(DIO_u8PORTA,DIO_u8PIN0);
}

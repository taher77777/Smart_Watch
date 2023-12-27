#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "USART_register.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void USART_voidInit(void)
{
	/*we can not use set bit or clr bit here because it want in same time so we will creat a variable*/
	u8 Local_u8UCSRCValue=0;
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);  //to use UCSRC
	//set to 8 bit send and receive
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	// now will set this value in UCSRC at same time
	UCSRC=Local_u8UCSRCValue;
	//boud rate now 9600 with 8M hz
	UBRRL=51;
	
	//enable
	SET_BIT(UCSRB,UCSRB_TXEN);   //tx enable
	SET_BIT(UCSRB,UCSRB_RXEN);   //rx enable
	
}
//func to receive data no 8bit
u8 USART_u8Receive(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);  //wait until be low by default it high when receive become low
	return UDR;		//return the receive data
}

void USART_voidSend(u8 Copy_u8data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);      //wait untiltransmit data empty
	UDR=Copy_u8data;   //transmit data
}
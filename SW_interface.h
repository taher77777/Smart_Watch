/***********************************************************************/
/***********************************************************************/
/*****************    AUTHOR: TAHER MOHAMED   **************************/
/*****************    LAYER:  HAL             **************************/
/*****************    SWC:    SWITCH          **************************/
/*****************    VERSION:1.00            **************************/
/***********************************************************************/
/***********************************************************************/
#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_



#define SW_PRESSED           1
#define SW_NOT_PRESSED       0

u8 SW_u8GetState(u8 Copy_u8Port,u8 Copy_u8Pin);

#endif
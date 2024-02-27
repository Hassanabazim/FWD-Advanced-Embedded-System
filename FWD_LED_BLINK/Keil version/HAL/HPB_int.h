/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  PUSH BUTTON							 	*/
/****************************************************************/

#ifndef HPB_HPB_INT_H_
#define HPB_HPB_INT_H_

typedef enum
{
	PB_PRESSED,
	PB_RELEASED
}PBState_t;


typedef enum
{
	PULL_UP,
	PULL_DOWN
}PBMode_t;

typedef struct
{
	MGPIO_PORT_t PB_PORT;
	MGPIO_PIN_t  PB_PIN;
	PBMode_t PB_MODE;
}PB_ST;


ErrorState_t HPB_enInit(PB_ST *ptrPB);
ErrorState_t HPB_enRead(PB_ST *ptrPB, PBState_t * ptrPBState);

#endif /* HPB_HPB_INT_H_ */

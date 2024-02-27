/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  PUSH BUTTON							 	*/
/****************************************************************/

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MGPIO_int.h"
#include "MSYSTICK_int.h"
#include "HPB_int.h"
#include "HPB_priv.h"
#include "HPB_config.h"




ErrorState_t HPB_enInit(PB_ST *ptrPB)
{
	ErrorState_t Local_state = SUCCESS;

	if (ptrPB->PB_PORT >= PORTA && ptrPB->PB_PORT <= PORTC)
	{
		MGPIO_enSetPinDirection(ptrPB->PB_PORT, ptrPB->PB_PIN, IN_PULL_UP_PULL_DOWN);

		/* Activiate Internal PULL-UPS Resistors */
		if(ptrPB->PB_MODE== PULL_UP)
		{
			MGPIO_enSetPinValue(ptrPB->PB_PORT, ptrPB->PB_PIN, HIGH);
		}
	}

	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}

	return Local_state;
}


ErrorState_t HPB_enRead(PB_ST *ptrPB, PBState_t * ptrPBState)
{
	ErrorState_t Local_state = SUCCESS;

	u8 Local_u8pinRead = PB_RELEASED;

	MGPIO_enGetPinValue(ptrPB->PB_PORT, ptrPB->PB_PIN, &Local_u8pinRead);
	if (Local_u8pinRead == PB_PRESSED)
	{
		// Wait for debouncing
		MSYSTICK_enDelayMS(200);
		MGPIO_enGetPinValue(ptrPB->PB_PORT, ptrPB->PB_PIN, &Local_u8pinRead);
		if (Local_u8pinRead == PB_PRESSED)
		{
			// for single press busy wait
			while (Local_u8pinRead == PB_PRESSED)
			{
				MGPIO_enGetPinValue(ptrPB->PB_PORT, ptrPB->PB_PIN, &Local_u8pinRead);
			}
			*ptrPBState = PB_PRESSED;
		}
		else
		{
			*ptrPBState = PB_RELEASED;
		}
	}
	else
	{
		*ptrPBState = PB_RELEASED;
	}

	return Local_state;
}

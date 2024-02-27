/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LED							 			*/
/****************************************************************/


#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MGPIO_int.h"
#include "HLED_int.h"
#include "HLED_priv.h"
#include "HLED_config.h"


ErrorState_t HLED_enInit(u8 copyu8_LedPort, u8 copyu8_LedPin)
{
	MGPIO_enSetPinDirection(copyu8_LedPort, copyu8_LedPin, OUT_2MHZ_PUSH_PULL);

	return SUCCESS;
}

ErrorState_t HLED_enSetON(u8 copyu8_LedPort, u8 copyu8_LedPin)
{
#if(HLED_DIR == HLED_DIR_FORWARD)
	MGPIO_enSetPinValue(copyu8_LedPort, copyu8_LedPin, HIGH);

#elif (HLED_RED_DIR == HLED_DIR_REVERSE)
	MGPIO_enSetPinValue(copyu8_LedPort, copyu8_LedPin, LOW);
#else
#error ("WRONG LED DIRECTION")
#endif

	return SUCCESS;
}

ErrorState_t HLED_enSetOFF(u8 copyu8_LedPort, u8 copyu8_LedPin)
{
#if(HLED_DIR == HLED_DIR_FORWARD)
	MGPIO_enSetPinValue(copyu8_LedPort, copyu8_LedPin, LOW);

#elif (HLED_RED_DIR == HLED_DIR_REVERSE)
	MGPIO_enSetPinValue(copyu8_LedPort, copyu8_LedPin, HIGH);
#else
#error ("WRONG LED DIRECTION")
#endif

	return SUCCESS;
}

ErrorState_t HLED_enToggle(u8 copyu8_LedPort, u8 copyu8_LedPin)
{
	MGPIO_enTogglePin(copyu8_LedPort, copyu8_LedPin);

	return SUCCESS;
}

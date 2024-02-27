/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  19/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  LED							 			*/
/****************************************************************/


#ifndef HLED_HLED_INT_H_
#define HLED_HLED_INT_H_


ErrorState_t HLED_enInit(u8 copyu8_LedPort, u8 copyu8_LedPin);
ErrorState_t HLED_enSetON(u8 copyu8_LedPort, u8 copyu8_LedPin);
ErrorState_t HLED_enSetOFF(u8 copyu8_LedPort, u8 copyu8_LedPin);
ErrorState_t HLED_enToggle(u8 copyu8_LedPort, u8 copyu8_LedPin);



#endif /* HLED_HLED_INT_H_ */

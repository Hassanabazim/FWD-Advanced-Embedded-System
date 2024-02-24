/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  MEXTI_config.h
 *         @Module	:  EXTI
 *
 *  Description:  This file provide the pre Configuration of the Module
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HEADER GUARD
 *********************************************************************************************************************/
#ifndef MEXTI_EXTINT_CONFIG_H_
#define MEXTI_EXTINT_CONFIG_H_

/**********************************************************************************************************************
*  LOCAL MACROS CONFIGURATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
* PLEASE CHOOSE THE MEXTI_MODE FROM THE FOLLOWING MODES:
*
	* MEXTI_RISING_TRIG
	* MEXTI_FAILING_TRIG
	* MEXTI_LOGIC_CHANGE
 *********************************************************************************************************************/
#define MEXTI_MODE 			MEXTI_RISING_TRIG


/**********************************************************************************************************************
* PLEASE CHOOSE THE MEXTI_LINE FROM THE FOLLOWING LINES:
*
	* MEXTI0_LINE
	* MEXTI1_LINE
	* MEXTI2_LINE
	* MEXTI3_LINE
	* MEXTI4_LINE
	* MEXTI5_LINE
	* MEXTI6_LINE
	* MEXTI7_LINE
	* MEXTI8_LINE
	* MEXTI9_LINE
	* MEXTI10_LINE
	* MEXTI11_LINE
	* MEXTI12_LINE
	* MEXTI13_LINE
	* MEXTI14_LINE
	* MEXTI15_LINE
 *********************************************************************************************************************/
#define MEXTI_LINE			MEXTI0_LINE




#endif /* MEXTI_EXTINT_CONFIG_H_ */

 /**********************************************************************************************************************
  *  END OF FILE:	MEXTI_config.h
  *********************************************************************************************************************/
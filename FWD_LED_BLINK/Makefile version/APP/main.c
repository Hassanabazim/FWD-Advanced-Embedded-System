#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "MAFIO_int.h"
#include "MSYSTICK_int.h"
#include "HLED_int.h"
#include "HPB_int.h"
#include "main.h"

#if (ENVIRONMENT == CMD_MAKEFILE) 
#include <stdio.h>
extern void initialise_monitor_handles(void);
#endif

static void Led_Blink(u8 timeON, u8 time_off);
void Switch_count(void);
void Switch_confirm(void);
void systick_TON(void);
void systick_TOFF(void);


extern const periodicity_t time[1] ;
volatile u8 confirm_flag = 0;
volatile u8 time_on = 0;
volatile u8 time_off = 0;
volatile u8 flip_flag = 0;


int main(void)
{
	u8 temp1[1], temp2[1];

	/*	system clock init and peripherial clocks */
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MRCC_enEnablePeripheralCLK(MRCC_AFIO);


	/* init systick */
	MSYSTICK_enInit();

	/*	configure push buttons */
	PB_ST switch_count = {PORTA, PIN0, PULL_DOWN};
	PB_ST switch_confirm = {PORTA, PIN1, PULL_DOWN};
	HPB_enInit(&switch_count);
	HPB_enInit(&switch_confirm);

	/* configure Blink Led, confirm led */
	HLED_enInit(PORTA, PIN2);
	HLED_enInit(PORTA, PIN3);

	/*	configure NVIC */
	MNVIC_enEnableNVIC();
	MNVIC_enEnableInt(MNVIC_EXT0_INT);
	MNVIC_enEnableInt(MNVIC_EXT1_INT);

	/* configure EXT interrupt mood and callback */
	MEXTI_enCallBack(MEXTI0_LINE, Switch_count);
	MEXTI_enCallBack(MEXTI1_LINE, Switch_confirm);
	MEXTI_enInit();
	MEXTI_enSetLatch(MEXTI1_LINE, MEXTI_RISING_TRIG);

	/*	configure AFIO for EXTI1 for Port A */
	MAFIO_enSetEXTI_Config(MEXTI1_LINE, MAFIO_GPIOA);
	
#if (ENVIRONMENT == CMD_MAKEFILE)

	initialise_monitor_handles();
	printf("********************************************************\n");
	printf("      ADVANCED EMBEDDED SYSTEM NANODEGREE FWD      		\n");
	printf("      Author : HASSAN ABDELAZIM ABDELSALAM ELSAYED      \n");
	printf("		Project: Configurable LED BLINK ON,OFF TIME 	\n");
	printf("********************************************************\n");
	printf("        PLEASE CHOOSE FROM THE FOLLOWING OPTIONS        \n");
	printf("********************************************************\n");
	printf("1:HW_SWITCH\n2:SW_SEMI_HOSTING\n3:SW_DYNAMIC_LINKING\n");
	printf("YOUR CHOICE = ");
	gets(temp1);
	printf(" YOU Entered %s", temp1);
	if (temp1[0] == '1')
	{
		confirm_flag = 0; 
	}
	else if (temp1[0] == '2')
	{
		printf("Enter T_ON in seconds = ");
		gets(temp1);
		printf("Enter T_OFF in seconds = ");
		gets(temp2);
		printf("T_ON = %d, T_OFF = %d\n", (temp1[0] - '0'), (temp2[0] - '0'));
		confirm_flag = 3; 
	}
	
	else if (temp1[0] == '3')
	{
		confirm_flag = 4; 
	}
	#endif
	
	while (1)
	{	
		if (confirm_flag == HW_SWITCH)
		{
			Led_Blink(time_on, time_off);
		}
		else if (confirm_flag == SW_SEMI_HOSTING)
		{	
			Led_Blink(SEMI_TIME_ON, SEMI_TIME_OFF);
		}
		else if (confirm_flag == SW_STATIC_LINKING)
		{
			Led_Blink(time[0].onTime, time[0].offTime);
		}

	}
}


void Switch_count(void)
{
	if (confirm_flag == 0)
	{
		MSYSTICK_enDelayMS(50);
		time_on ++;
	}
	else if (confirm_flag == 1)
	{
		MSYSTICK_enDelayMS(50);
		time_off ++;
	}
	else
	{
		confirm_flag = 0;
		time_on = 0;
		time_off = 0;
	}
	MEXTI_enClearPendingBit(MEXTI0_LINE);
}

void Switch_confirm(void)
{
	if (time_off != 0)
	{
		confirm_flag = HW_SWITCH;
		HLED_enSetOFF(PORTA, PIN2);
	}
	else if (time_on != 0)
	{
		confirm_flag = 1;
		HLED_enSetON(PORTA, PIN2);
	}
	else
	{
		// do nothing
	}
	MEXTI_enClearPendingBit(MEXTI1_LINE);

}

void systick_TON(void)
{
	MGPIO_enTogglePin(PORTA, PIN3);
	flip_flag = ON;

}

void systick_TOFF(void)
{
	HLED_enSetOFF(PORTA, PIN3);
	flip_flag = OFF;
}

static void Led_Blink(u8 timeON, u8 timeOFF)
{
	if (flip_flag == OFF)
	{
		MSYSTICK_enSetIntervalPeriodic((timeON * MICRO_SECOND), systick_TON);
	}
	else
	{
		MSYSTICK_enSetIntervalPeriodic((timeOFF * MICRO_SECOND), systick_TOFF);
	}
}

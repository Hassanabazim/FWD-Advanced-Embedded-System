/*
 * FreeRTOS Kernel V10.2.0 (method 3 stats)
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "main.h"
#include "serial.h"
#include "GPIO.h"

TaskHandle_t xHandleHigh = NULL;
TaskHandle_t xHandleLow = NULL;

int inTime_1 = 0 , outTime_1 = 1, totalTime_1 = 0; 
int inTime_2 = 0 , outTime_2 = 1, totalTime_2 = 0; 

int systemTime = 0; 
int cpu_load = 0; 

	/* Task to be created. */
void High_led( void * pvParameters )
{
		
		int i = 0;
		TickType_t xLastWakeTime;
		xLastWakeTime = xTaskGetTickCount();
		vTaskSetApplicationTaskTag(NULL, (void*) 1);
    for( ;; )
    {	
      /* Task code goes here. */	
			for (i = 0; i < 100000; i++)
			{
				i = i; 
			}
			/* Exrecuation time calculations */
			vTaskDelayUntil(&xLastWakeTime, 300);		
    }
}
												
void Low_led( void * pvParameters )
{
   
		int i = 0;
		TickType_t xLastWakeTime;
		xLastWakeTime = xTaskGetTickCount();
		vTaskSetApplicationTaskTag(NULL, (void*) 2);

    for(;;)
    {	
     /* Task code goes here. */	
			for (i = 0; i < 10000; i++)
			{
				i = i; 
			}
			
			/* Exrecuation time calculations */
			GPIO_write(PORT_0, PIN5, PIN_IS_LOW);
			vTaskDelayUntil(&xLastWakeTime, 100); 
			GPIO_write(PORT_0, PIN5, PIN_IS_HIGH);		
		}	
}
		
void vApplicationTickHook(void)
{
		/*	implement tick hook by GPIO pin	*/
		GPIO_write(PORT_0, PIN1, PIN_IS_HIGH);
		GPIO_write(PORT_0, PIN1, PIN_IS_LOW);
}

// TODO in datasheet
void Timer_config(void)
{
	T1IR = 1000;
	T1TCR |= 0x01;
}

void Timer_reset(void)
{
	T1TCR |=  0x2;
	T1TCR &= ~0x2;
}

int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	

/* Function that creates a task. */


    /* Create the task, storing the handle. */
				xTaskCreate(
                    High_led,      	 /* Function that implements the task. */
                    "HIGH LED",      /* Text name for the task. */
                    100,				      /* Stack size in words, not bytes. */
                    ( void * ) 0,    /* Parameter passed into the task. */
											1,						/* Priority at which the task is created. */
                    &xHandleHigh );    /* Used to pass out the created task's handle. */
										
										
				xTaskCreate(
                    Low_led,      	 /* Function that implements the task. */
                    "LOW LED",      /* Text name for the task. */
                    100,				      /* Stack size in words, not bytes. */
                    ( void * ) 0,    /* Parameter passed into the task. */
											1,						/* Priority at which the task is created. */
                    &xHandleLow );      /* Used to pass out the created task's handle. */
	
	/* Now all the tasks have been started - start the scheduler.

	
	
	
	
	
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/


static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	Timer_config();
	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/

				


#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdint.h>

#define NUMBER_OF_TASKS				((uint8_t)6)	
						
#define PROBE_TICK						PIN0
#define PROBE_TASK_1					PIN1
#define PROBE_TASK_2					PIN2	
#define PROBE_TASK_3					PIN3
#define PROBE_TASK_4					PIN4	
#define PROBE_TASK_5					PIN5
#define PROBE_TASK_6					PIN6				
#define PROBE_IDLE						PIN7
														
#define PERIODICITY_TASK_1		((uint8_t)50)													
#define PERIODICITY_TASK_2		((uint8_t)50)													
#define PERIODICITY_TASK_3		((uint8_t)100)													
#define PERIODICITY_TASK_4		((uint8_t)20)																																						
#define PERIODICITY_TASK_5		((uint8_t)10)
#define PERIODICITY_TASK_6		((uint8_t)100)
														
#define ET_TASK_5						  ((uint8_t)5)
#define ET_TASK_6							((uint8_t)12)														
														
#define ET_2_COUNT_MAP				((uint16_t)6666)
#define DUMMY_ET(ET)																									\
					do{																													\
							uint32_t  i;																						\
							for(i=0; i<(ET * ET_2_COUNT_MAP); i++){									\
								i=i;																									\
							}																												\
					}while(0)

					



					
#define TO_ASCII(num)						(num + (uint8_t)48)

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )


static void prvSetupHardware( void );



#if ( configUSE_EDF_SCHEDULER == 1 )
	BaseType_t xTaskPeriodicCreate( TaskFunction_t pxTaskCode,
													const char * const pcName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
													const configSTACK_DEPTH_TYPE usStackDepth,
													void * const pvParameters,
													UBaseType_t uxPriority,
													TaskHandle_t * const pxCreatedTask ,
													TickType_t period);
#endif


#endif /*_MAIN_H_*/
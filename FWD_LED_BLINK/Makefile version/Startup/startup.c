/*
	This my own startup code from stratch for STM32F103C8
	startuo code runs before entry point manin()
	
	1- create the vector table
	2. create a Reset_Handler routine
*/

#include "STD_TYPES.h"

/* create a vector table STM32F103C8, 
MSP, 10 system exception and 59 IRQs and 5.word size reserved
*/

extern u32 _estack ;
extern u32 _sidata ;
extern u32 _etext ;
extern u32 _sdata ;
extern u32 _edata ;
extern u32 _sbss ;
extern u32 _ebss ;

void __libc_init_array(void);
void main(void);	

				            
void Reset_Handler(void);
void NMI_Handler(void) 			 			__attribute__((weak,alias("Default_Handler")));
void HardFault_Handler(void)	 			__attribute__((weak,alias("Default_Handler")));
void MemMangage_Handler(void) 	 			__attribute__((weak,alias("Default_Handler")));
void BusFault_Handler(void) 	 			__attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler(void)	 			__attribute__((weak,alias("Default_Handler")));
void SVCall_Handler(void) 		 			__attribute__((weak,alias("Default_Handler")));
void DebugMon_Handler(void)		 			__attribute__((weak,alias("Default_Handler")));
void PendSV_Handler(void)		 			__attribute__((weak,alias("Default_Handler")));
void sysTick_Handler(void) 		 			__attribute__((weak,alias("Default_Handler")));
void WWDG_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void PVD_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void TAMPER_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void RTC_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void RCC_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void EXTI0_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void ADC1_2_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void USB_LP_CAN_RX0_IRQHandler(void)		__attribute__((weak,alias("Default_Handler")));
void CAN_RX1_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void CAN_SCE_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)	__attribute__((weak,alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void RTCAlarm_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler(void)		__attribute__((weak,alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler(void)	__attribute__((weak,alias("Default_Handler")));
void TIM8_CC_IRQHandler(void)		 		__attribute__((weak,alias("Default_Handler")));
void ADC3_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void FSMC_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void SDIO_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void TIM5_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void SPI3_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void UART4_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void UART5_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void TIM6_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void TIM7_IRQHandler(void)		 			__attribute__((weak,alias("Default_Handler")));
void DMA2_Channel1_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA2_Channel2_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA2_Channel3_IRQHandler(void)		 	__attribute__((weak,alias("Default_Handler")));
void DMA2_Channel4_5_IRQHandler(void)		__attribute__((weak,alias("Default_Handler")));


 
u32 vectors[] __attribute__((section(".isr_vector"))) = {
(u32) &_estack, 
(u32) &Reset_Handler,
(u32) &NMI_Handler,
(u32) &HardFault_Handler,
(u32) &MemMangage_Handler, 	
(u32) &BusFault_Handler,
(u32) &UsageFault_Handler,
0,
0,
0,
0,
(u32) &SVCall_Handler, 		
(u32) &DebugMon_Handler,
(u32) &PendSV_Handler,		
(u32) &sysTick_Handler,
(u32) &WWDG_IRQHandler,							/* Window Watchdog interrupt                        */
(u32) &PVD_IRQHandler,		                    /* PVD through EXTI line detection interrupt        */
(u32) &TAMPER_IRQHandler,		                /* Tamper interrupt                                 */
(u32) &RTC_IRQHandler,		                    /* RTC global interrupt                             */
(u32) &FLASH_IRQHandler,                        /* Flash global interrupt                           */
(u32) &RCC_IRQHandler,                          /* RCC global interrupt                             */
(u32) &EXTI0_IRQHandler,                        /* EXTI Line0 interrupt                             */
(u32) &EXTI1_IRQHandler,                        /* EXTI Line1 interrupt                             */
(u32) &EXTI2_IRQHandler,                        /* EXTI Line2 interrupt                             */
(u32) &EXTI3_IRQHandler,                        /* EXTI Line3 interrupt                             */
(u32) &EXTI4_IRQHandler,                        /* EXTI Line4 interrupt                             */
(u32) &DMA1_Channel1_IRQHandler,                /* DMA1 Channel1 global interrupt                   */
(u32) &DMA1_Channel2_IRQHandler,                /* DMA1 Channel2 global interrupt                   */
(u32) &DMA1_Channel3_IRQHandler,                /* DMA1 Channel3 global interrupt                   */
(u32) &DMA1_Channel4_IRQHandler,                /* DMA1 Channel4 global interrupt                   */
(u32) &DMA1_Channel5_IRQHandler,                /* DMA1 Channel5 global interrupt                   */
(u32) &DMA1_Channel6_IRQHandler,                /* DMA1 Channel6 global interrupt                   */
(u32) &DMA1_Channel7_IRQHandler,                /* DMA1 Channel7 global interrupt                   */
(u32) &ADC1_2_IRQHandler,                       /* ADC1 and ADC2 global interrupt                   */
(u32) &USB_HP_CAN_TX_IRQHandler,                /* USB High Priority or CAN TX interrupts           */
(u32) &USB_LP_CAN_RX0_IRQHandler,               /* USB Low Priority or CAN RX0 interrupts           */
(u32) &CAN_RX1_IRQHandler,                      /* CAN RX1 interrupt                                */
(u32) &CAN_SCE_IRQHandler,                      /* CAN SCE interrupt                                */
(u32) &EXTI9_5_IRQHandler,                      /* EXTI Line[9:5] interrupts                        */
(u32) &TIM1_BRK_TIM9_IRQHandler,                /* TIM1 Break interrupt                             */
(u32) &TIM1_UP_TIM10_IRQHandler,                /* TIM1 Update interrupt                            */
(u32) &TIM1_TRG_COM_TIM11_IRQHandler,           /* TIM1 Trigger and Commutation interrupts          */
(u32) &TIM1_CC_IRQHandler,                      /* TIM1 Capture Compare interrupt                   */
(u32) &TIM2_IRQHandler,                         /* TIM2 global interrupt                            */
(u32) &TIM3_IRQHandler,                         /* TIM3 global interrupt                            */
(u32) &TIM4_IRQHandler,                         /* TIM4 global interrupt                            */
(u32) &I2C1_EV_IRQHandler,                      /* I2C1 event interrupt                             */
(u32) &I2C1_ER_IRQHandler,                      /* I2C1 error interrupt                             */
(u32) &I2C2_EV_IRQHandler,                      /* I2C2 event interrupt                             */
(u32) &I2C2_ER_IRQHandler,                      /* I2C2 error interrupt                             */
(u32) &SPI1_IRQHandler,                         /* SPI1 global interrupt                            */
(u32) &SPI2_IRQHandler,                         /* SPI2 global interrupt                            */
(u32) &USART1_IRQHandler,                       /* USART1 global interrupt                          */
(u32) &USART2_IRQHandler,                       /* USART2 global interrupt                          */
(u32) &USART3_IRQHandler,                       /* USART3 global interrupt                          */
(u32) &EXTI15_10_IRQHandler,                    /* EXTI Line[15:10] interrupts                      */
(u32) &RTCAlarm_IRQHandler,                     /* RTC Alarms through EXTI line interrupt           */
0,												/* Reserved                                         */
(u32) &TIM8_BRK_TIM12_IRQHandler,               /* TIM8 Break interrupt                             */
(u32) &TIM8_UP_TIM13_IRQHandler,                /* TIM8 Update interrupt                            */
(u32) &TIM8_TRG_COM_TIM14_IRQHandler,           /* TIM8 Trigger and Commutation interrupts          */
(u32) &TIM8_CC_IRQHandler,                      /* TIM8 Capture Compare interrupt                   */
(u32) &ADC3_IRQHandler,                         /* ADC3 global interrupt                            */
(u32) &FSMC_IRQHandler,                         /* FSMC global interrupt                            */
(u32) &SDIO_IRQHandler,                         /* SDIO global interrupt                            */
(u32) &TIM5_IRQHandler,                         /* TIM5 global interrupt                            */
(u32) &SPI3_IRQHandler,                         /* SPI3 global interrupt                            */
(u32) &UART4_IRQHandler,                        /* UART4 global interrupt                           */
(u32) &UART5_IRQHandler,                        /* UART5 global interrupt                           */
(u32) &TIM6_IRQHandler,                         /* TIM6 global interrupt                            */
(u32) &TIM7_IRQHandler,                         /* TIM7 global interrupt                            */
(u32) &DMA2_Channel1_IRQHandler,                /* DMA2 Channel1 global interrupt                   */
(u32) &DMA2_Channel2_IRQHandler,                /* DMA2 Channel2 global interrupt                   */
(u32) &DMA2_Channel3_IRQHandler,                /* DMA2 Channel3 global interrupt                   */
(u32) &DMA2_Channel4_5_IRQHandler               /* DMA2 Channel4 and DMA2 Channel5 global interrupt */
};

void Reset_Handler(void)
{
	/* 1. set the stack pointer */

	/* 2. copy .data from Flash to Ram */
	
	u32 *ptr2Src =  (u32*)&_etext; 
	u32 *ptr2sDes = (u32*)&_sdata;
	u32 *ptr2eDes = (u32*)&_edata;
	u32 *ptr2sBss = (u32*)&_sbss;
	u32 *ptr2eBss = (u32*)&_ebss;
	
	while (ptr2sDes < ptr2eDes)
	{
		*(ptr2sDes++) = *(ptr2Src++);
	}

	/* 3. set non intialzite Ram data .bss with zeros */
	
	while (ptr2sBss < ptr2eBss)
	{
		*(ptr2sBss++) = 0;
	}
	
	/* 4. include the system calls  */
	
	__libc_init_array();
	

	/* 5. call the entry program point main() */
	main();
	
	while (1);
}

void Default_Handler(void)
{
	while (1);
}

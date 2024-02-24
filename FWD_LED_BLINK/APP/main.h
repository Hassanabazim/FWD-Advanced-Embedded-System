/*
 * main.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Hassa
 */

#ifndef MAIN_H_
#define MAIN_H_

#define CMD_MAKEFILE					6
#define KEIL_IDE							7
#define ENVIRONMENT 					KEIL_IDE

#define HW_SWITCH 						2
#define SW_SEMI_HOSTING 			3
#define SW_DYNAMIC_LINKING		4

#define SEMI_TIME_ON	((temp1[0]) - '0')
#define SEMI_TIME_OFF	((temp2[0]) - '0')

#define MICRO_SECOND 	(1000000)


#define ON		1
#define OFF		0
typedef struct
{
	u8 onTime;
	u8 offTime;

}periodicity_t;

#endif /* MAIN_H_ */

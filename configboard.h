
#ifndef CONFIGBOARD_H_
#define CONFIGBOARD_H_


/* Private includes ----------------------------------------------------------*/
#include <LPC17xx.h>


/* Board defines ------------------------------------------------------------*/
#define configLED    	 	0
#define configButton  		1
#define configSevenSeg		1


#if configSevenSeg
#define SEGDATAPORT       PORT1
#define SEGDATAPIN_A      PIN19
#define SEGDATAPIN_B      PIN20
#define SEGDATAPIN_C      PIN21
#define SEGDATAPIN_D      PIN22
#define SEGDATAPIN_E      PIN23
#define SEGDATAPIN_F      PIN24
#define SEGDATAPIN_G      PIN25
#define SEGDATAPIN_DP     PIN26

#define SEGCTRLPORT       PORT0
#define SEGCTRLPIN_1      PIN4
#define SEGCTRLPIN_2      PIN5
#define SEGCTRLPIN_3      PIN6
#define SEGCTRLPIN_4      PIN7
#endif



#if configButton
#define BUTTON0PORT  PORT2
#define BUTTON0PIN   PIN10
#endif




#if configLED
#define LED0PORT  PORT1
#define LED1PORT  PORT1
#define LED2PORT  PORT1

/* TODO : Update the #defines for PORT for 6 more LEDs */

#define LED0PIN   PIN29
#define LED1PIN   PIN19
#define LED2PIN   PIN20

/* TODO : Update the #defines for PINs for 6more LEDs */

#endif





#endif /* CONFIGBOARD_H_ */

/*
===============================================================================
 Name        : 11_Day28_23092021_GPIO011.c

 Description : Implement 2 functionalities for a button - short press and long press
 	 	 	   Short press - decision for making increment/decrement
 	 	 	   Long press  - based on the previous decision increment/decrement the count in seven segment display
 	 	 	   Data Pins PORT 1.19 to P1.26
 	 	 	   Control Pins PORT 0.4 to 0.7



 Layered Architecture used for this project
 ************************************
 Application layer-11_Day28_23092021_GPIO011.c
 ************************************
 Board layer - sevenseg.c/.h, button.c/.h, configboard.h
 ************************************
 Low level drivers or chip level - gpio.c/.h
 ************************************
 Hardware
 ************************************

===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "sevenseg.h"
#include "button.h"
/* Private typedef -----------------------------------------------------------*/

enum {DECREMENT=0,INCREMENT};
/* Private define ------------------------------------------------------------*/
#define MAXTIMEOUT 0xFFFFF

#define MINLONGPRESSCOUNT  150000
#define MINSHORTPRESSCOUNT 500

#define MAXLONGPRESSCOUNT  200000
#define MAXSHORTPRESSCOUNT 50000
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{

	vSevenSegInitialize();
	vButtonInitialize();
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	uint8_t  segarray[4]={0,0,0,0};
	uint8_t  segno=0, updown=INCREMENT;
	int16_t num=0;
	uint32_t pushcount=0;

  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {

     vSevenSegDisplay(segno, segarray[segno]);
     segno++;
     if(segno>3)
    	 segno=0;


     if (ucButtonState(BUTTON_0) == BUTTON_PRESSED) {

    	   pushcount++;

    	   if(pushcount>MAXLONGPRESSCOUNT)
    	   {
				if (updown == INCREMENT) {
					num++;
					if (num > 9999)
						num = 0;
				} else if (updown == DECREMENT) {
					num--;
					if (num < 0)
						num = 9999;
				}

				segarray[3] = num % 10;
				segarray[2] = (num / 10) % 10;
				segarray[1] = (num / 100) % 10;
				segarray[0] = (num / 1000);
				pushcount = MINLONGPRESSCOUNT;

    	   }
 		}

	   if (ucButtonState(BUTTON_0) == BUTTON_NOTPRESSED) {

		   if(pushcount>MINSHORTPRESSCOUNT && pushcount<MAXSHORTPRESSCOUNT)
			   /* For changing increment to decrement or vice versa */
			   updown ^= 1;


		   pushcount=0;
		}

  }
  /* End of Application entry point */
}





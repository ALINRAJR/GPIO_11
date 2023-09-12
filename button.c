

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "button.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

#if configButton

 /**
  * @brief Setting direction for Button connected on board
  * @return None
  **/
void vButtonInitialize(void)
{
	    vGpioSetDir(BUTTON0PORT,BUTTON0PIN,INPUT);
}

/**
 * @brief Making selected LED on board to ON state
 * @param[in] lednum specify the LED number
 * @return None
 **/
uint8_t ucButtonState(uint8_t buttonnum)
{
	/* Holds the 32bit port value */
	uint32_t buttonstatus =0;
	switch(buttonnum)
	{
	case BUTTON_0:
		buttonstatus = uiGpioGetPinValue(BUTTON0PORT,BUTTON0PIN);
		break;
	default:
		/* DO NOTHING */
		break;
	}

	if(buttonstatus)
		return BUTTON_NOTPRESSED;
	else
	   return BUTTON_PRESSED;
}


#endif




/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "sevenseg.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
#if COMMONCATHODESEG
const uint8_t segArray[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
#elif COMMONANODESEG
const uint8_t segArray[] = {0xFF-0x3F,0xFF-0x06,0xFF-0x5B,0xFF-0x4F,0xFF-0x66,0xFF-0x6D,0xFF-0x7D,0xFF-0x07,0xFF-0x7F,0xFF-0x6F,0xFF-0x77,0xFF-0x7C,0xFF-0x39,0xFF-0x5E,0xFF-0x79,0xFF-0x71};
#endif

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

 /**
  * @brief Setting direction for Seven segment pins connected on board
  * @return None
  **/
void vSevenSegInitialize(void)
{
	/* Setting directions of the data pins of the seven segment */
	vGpioSetDir(SEGDATAPORT, SEGDATAPIN_A, OUTPUT);
	vGpioSetDir(SEGDATAPORT, SEGDATAPIN_B, OUTPUT);
	vGpioSetDir(SEGDATAPORT, SEGDATAPIN_C, OUTPUT);
	vGpioSetDir(SEGDATAPORT, SEGDATAPIN_D, OUTPUT);
	vGpioSetDir(SEGDATAPORT, SEGDATAPIN_E, OUTPUT);
	vGpioSetDir(SEGDATAPORT, SEGDATAPIN_F, OUTPUT);
	vGpioSetDir(SEGDATAPORT, SEGDATAPIN_G, OUTPUT);
	vGpioSetDir(SEGDATAPORT, SEGDATAPIN_DP, OUTPUT);

	/* Setting directions of the control pins of the seven segment */
	vGpioSetDir(SEGCTRLPORT, SEGCTRLPIN_1, OUTPUT);
	vGpioSetDir(SEGCTRLPORT, SEGCTRLPIN_2, OUTPUT);
	vGpioSetDir(SEGCTRLPORT, SEGCTRLPIN_3, OUTPUT);
	vGpioSetDir(SEGCTRLPORT, SEGCTRLPIN_4, OUTPUT);

#if COMMONCATHODESEG
	/* Clearing the data pins of the seven segment */
	vGpioSetByte(SEGDATAPORT, SEGDATAPIN_A,0x00);
	/* Clearing the control pins of the seven segment */
	vGpioSetNibble(SEGCTRLPORT, SEGCTRLPIN_1,0xF);

#elif COMMONANODESEG
	/* Clearing the data pins of the seven segment */
	vGpioSetByte(SEGDATAPORT, SEGDATAPIN_A,0xFF);
	/* Clearing the control pins of the seven segment */
	vGpioSetNibble(SEGCTRLPORT, SEGCTRLPIN_1,0x0);
#endif

}


/**
 * @brief Making selected segment on board to display the specified value
 * @param[in] segno specify the segment number
 * @param[in] segvalue value to display
 * @return None
 **/

void vSevenSegDisplay(uint8_t segno, uint8_t segvalue)
{

#if COMMONCATHODESEG
	/* Clearing the data pins of the seven segment */
	vGpioSetByte(SEGDATAPORT, SEGDATAPIN_A,0x00);
	/* Clearing the control pins of the seven segment */
	//vGpioSetNibble(SEGCTRLPORT, SEGCTRLPIN_1,0xF);

	vGpioSetPin(SEGCTRLPORT, SEGCTRLPIN_1);
	vGpioSetPin(SEGCTRLPORT, SEGCTRLPIN_2);
	vGpioSetPin(SEGCTRLPORT, SEGCTRLPIN_3);
	vGpioSetPin(SEGCTRLPORT, SEGCTRLPIN_4);

#elif COMMONANODESEG
	/* Clearing the data pins of the seven segment */
	vGpioSetByte(SEGDATAPORT, SEGDATAPIN_A,0xFF);
	/* Clearing or De selecting the control pins  of the seven segment */
//	vGpioSetNibble(SEGCTRLPORT, SEGCTRLPIN_1,0x0);

	vGpioClrPin(SEGCTRLPORT, SEGCTRLPIN_1);
	vGpioClrPin(SEGCTRLPORT, SEGCTRLPIN_2);
	vGpioClrPin(SEGCTRLPORT, SEGCTRLPIN_3);
	vGpioClrPin(SEGCTRLPORT, SEGCTRLPIN_4);
#endif

	/* For Selecting the segment to display */
	switch(segno)
	{
	case CTRL_1:
#if COMMONCATHODESEG
		vGpioClrPin(SEGCTRLPORT, SEGCTRLPIN_1);
#elif COMMONANODESEG
		vGpioSetPin(SEGCTRLPORT, SEGCTRLPIN_1);
#endif
		break;
	case CTRL_2:
#if COMMONCATHODESEG
		vGpioClrPin(SEGCTRLPORT, SEGCTRLPIN_2);
#elif COMMONANODESEG
		vGpioSetPin(SEGCTRLPORT, SEGCTRLPIN_2);
#endif
		break;
	case CTRL_3:
#if COMMONCATHODESEG
		vGpioClrPin(SEGCTRLPORT, SEGCTRLPIN_3);
#elif COMMONANODESEG
		vGpioSetPin(SEGCTRLPORT, SEGCTRLPIN_3);
#endif
		break;
	case CTRL_4:
#if COMMONCATHODESEG
		vGpioClrPin(SEGCTRLPORT, SEGCTRLPIN_4);
#elif COMMONANODESEG
		vGpioSetPin(SEGCTRLPORT, SEGCTRLPIN_4);
#endif
		break;
	default:
		/* DO NOTHING */
		break;
	}

	/* For Writing the data into the selected segment */
	vGpioSetByte(SEGDATAPORT, SEGDATAPIN_A,segArray[segvalue]);
}













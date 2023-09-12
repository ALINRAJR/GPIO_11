

#ifndef SEVENSEG_H_
#define SEVENSEG_H_



/* Private includes ----------------------------------------------------------*/
#include "gpio.h"
#include "configboard.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define COMMONCATHODESEG  0
#define COMMONANODESEG    1

enum {CTRL_1=0,CTRL_2,CTRL_3,CTRL_4};
/* Private macro -------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Setting direction for Seven segment pins connected on board
 * @return None
 **/
void vSevenSegInitialize(void);

/**
 * @brief Making selected segment on board to display the specified value
 * @param[in] segno specify the segment number
 * @param[in] segvalue value to display
 * @return None
 **/

void vSevenSegDisplay(uint8_t segno, uint8_t segvalue);



#endif /* SEVENSEG_H_ */

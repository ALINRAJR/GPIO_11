
#ifndef BUTTON_H_
#define BUTTON_H_

/* Private includes ----------------------------------------------------------*/
#include "configboard.h"
#include "gpio.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
enum {BUTTON_0=0};
enum {BUTTON_NOTPRESSED=0,BUTTON_PRESSED};

/* Private macro -------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Setting direction for Button connected on board
 * @return None
 **/
void vButtonInitialize(void);

/**
* @brief Making selected LED on board to ON state
* @param[in] lednum specify the LED number
* @return None
**/
uint8_t ucButtonState(uint8_t buttonnum);


#endif /* BUTTON_H_ */

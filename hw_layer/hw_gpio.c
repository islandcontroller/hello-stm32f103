/*!****************************************************************************
 * @file
 * hw_gpio.c
 *
 * @brief
 * Hardware Layer - GPIOs
 *
 * @date  13.10.2025
 ******************************************************************************/

/*- Header files -------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "hw_gpio.h"
#include "hw_iodef.h"


/*- Public interface ---------------------------------------------------------*/
/*!****************************************************************************
 * @brief
 * Initialise GPIOs
 *
 * - PC13 "LED": Open-drain output
 *
 * @date  18.10.2025
 ******************************************************************************/
void vHW_GPIO_Init(void)
{
  __HAL_RCC_GPIOC_CLK_ENABLE();

  GPIO_InitTypeDef sLed = {
    .Pin = LED_PIN,
    .Mode = GPIO_MODE_OUTPUT_OD,
    .Pull = GPIO_NOPULL,
    .Speed = GPIO_SPEED_LOW
  };
  HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
  HAL_GPIO_Init(LED_PORT, &sLed);
}

/*!****************************************************************************
 * @brief
 * Toggle LED pin output state
 *
 * @date  18.10.2025
 ******************************************************************************/
void vHW_GPIO_ToggleLed(void)
{
  HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
}

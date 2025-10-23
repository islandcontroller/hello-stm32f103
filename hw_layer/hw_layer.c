/*!****************************************************************************
 * @file
 * hw_layer.c
 *
 * @brief
 * Hardware Layer
 *
 * @date  13.10.2025
 ******************************************************************************/

/*- Header files -------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "hw_clk.h"
#include "hw_gpio.h"
#include "hw_swo.h"
#include "hw_layer.h"


/*- Public interface ---------------------------------------------------------*/
/*!****************************************************************************
 * @brief
 * Initialise hardware layer
 *
 * @date  13.10.2025
 ******************************************************************************/
void vHW_Init(void)
{
  HAL_Init();

  vHW_CLK_Init();
  vHW_GPIO_Init();
}


/*- Delegated to submodules --------------------------------------------------*/
void vHW_ToggleLed(void)          { vHW_GPIO_ToggleLed(); }
uint32_t ulHW_GetTime(void)       { return ulHW_CLK_GetTime(); }
bool bHW_IsSwoDataAvailable(void) { return bHW_SWO_IsDataAvailable(); }
char cHW_ReadSwo(void)            { return cHW_SWO_Read(); }
void vHW_WriteSwo(char cCh)       { vHW_SWO_Write(cCh); }

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

/*!****************************************************************************
 * @brief
 * Get CPUID register from SCB
 *
 * @return  (uint32_t)  CPUID register value
 * @date  25.10.2025
 ******************************************************************************/
uint32_t ulHW_GetCpuid(void)
{
  return SCB->CPUID;
}

/*!****************************************************************************
 * @brief
 * Get FLASH memory size in kB
 *
 * @return  (uint16_t)  FLASH memory size in kB
 * @date  25.10.2025
 ******************************************************************************/
uint16_t uiHW_GetFlashSize(void)
{
  return *(const uint16_t*)FLASHSIZE_BASE;
}

/*!****************************************************************************
 * @brief
 * Get unique ID
 *
 * The ID spans 96 bits (3 words)
 *
 * @return  (uint32_t*)  First word of unique ID
 * @date  25.10.2025
 ******************************************************************************/
const uint32_t* pulHW_GetUID(void)
{
  return (const uint32_t*)UID_BASE;
}


/*- Delegated to submodules --------------------------------------------------*/
void vHW_ToggleLed(void) { vHW_GPIO_ToggleLed(); }
uint32_t ulHW_GetTime(void) { return ulHW_CLK_GetTime(); }
uint32_t ulHW_GetCoreClkFreq(void) { return ulHW_CLK_GetCoreClkFreq(); }
bool bHW_IsSwoDataAvailable(void) { return bHW_SWO_IsDataAvailable(); }
char cHW_ReadSwo(void) { return cHW_SWO_Read(); }
void vHW_WriteSwo(char cCh) { vHW_SWO_Write(cCh); }

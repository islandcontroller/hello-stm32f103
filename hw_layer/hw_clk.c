/*!****************************************************************************
 * @file
 * hw_clk.c
 *
 * @brief
 * Hardware Layer - System Clock
 *
 * @date  13.10.2025
 ******************************************************************************/

/*- Header files -------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "hw_clk.h"


/*- Public interface ---------------------------------------------------------*/
/*!****************************************************************************
 * @brief
 * Configure system clock tree
 *
 *       8 MHz    /1    72 MHz            72 MHz
 *       HSECLK   *9    SYSCLK     /1     HCLK
 *   HSE------->[ PLL ]------->[ AHBPRE ]----+-------------------------> CPU
 *                                           |               9 MHz
 *                                           |        /8     STKCLK
 *                                           +----[ STKPRE ]-------> SysTick
 *                                           |                36 MHz
 *                                           |        /2      PCLK1
 *                                           +----[ APB1PRE ]---------> APB1
 *                                           |                36 MHz
 *                                           |        /2      PCLK2
 *                                           '----[ APB2PRE ]---------> APB2
 *
 * @date  13.10.2025
 ******************************************************************************/
void vHW_CLK_Init(void)
{
  // Set up PLL and SYSCLK
  RCC_OscInitTypeDef sOsc = {
    .OscillatorType = RCC_OSCILLATORTYPE_HSE,
    .HSEPredivValue = RCC_HSE_PREDIV_DIV1,
    .HSEState = RCC_HSE_ON,
    .PLL = {
      .PLLSource = RCC_PLLSOURCE_HSE,
      .PLLState = RCC_PLL_ON,
      .PLLMUL = RCC_PLL_MUL9
    }
  };
  if (HAL_RCC_OscConfig(&sOsc) != HAL_OK) __BKPT();

  // Switch HCLK to PLLCLK source and configure PCLKs
  RCC_ClkInitTypeDef sClk = {
    .ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2,
    .SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK,
    .AHBCLKDivider = RCC_SYSCLK_DIV1,
    .APB1CLKDivider = RCC_HCLK_DIV2,
    .APB2CLKDivider = RCC_HCLK_DIV2
  };
  if (HAL_RCC_ClockConfig(&sClk, FLASH_LATENCY_2) != HAL_OK) __BKPT();

  // Disable unused LSI and HSI
  __HAL_RCC_LSI_DISABLE();
  __HAL_RCC_HSI_DISABLE();
}

/*!****************************************************************************
 * @brief
 * Get system time
 *
 * System time is incremented by SysTick every 1 millisecond.
 *
 * @return  (uint32_t)  System time in milliseconds
 * @date  20.10.2025
 ******************************************************************************/
uint32_t ulHW_CLK_GetTime(void)
{
  return HAL_GetTick();
}

/*!****************************************************************************
 * @brief
 * Get current core clock frequency
 *
 * @return  (uint32_t)  Core clock frequency in Hz
 * @date  25.10.2025
 ******************************************************************************/
uint32_t ulHW_CLK_GetCoreClkFreq(void)
{
  return SystemCoreClock;
}

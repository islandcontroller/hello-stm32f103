/*!****************************************************************************
 * @file
 * hw_clk.h
 *
 * @brief
 * Hardware Layer - System Clock
 *
 * @date  13.10.2025
 ******************************************************************************/

#ifndef HW_CLK_H_
#define HW_CLK_H_

/*- Header files -------------------------------------------------------------*/
#include <stdint.h>


/*- Public interface ---------------------------------------------------------*/
void vHW_CLK_Init(void);
uint32_t ulHW_CLK_GetTime(void);
uint32_t ulHW_CLK_GetCoreClkFreq(void);

#endif // HW_CLK_H_

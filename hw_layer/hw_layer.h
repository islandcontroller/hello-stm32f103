/*!****************************************************************************
 * @file
 * hw_layer.h
 *
 * @brief
 * Hardware Layer
 *
 * @date  13.10.2025
 ******************************************************************************/

#ifndef HW_LAYER_H_
#define HW_LAYER_H_

/*- Header files -------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>


/*- Public interface ---------------------------------------------------------*/
void vHW_Init(void);

// GPIOs
void vHW_ToggleLed(void);

// System Time / Clock
uint32_t ulHW_GetTime(void);
uint32_t ulHW_GetCoreClkFreq(void);

// SWO
bool bHW_IsSwoDataAvailable(void);
char cHW_ReadSwo(void);
void vHW_WriteSwo(char cCh);

// Core info
uint32_t ulHW_GetCpuid(void);
uint16_t uiHW_GetFlashSize(void);
const uint32_t* pulHW_GetUID();

#endif // HW_LAYER_H_

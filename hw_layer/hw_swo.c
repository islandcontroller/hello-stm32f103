/*!****************************************************************************
 * @file
 * hw_swo.c
 *
 * @brief
 * Hardware Layer - SWO-based I/O
 *
 * @date  13.08.2025
 ******************************************************************************/

/*- Header files -------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "hw_swo.h"


/*- Global data --------------------------------------------------------------*/
/// Data receive buffer
volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;


/*- Public interface ---------------------------------------------------------*/
/*!****************************************************************************
 * @brief
 * Check if new data is available in the receive buffer
 *
 * @return  (bool)  New data available
 * @date  13.08.2025
 ******************************************************************************/
bool bHW_SWO_IsDataAvailable(void)
{
  return (bool)ITM_CheckChar();
}

/*!****************************************************************************
 * @brief
 * Read character from debugger input
 *
 * @return  (char)  Input data or -1 if no data is available
 * @date  13.08.2025
 ******************************************************************************/
char cHW_SWO_Read(void)
{
  return (char)ITM_ReceiveChar();
}

/*!****************************************************************************
 * @brief
 * Write character to debugger output
 *
 * When a debugger is connected, this call blocks until the previous character
 * has been transmitted.
 *
 * @param[in] cCh   Character to send
 * @date  13.08.2025
 ******************************************************************************/
void vHW_SWO_Write(char cCh)
{
  (void)ITM_SendChar(cCh);
}

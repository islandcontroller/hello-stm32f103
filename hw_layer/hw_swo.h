/*!****************************************************************************
 * @file
 * hw_swo.h
 *
 * @brief
 * Hardware Layer - SWO-based I/O
 *
 * @date  13.08.2025
 ******************************************************************************/

#ifndef SWO_H_
#define SWO_H_

/*- Header files -------------------------------------------------------------*/
#include <stdbool.h>


/*- Public interface ---------------------------------------------------------*/
bool bHW_SWO_IsDataAvailable(void);

char cHW_SWO_Read(void);
void vHW_SWO_Write(char cCh);

#endif // SWO_H_

/*!****************************************************************************
 * @brief
 * main.c
 *
 * @brief
 * Main program
 *
 * @date  19.10.2025
 ******************************************************************************/

/*- Header files -------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include "vt100.h"
#include "hw_layer.h"


/*- Macros -------------------------------------------------------------------*/
/// LED toggle interval in milliseconds
#define LED_TOGGLE_INTERVAL         500uL


/*- Private data -------------------------------------------------------------*/
/// Last time the LED was toggled
static uint32_t ulLastToggle;


/*- Private functions --------------------------------------------------------*/
static void vPrintCoreInfo(void);
static void vPrintSysCoreClk(void);
static void vPrintEsigInfo(void);


/*- Public interface ---------------------------------------------------------*/
/*!****************************************************************************
 * @brief
 * Main program entrypoint and background task
 *
 * @date  19.10.2025
 ******************************************************************************/
int main(void)
{
  // Initialise hardware layer
  vHW_Init();

  // Initialise LED blinky
  ulLastToggle = ulHW_GetTime();

  // Display MCU info via SWO
  printf(
    VT100_ERASE_DISPLAY
    VT100_INVERT
    "--------------------------------------------------\r\n"
    "        ##                                        \r\n"
    "                                                  \r\n"
    "      ##    ######                                \r\n"
    "     ##  ##                                       \r\n"
    "    ##  ##                                        \r\n"
    "   ##    ######  ######                 @islandc_ \r\n"
    "--------------------------------------------------\r\n"
    " MCU:  STMicroelectronics STM32F103               \r\n"
    " Core: Arm Cortex-M3                              \r\n"
    "--------------------------------------------------\r\n"
    VT100_NO_INVERT
    "\r\n"
  );
  vPrintCoreInfo();
  printf("\r\n");
  vPrintSysCoreClk();
  printf("\r\n");
  vPrintEsigInfo();

  // LED blinky in background task
  while (1)
  {
    uint32_t ulNow = ulHW_GetTime();
    if (ulNow - ulLastToggle > LED_TOGGLE_INTERVAL)
    {
      vHW_ToggleLed();
      ulLastToggle = ulNow;
    }
  }
}


/*- Private functions --------------------------------------------------------*/
/*!****************************************************************************
 * @brief
 * Print core information from CPUID
 *
 * @date  25.10.2025
 ******************************************************************************/
static void vPrintCoreInfo(void)
{
  uint32_t ulCpuid = ulHW_GetCpuid();
  printf(
    "-- Core Information ------------------------------\r\n"
    "CPUID:       0x%08lX\r\n", ulCpuid
  );

  // Implementor
  uint8_t ucImpl = (uint8_t)(ulCpuid >> 24);
  printf("implementer: 0x%02X  (%s)\r\n", ucImpl, (ucImpl == 0x41u) ? "ARM" : "unknown");

  // Processor revision
  uint8_t ucVar = (uint8_t)((ulCpuid >> 20) & 0xFuL);
  printf("variant:     0x%01X   (Revision %d)\r\n", ucVar, ucVar);

  // Part number
  uint16_t uiPartno = (uint16_t)((ulCpuid >> 4) & 0xFFFuL);
  printf("partno:      0x%03X (%s)\r\n", uiPartno, (uiPartno == 0xC23u) ? "Cortex-M3" : "unknown");

  // Patch release
  uint8_t ucRev = (uint8_t)(ulCpuid & 0xFuL);
  printf("revision:    0x%01X   (Patch %d)\r\n", ucRev, ucRev);
}

/*!****************************************************************************
 * @brief
 * Print system core clock frequency
 *
 * @date  25.10.2025
 ******************************************************************************/
static void vPrintSysCoreClk(void)
{
  uint32_t ulFreq_kHz = ulHW_GetCoreClkFreq() / 1000uL;
  uint16_t uiFreq_MHz = (uint16_t)(ulFreq_kHz / 1000uL);
  uint16_t uiFreqRem_kHz = (uint16_t)(ulFreq_kHz % 1000uL);
  printf(
    "-- Clocks ----------------------------------------\r\n"
    "f_HCLK = %d.%03d MHz\r\n", uiFreq_MHz, uiFreqRem_kHz
  );
}

/*!****************************************************************************
 * @brief
 * Print FLASH size and unique ID
 *
 * @date  25.10.2025
 ******************************************************************************/
static void vPrintEsigInfo(void)
{
  printf(
    "-- ESIG ------------------------------------------\r\n"
  );

  uint16_t uiFlashSize = uiHW_GetFlashSize();
  printf("FLASH Size: %d KB\r\n", uiFlashSize);

  const uint32_t* pulUID = pulHW_GetUID();
  printf("Unique ID: %08lX %08lX %08lX\r\n", pulUID[0], pulUID[1], pulUID[2]);
}

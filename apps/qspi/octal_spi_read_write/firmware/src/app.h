/*******************************************************************************
  Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef APP_H
#define APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdlib.h>
#include <string.h>
#include "definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#define PAGE_SIZE                  (256U)
#define SECTOR_SIZE                (4096U)

/* Erase, Write and Read 80KBytes of memory */
#define SECTORS_TO_EWR             (20U)

#define BUFFER_SIZE                (SECTOR_SIZE * SECTORS_TO_EWR)

#define MEM_START_ADDRESS          (0x00000000U)

#define MX66LM1G45G_JEDEC_ID       (0x3B85C2U)

#define LED_ON()                     LED_GREEN_Set()
#define LED_OFF()                    LED_GREEN_Clear()
#define LED_TOGGLE()                 LED_GREEN_Toggle()

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* The app mounts the disk */
    APP_STATE_INIT = 0,

    /* Reset Flash */
    APP_STATE_RESET_FLASH,

    /* Enable Octa command */
    APP_STATE_ENABLE_OCTA_CMD,

    /* Unlock Flash */
    APP_STATE_UNLOCK_FLASH,

    /* Read JEDEC ID */
    APP_STATE_READ_JEDEC_ID,

    /* Erase Flash */
    APP_STATE_ERASE_FLASH,

    /* Erase Wait */
    APP_STATE_ERASE_WAIT,

    /* Write to Memory */
    APP_STATE_WRITE_MEMORY,

    /* Erase Wait */
    APP_STATE_WRITE_WAIT,

    /* Read From Memory */
    APP_STATE_READ_MEMORY,

    /* Verify Data Read */
    APP_STATE_VERIFY_DATA,

    /* The app idles */
    APP_STATE_SUCCESS,

    /* An app error has occurred */
    APP_STATE_ERROR

} APP_STATES;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* Application's current state */
    APP_STATES state;

    /* Application transfer status */
    volatile bool xfer_done;

    /* Jedec-ID*/
    uint32_t jedec_id;

    /* Read Buffer */
    uint8_t readBuffer[BUFFER_SIZE];

    /* Write Buffer*/
    uint8_t writeBuffer[BUFFER_SIZE];
} APP_DATA;

/* MX66 Command set

  Summary:
    Enumeration listing the MX66LM commands.

  Description:
    This enumeration defines the commands used to interact with the MX66LM
    series of devices.

  Remarks:
    None
*/

typedef enum
{
    /* ******** SPI command ******** */
    /* Reset enable command. */
    MX66_CMD_FLASH_RESET_ENABLE    = 0x66,

    /* Command to reset the flash. */
    MX66_CMD_FLASH_RESET           = 0x99,

    /* Write enable command. */
    MX66_CMD_WRITE_ENABLE          = 0x06,

    /* Command to Write configuration register 2 */
    MX66_CMD_WRCR2                 = 0x72,

    /* ******** OPI command ******** */
    /* OCTA Command to read JEDEC-ID of the flash device. */
    MX66_CMD_OCTA_JEDEC_ID_READ    = 0x9F60,

    /* OCTA I/O STR read */
    MX66_CMD_OCTA_8READ            = 0xEC13,

    /* OCTA I/O DTR read */
    MX66_CMD_OCTA_8DTRD            = 0xEE11,

    /* OCTA Write enable command. */
    MX66_CMD_OCTA_WRITE_ENABLE     = 0x06F9,

    /* OCTA Page Program command. */
    MX66_CMD_OCTA_PAGE_PROGRAM     = 0x12ED,

    /* OCTA Command to read the Flash status register. */
    MX66_CMD_OCTA_READ_STATUS_REG  = 0x05FA,

    /* OCTA Command to perform sector erase */
    MX66_CMD_OCTA_SECTOR_ERASE     = 0x21DE,

    /* OCTA Command to perform Block erase */
    MX66_CMD_OCTA_BLOCK_ERASE_64K  = 0xDC23,

    /* OCTA Command to perform Chip erase */
    MX66_CMD_OCTA_CHIP_ERASE       = 0xC738,

    /* Command to unlock the flash device. */
    MX66_CMD_OCTA_UNPROTECT_GLOBAL = 0x9867

} MX66_CMD;

typedef enum
{
    /* Buffer is being processed */
    APP_TRANSFER_BUSY,
    /* APP Buffer transfer is successfully completed*/
    APP_TRANSFER_COMPLETED,
    /* APP Buffer transfer had error*/
    APP_TRANSFER_ERROR_UNKNOWN,
    /* APP Transfer has not been asked yet */
    APP_TRANSFER_IDLE
} APP_TRANSFER_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     Application initialization routine.

  Description:
    This function initializes the application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the main function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    Application tasks function

  Description:
    This routine is the Application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks( void );


#endif /* APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */


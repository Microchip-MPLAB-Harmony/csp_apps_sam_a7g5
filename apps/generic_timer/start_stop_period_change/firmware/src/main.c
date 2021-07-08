/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

static bool timerOn = false;
static uint64_t basePeriod = 0U;
static uint32_t periodMultiplier = 1U;

void toggleTimer(PIO_PIN pin, uintptr_t context)
{
    (void)context;
    (void)pin;
    if (timerOn){
        GENERIC_TIMER_Stop();
        timerOn = false;
    }else {
        GENERIC_TIMER_Start();
        timerOn = true;
    }
}

void toggleLED(void* pContext)
{
    (void)pContext;
    LED_BLUE_Toggle();
}

void togglePeriod(PIO_PIN pin, uintptr_t context)
{
    (void)context;
    (void)pin;
    
    periodMultiplier = 1U + (periodMultiplier % 4U) ;
    
    GENERIC_TIMER_PeriodSet(periodMultiplier * basePeriod);
}


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    GENERIC_TIMER_RegisterCallback(toggleLED, NULL);

    PIO_PinInterruptCallbackRegister(USER_BUTTON_PIN, toggleTimer, 0U);
    PIO_PinInterruptEnable(USER_BUTTON_PIN);

    PIO_PinInterruptCallbackRegister(SW4_PIN, togglePeriod, 0U);
    PIO_PinInterruptEnable(SW4_PIN);
    
    basePeriod = GENERIC_TIMER_PeriodGet();

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/


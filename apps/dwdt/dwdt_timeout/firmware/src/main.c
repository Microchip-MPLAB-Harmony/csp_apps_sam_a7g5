/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.
  
  File Name:
    main_sam_a5d2.c

  Summary:
    This file contains a demonstration of the WDT periopheral for the SAM_A5D2.

  Description:
    A simple loop process blinks the LED for user feedback.  Within the loop
    the watch dog receives a 'pet' until the user presses the test push button. 
    The process will then starve the watch petting and the processor will reset.
    A spin lock creates a process starvation emulating a dead lock. 

    The PIT is used to provide a delay for the led blink and is not otherwise
    applicable to the demonstration

 *******************************************************************************/

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                		// Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

volatile bool deadLockSwitchPressed = false;
volatile bool repeatThresholdSwitchPressed = false;
volatile uint32_t interruptCounter = 0U;
volatile bool repeatThresholdInterrupt = false;
volatile bool levelInterrupt = false;

void deadLockSet(PIO_PIN pin, uintptr_t context)
{
    (void)pin;
    (void)context;
    deadLockSwitchPressed = true;
}

void repeatThresholdSet(PIO_PIN pin, uintptr_t context)
{
    (void)pin;
    (void)context;
    repeatThresholdSwitchPressed = true;
}

void timerCallback(void* context)
{
    (void)context;
    interruptCounter++;
}

void dwdt_ps_callback(uint32_t interruptStatus, void* context)
{
    if((interruptStatus & DWDT_PS_WDT_ISR_LVLINT_Msk) != 0U)
    {
        levelInterrupt = true;
    }
    if((interruptStatus & DWDT_PS_WDT_ISR_RPTHINT_Msk) != 0U)
    {
        repeatThresholdInterrupt = true;
    }
    
}


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
int main( void )
{
    /* Initialize all modules */
    SYS_Initialize( NULL );
    PIO_PinInterruptCallbackRegister( PB_USER1_PIN, deadLockSet, (uintptr_t) NULL );
    PIO_PinInterruptEnable( PB_USER1_PIN );
    
    PIO_PinInterruptCallbackRegister( PB_USER2_PIN, repeatThresholdSet, (uintptr_t) NULL );
    PIO_PinInterruptEnable( PB_USER2_PIN );
    
    GENERIC_TIMER_RegisterCallback(timerCallback, NULL);
    
    DWDT_PS_RegisterCallback(dwdt_ps_callback, NULL);

    printf( "\r\n-------------------------------------------------------------" );
    printf( "\r\n                          DWDT DEMO" );
    printf( "\r\n-------------------------------------------------------------" );
    printf( "\r\nFlashing LED indicates process is running\r\nPress SWITCH1 " 
            "to simulate a deadlock\r\nPress SWITCH2 to simulate repeat "
            "threshold violation\r\n");
    
    uint32_t toggleCount = interruptCounter;
    uint32_t clearCount  = interruptCounter;
    
    GENERIC_TIMER_Start();
    
    while( true )
    {
        if ((interruptCounter - toggleCount) > 1U)
        {        
            toggleCount = interruptCounter;
            // Led toggle with timer for reasonable blink
            LED_BLUE_Toggle();
        }
        
        if ((interruptCounter - clearCount) > 5U)
        {  
            clearCount = interruptCounter;
            DWDT_PS_Clear();
        }
        
        if (repeatThresholdSwitchPressed)
        {
            repeatThresholdSwitchPressed = false;
            DWDT_PS_Clear();
        }
        
        if(repeatThresholdInterrupt)
        {
            printf("Repeat threshold interrupt occurred !!!!............\r\n");
            repeatThresholdInterrupt = false;
        }

        if( deadLockSwitchPressed )
        {   
            printf( "Process starvation .................\r\n" );
            printf( "\tDevice reset will occur in %lu seconds\r\n",
                        (4 - (interruptCounter - clearCount)));
            LED_BLUE_Set();
            while( 1 )
            {
                if(levelInterrupt)
                {
                    printf("Level interrupt occurred !!!!............\r\n");
                    levelInterrupt = false;
                }
            }
        }
    }

    /* Execution should not come here during normal operation */
    return( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

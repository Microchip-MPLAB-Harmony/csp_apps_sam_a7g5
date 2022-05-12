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

volatile static bool switchPressed = false;

void generic_timer_callback(uintptr_t context)
{
   (void)context;
   LED_BLUE_Toggle();
}

void switchHandler( PIO_PIN pin, uintptr_t context)
{
   switchPressed = true;
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

    struct tm sys_time;
    struct tm alarm_time;
    //15-01-2018 12:00:00 Monday
    sys_time.tm_hour = 12;
    sys_time.tm_sec = 00;
    sys_time.tm_min = 00;
    sys_time.tm_mon = 0;
    sys_time.tm_year = 118;
    sys_time.tm_mday = 15;
    sys_time.tm_wday = 1;
    
    GENERIC_TIMER_CallbackRegister(generic_timer_callback, 0U);
    
    RTC_TimeSet(&sys_time);
   
    PIO_PinInterruptCallbackRegister(SW1_PIN, switchHandler, 0U);
    PIO_PinInterruptEnable(SW1_PIN);

    GENERIC_TIMER_Start();

    while ( true )
    {
        
        if(switchPressed)
        {
          RTC_TimeGet(&alarm_time);
          alarm_time.tm_sec += 5;
          RTC_AlarmSet(&alarm_time, RTC_ALARM_MASK_HHMISS);
          SHDWC_Shutdown();
          switchPressed = false;
        }
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );

}


/*******************************************************************************
 End of File
*/


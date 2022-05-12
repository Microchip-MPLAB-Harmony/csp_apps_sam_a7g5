/*******************************************************************************
  FLEXCOM11 USART PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_flexcom11_usart.c

  Summary:
    FLEXCOM11 USART PLIB Implementation File

  Description
    This file defines the interface to the FLEXCOM11 USART peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
*******************************************************************************/

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/
#include "plib_flexcom11_usart.h"
#include "interrupts.h"

#define FLEXCOM11_USART_HW_RX_FIFO_THRES                 16
#define FLEXCOM11_USART_HW_TX_FIFO_THRES                 16

// *****************************************************************************
// *****************************************************************************
// Section: FLEXCOM11 USART Implementation
// *****************************************************************************
// *****************************************************************************
FLEXCOM_USART_OBJECT flexcom11UsartObj;

void static FLEXCOM11_USART_ErrorClear( void )
{
    uint16_t dummyData = 0;

    if (FLEXCOM11_REGS->FLEX_US_CSR & (FLEX_US_CSR_OVRE_Msk | FLEX_US_CSR_FRAME_Msk | FLEX_US_CSR_PARE_Msk))
    {
        /* Clear the error flags */
        FLEXCOM11_REGS->FLEX_US_CR = FLEX_US_CR_RSTSTA_Msk;

        /* Flush existing error bytes from the RX FIFO */
        while( FLEXCOM11_REGS->FLEX_US_CSR & FLEX_US_CSR_RXRDY_Msk )
        {
            if (FLEXCOM11_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk)
            {
                dummyData = *((uint16_t*)&FLEXCOM11_REGS->FLEX_US_RHR) & FLEX_US_RHR_RXCHR_Msk;
            }
            else
            {
                dummyData = *((uint8_t*)&FLEXCOM11_REGS->FLEX_US_RHR);
            }
        }
    }

    /* Ignore the warning */
    (void)dummyData;

    return;
}

void static FLEXCOM11_USART_ISR_RX_Handler( void )
{
    uint32_t rxPending = 0;
    uint32_t rxThreshold = 0;
    if(flexcom11UsartObj.rxBusyStatus == true)
    {
        while( (FLEXCOM11_REGS->FLEX_US_CSR & FLEX_US_CSR_RXRDY_Msk) && (flexcom11UsartObj.rxProcessedSize < flexcom11UsartObj.rxSize) )
        {
            if (FLEXCOM11_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk)
            {
                ((uint16_t*)flexcom11UsartObj.rxBuffer)[flexcom11UsartObj.rxProcessedSize++] = *((uint16_t*)&FLEXCOM11_REGS->FLEX_US_RHR) & FLEX_US_RHR_RXCHR_Msk;
            }
            else
            {
                flexcom11UsartObj.rxBuffer[flexcom11UsartObj.rxProcessedSize++] = *((uint8_t*)&FLEXCOM11_REGS->FLEX_US_RHR);
            }
        }

        rxPending = flexcom11UsartObj.rxSize - flexcom11UsartObj.rxProcessedSize;
        if (rxPending > 0)
        {
            rxThreshold = (FLEXCOM11_REGS->FLEX_US_FMR & FLEX_US_FMR_RXFTHRES_Msk) >> FLEX_US_FMR_RXFTHRES_Pos;
            if (rxPending < rxThreshold)
            {
                FLEXCOM11_REGS->FLEX_US_FMR = (FLEXCOM11_REGS->FLEX_US_FMR & ~FLEX_US_FMR_RXFTHRES_Msk) | FLEX_US_FMR_RXFTHRES(rxPending);
            }
        }

        /* Check if the buffer is done */
        if(flexcom11UsartObj.rxProcessedSize >= flexcom11UsartObj.rxSize)
        {
            flexcom11UsartObj.rxBusyStatus = false;

            /* Disable Read, Overrun, Parity and Framing error interrupts */
            FLEXCOM11_REGS->FLEX_US_FIDR = FLEX_US_FIDR_RXFTHF_Msk;
            FLEXCOM11_REGS->FLEX_US_IDR = (FLEX_US_IDR_FRAME_Msk | FLEX_US_IDR_PARE_Msk | FLEX_US_IDR_OVRE_Msk);

            if(flexcom11UsartObj.rxCallback != NULL)
            {
                flexcom11UsartObj.rxCallback(flexcom11UsartObj.rxContext);
            }
        }
    }
    else
    {
        /* Nothing to process */
        ;
    }

    return;
}

void static FLEXCOM11_USART_ISR_TX_Handler( void )
{
    if(flexcom11UsartObj.txBusyStatus == true)
    {
        while( (FLEXCOM11_REGS->FLEX_US_CSR & FLEX_US_CSR_TXRDY_Msk) && (flexcom11UsartObj.txProcessedSize < flexcom11UsartObj.txSize))
        {
            if (FLEXCOM11_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk)
            {
                *((uint16_t*)&FLEXCOM11_REGS->FLEX_US_THR) =  ((uint16_t*)flexcom11UsartObj.txBuffer)[flexcom11UsartObj.txProcessedSize++] & FLEX_US_THR_TXCHR_Msk;
            }
            else
            {
                *((uint8_t*)&FLEXCOM11_REGS->FLEX_US_THR) =  ((uint8_t*)flexcom11UsartObj.txBuffer)[flexcom11UsartObj.txProcessedSize++];
            }
        }

        /* Check if the buffer is done */
        if(flexcom11UsartObj.txProcessedSize >= flexcom11UsartObj.txSize)
        {
            if (FLEXCOM11_REGS->FLEX_US_CSR & FLEX_US_CSR_TXEMPTY_Msk)
            {
                flexcom11UsartObj.txBusyStatus = false;

                FLEXCOM11_REGS->FLEX_US_FIDR = FLEX_US_FIDR_TXFTHF_Msk;

                FLEXCOM11_REGS->FLEX_US_IDR = FLEX_US_IDR_TXEMPTY_Msk;

                if(flexcom11UsartObj.txCallback != NULL)
                {
                    flexcom11UsartObj.txCallback(flexcom11UsartObj.txContext);
                }
            }
            else
            {
                FLEXCOM11_REGS->FLEX_US_FIDR = FLEX_US_FIDR_TXFTHF_Msk;

                FLEXCOM11_REGS->FLEX_US_IER = FLEX_US_IER_TXEMPTY_Msk;
            }
        }
    }
    else
    {
        /* Nothing to process */
        ;
    }

    return;
}

void FLEXCOM11_InterruptHandler( void )
{
    /* Channel status */
    uint32_t channelStatus = FLEXCOM11_REGS->FLEX_US_CSR;
    uint32_t interruptMask = FLEXCOM11_REGS->FLEX_US_IMR;

    /* Error status */
    uint32_t errorStatus = (channelStatus & (FLEX_US_CSR_OVRE_Msk | FLEX_US_CSR_FRAME_Msk | FLEX_US_CSR_PARE_Msk));

    if((errorStatus != 0) && (interruptMask & (FLEX_US_IMR_RXRDY_Msk | FLEX_US_IMR_FRAME_Msk | FLEX_US_IMR_PARE_Msk | FLEX_US_IMR_OVRE_Msk)))
    {
        /* Save error to report it later */
        flexcom11UsartObj.errorStatus = (FLEXCOM_USART_ERROR)errorStatus;

        /* Clear error flags and flush the error data */
        FLEXCOM11_USART_ErrorClear();

        /* Transfer complete. Clear the busy flag. */
        flexcom11UsartObj.rxBusyStatus = false;

        FLEXCOM11_REGS->FLEX_US_FIDR = FLEX_US_FIDR_RXFTHF_Msk;

        /* Disable Read, Overrun, Parity and Framing error interrupts */
        FLEXCOM11_REGS->FLEX_US_IDR = (FLEX_US_IDR_RXRDY_Msk | FLEX_US_IDR_FRAME_Msk | FLEX_US_IDR_PARE_Msk | FLEX_US_IDR_OVRE_Msk);

        /* USART errors are normally associated with the receiver, hence calling receiver context */
        if( flexcom11UsartObj.rxCallback != NULL )
        {
            flexcom11UsartObj.rxCallback(flexcom11UsartObj.rxContext);
        }
    }


    /* Clear the FIFO related interrupt flags */
    FLEXCOM11_REGS->FLEX_US_CR = FLEX_US_CR_RSTSTA_Msk;

    FLEXCOM11_USART_ISR_RX_Handler();

    FLEXCOM11_USART_ISR_TX_Handler();

}


void FLEXCOM11_USART_Initialize( void )
{
    /* Set FLEXCOM USART operating mode */
    FLEXCOM11_REGS->FLEX_MR = FLEX_MR_OPMODE_USART;

    /* Reset FLEXCOM11 USART */
    FLEXCOM11_REGS->FLEX_US_CR = (FLEX_US_CR_RSTRX_Msk | FLEX_US_CR_RSTTX_Msk | FLEX_US_CR_RSTSTA_Msk  | FLEX_US_CR_FIFOEN_Msk );

    FLEXCOM11_REGS->FLEX_US_FMR = FLEX_US_FMR_TXFTHRES(FLEXCOM11_USART_HW_TX_FIFO_THRES) | FLEX_US_FMR_RXFTHRES(FLEXCOM11_USART_HW_RX_FIFO_THRES)  | FLEX_US_FMR_RXFTHRES2(12) | FLEX_US_FMR_FRTSC_Msk ;

    /* Setup transmitter timeguard register */
    FLEXCOM11_REGS->FLEX_US_TTGR = 0;

    /* Configure FLEXCOM11 USART mode */
    FLEXCOM11_REGS->FLEX_US_MR = ( FLEX_US_MR_USART_MODE_HW_HANDSHAKING | FLEX_US_MR_USCLKS_MCK | FLEX_US_MR_CHRL_8_BIT | FLEX_US_MR_PAR_NO | FLEX_US_MR_NBSTOP_1_BIT | (0 << FLEX_US_MR_OVER_Pos));

    /* Configure FLEXCOM11 USART Baud Rate */
    FLEXCOM11_REGS->FLEX_US_BRGR = FLEX_US_BRGR_CD(108) | FLEX_US_BRGR_FP(4);

    /* Enable FLEXCOM11 USART */
    FLEXCOM11_REGS->FLEX_US_CR = (FLEX_US_CR_TXEN_Msk | FLEX_US_CR_RXEN_Msk);


    /* Initialize instance object */
    flexcom11UsartObj.rxBuffer = NULL;
    flexcom11UsartObj.rxSize = 0;
    flexcom11UsartObj.rxProcessedSize = 0;
    flexcom11UsartObj.rxBusyStatus = false;
    flexcom11UsartObj.rxCallback = NULL;
    flexcom11UsartObj.errorStatus = FLEXCOM_USART_ERROR_NONE;
    flexcom11UsartObj.txBuffer = NULL;
    flexcom11UsartObj.txSize = 0;
    flexcom11UsartObj.txProcessedSize = 0;
    flexcom11UsartObj.txBusyStatus = false;
    flexcom11UsartObj.txCallback = NULL;

    return;
}

FLEXCOM_USART_ERROR FLEXCOM11_USART_ErrorGet( void )
{
    FLEXCOM_USART_ERROR errorStatus = flexcom11UsartObj.errorStatus;

    flexcom11UsartObj.errorStatus = FLEXCOM_USART_ERROR_NONE;

    /* All errors are cleared, but send the previous error state */
    return errorStatus;
}

static void FLEXCOM11_USART_BaudCalculate(uint32_t srcClkFreq, uint32_t reqBaud, uint8_t overSamp, uint32_t* cd, uint32_t* fp, uint32_t* baudError)
{
    uint32_t actualBaud = 0;

    *cd = srcClkFreq / (reqBaud * 8 * (2 - overSamp));

    if (*cd > 0)
    {
        *fp = ((srcClkFreq / (reqBaud * (2 - overSamp))) - ((*cd) * 8));
        actualBaud = (srcClkFreq / (((*cd) * 8) + (*fp))) / (2 - overSamp);
        *baudError = ((100 * actualBaud)/reqBaud) - 100;
    }
}

bool FLEXCOM11_USART_SerialSetup( FLEXCOM_USART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    uint32_t baud = 0;
    uint32_t overSampVal = 0;
    uint32_t usartMode;
    uint32_t cd0, fp0, cd1, fp1, baudError0, baudError1;
    bool status = false;

    cd0 = fp0 = cd1 = fp1 = baudError0 = baudError1 = 0;

    if((flexcom11UsartObj.rxBusyStatus == true) || (flexcom11UsartObj.txBusyStatus == true))
    {
        /* Transaction is in progress, so return without updating settings */
        return false;
    }

    if (setup != NULL)
    {
        baud = setup->baudRate;

        if(srcClkFreq == 0)
        {
            srcClkFreq = FLEXCOM11_USART_FrequencyGet();
        }

        /* Calculate baud register values for 8x/16x oversampling values */

        FLEXCOM11_USART_BaudCalculate(srcClkFreq, baud, 0, &cd0, &fp0, &baudError0);
        FLEXCOM11_USART_BaudCalculate(srcClkFreq, baud, 1, &cd1, &fp1, &baudError1);

        if ( !(cd0 > 0 && cd0 <= 65535) && !(cd1 > 0 && cd1 <= 65535) )
        {
            /* Requested baud cannot be generated with current clock settings */
            return status;
        }

        if ( (cd0 > 0 && cd0 <= 65535) && (cd1 > 0 && cd1 <= 65535) )
        {
            /* Requested baud can be generated with both 8x and 16x oversampling. Select the one with less % error. */
            if (baudError1 < baudError0)
            {
                cd0 = cd1;
                fp0 = fp1;
                overSampVal = (1 << FLEX_US_MR_OVER_Pos) & FLEX_US_MR_OVER_Msk;
            }
        }
        else
        {
            /* Requested baud can be generated with either with 8x oversampling or with 16x oversampling. Select valid one. */
            if (cd1 > 0 && cd1 <= 65535)
            {
                cd0 = cd1;
                fp0 = fp1;
                overSampVal = (1 << FLEX_US_MR_OVER_Pos) & FLEX_US_MR_OVER_Msk;
            }
        }

        /* Configure FLEXCOM11 USART mode */
        usartMode = FLEXCOM11_REGS->FLEX_US_MR;
        usartMode &= ~(FLEX_US_MR_CHRL_Msk | FLEX_US_MR_MODE9_Msk | FLEX_US_MR_PAR_Msk | FLEX_US_MR_NBSTOP_Msk | FLEX_US_MR_OVER_Msk);
        FLEXCOM11_REGS->FLEX_US_MR = usartMode | ((uint32_t)setup->dataWidth | (uint32_t)setup->parity | (uint32_t)setup->stopBits | overSampVal);

        /* Configure FLEXCOM11 USART Baud Rate */
        FLEXCOM11_REGS->FLEX_US_BRGR = FLEX_US_BRGR_CD(cd0) | FLEX_US_BRGR_FP(fp0);
        status = true;
    }

    return status;
}

bool FLEXCOM11_USART_Read( void *buffer, const size_t size )
{
    bool status = false;
    uint8_t* pBuffer = (uint8_t *)buffer;

    if(pBuffer != NULL)
    {
        /* Check if receive request is in progress */
        if(flexcom11UsartObj.rxBusyStatus == false)
        {
            /* Clear errors that may have got generated when there was no active read request pending */
            FLEXCOM11_USART_ErrorClear();

            /* Clear the errors related to pervious read requests */
            flexcom11UsartObj.errorStatus = FLEXCOM_USART_ERROR_NONE;

            flexcom11UsartObj.rxBuffer = pBuffer;
            flexcom11UsartObj.rxSize = size;
            flexcom11UsartObj.rxProcessedSize = 0;
            flexcom11UsartObj.rxBusyStatus = true;
            status = true;


            /* Clear RX FIFO */
            FLEXCOM11_REGS->FLEX_US_CR = FLEX_US_CR_RXFCLR_Msk;

            if (flexcom11UsartObj.rxSize < FLEXCOM11_USART_HW_RX_FIFO_THRES)
            {
                FLEXCOM11_REGS->FLEX_US_FMR = (FLEXCOM11_REGS->FLEX_US_FMR & ~FLEX_US_FMR_RXFTHRES_Msk) | FLEX_US_FMR_RXFTHRES(flexcom11UsartObj.rxSize);
            }
            else
            {
                FLEXCOM11_REGS->FLEX_US_FMR = (FLEXCOM11_REGS->FLEX_US_FMR & ~FLEX_US_FMR_RXFTHRES_Msk) | FLEX_US_FMR_RXFTHRES(FLEXCOM11_USART_HW_RX_FIFO_THRES);
            }

            /* Enable Read, Overrun, Parity and Framing error interrupts */
            FLEXCOM11_REGS->FLEX_US_IER = (FLEX_US_IER_FRAME_Msk | FLEX_US_IER_PARE_Msk | FLEX_US_IER_OVRE_Msk);

            /* Enable RX FIFO Threshold interrupt */
            FLEXCOM11_REGS->FLEX_US_FIER = FLEX_US_FIER_RXFTHF_Msk;

        }
    }

    return status;
}

bool FLEXCOM11_USART_Write( void *buffer, const size_t size )
{
    bool status = false;
    uint8_t* pBuffer = (uint8_t *)buffer;

    if(pBuffer != NULL)
    {
        /* Check if transmit request is in progress */
        if(flexcom11UsartObj.txBusyStatus == false)
        {
            flexcom11UsartObj.txBuffer = (uint8_t*)pBuffer;
            flexcom11UsartObj.txSize = size;
            flexcom11UsartObj.txProcessedSize = 0;
            flexcom11UsartObj.txBusyStatus = true;
            status = true;

            /* Initiate the transfer by sending first byte */
            while( (FLEXCOM11_REGS->FLEX_US_CSR & FLEX_US_CSR_TXRDY_Msk) && (flexcom11UsartObj.txProcessedSize < flexcom11UsartObj.txSize) )
            {
                if (FLEXCOM11_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk)
                {
                    *((uint16_t*)&FLEXCOM11_REGS->FLEX_US_THR) =  ((uint16_t*)flexcom11UsartObj.txBuffer)[flexcom11UsartObj.txProcessedSize++] & FLEX_US_THR_TXCHR_Msk;
                }
                else
                {
                    *((uint8_t*)&FLEXCOM11_REGS->FLEX_US_THR) =  ((uint8_t*)flexcom11UsartObj.txBuffer)[flexcom11UsartObj.txProcessedSize++];
                }
            }

            if ( flexcom11UsartObj.txProcessedSize >= flexcom11UsartObj.txSize)
            {
                FLEXCOM11_REGS->FLEX_US_IER = FLEX_US_IER_TXEMPTY_Msk;
            }
            else
            {
                FLEXCOM11_REGS->FLEX_US_FIER = FLEX_US_FIER_TXFTHF_Msk;
            }
        }
    }

    return status;
}

void FLEXCOM11_USART_WriteCallbackRegister( FLEXCOM_USART_CALLBACK callback, uintptr_t context )
{
    flexcom11UsartObj.txCallback = callback;
    flexcom11UsartObj.txContext = context;
}

void FLEXCOM11_USART_ReadCallbackRegister( FLEXCOM_USART_CALLBACK callback, uintptr_t context )
{
    flexcom11UsartObj.rxCallback = callback;
    flexcom11UsartObj.rxContext = context;
}

bool FLEXCOM11_USART_WriteIsBusy( void )
{
    return flexcom11UsartObj.txBusyStatus;
}

bool FLEXCOM11_USART_ReadIsBusy( void )
{
    return flexcom11UsartObj.rxBusyStatus;
}

size_t FLEXCOM11_USART_WriteCountGet( void )
{
    return flexcom11UsartObj.txProcessedSize;
}

size_t FLEXCOM11_USART_ReadCountGet( void )
{
    return flexcom11UsartObj.rxProcessedSize;
}

bool FLEXCOM11_USART_ReadAbort(void)
{
    if (flexcom11UsartObj.rxBusyStatus == true)
    {
        /* Disable Read, Overrun, Parity and Framing error interrupts */
        FLEXCOM11_REGS->FLEX_US_IDR = (FLEX_US_IDR_RXRDY_Msk | FLEX_US_IDR_FRAME_Msk | FLEX_US_IDR_PARE_Msk | FLEX_US_IDR_OVRE_Msk);

        flexcom11UsartObj.rxBusyStatus = false;

        /* If required application should read the num bytes processed prior to calling the read abort API */
        flexcom11UsartObj.rxSize = flexcom11UsartObj.rxProcessedSize = 0;
    }

    return true;
}


bool FLEXCOM11_USART_TransmitComplete( void )
{
    bool status = false;

    if (FLEXCOM11_REGS->FLEX_US_CSR & FLEX_US_CSR_TXEMPTY_Msk)
    {
        status = true;
    }

    return status;
}


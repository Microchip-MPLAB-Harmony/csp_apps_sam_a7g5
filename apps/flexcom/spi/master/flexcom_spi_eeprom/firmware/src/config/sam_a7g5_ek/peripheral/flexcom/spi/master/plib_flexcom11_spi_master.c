/*******************************************************************************
  FLEXCOM11 SPI PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_flexcom11_spi_master.c

  Summary:
    FLEXCOM11 SPI Master PLIB Implementation File.

  Description:
    This file defines the interface to the FLEXCOM SPI peripheral library.
    This library provides access to and control of the associated
    peripheral instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#include "plib_flexcom11_spi_master.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: FLEXCOM11 SPI Implementation
// *****************************************************************************
// *****************************************************************************
/* Global object to save FLEXCOM SPI Exchange related data */
FLEXCOM_SPI_OBJECT flexcom11SpiObj;

void FLEXCOM11_SPI_Initialize ( void )
{
    /* Set FLEXCOM SPI operating mode */
    FLEXCOM11_REGS->FLEX_MR = FLEX_MR_OPMODE_SPI;

    /* Disable and Reset the FLEXCOM SPI */
    FLEXCOM11_REGS->FLEX_SPI_CR = FLEX_SPI_CR_SPIDIS_Msk | FLEX_SPI_CR_SWRST_Msk;

    FLEXCOM11_REGS->FLEX_SPI_CR = FLEX_SPI_CR_FIFOEN_Msk;

    /* Enable Master mode, select clock source, select particular NPCS line for chip select and disable mode fault detection */
    FLEXCOM11_REGS->FLEX_SPI_MR = FLEX_SPI_MR_MSTR_Msk | FLEX_SPI_MR_BRSRCCLK_PERIPH_CLK | FLEX_SPI_MR_DLYBCS(0) | FLEX_SPI_MR_PCS(FLEXCOM_SPI_CHIP_SELECT_NPCS0) | FLEX_SPI_MR_MODFDIS_Msk;

    /* Set up clock Polarity, data phase, Communication Width, Baud Rate */
    FLEXCOM11_REGS->FLEX_SPI_CSR[0]= FLEX_SPI_CSR_CPOL(0) | FLEX_SPI_CSR_NCPHA(1) | FLEX_SPI_CSR_BITS_8_BIT | FLEX_SPI_CSR_SCBR(200) | FLEX_SPI_CSR_DLYBS(0) | FLEX_SPI_CSR_DLYBCT(0) | FLEX_SPI_CSR_CSAAT_Msk;




    /* Initialize global variables */
    flexcom11SpiObj.transferIsBusy = false;
    flexcom11SpiObj.callback = NULL;

    /* Enable FLEXCOM11 SPI */
    FLEXCOM11_REGS->FLEX_SPI_CR = FLEX_SPI_CR_SPIEN_Msk;
    return;
}




static uint8_t FLEXCOM11_SPI_FIFO_Fill(void)
{
    uint8_t nDataCopiedToFIFO = 0;
    uint32_t dataBits = FLEXCOM11_REGS->FLEX_SPI_CSR[0] & FLEX_SPI_CSR_BITS_Msk;

    while ((nDataCopiedToFIFO < 32) && (FLEXCOM11_REGS->FLEX_SPI_SR & FLEX_SPI_SR_TDRE_Msk))
    {
        if(dataBits == FLEX_SPI_CSR_BITS_8_BIT)
        {
            if (flexcom11SpiObj.txCount < flexcom11SpiObj.txSize)
            {
                *((uint8_t*)&FLEXCOM11_REGS->FLEX_SPI_TDR) =  ((uint8_t*)flexcom11SpiObj.txBuffer)[flexcom11SpiObj.txCount++];
            }
            else if (flexcom11SpiObj.dummySize > 0)
            {
                *((uint8_t*)&FLEXCOM11_REGS->FLEX_SPI_TDR) = (uint8_t)(0xff);
                flexcom11SpiObj.dummySize--;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (flexcom11SpiObj.txCount < flexcom11SpiObj.txSize)
            {
                *((uint16_t*)&FLEXCOM11_REGS->FLEX_SPI_TDR) =  ((uint16_t*)flexcom11SpiObj.txBuffer)[flexcom11SpiObj.txCount++];
            }
            else if (flexcom11SpiObj.dummySize > 0)
            {
                *((uint16_t*)&FLEXCOM11_REGS->FLEX_SPI_TDR) = (uint16_t)(0xffff);
                flexcom11SpiObj.dummySize--;
            }
            else
            {
                break;
            }
        }

        nDataCopiedToFIFO++;
    }

    return nDataCopiedToFIFO;
}

bool FLEXCOM11_SPI_WriteRead (void* pTransmitData, size_t txSize, void* pReceiveData, size_t rxSize)
{
    bool isRequestAccepted = false;
    uint32_t nTxPending = 0;
    uint8_t rxThreshold = 0;

    /* Verify the request */
    if((((txSize > 0) && (pTransmitData != NULL)) || ((rxSize > 0) && (pReceiveData != NULL))) && (flexcom11SpiObj.transferIsBusy == false))
    {
        isRequestAccepted = true;
        flexcom11SpiObj.txBuffer = pTransmitData;
        flexcom11SpiObj.rxBuffer = pReceiveData;
        flexcom11SpiObj.rxCount = 0;
        flexcom11SpiObj.txCount = 0;
        flexcom11SpiObj.dummySize = 0;

        if (pTransmitData != NULL)
        {
            flexcom11SpiObj.txSize = txSize;
        }
        else
        {
            flexcom11SpiObj.txSize = 0;
        }

        if (pReceiveData != NULL)
        {
            flexcom11SpiObj.rxSize = rxSize;
        }
        else
        {
            flexcom11SpiObj.rxSize = 0;
        }

        flexcom11SpiObj.transferIsBusy = true;

        if (flexcom11SpiObj.rxSize > flexcom11SpiObj.txSize)
        {
            flexcom11SpiObj.dummySize = flexcom11SpiObj.rxSize - flexcom11SpiObj.txSize;
        }

        if((FLEXCOM11_REGS->FLEX_SPI_CSR[0] & FLEX_SPI_CSR_BITS_Msk) != FLEX_SPI_CSR_BITS_8_BIT)
        {
            flexcom11SpiObj.txSize >>= 1;
            flexcom11SpiObj.dummySize >>= 1;
            flexcom11SpiObj.rxSize >>= 1;
        }

        /* Clear TX and RX FIFO */
        FLEXCOM11_REGS->FLEX_SPI_CR = (FLEX_SPI_CR_RXFCLR_Msk | FLEX_SPI_CR_TXFCLR_Msk);

        nTxPending = (flexcom11SpiObj.txSize - flexcom11SpiObj.txCount) + flexcom11SpiObj.dummySize;

        if (nTxPending < 32)
        {
            rxThreshold = nTxPending;
        }
        else
        {
            rxThreshold = 32;
        }

        /* Set RX FIFO level so as to generate interrupt after all bytes are transmitted and response from slave is received for all the bytes */
        /* RX FIFO level must be set first or else FIFO may be filled before RX threshold is set and hardware may not recognize threshold crossover and not generate threshold interrupt */
        FLEXCOM11_REGS->FLEX_SPI_FMR = (FLEXCOM11_REGS->FLEX_SPI_FMR & ~FLEX_SPI_FMR_RXFTHRES_Msk) | FLEX_SPI_FMR_RXFTHRES(rxThreshold);

        (void) FLEXCOM11_SPI_FIFO_Fill();

        /* Enable RX FIFO Threshold interrupt */
        FLEXCOM11_REGS->FLEX_SPI_IER = FLEX_SPI_IER_RXFTHF_Msk;
    }

    return isRequestAccepted;
}

bool FLEXCOM11_SPI_TransferSetup (FLEXCOM_SPI_TRANSFER_SETUP * setup, uint32_t spiSourceClock )
{
    uint32_t scbr;
    if ((setup == NULL) || (setup->clockFrequency == 0))
    {
        return false;
    }
    if(spiSourceClock == 0)
    {
        // Fetch Master Clock Frequency directly
        spiSourceClock = 200000000;
    }

    scbr = spiSourceClock/setup->clockFrequency;

    if(scbr == 0)
    {
        scbr = 1;
    }
    else if(scbr > 255)
    {
        scbr = 255;
    }

    FLEXCOM11_REGS->FLEX_SPI_CSR[0]= (FLEXCOM11_REGS->FLEX_SPI_CSR[0] & ~(FLEX_SPI_CSR_CPOL_Msk | FLEX_SPI_CSR_NCPHA_Msk | FLEX_SPI_CSR_BITS_Msk | FLEX_SPI_CSR_SCBR_Msk)) | ((uint32_t)setup->clockPolarity | (uint32_t)setup->clockPhase | (uint32_t)setup->dataBits | FLEX_SPI_CSR_SCBR(scbr));

    return true;
}

bool FLEXCOM11_SPI_Write(void* pTransmitData, size_t txSize)
{
    return(FLEXCOM11_SPI_WriteRead(pTransmitData, txSize, NULL, 0));
}

bool FLEXCOM11_SPI_Read(void* pReceiveData, size_t rxSize)
{
    return(FLEXCOM11_SPI_WriteRead(NULL, 0, pReceiveData, rxSize));
}

void FLEXCOM11_SPI_CallbackRegister (FLEXCOM_SPI_CALLBACK callback, uintptr_t context)
{
    flexcom11SpiObj.callback = callback;
    flexcom11SpiObj.context = context;
}

bool FLEXCOM11_SPI_IsBusy(void)
{
    return ((flexcom11SpiObj.transferIsBusy) || ((FLEXCOM11_REGS->FLEX_SPI_SR & FLEX_SPI_SR_TXEMPTY_Msk) == 0));
}

void FLEXCOM11_InterruptHandler(void)
{
    uint32_t dataBits = FLEXCOM11_REGS->FLEX_SPI_CSR[0] & FLEX_SPI_CSR_BITS_Msk;
    uint32_t nTxPending = 0;
    uint8_t rxThreshold = 0;

    while ((FLEXCOM11_REGS->FLEX_SPI_SR & FLEX_SPI_SR_RDRF_Msk ) && (flexcom11SpiObj.rxCount < flexcom11SpiObj.rxSize))
    {
        if(dataBits == FLEX_SPI_CSR_BITS_8_BIT)
        {
            ((uint8_t*)flexcom11SpiObj.rxBuffer)[flexcom11SpiObj.rxCount++] = *((uint8_t*)&FLEXCOM11_REGS->FLEX_SPI_RDR);
        }
        else
        {
            ((uint16_t*)flexcom11SpiObj.rxBuffer)[flexcom11SpiObj.rxCount++] = *((uint16_t*)&FLEXCOM11_REGS->FLEX_SPI_RDR);
        }
    }

    /* Clear RX FIFO. This is done for the case where RX size is less than TX size and hence data is not read and copied into the application rx buffer. */
    FLEXCOM11_REGS->FLEX_SPI_CR = FLEX_SPI_CR_RXFCLR_Msk;

    nTxPending = (flexcom11SpiObj.txSize - flexcom11SpiObj.txCount) + flexcom11SpiObj.dummySize;

    if (nTxPending > 0)
    {
        if (nTxPending < 32)
        {
            rxThreshold = nTxPending;
        }
        else
        {
            rxThreshold = 32;
        }

        /* Set RX FIFO level so as to generate interrupt after all bytes are transmitted and response from slave is received for all the bytes */
        /* RX FIFO level must be set first or else FIFO may be filled before RX threshold is set and hardware may not recognize threshold crossover and not generate threshold interrupt */
        FLEXCOM11_REGS->FLEX_SPI_FMR = (FLEXCOM11_REGS->FLEX_SPI_FMR & ~FLEX_SPI_FMR_RXFTHRES_Msk) | FLEX_SPI_FMR_RXFTHRES(rxThreshold);

        (void) FLEXCOM11_SPI_FIFO_Fill();
    }
    else
    {
        /* Set Last transfer to deassert NPCS after the last byte written in TDR has been transferred. */
        FLEXCOM11_REGS->FLEX_SPI_CR = FLEX_SPI_CR_LASTXFER_Msk;

        flexcom11SpiObj.transferIsBusy = false;

        /* Disable Receive FIFO Threshold interrupt */
        FLEXCOM11_REGS->FLEX_SPI_IDR = FLEX_SPI_IDR_RXFTHF_Msk;

        if(flexcom11SpiObj.callback != NULL)
        {
            flexcom11SpiObj.callback(flexcom11SpiObj.context);
        }
    }
}


/*******************************************************************************
 End of File
*/


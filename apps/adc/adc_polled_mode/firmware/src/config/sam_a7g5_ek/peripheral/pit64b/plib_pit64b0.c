/*******************************************************************************
  Periodic Interval Timer (PIT64B0)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pit64b0.h

  Summary:
    Periodic Interval Timer (PIT64B0) PLIB.

  Description:
    This file declares the interface for the Periodic Interval Timer (PIT64B0).
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_pit64b0.h"

typedef struct
{
    PIT64B0_CALLBACK callback;
    uintptr_t context;
    volatile uint32_t tickCounter;
    bool running;
} PIT64B0_OBJECT;

static PIT64B0_OBJECT pit64b0;

void PIT64B0_TimerInitialize(void)
{
    PIT64B0_REGS->PIT64B_CR = PIT64B_CR_SWRST_Msk;
    PIT64B0_REGS->PIT64B_MR = PIT64B_MR_CONT(1) | PIT64B_MR_SGCLK(0) | PIT64B_MR_PRESCALER(0);
    PIT64B0_REGS->PIT64B_MSBPR = 0;
    PIT64B0_REGS->PIT64B_LSBPR = 200000;
    PIT64B0_REGS->PIT64B_MR |= PIT64B_MR_SMOD(0);
    pit64b0.running = 0;
    PIT64B0_REGS->PIT64B_IDR = PIT64B_IDR_Msk;
    PIT64B0_REGS->PIT64B_IER = PIT64B_IER_PERIOD(1) | PIT64B_IER_OVRE(0) | PIT64B_IER_SECE(0);
}

void PIT64B0_TimerRestart(void)
{
    PIT64B0_TimerInitialize();
    PIT64B0_TimerStart();
    pit64b0.running = 1;
}

void PIT64B0_TimerStart(void)
{
    PIT64B0_REGS->PIT64B_CR = PIT64B_CR_START_Msk;
    pit64b0.running = 1;
}

void PIT64B0_TimerStop(void)
{
    PIT64B0_TimerInitialize();
    pit64b0.running = 0;
}

void PIT64B0_TimerPeriodSet(uint64_t period)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlong-long"
    PIT64B0_REGS->PIT64B_MSBPR = (period & 0xFFFFFFFF00000000)>>32;
    PIT64B0_REGS->PIT64B_LSBPR = (period & 0xFFFFFFFF);
#pragma GCC diagnostic pop
}

uint64_t PIT64B0_TimerPeriodGet(void)
{
    uint64_t reg = PIT64B0_REGS->PIT64B_MSBPR;
    reg = reg<<32;
    reg |= PIT64B0_REGS->PIT64B_LSBPR;
    return reg;
}

uint64_t PIT64B0_TimerCounterGet(void)
{
    uint64_t reg = PIT64B0_REGS->PIT64B_TMSBR;
    reg = reg<<32;
    reg |= PIT64B0_REGS->PIT64B_TLSBR;
    return reg;
}

uint32_t PIT64B0_TimerFrequencyGet(void)
{
    return 200000000;
}

void PIT64B0_DelayMs(uint32_t delay)
{
    uint32_t tickStart;
    uint32_t delayTicks;
    uint64_t periodVal = PIT64B0_TimerPeriodGet();
    uint32_t timerFreq = 200000000;

    if (pit64b0.running && ((PIT64B0_REGS->PIT64B_IMR & PIT64B_IMR_PERIOD_Msk) == PIT64B_IMR_PERIOD_Msk)) {
        tickStart=pit64b0.tickCounter;
        delayTicks = ((timerFreq / periodVal) * delay ) / 1000;

        while((pit64b0.tickCounter-tickStart) < delayTicks);
    }
}

void PIT64B0_TimerCallbackSet(PIT64B0_CALLBACK callback, uintptr_t context)
{
    pit64b0.callback = callback;
    pit64b0.context = context;
}

void PIT64B0_InterruptHandler(void)
{
    uint32_t reg = PIT64B0_REGS->PIT64B_ISR;
    (void)reg;
    pit64b0.tickCounter++;
    if(pit64b0.callback)
        pit64b0.callback(pit64b0.context);
}
/*
 * Instance header file for ATSAMA7G54D4G
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2024-02-20T14:30:20Z */
#ifndef _SAMA7G5_TC0_INSTANCE_
#define _SAMA7G5_TC0_INSTANCE_


/* ========== Instance Parameter definitions for TC0 peripheral ========== */
#define TC0_CLOCK_ID_CHANNEL0                    (88)       
#define TC0_CLOCK_ID_CHANNEL1                    (89)       
#define TC0_CLOCK_ID_CHANNEL2                    (90)       
#define TC0_DMAC_ID_RX                           (51)       
#define TC0_INSTANCE_ID_CHANNEL0                 (88)       /* 32-bit Timer Counter 0 Channel 0 */
#define TC0_INSTANCE_ID_CHANNEL1                 (89)       /* 32-bit Timer Counter 0 Channel 1 interrupt */
#define TC0_INSTANCE_ID_CHANNEL2                 (90)       /* 32-bit Timer Counter 0 Channel 2 interrupt */
#define TC0_INSTANCE_ID_SINT0                    (145)      /* 32-bit Timer Counter 0 Channel 0, Secure INTerrupt */
#define TC0_INSTANCE_ID_SINT1                    (146)      /* 32-bit Timer Counter 0 Channel 1, Secure INTerrupt */
#define TC0_INSTANCE_ID_SINT2                    (147)      /* 32-bit Timer Counter 0 Channel 2 */
#define TC0_NUM_INTERRUPT_LINES                  (3)        
#define TC0_TCCLKS_                              (0)        /* MCK1 */
#define TC0_TCCLKS_TIMER_CLOCK1                  (1)        /* GCLK */
#define TC0_TCCLKS_TIMER_CLOCK2                  (2)        /* MCK1/8 */
#define TC0_TCCLKS_TIMER_CLOCK3                  (3)        /* MCK1/32 */
#define TC0_TCCLKS_TIMER_CLOCK4                  (4)        /* MCK1/128 */
#define TC0_TCCLKS_TIMER_CLOCK5                  (5)        /* TD_SLCK */
#define TC0_TCCLKS_XC0                           (6)        /* XC0 */
#define TC0_TCCLKS_XC1                           (7)        /* XC1 */
#define TC0_TCCLKS_XC2                           (8)        /* XC2 */
#define TC0_TIMER_WIDTH                          (32)       

#endif /* _SAMA7G5_TC0_INSTANCE_ */

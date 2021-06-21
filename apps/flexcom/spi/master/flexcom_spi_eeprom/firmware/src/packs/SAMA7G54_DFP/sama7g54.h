/**
 * \brief Header file for SAMA7G54
 *
 * Copyright (c) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2021-05-08T21:15:36Z */
#ifndef _SAMA7G54_H_
#define _SAMA7G54_H_

// Header version uses Semantic Versioning 2.0.0 (https://semver.org/)
#define HEADER_FORMAT_VERSION "2.0.0"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (0)

/** \addtogroup SAMA7G54_definitions SAMA7G54 definitions
  This file defines all structures and symbols for SAMA7G54:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
 *  @{
 */

#ifdef __cplusplus
 extern "C" {
#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  include <stdint.h>
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !defined(SKIP_INTEGER_LITERALS)
#  if defined(_U_) || defined(_L_) || defined(_UL_)
#    error "Integer Literals macros already defined elsewhere"
#  endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with adding suffixes to integer literal constants for C/C++ */
#  define _U_(x) (x ## U)    /**< C code: Unsigned integer literal constant value */
#  define _L_(x) (x ## L)    /**< C code: Long integer literal constant value */
#  define _UL_(x) (x ## UL)  /**< C code: Unsigned Long integer literal constant value */

#else /* Assembler */

#  define _U_(x) x    /**< Assembler: Unsigned integer literal constant value */
#  define _L_(x) x    /**< Assembler: Long integer literal constant value */
#  define _UL_(x) x   /**< Assembler: Unsigned Long integer literal constant value */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* SKIP_INTEGER_LITERALS */
/** @}  end of Atmel Global Defines */

/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR SAMA7G54                                           */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-A7 Processor Exceptions Numbers ******************************/
/******  SAMA7G54 specific Interrupt Numbers ***********************************/
  SGI0_IRQn                 =   0, /**< 0   SGI0 (ARM)                          */
  SGI1_IRQn                 =   1, /**< 1   SGI1 (ARM)                          */
  SGI2_IRQn                 =   2, /**< 2   SGI2 (ARM)                          */
  SGI3_IRQn                 =   3, /**< 3   SGI3 (ARM)                          */
  SGI4_IRQn                 =   4, /**< 4   SGI4 (ARM)                          */
  SGI5_IRQn                 =   5, /**< 5   SGI5 (ARM)                          */
  SGI6_IRQn                 =   6, /**< 6   SGI6 (ARM)                          */
  SGI7_IRQn                 =   7, /**< 7   SGI7 (ARM)                          */
  SGI8_IRQn                 =   8, /**< 8   SGI8 (ARM)                          */
  SGI9_IRQn                 =   9, /**< 9   SGI9 (ARM)                          */
  SGI10_IRQn                =  10, /**< 10  SGI10 (ARM)                         */
  SGI11_IRQn                =  11, /**< 11  SGI11 (ARM)                         */
  SGI12_IRQn                =  12, /**< 12  SGI12 (ARM)                         */
  SGI13_IRQn                =  13, /**< 13  SGI13 (ARM)                         */
  SGI14_IRQn                =  14, /**< 14  SGI14 (ARM)                         */
  SGI15_IRQn                =  15, /**< 15  SGI15 (ARM)                         */
  LegacynFIQ_IRQn           =  28, /**< 28  LegacynFIQ (ARM)                    */
  SecPhysTimer_IRQn         =  29, /**< 29  SecPhysTimer (ARM)                  */
  NonSecPhysTimer_IRQn      =  30, /**< 30  NonSecPhysTimer (ARM)               */
  LegacynIRQ_IRQn           =  31, /**< 31  LegacynIRQ (ARM)                    */
  VirtTimer_IRQn            =  27, /**< 27  VirtTimer (ARM)                     */
  HyperVTimer_IRQn          =  26, /**< 26  HyperVTimer (ARM)                   */
  VirtMaint_IRQn            =  25, /**< 25  VirtMaint (ARM)                     */
  DWDT_SW_IRQn              =  32, /**< 32  Dual Watchdog Timer (DWDT)          */
  DWDT_NSW_IRQn             =  33, /**< 33  Dual Watchdog Timer (DWDT)          */
  DWDT_NSW_ALARM_IRQn       =  34, /**< 34  Dual Watchdog Timer (DWDT)          */
  SCKC_IRQn                 =  36, /**< 36  Slow Clock Controller (SCKC)        */
  SHDWC_IRQn                =  37, /**< 37  Shutdown Controller (SHDWC)         */
  RSTC_IRQn                 =  38, /**< 38  Reset Controller (RSTC)             */
  RTC_IRQn                  =  39, /**< 39  Real-time Clock (RTC)               */
  RTT_IRQn                  =  40, /**< 40  Real-time Timer (RTT)               */
  PMC_IRQn                  =  42, /**< 42  Power Management Controller (PMC)   */
  PIOA_IRQn                 =  43, /**< 43  Parallel Input/Output Controller (PIOA) */
  PIOB_IRQn                 =  44, /**< 44  Parallel Input/Output Controller (PIOB) */
  PIOC_IRQn                 =  45, /**< 45  Parallel Input/Output Controller (PIOC) */
  PIOD_IRQn                 =  46, /**< 46  Parallel Input/Output Controller (PIOD) */
  PIOE_IRQn                 =  47, /**< 47  Parallel Input/Output Controller (PIOE) */
  SECUMOD_IRQn              =  49, /**< 49  Security Module (SECUMOD)           */
  SECURAM_IRQn              =  50, /**< 50   (SECURAM)                          */
  SFR_IRQn                  =  51, /**< 51  Special Function Register (SFR)     */
  HSMC_IRQn                 =  53, /**< 53  Static Memory Controller (HSMC)     */
  XDMAC0_IRQn               =  54, /**< 54  Extensible DMA Controller (XDMAC0)  */
  XDMAC1_IRQn               =  55, /**< 55  Extensible DMA Controller (XDMAC1)  */
  XDMAC2_IRQn               =  56, /**< 56  Extensible DMA Controller (XDMAC2)  */
  ACC_IRQn                  =  57, /**< 57  Analog Comparator Controller (ACC)  */
  ADC_IRQn                  =  58, /**< 58  Analog-to-Digital Converter (ADC)   */
  AES_IRQn                  =  59, /**< 59  Advanced Encryption Standard (AES)  */
  ARM_IRQn                  =  61, /**< 61  ARM (ARM)                           */
  ASRC_IRQn                 =  62, /**< 62  Asynchronous Sample Rate Converter (ASRC) */
  CPKCC_IRQn                =  64, /**< 64  Classic Public Key Cryptography Controller (CPKCC) */
  CSI_IRQn                  =  65, /**< 65  Camera Serial Interface 2 Controller and MIPI PHY (CSI) */
  CSI2DC_IRQn               =  66, /**< 66  CSI-2 Demultiplexer Controller (CSI2DC) */
  FLEXCOM0_IRQn             =  70, /**< 70  Flexible Serial Communication (FLEXCOM0) */
  FLEXCOM1_IRQn             =  71, /**< 71  Flexible Serial Communication (FLEXCOM1) */
  FLEXCOM2_IRQn             =  72, /**< 72  Flexible Serial Communication (FLEXCOM2) */
  FLEXCOM3_IRQn             =  73, /**< 73  Flexible Serial Communication (FLEXCOM3) */
  FLEXCOM4_IRQn             =  74, /**< 74  Flexible Serial Communication (FLEXCOM4) */
  FLEXCOM5_IRQn             =  75, /**< 75  Flexible Serial Communication (FLEXCOM5) */
  FLEXCOM6_IRQn             =  76, /**< 76  Flexible Serial Communication (FLEXCOM6) */
  FLEXCOM7_IRQn             =  77, /**< 77  Flexible Serial Communication (FLEXCOM7) */
  FLEXCOM8_IRQn             =  78, /**< 78  Flexible Serial Communication (FLEXCOM8) */
  FLEXCOM9_IRQn             =  79, /**< 79  Flexible Serial Communication (FLEXCOM9) */
  FLEXCOM10_IRQn            =  80, /**< 80  Flexible Serial Communication (FLEXCOM10) */
  FLEXCOM11_IRQn            =  81, /**< 81  Flexible Serial Communication (FLEXCOM11) */
  GMAC0_IRQn                =  83, /**< 83  Gigabit Ethernet MAC (GMAC0)        */
  GMAC1_IRQn                =  84, /**< 84  Gigabit Ethernet MAC (GMAC1)        */
  GMAC0_TSU_IRQn            =  85, /**< 85  Gigabit Ethernet MAC (GMAC0)        */
  GMAC1_TSU_IRQn            =  86, /**< 86  Gigabit Ethernet MAC (GMAC1)        */
  ICM_IRQn                  =  87, /**< 87  Integrity Check Monitor (ICM)       */
  ISC_IRQn                  =  88, /**< 88  Image Sensor Controller (ISC)       */
  I2SMCC0_IRQn              =  89, /**< 89  Inter-IC Sound Multi Channel Controller (I2SMCC0) */
  I2SMCC1_IRQn              =  90, /**< 90  Inter-IC Sound Multi Channel Controller (I2SMCC1) */
  MATRIX_IRQn               =  92, /**< 92  AHB Bus Matrix (MATRIX)             */
  MCAN0_INT0_IRQn           =  93, /**< 93  Controller Area Network (MCAN0)     */
  MCAN1_INT0_IRQn           =  94, /**< 94  Controller Area Network (MCAN1)     */
  MCAN2_INT0_IRQn           =  95, /**< 95  Controller Area Network (MCAN2)     */
  MCAN3_INT0_IRQn           =  96, /**< 96  Controller Area Network (MCAN3)     */
  MCAN4_INT0_IRQn           =  97, /**< 97  Controller Area Network (MCAN4)     */
  MCAN5_INT0_IRQn           =  98, /**< 98  Controller Area Network (MCAN5)     */
  OTPC_IRQn                 =  99, /**< 99  OTP Memory Controller (OTPC)        */
  PDMC0_IRQn                = 100, /**< 100 Pulse Density Microphone Controller (PDMC0) */
  PDMC1_IRQn                = 101, /**< 101 Pulse Density Microphone Controller (PDMC1) */
  PIT64B0_IRQn              = 102, /**< 102 Periodic Interval Timer 64-bit (PIT64B0) */
  PIT64B1_IRQn              = 103, /**< 103 Periodic Interval Timer 64-bit (PIT64B1) */
  PIT64B2_IRQn              = 104, /**< 104 Periodic Interval Timer 64-bit (PIT64B2) */
  PIT64B3_IRQn              = 105, /**< 105 Periodic Interval Timer 64-bit (PIT64B3) */
  PIT64B4_IRQn              = 106, /**< 106 Periodic Interval Timer 64-bit (PIT64B4) */
  PIT64B5_IRQn              = 107, /**< 107 Periodic Interval Timer 64-bit (PIT64B5) */
  PWM_IRQn                  = 109, /**< 109 Pulse Width Modulation Controller (PWM) */
  QSPI0_IRQn                = 110, /**< 110 Quad Serial Peripheral Interface (QSPI0) */
  QSPI1_IRQn                = 111, /**< 111 Quad Serial Peripheral Interface (QSPI1) */
  SDMMC0_IRQn               = 112, /**< 112 Secure Digital MultiMedia Card Controller (SDMMC0) */
  SDMMC1_IRQn               = 113, /**< 113 Secure Digital MultiMedia Card Controller (SDMMC1) */
  SDMMC2_IRQn               = 114, /**< 114 Secure Digital MultiMedia Card Controller (SDMMC2) */
  SHA_IRQn                  = 115, /**< 115 Secure Hash Algorithm (SHA)         */
  SPDIFRX_IRQn              = 116, /**< 116 Sony/Philips Digital Interface Receiver (SPDIFRX) */
  SPDIFTX_IRQn              = 117, /**< 117 Sony/Philips Digital Interface (SPDIFTX) */
  SSC0_IRQn                 = 118, /**< 118 Synchronous Serial Controller (SSC0) */
  SSC1_IRQn                 = 119, /**< 119 Synchronous Serial Controller (SSC1) */
  TC0_CH0_IRQn              = 120, /**< 120 Timer Counter (TC0)                 */
  TC0_CH1_IRQn              = 121, /**< 121 Timer Counter (TC0)                 */
  TC0_CH2_IRQn              = 122, /**< 122 Timer Counter (TC0)                 */
  TC1_CH0_IRQn              = 123, /**< 123 Timer Counter (TC1)                 */
  TC1_CH1_IRQn              = 124, /**< 124 Timer Counter (TC1)                 */
  TC1_CH2_IRQn              = 125, /**< 125 Timer Counter (TC1)                 */
  TCPCA_IRQn                = 126, /**< 126 Battery Charging and Type-C Port Controller (TCPCA) */
  TCPCB_IRQn                = 127, /**< 127 Battery Charging and Type-C Port Controller (TCPCB) */
  TDES_IRQn                 = 128, /**< 128 Triple Data Encryption Standard (TDES) */
  TRNG_IRQn                 = 129, /**< 129 True Random Number Generator (TRNG) */
  TZAESB_NS_IRQn            = 130, /**< 130 TrustZone Advanced Encryption Standard Bridge (TZAESB) */
  TZAESB_NS_SINT_IRQn       = 131, /**< 131 TrustZone Advanced Encryption Standard Bridge (TZAESB) */
  TZAESB_S_IRQn             = 132, /**< 132 TrustZone Advanced Encryption Standard Bridge (TZAESB) */
  TZAESB_S_SINT_IRQn        = 133, /**< 133 TrustZone Advanced Encryption Standard Bridge (TZAESB) */
  TZC_IRQn                  = 134, /**< 134 TrustZone Address Space Controller (TZC) */
  TZPM_IRQn                 = 135, /**< 135 System Interconnect and Security (TZPM) */
  UDPHSA_IRQn               = 136, /**< 136 USB High Speed Device Port (UDPHSA) */
  UDPHSB_IRQn               = 137, /**< 137 USB High Speed Device Port (UDPHSB) */
  UHPHS_IRQn                = 138, /**< 138 USB Host High Speed Port (UHPHS)    */
  ARM_NPMUIRQ_IRQn          = 142, /**< 142 ARM_NPMUIRQ (ARM)                   */
  ARM_NAXIERRIRQ_IRQn       = 143, /**< 143 ARM_NAXIERRIRQ (ARM)                */
  XDMAC0_SINT_IRQn          = 144, /**< 144 Extensible DMA Controller (XDMAC0)  */
  XDMAC1_SINT_IRQn          = 145, /**< 145 Extensible DMA Controller (XDMAC1)  */
  XDMAC2_SINT_IRQn          = 146, /**< 146 Extensible DMA Controller (XDMAC2)  */
  AES_SINT_IRQn             = 147, /**< 147 Advanced Encryption Standard (AES)  */
  GMAC0_Q1_IRQn             = 148, /**< 148 Gigabit Ethernet MAC (GMAC0)        */
  GMAC0_Q2_IRQn             = 149, /**< 149 Gigabit Ethernet MAC (GMAC0)        */
  GMAC0_Q3_IRQn             = 150, /**< 150 Gigabit Ethernet MAC (GMAC0)        */
  GMAC0_Q4_IRQn             = 151, /**< 151 Gigabit Ethernet MAC (GMAC0)        */
  GMAC0_Q5_IRQn             = 152, /**< 152 Gigabit Ethernet MAC (GMAC0)        */
  GMAC1_Q1_IRQn             = 153, /**< 153 Gigabit Ethernet MAC (GMAC1)        */
  ICM_SINT_IRQn             = 154, /**< 154 Integrity Check Monitor (ICM)       */
  MCAN0_INT1_IRQn           = 155, /**< 155 Controller Area Network (MCAN0)     */
  MCAN1_INT1_IRQn           = 156, /**< 156 Controller Area Network (MCAN1)     */
  MCAN2_INT1_IRQn           = 157, /**< 157 Controller Area Network (MCAN2)     */
  MCAN3_INT1_IRQn           = 158, /**< 158 Controller Area Network (MCAN3)     */
  MCAN4_INT1_IRQn           = 159, /**< 159 Controller Area Network (MCAN4)     */
  MCAN5_INT1_IRQn           = 160, /**< 160 Controller Area Network (MCAN5)     */
  PIOA_SINT_IRQn            = 161, /**< 161 Parallel Input/Output Controller (PIOA) */
  PIOB_SINT_IRQn            = 162, /**< 162 Parallel Input/Output Controller (PIOB) */
  PIOC_SINT_IRQn            = 163, /**< 163 Parallel Input/Output Controller (PIOC) */
  PIOD_SINT_IRQn            = 164, /**< 164 Parallel Input/Output Controller (PIOD) */
  PIOE_SINT_IRQn            = 165, /**< 165 Parallel Input/Output Controller (PIOE) */
  PIT64B0_SINT_IRQn         = 167, /**< 167 Periodic Interval Timer 64-bit (PIT64B0) */
  PIT64B1_SINT_IRQn         = 168, /**< 168 Periodic Interval Timer 64-bit (PIT64B1) */
  PIT64B2_SINT_IRQn         = 169, /**< 169 Periodic Interval Timer 64-bit (PIT64B2) */
  PIT64B3_SINT_IRQn         = 170, /**< 170 Periodic Interval Timer 64-bit (PIT64B3) */
  PIT64B4_SINT_IRQn         = 171, /**< 171 Periodic Interval Timer 64-bit (PIT64B4) */
  PIT64B5_SINT_IRQn         = 172, /**< 172 Periodic Interval Timer 64-bit (PIT64B5) */
  SDMMC0_TIMER_IRQn         = 173, /**< 173 Secure Digital MultiMedia Card Controller (SDMMC0) */
  SDMMC1_TIMER_IRQn         = 174, /**< 174 Secure Digital MultiMedia Card Controller (SDMMC1) */
  SDMMC2_TIMER_IRQn         = 175, /**< 175 Secure Digital MultiMedia Card Controller (SDMMC2) */
  SHA_SINT_IRQn             = 176, /**< 176 Secure Hash Algorithm (SHA)         */
  TC0_SINT0_IRQn            = 177, /**< 177 Timer Counter (TC0)                 */
  TC0_SINT1_IRQn            = 178, /**< 178 Timer Counter (TC0)                 */
  TC0_SINT2_IRQn            = 179, /**< 179 Timer Counter (TC0)                 */
  TC1_SINT0_IRQn            = 180, /**< 180 Timer Counter (TC1)                 */
  TC1_SINT1_IRQn            = 181, /**< 181 Timer Counter (TC1)                 */
  TC1_SINT2_IRQn            = 182, /**< 182 Timer Counter (TC1)                 */
  TDES_SINT_IRQn            = 183, /**< 183 Triple Data Encryption Standard (TDES) */
  TRNG_SINT_IRQn            = 184, /**< 184 True Random Number Generator (TRNG) */
  EIC_EXT_IRQ0_IRQn         = 185, /**< 185 External Interrupt Controller (EIC) */
  EIC_EXT_IRQ1_IRQn         = 186, /**< 186 External Interrupt Controller (EIC) */

  PERIPH_MAX_IRQn           = 186  /**< Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-A7 handlers */
  void* pvReservedC15;
  void* pvReservedC14;
  void* pvReservedC13;
  void* pvReservedC12;
  void* pvReservedC11;
  void* pvReservedC10;
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pvReservedC5;
  void* pvReservedC4;
  void* pvReservedC3;
  void* pvReservedC2;
  void* pvReservedC1;

  /* Peripheral handlers */
  void* pvReserved0;
  void* pvReserved1;
  void* pvReserved2;
  void* pvReserved3;
  void* pvReserved4;
  void* pvReserved5;
  void* pvReserved6;
  void* pvReserved7;
  void* pvReserved8;
  void* pvReserved9;
  void* pvReserved10;
  void* pvReserved11;
  void* pvReserved12;
  void* pvReserved13;
  void* pvReserved14;
  void* pvReserved15;
  void* pvReserved16;
  void* pvReserved17;
  void* pvReserved18;
  void* pvReserved19;
  void* pvReserved20;
  void* pvReserved21;
  void* pvReserved22;
  void* pvReserved23;
  void* pvReserved24;
  void* pvReserved25;
  void* pvReserved26;
  void* pvReserved27;
  void* pvReserved28;
  void* pvReserved29;
  void* pvReserved30;
  void* pvReserved31;
  void* pfnDWDT_SW_Handler;                      /*  32 Dual Watchdog Timer (DWDT) */
  void* pfnDWDT_NSW_Handler;                     /*  33 Dual Watchdog Timer (DWDT) */
  void* pfnDWDT_NSW_ALARM_Handler;               /*  34 Dual Watchdog Timer (DWDT) */
  void* pvReserved35;
  void* pfnSCKC_Handler;                         /*  36 Slow Clock Controller (SCKC) */
  void* pfnSHDWC_Handler;                        /*  37 Shutdown Controller (SHDWC) */
  void* pfnRSTC_Handler;                         /*  38 Reset Controller (RSTC) */
  void* pfnRTC_Handler;                          /*  39 Real-time Clock (RTC) */
  void* pfnRTT_Handler;                          /*  40 Real-time Timer (RTT) */
  void* pvReserved41;
  void* pfnPMC_Handler;                          /*  42 Power Management Controller (PMC) */
  void* pfnPIOA_Handler;                         /*  43 Parallel Input/Output Controller (PIOA) */
  void* pfnPIOB_Handler;                         /*  44 Parallel Input/Output Controller (PIOB) */
  void* pfnPIOC_Handler;                         /*  45 Parallel Input/Output Controller (PIOC) */
  void* pfnPIOD_Handler;                         /*  46 Parallel Input/Output Controller (PIOD) */
  void* pfnPIOE_Handler;                         /*  47 Parallel Input/Output Controller (PIOE) */
  void* pvReserved48;
  void* pfnSECUMOD_Handler;                      /*  49 Security Module (SECUMOD) */
  void* pfnSECURAM_Handler;                      /*  50  (SECURAM) */
  void* pfnSFR_Handler;                          /*  51 Special Function Register (SFR) */
  void* pvReserved52;
  void* pfnHSMC_Handler;                         /*  53 Static Memory Controller (HSMC) */
  void* pfnXDMAC0_Handler;                       /*  54 Extensible DMA Controller (XDMAC0) */
  void* pfnXDMAC1_Handler;                       /*  55 Extensible DMA Controller (XDMAC1) */
  void* pfnXDMAC2_Handler;                       /*  56 Extensible DMA Controller (XDMAC2) */
  void* pfnACC_Handler;                          /*  57 Analog Comparator Controller (ACC) */
  void* pfnADC_Handler;                          /*  58 Analog-to-Digital Converter (ADC) */
  void* pfnAES_Handler;                          /*  59 Advanced Encryption Standard (AES) */
  void* pvReserved60;
  void* pvReserved61;
  void* pfnASRC_Handler;                         /*  62 Asynchronous Sample Rate Converter (ASRC) */
  void* pvReserved63;
  void* pfnCPKCC_Handler;                        /*  64 Classic Public Key Cryptography Controller (CPKCC) */
  void* pfnCSI_Handler;                          /*  65 Camera Serial Interface 2 Controller and MIPI PHY (CSI) */
  void* pfnCSI2DC_Handler;                       /*  66 CSI-2 Demultiplexer Controller (CSI2DC) */
  void* pvReserved67;
  void* pvReserved68;
  void* pvReserved69;
  void* pfnFLEXCOM0_Handler;                     /*  70 Flexible Serial Communication (FLEXCOM0) */
  void* pfnFLEXCOM1_Handler;                     /*  71 Flexible Serial Communication (FLEXCOM1) */
  void* pfnFLEXCOM2_Handler;                     /*  72 Flexible Serial Communication (FLEXCOM2) */
  void* pfnFLEXCOM3_Handler;                     /*  73 Flexible Serial Communication (FLEXCOM3) */
  void* pfnFLEXCOM4_Handler;                     /*  74 Flexible Serial Communication (FLEXCOM4) */
  void* pfnFLEXCOM5_Handler;                     /*  75 Flexible Serial Communication (FLEXCOM5) */
  void* pfnFLEXCOM6_Handler;                     /*  76 Flexible Serial Communication (FLEXCOM6) */
  void* pfnFLEXCOM7_Handler;                     /*  77 Flexible Serial Communication (FLEXCOM7) */
  void* pfnFLEXCOM8_Handler;                     /*  78 Flexible Serial Communication (FLEXCOM8) */
  void* pfnFLEXCOM9_Handler;                     /*  79 Flexible Serial Communication (FLEXCOM9) */
  void* pfnFLEXCOM10_Handler;                    /*  80 Flexible Serial Communication (FLEXCOM10) */
  void* pfnFLEXCOM11_Handler;                    /*  81 Flexible Serial Communication (FLEXCOM11) */
  void* pvReserved82;
  void* pfnGMAC0_Handler;                        /*  83 Gigabit Ethernet MAC (GMAC0) */
  void* pfnGMAC1_Handler;                        /*  84 Gigabit Ethernet MAC (GMAC1) */
  void* pfnGMAC0_TSU_Handler;                    /*  85 Gigabit Ethernet MAC (GMAC0) */
  void* pfnGMAC1_TSU_Handler;                    /*  86 Gigabit Ethernet MAC (GMAC1) */
  void* pfnICM_Handler;                          /*  87 Integrity Check Monitor (ICM) */
  void* pfnISC_Handler;                          /*  88 Image Sensor Controller (ISC) */
  void* pfnI2SMCC0_Handler;                      /*  89 Inter-IC Sound Multi Channel Controller (I2SMCC0) */
  void* pfnI2SMCC1_Handler;                      /*  90 Inter-IC Sound Multi Channel Controller (I2SMCC1) */
  void* pvReserved91;
  void* pfnMATRIX_Handler;                       /*  92 AHB Bus Matrix (MATRIX) */
  void* pfnMCAN0_INT0_Handler;                   /*  93 Controller Area Network (MCAN0) */
  void* pfnMCAN1_INT0_Handler;                   /*  94 Controller Area Network (MCAN1) */
  void* pfnMCAN2_INT0_Handler;                   /*  95 Controller Area Network (MCAN2) */
  void* pfnMCAN3_INT0_Handler;                   /*  96 Controller Area Network (MCAN3) */
  void* pfnMCAN4_INT0_Handler;                   /*  97 Controller Area Network (MCAN4) */
  void* pfnMCAN5_INT0_Handler;                   /*  98 Controller Area Network (MCAN5) */
  void* pfnOTPC_Handler;                         /*  99 OTP Memory Controller (OTPC) */
  void* pfnPDMC0_Handler;                        /* 100 Pulse Density Microphone Controller (PDMC0) */
  void* pfnPDMC1_Handler;                        /* 101 Pulse Density Microphone Controller (PDMC1) */
  void* pfnPIT64B0_Handler;                      /* 102 Periodic Interval Timer 64-bit (PIT64B0) */
  void* pfnPIT64B1_Handler;                      /* 103 Periodic Interval Timer 64-bit (PIT64B1) */
  void* pfnPIT64B2_Handler;                      /* 104 Periodic Interval Timer 64-bit (PIT64B2) */
  void* pfnPIT64B3_Handler;                      /* 105 Periodic Interval Timer 64-bit (PIT64B3) */
  void* pfnPIT64B4_Handler;                      /* 106 Periodic Interval Timer 64-bit (PIT64B4) */
  void* pfnPIT64B5_Handler;                      /* 107 Periodic Interval Timer 64-bit (PIT64B5) */
  void* pvReserved108;
  void* pfnPWM_Handler;                          /* 109 Pulse Width Modulation Controller (PWM) */
  void* pfnQSPI0_Handler;                        /* 110 Quad Serial Peripheral Interface (QSPI0) */
  void* pfnQSPI1_Handler;                        /* 111 Quad Serial Peripheral Interface (QSPI1) */
  void* pfnSDMMC0_Handler;                       /* 112 Secure Digital MultiMedia Card Controller (SDMMC0) */
  void* pfnSDMMC1_Handler;                       /* 113 Secure Digital MultiMedia Card Controller (SDMMC1) */
  void* pfnSDMMC2_Handler;                       /* 114 Secure Digital MultiMedia Card Controller (SDMMC2) */
  void* pfnSHA_Handler;                          /* 115 Secure Hash Algorithm (SHA) */
  void* pfnSPDIFRX_Handler;                      /* 116 Sony/Philips Digital Interface Receiver (SPDIFRX) */
  void* pfnSPDIFTX_Handler;                      /* 117 Sony/Philips Digital Interface (SPDIFTX) */
  void* pfnSSC0_Handler;                         /* 118 Synchronous Serial Controller (SSC0) */
  void* pfnSSC1_Handler;                         /* 119 Synchronous Serial Controller (SSC1) */
  void* pfnTC0_CH0_Handler;                      /* 120 Timer Counter (TC0) */
  void* pfnTC0_CH1_Handler;                      /* 121 Timer Counter (TC0) */
  void* pfnTC0_CH2_Handler;                      /* 122 Timer Counter (TC0) */
  void* pfnTC1_CH0_Handler;                      /* 123 Timer Counter (TC1) */
  void* pfnTC1_CH1_Handler;                      /* 124 Timer Counter (TC1) */
  void* pfnTC1_CH2_Handler;                      /* 125 Timer Counter (TC1) */
  void* pfnTCPCA_Handler;                        /* 126 Battery Charging and Type-C Port Controller (TCPCA) */
  void* pfnTCPCB_Handler;                        /* 127 Battery Charging and Type-C Port Controller (TCPCB) */
  void* pfnTDES_Handler;                         /* 128 Triple Data Encryption Standard (TDES) */
  void* pfnTRNG_Handler;                         /* 129 True Random Number Generator (TRNG) */
  void* pfnTZAESB_NS_Handler;                    /* 130 TrustZone Advanced Encryption Standard Bridge (TZAESB) */
  void* pfnTZAESB_NS_SINT_Handler;               /* 131 TrustZone Advanced Encryption Standard Bridge (TZAESB) */
  void* pfnTZAESB_S_Handler;                     /* 132 TrustZone Advanced Encryption Standard Bridge (TZAESB) */
  void* pfnTZAESB_S_SINT_Handler;                /* 133 TrustZone Advanced Encryption Standard Bridge (TZAESB) */
  void* pfnTZC_Handler;                          /* 134 TrustZone Address Space Controller (TZC) */
  void* pfnTZPM_Handler;                         /* 135 System Interconnect and Security (TZPM) */
  void* pfnUDPHSA_Handler;                       /* 136 USB High Speed Device Port (UDPHSA) */
  void* pfnUDPHSB_Handler;                       /* 137 USB High Speed Device Port (UDPHSB) */
  void* pfnUHPHS_Handler;                        /* 138 USB Host High Speed Port (UHPHS) */
  void* pvReserved139;
  void* pvReserved140;
  void* pvReserved141;
  void* pvReserved142;
  void* pvReserved143;
  void* pfnXDMAC0_SINT_Handler;                  /* 144 Extensible DMA Controller (XDMAC0) */
  void* pfnXDMAC1_SINT_Handler;                  /* 145 Extensible DMA Controller (XDMAC1) */
  void* pfnXDMAC2_SINT_Handler;                  /* 146 Extensible DMA Controller (XDMAC2) */
  void* pfnAES_SINT_Handler;                     /* 147 Advanced Encryption Standard (AES) */
  void* pfnGMAC0_Q1_Handler;                     /* 148 Gigabit Ethernet MAC (GMAC0) */
  void* pfnGMAC0_Q2_Handler;                     /* 149 Gigabit Ethernet MAC (GMAC0) */
  void* pfnGMAC0_Q3_Handler;                     /* 150 Gigabit Ethernet MAC (GMAC0) */
  void* pfnGMAC0_Q4_Handler;                     /* 151 Gigabit Ethernet MAC (GMAC0) */
  void* pfnGMAC0_Q5_Handler;                     /* 152 Gigabit Ethernet MAC (GMAC0) */
  void* pfnGMAC1_Q1_Handler;                     /* 153 Gigabit Ethernet MAC (GMAC1) */
  void* pfnICM_SINT_Handler;                     /* 154 Integrity Check Monitor (ICM) */
  void* pfnMCAN0_INT1_Handler;                   /* 155 Controller Area Network (MCAN0) */
  void* pfnMCAN1_INT1_Handler;                   /* 156 Controller Area Network (MCAN1) */
  void* pfnMCAN2_INT1_Handler;                   /* 157 Controller Area Network (MCAN2) */
  void* pfnMCAN3_INT1_Handler;                   /* 158 Controller Area Network (MCAN3) */
  void* pfnMCAN4_INT1_Handler;                   /* 159 Controller Area Network (MCAN4) */
  void* pfnMCAN5_INT1_Handler;                   /* 160 Controller Area Network (MCAN5) */
  void* pfnPIOA_SINT_Handler;                    /* 161 Parallel Input/Output Controller (PIOA) */
  void* pfnPIOB_SINT_Handler;                    /* 162 Parallel Input/Output Controller (PIOB) */
  void* pfnPIOC_SINT_Handler;                    /* 163 Parallel Input/Output Controller (PIOC) */
  void* pfnPIOD_SINT_Handler;                    /* 164 Parallel Input/Output Controller (PIOD) */
  void* pfnPIOE_SINT_Handler;                    /* 165 Parallel Input/Output Controller (PIOE) */
  void* pvReserved166;
  void* pfnPIT64B0_SINT_Handler;                 /* 167 Periodic Interval Timer 64-bit (PIT64B0) */
  void* pfnPIT64B1_SINT_Handler;                 /* 168 Periodic Interval Timer 64-bit (PIT64B1) */
  void* pfnPIT64B2_SINT_Handler;                 /* 169 Periodic Interval Timer 64-bit (PIT64B2) */
  void* pfnPIT64B3_SINT_Handler;                 /* 170 Periodic Interval Timer 64-bit (PIT64B3) */
  void* pfnPIT64B4_SINT_Handler;                 /* 171 Periodic Interval Timer 64-bit (PIT64B4) */
  void* pfnPIT64B5_SINT_Handler;                 /* 172 Periodic Interval Timer 64-bit (PIT64B5) */
  void* pfnSDMMC0_TIMER_Handler;                 /* 173 Secure Digital MultiMedia Card Controller (SDMMC0) */
  void* pfnSDMMC1_TIMER_Handler;                 /* 174 Secure Digital MultiMedia Card Controller (SDMMC1) */
  void* pfnSDMMC2_TIMER_Handler;                 /* 175 Secure Digital MultiMedia Card Controller (SDMMC2) */
  void* pfnSHA_SINT_Handler;                     /* 176 Secure Hash Algorithm (SHA) */
  void* pfnTC0_SINT0_Handler;                    /* 177 Timer Counter (TC0) */
  void* pfnTC0_SINT1_Handler;                    /* 178 Timer Counter (TC0) */
  void* pfnTC0_SINT2_Handler;                    /* 179 Timer Counter (TC0) */
  void* pfnTC1_SINT0_Handler;                    /* 180 Timer Counter (TC1) */
  void* pfnTC1_SINT1_Handler;                    /* 181 Timer Counter (TC1) */
  void* pfnTC1_SINT2_Handler;                    /* 182 Timer Counter (TC1) */
  void* pfnTDES_SINT_Handler;                    /* 183 Triple Data Encryption Standard (TDES) */
  void* pfnTRNG_SINT_Handler;                    /* 184 True Random Number Generator (TRNG) */
  void* pfnEIC_EXT_IRQ0_Handler;                 /* 185 External Interrupt Controller (EIC) */
  void* pfnEIC_EXT_IRQ1_Handler;                 /* 186 External Interrupt Controller (EIC) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-A7 exception handlers */
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void DWDT_SW_Handler               ( void );
void DWDT_NSW_Handler              ( void );
void DWDT_NSW_ALARM_Handler        ( void );
void SCKC_Handler                  ( void );
void SHDWC_Handler                 ( void );
void RSTC_Handler                  ( void );
void RTC_Handler                   ( void );
void RTT_Handler                   ( void );
void PMC_Handler                   ( void );
void PIOA_Handler                  ( void );
void PIOB_Handler                  ( void );
void PIOC_Handler                  ( void );
void PIOD_Handler                  ( void );
void PIOE_Handler                  ( void );
void SECUMOD_Handler               ( void );
void SECURAM_Handler               ( void );
void SFR_Handler                   ( void );
void HSMC_Handler                  ( void );
void XDMAC0_Handler                ( void );
void XDMAC1_Handler                ( void );
void XDMAC2_Handler                ( void );
void ACC_Handler                   ( void );
void ADC_Handler                   ( void );
void AES_Handler                   ( void );
void ASRC_Handler                  ( void );
void CPKCC_Handler                 ( void );
void CSI_Handler                   ( void );
void CSI2DC_Handler                ( void );
void FLEXCOM0_Handler              ( void );
void FLEXCOM1_Handler              ( void );
void FLEXCOM2_Handler              ( void );
void FLEXCOM3_Handler              ( void );
void FLEXCOM4_Handler              ( void );
void FLEXCOM5_Handler              ( void );
void FLEXCOM6_Handler              ( void );
void FLEXCOM7_Handler              ( void );
void FLEXCOM8_Handler              ( void );
void FLEXCOM9_Handler              ( void );
void FLEXCOM10_Handler             ( void );
void FLEXCOM11_Handler             ( void );
void GMAC0_Handler                 ( void );
void GMAC1_Handler                 ( void );
void GMAC0_TSU_Handler             ( void );
void GMAC1_TSU_Handler             ( void );
void ICM_Handler                   ( void );
void ISC_Handler                   ( void );
void I2SMCC0_Handler               ( void );
void I2SMCC1_Handler               ( void );
void MATRIX_Handler                ( void );
void MCAN0_INT0_Handler            ( void );
void MCAN1_INT0_Handler            ( void );
void MCAN2_INT0_Handler            ( void );
void MCAN3_INT0_Handler            ( void );
void MCAN4_INT0_Handler            ( void );
void MCAN5_INT0_Handler            ( void );
void OTPC_Handler                  ( void );
void PDMC0_Handler                 ( void );
void PDMC1_Handler                 ( void );
void PIT64B0_Handler               ( void );
void PIT64B1_Handler               ( void );
void PIT64B2_Handler               ( void );
void PIT64B3_Handler               ( void );
void PIT64B4_Handler               ( void );
void PIT64B5_Handler               ( void );
void PWM_Handler                   ( void );
void QSPI0_Handler                 ( void );
void QSPI1_Handler                 ( void );
void SDMMC0_Handler                ( void );
void SDMMC1_Handler                ( void );
void SDMMC2_Handler                ( void );
void SHA_Handler                   ( void );
void SPDIFRX_Handler               ( void );
void SPDIFTX_Handler               ( void );
void SSC0_Handler                  ( void );
void SSC1_Handler                  ( void );
void TC0_CH0_Handler               ( void );
void TC0_CH1_Handler               ( void );
void TC0_CH2_Handler               ( void );
void TC1_CH0_Handler               ( void );
void TC1_CH1_Handler               ( void );
void TC1_CH2_Handler               ( void );
void TCPCA_Handler                 ( void );
void TCPCB_Handler                 ( void );
void TDES_Handler                  ( void );
void TRNG_Handler                  ( void );
void TZAESB_NS_Handler             ( void );
void TZAESB_NS_SINT_Handler        ( void );
void TZAESB_S_Handler              ( void );
void TZAESB_S_SINT_Handler         ( void );
void TZC_Handler                   ( void );
void TZPM_Handler                  ( void );
void UDPHSA_Handler                ( void );
void UDPHSB_Handler                ( void );
void UHPHS_Handler                 ( void );
void XDMAC0_SINT_Handler           ( void );
void XDMAC1_SINT_Handler           ( void );
void XDMAC2_SINT_Handler           ( void );
void AES_SINT_Handler              ( void );
void GMAC0_Q1_Handler              ( void );
void GMAC0_Q2_Handler              ( void );
void GMAC0_Q3_Handler              ( void );
void GMAC0_Q4_Handler              ( void );
void GMAC0_Q5_Handler              ( void );
void GMAC1_Q1_Handler              ( void );
void ICM_SINT_Handler              ( void );
void MCAN0_INT1_Handler            ( void );
void MCAN1_INT1_Handler            ( void );
void MCAN2_INT1_Handler            ( void );
void MCAN3_INT1_Handler            ( void );
void MCAN4_INT1_Handler            ( void );
void MCAN5_INT1_Handler            ( void );
void PIOA_SINT_Handler             ( void );
void PIOB_SINT_Handler             ( void );
void PIOC_SINT_Handler             ( void );
void PIOD_SINT_Handler             ( void );
void PIOE_SINT_Handler             ( void );
void PIT64B0_SINT_Handler          ( void );
void PIT64B1_SINT_Handler          ( void );
void PIT64B2_SINT_Handler          ( void );
void PIT64B3_SINT_Handler          ( void );
void PIT64B4_SINT_Handler          ( void );
void PIT64B5_SINT_Handler          ( void );
void SDMMC0_TIMER_Handler          ( void );
void SDMMC1_TIMER_Handler          ( void );
void SDMMC2_TIMER_Handler          ( void );
void SHA_SINT_Handler              ( void );
void TC0_SINT0_Handler             ( void );
void TC0_SINT1_Handler             ( void );
void TC0_SINT2_Handler             ( void );
void TC1_SINT0_Handler             ( void );
void TC1_SINT1_Handler             ( void );
void TC1_SINT2_Handler             ( void );
void TDES_SINT_Handler             ( void );
void TRNG_SINT_Handler             ( void );
void EIC_EXT_IRQ0_Handler          ( void );
void EIC_EXT_IRQ1_Handler          ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/** \brief Configuration of the CORTEX-A7 Processor and Core Peripherals */
#define __CA_REV                      0x0005 /**< CA7 Core Revision(r0p5)                                                   */
#define __CORTEX_A                         7 /**< Core type number (Cortex-A7)                                              */
#define __FPU_PRESENT                      1 /**< FPU is present on core                                                    */
#define __GIC_PRESENT                      1 /**< GIC is present on core                                                    */
#define GIC_DISTRIBUTOR_BASE      0xE8C11000 /**< Base address for GIC distributor interface                                */
#define GIC_INTERFACE_BASE        0xE8C12000 /**< Base address for GIC CPU interface                                        */
#define __TIM_PRESENT                      1 /**< Generic Timer capability is present                                       */
#define __L2C_PRESENT                      0 /**< L2C-310 cache controller is absent                                        */

/*
 * \brief CMSIS includes
 */
#include "core_ca.h"
#if defined USE_CMSIS_INIT
#include "system_sama7g.h"
#endif /* USE_CMSIS_INIT */

/** \defgroup SAMA7G54_api Peripheral Software API
 *  @{
 */

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR SAMA7G54                          */
/* ************************************************************************** */
#include "component/acc.h"
#include "component/adc.h"
#include "component/aes.h"
#include "component/asrc.h"
#include "component/bsc.h"
#include "component/chipid.h"
#include "component/cpkcc.h"
#include "component/csi2dc.h"
#include "component/ddr3phy.h"
#include "component/dwdt.h"
#include "component/eic.h"
#include "component/flexcom.h"
#include "component/gmac.h"
#include "component/gpbr.h"
#include "component/i2smcc.h"
#include "component/icm.h"
#include "component/isc.h"
#include "component/matrix.h"
#include "component/mcan.h"
#include "component/mipicsi2phy.h"
#include "component/nicgpv.h"
#include "component/otpc.h"
#include "component/pdmc.h"
#include "component/pio.h"
#include "component/pit64b.h"
#include "component/pmc.h"
#include "component/pwm.h"
#include "component/qspi.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/rtt.h"
#include "component/sckc.h"
#include "component/sdmmc.h"
#include "component/secumod.h"
#include "component/sfr.h"
#include "component/sfrbu.h"
#include "component/sha.h"
#include "component/shdwc.h"
#include "component/smc.h"
#include "component/spdifrx.h"
#include "component/spdiftx.h"
#include "component/ssc.h"
#include "component/syscwp.h"
#include "component/tc.h"
#include "component/tcpc.h"
#include "component/tdes.h"
#include "component/trng.h"
#include "component/tzaesb.h"
#include "component/tzaesbasc.h"
#include "component/tzc.h"
#include "component/tzpm.h"
#include "component/uddrc.h"
#include "component/udphs.h"
#include "component/uhpfs.h"
#include "component/uhphs.h"
#include "component/xdmac.h"
/** @}  end of Peripheral Software API */

/* ************************************************************************** */
/*   INSTANCE DEFINITIONS FOR SAMA7G54 */
/* ************************************************************************** */
#include "instance/acc.h"
#include "instance/adc.h"
#include "instance/aes.h"
#include "instance/asrc.h"
#include "instance/bsc.h"
#include "instance/chipid.h"
#include "instance/cpkcc.h"
#include "instance/csi.h"
#include "instance/csi2dc.h"
#include "instance/ddrpubl.h"
#include "instance/ddrumctl.h"
#include "instance/dwdt.h"
#include "instance/eic.h"
#include "instance/flexcom0.h"
#include "instance/flexcom1.h"
#include "instance/flexcom10.h"
#include "instance/flexcom11.h"
#include "instance/flexcom2.h"
#include "instance/flexcom3.h"
#include "instance/flexcom4.h"
#include "instance/flexcom5.h"
#include "instance/flexcom6.h"
#include "instance/flexcom7.h"
#include "instance/flexcom8.h"
#include "instance/flexcom9.h"
#include "instance/gmac0.h"
#include "instance/gmac1.h"
#include "instance/gpbr.h"
#include "instance/hsmc.h"
#include "instance/i2smcc0.h"
#include "instance/i2smcc1.h"
#include "instance/icm.h"
#include "instance/isc.h"
#include "instance/matrix.h"
#include "instance/mcan0.h"
#include "instance/mcan1.h"
#include "instance/mcan2.h"
#include "instance/mcan3.h"
#include "instance/mcan4.h"
#include "instance/mcan5.h"
#include "instance/nicgpv.h"
#include "instance/otpc.h"
#include "instance/pdmc0.h"
#include "instance/pdmc1.h"
#include "instance/pio.h"
#include "instance/pit64b0.h"
#include "instance/pit64b1.h"
#include "instance/pit64b2.h"
#include "instance/pit64b3.h"
#include "instance/pit64b4.h"
#include "instance/pit64b5.h"
#include "instance/pmc.h"
#include "instance/pwm.h"
#include "instance/qspi0.h"
#include "instance/qspi1.h"
#include "instance/rstc.h"
#include "instance/rtc.h"
#include "instance/rtt.h"
#include "instance/sckc.h"
#include "instance/sdmmc0.h"
#include "instance/sdmmc1.h"
#include "instance/sdmmc2.h"
#include "instance/secumod.h"
#include "instance/sfr.h"
#include "instance/sfrbu.h"
#include "instance/sha.h"
#include "instance/shdwc.h"
#include "instance/spdifrx.h"
#include "instance/spdiftx.h"
#include "instance/ssc0.h"
#include "instance/ssc1.h"
#include "instance/syscwp.h"
#include "instance/tc0.h"
#include "instance/tc1.h"
#include "instance/tcpca.h"
#include "instance/tcpcb.h"
#include "instance/tdes.h"
#include "instance/trng.h"
#include "instance/tzaesbasc.h"
#include "instance/tzaesbns.h"
#include "instance/tzaesbs.h"
#include "instance/tzc.h"
#include "instance/tzpm.h"
#include "instance/udphsa.h"
#include "instance/udphsb.h"
#include "instance/uhphs_ehci.h"
#include "instance/uhphs_ohci.h"
#include "instance/xdmac0.h"
#include "instance/xdmac1.h"
#include "instance/xdmac2.h"

/** \addtogroup SAMA7G54_id Peripheral Ids Definitions
 *  @{
 */

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR SAMA7G54                                    */
/* ************************************************************************** */
#define ID_DWDT_SW       (  0) /**< \brief Dual Watchdog Timer, Secure World (DWDT_SW) */
#define ID_DWDT_NSW      (  1) /**< \brief Dual Watchdog Timer, Non Secure World, interrupt (DWDT_NSW) */
#define ID_DWDT_NSW_ALARM (  2) /**< \brief Dual Watchdog Timer, Non Secure World Alarm, interrupt (DWDT_NSW_ALARM) */
#define ID_SCKC          (  4) /**< \brief Slow Clock Controller (SCKC) */
#define ID_SHDWC         (  5) /**< \brief SHutDoWn Controller (SHDWC) */
#define ID_RSTC          (  6) /**< \brief Reset Controller (RSTC) */
#define ID_RTC           (  7) /**< \brief Real-Time Clock (RTC) */
#define ID_RTT           (  8) /**< \brief Real-Time Timer (RTT) */
#define ID_CHIPID        (  9) /**< \brief Chip Identifier (CHIPID) */
#define ID_PMC           ( 10) /**< \brief Power Management Controller (PMC) */
#define ID_PIOA          ( 11) /**< \brief For PIO 0 to 31 (PIOA) */
#define ID_PIOB          ( 12) /**< \brief For PIO 32 to 63, interrupt (PIOB) */
#define ID_PIOC          ( 13) /**< \brief For PIO 64 to 95, interrupt (PIOC) */
#define ID_PIOD          ( 14) /**< \brief For PIO 96 to 127, interrupt (PIOD) */
#define ID_PIOE          ( 15) /**< \brief For PIO 128 to 136, interrupt (PIOE) */
#define ID_SECUMOD       ( 17) /**< \brief Security Module (SECUMOD) */
#define ID_SECURAM       ( 18) /**< \brief Secret RAM (SECURAM) */
#define ID_SFR           ( 19) /**< \brief Special Function Register (SFR) */
#define ID_SFRBU         ( 20) /**< \brief Special Function Register in BackUp zone (SFRBU) */
#define ID_HSMC          ( 21) /**< \brief Static Memory Controller - NAND Flash Controller (HSMC) */
#define ID_XDMAC0        ( 22) /**< \brief DMA 0, mem to periph, 32 Channels (XDMAC0) */
#define ID_XDMAC1        ( 23) /**< \brief DMA 1, mem to periph, 32 Channels (XDMAC1) */
#define ID_XDMAC2        ( 24) /**< \brief DMA 2, mem to mem, 4 Channels (XDMAC2) */
#define ID_ACC           ( 25) /**< \brief Analog Comparator Controller (ACC) */
#define ID_ADC           ( 26) /**< \brief Analog-to-Digital Converter (ADC) */
#define ID_AES           ( 27) /**< \brief Advanced Encryption Standard (AES) */
#define ID_TZAESBASC     ( 28) /**< \brief TrustZone Advanced Encryption Standard Bridge - Address Space Controlller (TZAESBASC) */
#define ID_ASRC          ( 30) /**< \brief Asynchronous Sample Rate Converter (ASRC) */
#define ID_CPKCC         ( 32) /**< \brief Classic Public Key Cryptography Controller (CPKCC) */
#define ID_CSI           ( 33) /**< \brief Camera Serial Interface 2 between ISC and MIPI PHY (CSI) */
#define ID_CSI2DC        ( 34) /**< \brief CSI to Demultiplexer Controller (CSI2DC) */
#define ID_DDRPUBL       ( 35) /**< \brief DDR SDRAM PHY Utility Block "Lite" aka PUBL (DDRPUBL) */
#define ID_DDRUMCTL      ( 36) /**< \brief Enhanced Universal DDR-SDRAM Memory Controller (DDRUMCTL) */
#define ID_EIC           ( 37) /**< \brief External  Interrupt Controller (EIC) */
#define ID_FLEXCOM0      ( 38) /**< \brief Flexcom 0 (FLEXCOM0) */
#define ID_FLEXCOM1      ( 39) /**< \brief Flexcom 1 (FLEXCOM1) */
#define ID_FLEXCOM2      ( 40) /**< \brief Flexcom 2 (FLEXCOM2) */
#define ID_FLEXCOM3      ( 41) /**< \brief Flexcom 3 (FLEXCOM3) */
#define ID_FLEXCOM4      ( 42) /**< \brief Flexcom 4 (FLEXCOM4) */
#define ID_FLEXCOM5      ( 43) /**< \brief Flexcom 5 (FLEXCOM5) */
#define ID_FLEXCOM6      ( 44) /**< \brief Flexcom 6 (FLEXCOM6) */
#define ID_FLEXCOM7      ( 45) /**< \brief Flexcom 7 (FLEXCOM7) */
#define ID_FLEXCOM8      ( 46) /**< \brief Flexcom 8 (FLEXCOM8) */
#define ID_FLEXCOM9      ( 47) /**< \brief Flexcom 9 (FLEXCOM9) */
#define ID_FLEXCOM10     ( 48) /**< \brief Flexcom 10 (FLEXCOM10) */
#define ID_FLEXCOM11     ( 49) /**< \brief Flexcom 11 (FLEXCOM11) */
#define ID_GMAC0         ( 51) /**< \brief Gigabit Ethernet MAC (GMAC0) */
#define ID_GMAC1         ( 52) /**< \brief Ethernet MAC (GMAC1) */
#define ID_GMAC0_TSU     ( 53) /**< \brief Gigabit Ethernet MAC - Time Stamp Unit Generic Clock - No Interrupt (GMAC0_TSU) */
#define ID_GMAC1_TSU     ( 54) /**< \brief Ethernet MAC - Time Stamp Unit Generic Clock - No Interrupt (GMAC1_TSU) */
#define ID_ICM           ( 55) /**< \brief Integrity Check Monitor (ICM) */
#define ID_ISC           ( 56) /**< \brief Camera Interface (ISC) */
#define ID_I2SMCC0       ( 57) /**< \brief Inter-IC Sound Controller 0 (I2SMCC0) */
#define ID_I2SMCC1       ( 58) /**< \brief Inter-IC Sound Controller 1 (I2SMCC1) */
#define ID_MATRIX        ( 60) /**< \brief HSS AHB Matrix (MATRIX) */
#define ID_MCAN0_INT0    ( 61) /**< \brief Master CAN 0 (MCAN0_INT0) */
#define ID_MCAN1_INT0    ( 62) /**< \brief Master CAN 1 (MCAN1_INT0) */
#define ID_MCAN2_INT0    ( 63) /**< \brief Master CAN 2 (MCAN2_INT0) */
#define ID_MCAN3_INT0    ( 64) /**< \brief Master CAN 3 (MCAN3_INT0) */
#define ID_MCAN4_INT0    ( 65) /**< \brief Master CAN 4 (MCAN4_INT0) */
#define ID_MCAN5_INT0    ( 66) /**< \brief Master CAN 5 (MCAN5_INT0) */
#define ID_OTPC          ( 67) /**< \brief One Time Programmable memory Controller (OTPC) */
#define ID_PDMC0         ( 68) /**< \brief Pulse Density Modulation Interface Controller 0 (PDMC0) */
#define ID_PDMC1         ( 69) /**< \brief Pulse Density Modulation Interface Controller 1 (PDMC1) */
#define ID_PIT64B0       ( 70) /**< \brief 64-bit Periodic Interval Timer 0 (PIT64B0) */
#define ID_PIT64B1       ( 71) /**< \brief 64-bit Periodic Interval Timer 1 (PIT64B1) */
#define ID_PIT64B2       ( 72) /**< \brief 64-bit Periodic Interval Timer 2 (PIT64B2) */
#define ID_PIT64B3       ( 73) /**< \brief 64-bit Periodic Interval Timer 3 (PIT64B3) */
#define ID_PIT64B4       ( 74) /**< \brief 64-bit Periodic Interval Timer 4 (PIT64B4) */
#define ID_PIT64B5       ( 75) /**< \brief 64-bit Periodic Interval Timer 5 (PIT64B5) */
#define ID_PWM           ( 77) /**< \brief Pulse Width Modulation (PWM) */
#define ID_QSPI0         ( 78) /**< \brief Quad IO Serial Peripheral Interface 0 (QSPI0) */
#define ID_QSPI1         ( 79) /**< \brief Quad IO Serial Peripheral Interface 1 (QSPI1) */
#define ID_SDMMC0        ( 80) /**< \brief Ultra High Speed SD Host controller 0 (eMMC 5.1) (SDMMC0) */
#define ID_SDMMC1        ( 81) /**< \brief Ultra High Speed SD Host controller 1 (eMMC 4.51) (SDMMC1) */
#define ID_SDMMC2        ( 82) /**< \brief Ultra High Speed SD Host controller 2 (eMMC 4.51) (SDMMC2) */
#define ID_SHA           ( 83) /**< \brief Secure Hash Algorithm (SHA) */
#define ID_SPDIFRX       ( 84) /**< \brief Sony Philips Digital Interface RX (SPDIFRX) */
#define ID_SPDIFTX       ( 85) /**< \brief Sony Philips Digital Interface TX (SPDIFTX) */
#define ID_SSC0          ( 86) /**< \brief Synchronous Serial Interface 0 (SSC0) */
#define ID_SSC1          ( 87) /**< \brief Synchronous Serial Interface 1 (SSC1) */
#define ID_TC0_CHANNEL0  ( 88) /**< \brief 32-bit Timer Counter 0 Channel 0 (TC0_CHANNEL0) */
#define ID_TC0_CHANNEL1  ( 89) /**< \brief 32-bit Timer Counter 0 Channel 1 interrupt (TC0_CHANNEL1) */
#define ID_TC0_CHANNEL2  ( 90) /**< \brief 32-bit Timer Counter 0 Channel 2 interrupt (TC0_CHANNEL2) */
#define ID_TC1_CHANNEL0  ( 91) /**< \brief 32-bit Timer Counter 1 Channel 0 (TC1_CHANNEL0) */
#define ID_TC1_CHANNEL1  ( 92) /**< \brief 32-bit Timer Counter 1 Channel 1 interrupt (TC1_CHANNEL1) */
#define ID_TC1_CHANNEL2  ( 93) /**< \brief 32-bit Timer Counter 1 Channel 2 interrupt (TC1_CHANNEL2) */
#define ID_TCPCA         ( 94) /**< \brief USB Type-C Port Controller A (TCPCA) */
#define ID_TCPCB         ( 95) /**< \brief USB Type-C Port Controller B (TCPCB) */
#define ID_TDES          ( 96) /**< \brief Triple Data Encryption System (TDES) */
#define ID_TRNG          ( 97) /**< \brief True Random Number Generator (TRNG) */
#define ID_TZAESB_NS     ( 98) /**< \brief TrustZone Advanced Encryption Standard Bridge Non-Secure (Clocks & Interrupt) (TZAESB_NS) */
#define ID_TZAESB_NS_SINT ( 99) /**< \brief TrustZone Advanced Encryption Standard Bridge Non-Secure (Interrupt only) (TZAESB_NS_SINT) */
#define ID_TZAESB_S      (100) /**< \brief TrustZone Advanced Encryption Standard Bridge Secure (TZAESB_S) */
#define ID_TZAESB_S_SINT (101) /**< \brief TrustZone Advanced Encryption Standard Bridge Secure (Interrupt only) (TZAESB_S_SINT) */
#define ID_TZC           (102) /**< \brief TrustZone Address Space Controller (TZC-400) (TZC) */
#define ID_TZPM          (103) /**< \brief TrustZone Peripheral Manager (TZPM) */
#define ID_UDPHSA        (104) /**< \brief USB Device High Speed A (UDPHSA) */
#define ID_UDPHSB        (105) /**< \brief USB Device High Speed B (UDPHSB) */
#define ID_UHPHS         (106) /**< \brief USB Host Controller High Speed (UHPHS) */
#define ID_XDMAC0_SINT   (112) /**< \brief DMA 0, mem to periph, 32 Channels, Secure INTerrupt (XDMAC0_SINT) */
#define ID_XDMAC1_SINT   (113) /**< \brief DMA 1, mem to periph, 32 Channels, Secure INTerrupt (XDMAC1_SINT) */
#define ID_XDMAC2_SINT   (114) /**< \brief DMA 2, mem to mem, 4 Channels, Secure INTerrupt (XDMAC2_SINT) */
#define ID_AES_SINT      (115) /**< \brief Advanced Encryption Standard, Secure INTerrupt (AES_SINT) */
#define ID_GMAC0_Q1      (116) /**< \brief GMAC0 Queue 1 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 1 (GMAC0_Q1) */
#define ID_GMAC0_Q2      (117) /**< \brief GMAC0 Queue 2 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 2 (GMAC0_Q2) */
#define ID_GMAC0_Q3      (118) /**< \brief GMAC0 Queue 3 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 3 (GMAC0_Q3) */
#define ID_GMAC0_Q4      (119) /**< \brief GMAC0 Queue 4 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 4 (GMAC0_Q4) */
#define ID_GMAC0_Q5      (120) /**< \brief GMAC0 Queue 5 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 5 (GMAC0_Q5) */
#define ID_GMAC1_Q1      (121) /**< \brief GMAC1 Queue 1 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 1 (GMAC1_Q1) */
#define ID_ICM_SINT      (122) /**< \brief Integrity Check Monitor, Secure INTerrupt (ICM_SINT) */
#define ID_MCAN0_INT1    (123) /**< \brief MCAN0 interrupt1 (MCAN0_INT1) */
#define ID_MCAN1_INT1    (124) /**< \brief MCAN1 interrupt1 (MCAN1_INT1) */
#define ID_MCAN2_INT1    (125) /**< \brief MCAN2 interrupt1 (MCAN2_INT1) */
#define ID_MCAN3_INT1    (126) /**< \brief MCAN3 interrupt1 (MCAN3_INT1) */
#define ID_MCAN4_INT1    (127) /**< \brief MCAN4 interrupt1 (MCAN4_INT1) */
#define ID_MCAN5_INT1    (128) /**< \brief MCAN5 interrupt1 (MCAN5_INT1) */
#define ID_PIOA_SINT     (129) /**< \brief For PIO 0 to 31, Secure INTerrupt (PIOA_SINT) */
#define ID_PIOB_SINT     (130) /**< \brief For PIO 32 to 63, Secure INTerrupt (PIOB_SINT) */
#define ID_PIOC_SINT     (131) /**< \brief For PIO 64 to 95, Secure INTerrupt (PIOC_SINT) */
#define ID_PIOD_SINT     (132) /**< \brief For PIO 96 to 127, Secure INTerrupt (PIOD_SINT) */
#define ID_PIOE_SINT     (133) /**< \brief For PIO 128 to 136, Secure INTerrupt (PIOE_SINT) */
#define ID_PIT64B0_SINT  (135) /**< \brief 64-bit Periodic Interval Timer 0, Secure INTerrupt (PIT64B0_SINT) */
#define ID_PIT64B1_SINT  (136) /**< \brief 64-bit Periodic Interval Timer 1, Secure INTerrupt (PIT64B1_SINT) */
#define ID_PIT64B2_SINT  (137) /**< \brief 64-bit Periodic Interval Timer 2, Secure INTerrupt (PIT64B2_SINT) */
#define ID_PIT64B3_SINT  (138) /**< \brief 64-bit Periodic Interval Timer 3, Secure INTerrupt (PIT64B3_SINT) */
#define ID_PIT64B4_SINT  (139) /**< \brief 64-bit Periodic Interval Timer 4, Secure INTerrupt (PIT64B4_SINT) */
#define ID_PIT64B5_SINT  (140) /**< \brief 64-bit Periodic Interval Timer 5, Secure INTerrupt (PIT64B5_SINT) */
#define ID_SDMMC0_TIMER  (141) /**< \brief Ultra High Speed SD Host controller 0 (eMMC 5.1) Timer interrupt (SDMMC0_TIMER) */
#define ID_SDMMC1_TIMER  (142) /**< \brief Ultra High Speed SD Host controller 1 (eMMC 4.51) Timer interrupt (SDMMC1_TIMER) */
#define ID_SDMMC2_TIMER  (143) /**< \brief Ultra High Speed SD Host controller 2 (eMMC 4.51) Timer interrupt (SDMMC2_TIMER) */
#define ID_SHA_SINT      (144) /**< \brief Secure Hash Algorithm, Secure INTerrupt (SHA_SINT) */
#define ID_TC0_SINT0     (145) /**< \brief 32-bit Timer Counter 0 Channel 0, Secure INTerrupt (TC0_SINT0) */
#define ID_TC0_SINT1     (146) /**< \brief 32-bit Timer Counter 0 Channel 1, Secure INTerrupt (TC0_SINT1) */
#define ID_TC0_SINT2     (147) /**< \brief 32-bit Timer Counter 0 Channel 2 (TC0_SINT2) */
#define ID_TC1_SINT0     (148) /**< \brief 32-bit Timer Counter 1 Channel 0, Secure INTerrupt (TC1_SINT0) */
#define ID_TC1_SINT1     (149) /**< \brief 32-bit Timer Counter 1 Channel 1, Secure INTerrupt (TC1_SINT1) */
#define ID_TC1_SINT2     (150) /**< \brief 32-bit Timer Counter 1 Channel 2, Secure INTerrupt (TC1_SINT2) */
#define ID_TDES_SINT     (151) /**< \brief Triple Data Encryption System, Secure INTerrupt (TDES_SINT) */
#define ID_TRNG_SINT     (152) /**< \brief True Random Number Generator, Secure INTerrupt (TRNG_SINT) */
#define ID_EXT_IRQ0      (153) /**< \brief External  Interrupt ID0 (FIQ) (EXT_IRQ0) */
#define ID_EXT_IRQ1      (154) /**< \brief External  Interrupt ID1 (IRQ) (EXT_IRQ1) */

#define ID_PERIPH_MAX    (154) /**< \brief Number of peripheral IDs */
/** @}  end of Peripheral Ids Definitions */

/** \addtogroup SAMA7G54_base Peripheral Base Address Definitions
 *  @{
 */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR SAMA7G54                      */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define ACC_REGS                         ((acc_registers_t*)0xe1600000)                /**< \brief ACC Registers Address        */
#define ADC_REGS                         ((adc_registers_t*)0xe1000000)                /**< \brief ADC Registers Address        */
#define AES_REGS                         ((aes_registers_t*)0xe1810000)                /**< \brief AES Registers Address        */
#define ASRC_REGS                        ((asrc_registers_t*)0xe1610000)               /**< \brief ASRC Registers Address       */
#define BSC_REGS                         ((bsc_registers_t*)0xe001d054)                /**< \brief BSC Registers Address        */
#define CHIPID_REGS                      ((chipid_registers_t*)0xe0020000)             /**< \brief CHIPID Registers Address     */
#define CPKCC_REGS                       ((cpkcc_registers_t*)0xe000c000)              /**< \brief CPKCC Registers Address      */
#define CSI2DC_REGS                      ((csi2dc_registers_t*)0xe1404000)             /**< \brief CSI2DC Registers Address     */
#define DDRPUBL_REGS                     ((ddr3phy_registers_t*)0xe3804000)            /**< \brief DDRPUBL Registers Address    */
#define DWDT_REGS                        ((dwdt_registers_t*)0xe001c000)               /**< \brief DWDT Registers Address       */
#define EIC_REGS                         ((eic_registers_t*)0xe1628000)                /**< \brief EIC Registers Address        */
#define FLEXCOM0_REGS                    ((flexcom_registers_t*)0xe1818000)            /**< \brief FLEXCOM0 Registers Address   */
#define FLEXCOM1_REGS                    ((flexcom_registers_t*)0xe181c000)            /**< \brief FLEXCOM1 Registers Address   */
#define FLEXCOM2_REGS                    ((flexcom_registers_t*)0xe1820000)            /**< \brief FLEXCOM2 Registers Address   */
#define FLEXCOM3_REGS                    ((flexcom_registers_t*)0xe1824000)            /**< \brief FLEXCOM3 Registers Address   */
#define FLEXCOM4_REGS                    ((flexcom_registers_t*)0xe2018000)            /**< \brief FLEXCOM4 Registers Address   */
#define FLEXCOM5_REGS                    ((flexcom_registers_t*)0xe201c000)            /**< \brief FLEXCOM5 Registers Address   */
#define FLEXCOM6_REGS                    ((flexcom_registers_t*)0xe2020000)            /**< \brief FLEXCOM6 Registers Address   */
#define FLEXCOM7_REGS                    ((flexcom_registers_t*)0xe2024000)            /**< \brief FLEXCOM7 Registers Address   */
#define FLEXCOM8_REGS                    ((flexcom_registers_t*)0xe2818000)            /**< \brief FLEXCOM8 Registers Address   */
#define FLEXCOM9_REGS                    ((flexcom_registers_t*)0xe281c000)            /**< \brief FLEXCOM9 Registers Address   */
#define FLEXCOM10_REGS                   ((flexcom_registers_t*)0xe2820000)            /**< \brief FLEXCOM10 Registers Address  */
#define FLEXCOM11_REGS                   ((flexcom_registers_t*)0xe2824000)            /**< \brief FLEXCOM11 Registers Address  */
#define GMAC0_REGS                       ((gmac_registers_t*)0xe2800000)               /**< \brief GMAC0 Registers Address      */
#define GMAC1_REGS                       ((gmac_registers_t*)0xe2804000)               /**< \brief GMAC1 Registers Address      */
#define GPBR_REGS                        ((gpbr_registers_t*)0xe001d060)               /**< \brief GPBR Registers Address       */
#define I2SMCC0_REGS                     ((i2smcc_registers_t*)0xe161c000)             /**< \brief I2SMCC0 Registers Address    */
#define I2SMCC1_REGS                     ((i2smcc_registers_t*)0xe1620000)             /**< \brief I2SMCC1 Registers Address    */
#define ICM_REGS                         ((icm_registers_t*)0xe081c000)                /**< \brief ICM Registers Address        */
#define ISC_REGS                         ((isc_registers_t*)0xe1408000)                /**< \brief ISC Registers Address        */
#define MATRIX_REGS                      ((matrix_registers_t*)0xe0804000)             /**< \brief MATRIX Registers Address     */
#define MCAN0_REGS                       ((mcan_registers_t*)0xe0828000)               /**< \brief MCAN0 Registers Address      */
#define MCAN1_REGS                       ((mcan_registers_t*)0xe082c000)               /**< \brief MCAN1 Registers Address      */
#define MCAN2_REGS                       ((mcan_registers_t*)0xe0830000)               /**< \brief MCAN2 Registers Address      */
#define MCAN3_REGS                       ((mcan_registers_t*)0xe0834000)               /**< \brief MCAN3 Registers Address      */
#define MCAN4_REGS                       ((mcan_registers_t*)0xe0838000)               /**< \brief MCAN4 Registers Address      */
#define MCAN5_REGS                       ((mcan_registers_t*)0xe083c000)               /**< \brief MCAN5 Registers Address      */
#define CSI_REGS                         ((mipicsi2phy_registers_t*)0xe1400000)        /**< \brief CSI Registers Address        */
#define NICGPV_REGS                      ((nicgpv_registers_t*)0xe8b00000)             /**< \brief NICGPV Registers Address     */
#define OTPC_REGS                        ((otpc_registers_t*)0xe8c00000)               /**< \brief OTPC Registers Address       */
#define PDMC0_REGS                       ((pdmc_registers_t*)0xe1608000)               /**< \brief PDMC0 Registers Address      */
#define PDMC1_REGS                       ((pdmc_registers_t*)0xe160c000)               /**< \brief PDMC1 Registers Address      */
#define PIO_REGS                         ((pio_registers_t*)0xe0014000)                /**< \brief PIO Registers Address        */
#define PIT64B0_REGS                     ((pit64b_registers_t*)0xe1800000)             /**< \brief PIT64B0 Registers Address    */
#define PIT64B1_REGS                     ((pit64b_registers_t*)0xe1804000)             /**< \brief PIT64B1 Registers Address    */
#define PIT64B2_REGS                     ((pit64b_registers_t*)0xe1808000)             /**< \brief PIT64B2 Registers Address    */
#define PIT64B3_REGS                     ((pit64b_registers_t*)0xe2004000)             /**< \brief PIT64B3 Registers Address    */
#define PIT64B4_REGS                     ((pit64b_registers_t*)0xe2008000)             /**< \brief PIT64B4 Registers Address    */
#define PIT64B5_REGS                     ((pit64b_registers_t*)0xe2810000)             /**< \brief PIT64B5 Registers Address    */
#define PMC_REGS                         ((pmc_registers_t*)0xe0018000)                /**< \brief PMC Registers Address        */
#define PWM_REGS                         ((pwm_registers_t*)0xe1604000)                /**< \brief PWM Registers Address        */
#define QSPI0_REGS                       ((qspi_registers_t*)0xe080c000)               /**< \brief QSPI0 Registers Address      */
#define QSPI1_REGS                       ((qspi_registers_t*)0xe0810000)               /**< \brief QSPI1 Registers Address      */
#define RSTC_REGS                        ((rstc_registers_t*)0xe001d000)               /**< \brief RSTC Registers Address       */
#define RTC_REGS                         ((rtc_registers_t*)0xe001d0a8)                /**< \brief RTC Registers Address        */
#define RTT_REGS                         ((rtt_registers_t*)0xe001d020)                /**< \brief RTT Registers Address        */
#define SCKC_REGS                        ((sckc_registers_t*)0xe001d050)               /**< \brief SCKC Registers Address       */
#define SDMMC0_REGS                      ((sdmmc_registers_t*)0xe1204000)              /**< \brief SDMMC0 Registers Address     */
#define SDMMC1_REGS                      ((sdmmc_registers_t*)0xe1208000)              /**< \brief SDMMC1 Registers Address     */
#define SDMMC2_REGS                      ((sdmmc_registers_t*)0xe120c000)              /**< \brief SDMMC2 Registers Address     */
#define SECUMOD_REGS                     ((secumod_registers_t*)0xe0004000)            /**< \brief SECUMOD Registers Address    */
#define SFR_REGS                         ((sfr_registers_t*)0xe1624000)                /**< \brief SFR Registers Address        */
#define SFRBU_REGS                       ((sfrbu_registers_t*)0xe0008000)              /**< \brief SFRBU Registers Address      */
#define SHA_REGS                         ((sha_registers_t*)0xe1814000)                /**< \brief SHA Registers Address        */
#define SHDWC_REGS                       ((shdwc_registers_t*)0xe001d010)              /**< \brief SHDWC Registers Address      */
#define HSMC_REGS                        ((smc_registers_t*)0xe0808000)                /**< \brief HSMC Registers Address       */
#define SPDIFRX_REGS                     ((spdifrx_registers_t*)0xe1614000)            /**< \brief SPDIFRX Registers Address    */
#define SPDIFTX_REGS                     ((spdiftx_registers_t*)0xe1618000)            /**< \brief SPDIFTX Registers Address    */
#define SSC0_REGS                        ((ssc_registers_t*)0xe180c000)                /**< \brief SSC0 Registers Address       */
#define SSC1_REGS                        ((ssc_registers_t*)0xe200c000)                /**< \brief SSC1 Registers Address       */
#define SYSCWP_REGS                      ((syscwp_registers_t*)0xe001d0dc)             /**< \brief SYSCWP Registers Address     */
#define TC0_REGS                         ((tc_registers_t*)0xe2814000)                 /**< \brief TC0 Registers Address        */
#define TC1_REGS                         ((tc_registers_t*)0xe0800000)                 /**< \brief TC1 Registers Address        */
#define TCPCA_REGS                       ((tcpc_registers_t*)0xe0840000)               /**< \brief TCPCA Registers Address      */
#define TCPCB_REGS                       ((tcpc_registers_t*)0xe0844000)               /**< \brief TCPCB Registers Address      */
#define TDES_REGS                        ((tdes_registers_t*)0xe2014000)               /**< \brief TDES Registers Address       */
#define TRNG_REGS                        ((trng_registers_t*)0xe2010000)               /**< \brief TRNG Registers Address       */
#define TZAESBNS_REGS                    ((tzaesb_registers_t*)0xe0820000)             /**< \brief TZAESBNS Registers Address   */
#define TZAESBS_REGS                     ((tzaesb_registers_t*)0xe0824000)             /**< \brief TZAESBS Registers Address    */
#define TZAESBASC_REGS                   ((tzaesbasc_registers_t*)0xe2000000)          /**< \brief TZAESBASC Registers Address  */
#define TZC_REGS                         ((tzc_registers_t*)0xe3000000)                /**< \brief TZC Registers Address        */
#define TZPM_REGS                        ((tzpm_registers_t*)0xe0010000)               /**< \brief TZPM Registers Address       */
#define DDRUMCTL_REGS                    ((uddrc_registers_t*)0xe3800000)              /**< \brief DDRUMCTL Registers Address   */
#define UDPHSA_REGS                      ((udphs_registers_t*)0xe0814000)              /**< \brief UDPHSA Registers Address     */
#define UDPHSB_REGS                      ((udphs_registers_t*)0xe0818000)              /**< \brief UDPHSB Registers Address     */
#define UHPHS_OHCI_REGS                  ((uhpfs_registers_t*)0x00400000)              /**< \brief UHPHS_OHCI Registers Address */
#define UHPHS_EHCI_REGS                  ((uhphs_registers_t*)0x00500000)              /**< \brief UHPHS_EHCI Registers Address */
#define XDMAC0_REGS                      ((xdmac_registers_t*)0xe2808000)              /**< \brief XDMAC0 Registers Address     */
#define XDMAC1_REGS                      ((xdmac_registers_t*)0xe280c000)              /**< \brief XDMAC1 Registers Address     */
#define XDMAC2_REGS                      ((xdmac_registers_t*)0xe1200000)              /**< \brief XDMAC2 Registers Address     */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Peripheral Base Address Definitions */

/** \addtogroup SAMA7G54_base Peripheral Base Address Definitions
 *  @{
 */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAMA7G54                                    */
/* ************************************************************************** */
#define ACC_BASE_ADDRESS                 _UL_(0xe1600000)                              /* ACC Base Address */
#define ADC_BASE_ADDRESS                 _UL_(0xe1000000)                              /* ADC Base Address */
#define AES_BASE_ADDRESS                 _UL_(0xe1810000)                              /* AES Base Address */
#define ASRC_BASE_ADDRESS                _UL_(0xe1610000)                              /* ASRC Base Address */
#define BSC_BASE_ADDRESS                 _UL_(0xe001d054)                              /* BSC Base Address */
#define CHIPID_BASE_ADDRESS              _UL_(0xe0020000)                              /* CHIPID Base Address */
#define CPKCC_BASE_ADDRESS               _UL_(0xe000c000)                              /* CPKCC Base Address */
#define CSI2DC_BASE_ADDRESS              _UL_(0xe1404000)                              /* CSI2DC Base Address */
#define DDRPUBL_BASE_ADDRESS             _UL_(0xe3804000)                              /* DDRPUBL Base Address */
#define DWDT_BASE_ADDRESS                _UL_(0xe001c000)                              /* DWDT Base Address */
#define EIC_BASE_ADDRESS                 _UL_(0xe1628000)                              /* EIC Base Address */
#define FLEXCOM0_BASE_ADDRESS            _UL_(0xe1818000)                              /* FLEXCOM0 Base Address */
#define FLEXCOM1_BASE_ADDRESS            _UL_(0xe181c000)                              /* FLEXCOM1 Base Address */
#define FLEXCOM2_BASE_ADDRESS            _UL_(0xe1820000)                              /* FLEXCOM2 Base Address */
#define FLEXCOM3_BASE_ADDRESS            _UL_(0xe1824000)                              /* FLEXCOM3 Base Address */
#define FLEXCOM4_BASE_ADDRESS            _UL_(0xe2018000)                              /* FLEXCOM4 Base Address */
#define FLEXCOM5_BASE_ADDRESS            _UL_(0xe201c000)                              /* FLEXCOM5 Base Address */
#define FLEXCOM6_BASE_ADDRESS            _UL_(0xe2020000)                              /* FLEXCOM6 Base Address */
#define FLEXCOM7_BASE_ADDRESS            _UL_(0xe2024000)                              /* FLEXCOM7 Base Address */
#define FLEXCOM8_BASE_ADDRESS            _UL_(0xe2818000)                              /* FLEXCOM8 Base Address */
#define FLEXCOM9_BASE_ADDRESS            _UL_(0xe281c000)                              /* FLEXCOM9 Base Address */
#define FLEXCOM10_BASE_ADDRESS           _UL_(0xe2820000)                              /* FLEXCOM10 Base Address */
#define FLEXCOM11_BASE_ADDRESS           _UL_(0xe2824000)                              /* FLEXCOM11 Base Address */
#define GMAC0_BASE_ADDRESS               _UL_(0xe2800000)                              /* GMAC0 Base Address */
#define GMAC1_BASE_ADDRESS               _UL_(0xe2804000)                              /* GMAC1 Base Address */
#define GPBR_BASE_ADDRESS                _UL_(0xe001d060)                              /* GPBR Base Address */
#define I2SMCC0_BASE_ADDRESS             _UL_(0xe161c000)                              /* I2SMCC0 Base Address */
#define I2SMCC1_BASE_ADDRESS             _UL_(0xe1620000)                              /* I2SMCC1 Base Address */
#define ICM_BASE_ADDRESS                 _UL_(0xe081c000)                              /* ICM Base Address */
#define ISC_BASE_ADDRESS                 _UL_(0xe1408000)                              /* ISC Base Address */
#define MATRIX_BASE_ADDRESS              _UL_(0xe0804000)                              /* MATRIX Base Address */
#define MCAN0_BASE_ADDRESS               _UL_(0xe0828000)                              /* MCAN0 Base Address */
#define MCAN1_BASE_ADDRESS               _UL_(0xe082c000)                              /* MCAN1 Base Address */
#define MCAN2_BASE_ADDRESS               _UL_(0xe0830000)                              /* MCAN2 Base Address */
#define MCAN3_BASE_ADDRESS               _UL_(0xe0834000)                              /* MCAN3 Base Address */
#define MCAN4_BASE_ADDRESS               _UL_(0xe0838000)                              /* MCAN4 Base Address */
#define MCAN5_BASE_ADDRESS               _UL_(0xe083c000)                              /* MCAN5 Base Address */
#define CSI_BASE_ADDRESS                 _UL_(0xe1400000)                              /* CSI Base Address */
#define NICGPV_BASE_ADDRESS              _UL_(0xe8b00000)                              /* NICGPV Base Address */
#define OTPC_BASE_ADDRESS                _UL_(0xe8c00000)                              /* OTPC Base Address */
#define PDMC0_BASE_ADDRESS               _UL_(0xe1608000)                              /* PDMC0 Base Address */
#define PDMC1_BASE_ADDRESS               _UL_(0xe160c000)                              /* PDMC1 Base Address */
#define PIO_BASE_ADDRESS                 _UL_(0xe0014000)                              /* PIO Base Address */
#define PIT64B0_BASE_ADDRESS             _UL_(0xe1800000)                              /* PIT64B0 Base Address */
#define PIT64B1_BASE_ADDRESS             _UL_(0xe1804000)                              /* PIT64B1 Base Address */
#define PIT64B2_BASE_ADDRESS             _UL_(0xe1808000)                              /* PIT64B2 Base Address */
#define PIT64B3_BASE_ADDRESS             _UL_(0xe2004000)                              /* PIT64B3 Base Address */
#define PIT64B4_BASE_ADDRESS             _UL_(0xe2008000)                              /* PIT64B4 Base Address */
#define PIT64B5_BASE_ADDRESS             _UL_(0xe2810000)                              /* PIT64B5 Base Address */
#define PMC_BASE_ADDRESS                 _UL_(0xe0018000)                              /* PMC Base Address */
#define PWM_BASE_ADDRESS                 _UL_(0xe1604000)                              /* PWM Base Address */
#define QSPI0_BASE_ADDRESS               _UL_(0xe080c000)                              /* QSPI0 Base Address */
#define QSPI1_BASE_ADDRESS               _UL_(0xe0810000)                              /* QSPI1 Base Address */
#define RSTC_BASE_ADDRESS                _UL_(0xe001d000)                              /* RSTC Base Address */
#define RTC_BASE_ADDRESS                 _UL_(0xe001d0a8)                              /* RTC Base Address */
#define RTT_BASE_ADDRESS                 _UL_(0xe001d020)                              /* RTT Base Address */
#define SCKC_BASE_ADDRESS                _UL_(0xe001d050)                              /* SCKC Base Address */
#define SDMMC0_BASE_ADDRESS              _UL_(0xe1204000)                              /* SDMMC0 Base Address */
#define SDMMC1_BASE_ADDRESS              _UL_(0xe1208000)                              /* SDMMC1 Base Address */
#define SDMMC2_BASE_ADDRESS              _UL_(0xe120c000)                              /* SDMMC2 Base Address */
#define SECUMOD_BASE_ADDRESS             _UL_(0xe0004000)                              /* SECUMOD Base Address */
#define SFR_BASE_ADDRESS                 _UL_(0xe1624000)                              /* SFR Base Address */
#define SFRBU_BASE_ADDRESS               _UL_(0xe0008000)                              /* SFRBU Base Address */
#define SHA_BASE_ADDRESS                 _UL_(0xe1814000)                              /* SHA Base Address */
#define SHDWC_BASE_ADDRESS               _UL_(0xe001d010)                              /* SHDWC Base Address */
#define HSMC_BASE_ADDRESS                _UL_(0xe0808000)                              /* HSMC Base Address */
#define SPDIFRX_BASE_ADDRESS             _UL_(0xe1614000)                              /* SPDIFRX Base Address */
#define SPDIFTX_BASE_ADDRESS             _UL_(0xe1618000)                              /* SPDIFTX Base Address */
#define SSC0_BASE_ADDRESS                _UL_(0xe180c000)                              /* SSC0 Base Address */
#define SSC1_BASE_ADDRESS                _UL_(0xe200c000)                              /* SSC1 Base Address */
#define SYSCWP_BASE_ADDRESS              _UL_(0xe001d0dc)                              /* SYSCWP Base Address */
#define TC0_BASE_ADDRESS                 _UL_(0xe2814000)                              /* TC0 Base Address */
#define TC1_BASE_ADDRESS                 _UL_(0xe0800000)                              /* TC1 Base Address */
#define TCPCA_BASE_ADDRESS               _UL_(0xe0840000)                              /* TCPCA Base Address */
#define TCPCB_BASE_ADDRESS               _UL_(0xe0844000)                              /* TCPCB Base Address */
#define TDES_BASE_ADDRESS                _UL_(0xe2014000)                              /* TDES Base Address */
#define TRNG_BASE_ADDRESS                _UL_(0xe2010000)                              /* TRNG Base Address */
#define TZAESBNS_BASE_ADDRESS            _UL_(0xe0820000)                              /* TZAESBNS Base Address */
#define TZAESBS_BASE_ADDRESS             _UL_(0xe0824000)                              /* TZAESBS Base Address */
#define TZAESBASC_BASE_ADDRESS           _UL_(0xe2000000)                              /* TZAESBASC Base Address */
#define TZC_BASE_ADDRESS                 _UL_(0xe3000000)                              /* TZC Base Address */
#define TZPM_BASE_ADDRESS                _UL_(0xe0010000)                              /* TZPM Base Address */
#define DDRUMCTL_BASE_ADDRESS            _UL_(0xe3800000)                              /* DDRUMCTL Base Address */
#define UDPHSA_BASE_ADDRESS              _UL_(0xe0814000)                              /* UDPHSA Base Address */
#define UDPHSB_BASE_ADDRESS              _UL_(0xe0818000)                              /* UDPHSB Base Address */
#define UHPHS_OHCI_BASE_ADDRESS          _UL_(0x00400000)                              /* UHPHS_OHCI Base Address */
#define UHPHS_EHCI_BASE_ADDRESS          _UL_(0x00500000)                              /* UHPHS_EHCI Base Address */
#define XDMAC0_BASE_ADDRESS              _UL_(0xe2808000)                              /* XDMAC0 Base Address */
#define XDMAC1_BASE_ADDRESS              _UL_(0xe280c000)                              /* XDMAC1 Base Address */
#define XDMAC2_BASE_ADDRESS              _UL_(0xe1200000)                              /* XDMAC2 Base Address */
/** @}  end of Peripheral Base Address Definitions */

/** \addtogroup SAMA7G54_pio Peripheral Pio Definitions
 *  @{
 */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAMA7G54                                             */
/* ************************************************************************** */
#include "pio/sama7g54.h"
/** @}  end of Peripheral Pio Definitions */

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAMA7G54                                  */
/* ************************************************************************** */

#define IROM_SIZE                      _UL_(0x00014000)    /*   80kB Memory segment type: rom */
#define ECC_ROM_SIZE                   _UL_(0x00018000)    /*   96kB Memory segment type: rom */
#define CPKCC_ROM_SIZE                 _UL_(0x00010000)    /*   64kB Memory segment type: rom */
#define CPKCC_RAM_SIZE                 _UL_(0x00001000)    /*    4kB Memory segment type: other */
#define IRAM_SIZE                      _UL_(0x00020000)    /*  128kB Memory segment type: ram */
#define UDPHS_RAMA_SIZE                _UL_(0x00100000)    /* 1024kB Memory segment type: other */
#define UDPHS_RAMB_SIZE                _UL_(0x00100000)    /* 1024kB Memory segment type: other */
#define UHPHS_OHCI_SIZE                _UL_(0x00001000)    /*    4kB Memory segment type: other */
#define UHPHS_EHCI_SIZE                _UL_(0x00100000)    /* 1024kB Memory segment type: other */
#define NFC_RAM_SIZE                   _UL_(0x00003000)    /*   12kB Memory segment type: other */
#define NFC_SIZE                       _UL_(0x08000000)    /* 131072kB Memory segment type: other */
#define QSPIMEM0_SIZE                  _UL_(0x10000000)    /* 262144kB Memory segment type: other */
#define QSPIMEM1_SIZE                  _UL_(0x10000000)    /* 262144kB Memory segment type: other */
#define EBI_CS0_SIZE                   _UL_(0x08000000)    /* 131072kB Memory segment type: other */
#define EBI_CS1_SIZE                   _UL_(0x08000000)    /* 131072kB Memory segment type: other */
#define EBI_CS2_SIZE                   _UL_(0x08000000)    /* 131072kB Memory segment type: other */
#define EBI_CS3_SIZE                   _UL_(0x08000000)    /* 131072kB Memory segment type: other */
#define DDR_CS_SIZE                    _UL_(0x80000000)    /* 2097152kB Memory segment type: other */
#define SECURAM_SIZE                   _UL_(0x00004000)    /*   16kB Memory segment type: other */
#define SDMMC0_SIZE                    _UL_(0x00004000)    /*   16kB Memory segment type: other */
#define SDMMC1_SIZE                    _UL_(0x00004000)    /*   16kB Memory segment type: other */
#define SDMMC2_SIZE                    _UL_(0x00004000)    /*   16kB Memory segment type: other */
#define APB_DBG_S_SIZE                 _UL_(0x00060000)    /*  384kB Memory segment type: other */
#define APB_DBG_SIZE                   _UL_(0x00001000)    /*    4kB Memory segment type: other */
#define NICGPV_SIZE                    _UL_(0x00100000)    /* 1024kB Memory segment type: other */
#define OTPC_SIZE                      _UL_(0x00001000)    /*    4kB Memory segment type: other */
#define CSI2DC_META_SIZE               _UL_(0x00002000)    /*    8kB Memory segment type: other */
#define ARM_PERIPH_SIZE                _UL_(0x00008000)    /*   32kB Memory segment type: io */
#define PERIPHERALS_SIZE               _UL_(0x10000000)    /* 262144kB Memory segment type: io */

#define IROM_ADDR                      _UL_(0x00000000)    /**< IROM base address (type: rom)*/
#define ECC_ROM_ADDR                   _UL_(0x00020000)    /**< ECC_ROM base address (type: rom)*/
#define CPKCC_ROM_ADDR                 _UL_(0x00040000)    /**< CPKCC_ROM base address (type: rom)*/
#define CPKCC_RAM_ADDR                 _UL_(0x00051000)    /**< CPKCC_RAM base address (type: other)*/
#define IRAM_ADDR                      _UL_(0x00100000)    /**< IRAM base address (type: ram)*/
#define UDPHS_RAMA_ADDR                _UL_(0x00200000)    /**< UDPHS_RAMA base address (type: other)*/
#define UDPHS_RAMB_ADDR                _UL_(0x00300000)    /**< UDPHS_RAMB base address (type: other)*/
#define UHPHS_OHCI_ADDR                _UL_(0x00400000)    /**< UHPHS_OHCI base address (type: other)*/
#define UHPHS_EHCI_ADDR                _UL_(0x00500000)    /**< UHPHS_EHCI base address (type: other)*/
#define NFC_RAM_ADDR                   _UL_(0x00600000)    /**< NFC_RAM base address (type: other)*/
#define NFC_ADDR                       _UL_(0x10000000)    /**< NFC base address (type: other)*/
#define QSPIMEM0_ADDR                  _UL_(0x20000000)    /**< QSPIMEM0 base address (type: other)*/
#define QSPIMEM1_ADDR                  _UL_(0x30000000)    /**< QSPIMEM1 base address (type: other)*/
#define EBI_CS0_ADDR                   _UL_(0x40000000)    /**< EBI_CS0 base address (type: other)*/
#define EBI_CS1_ADDR                   _UL_(0x48000000)    /**< EBI_CS1 base address (type: other)*/
#define EBI_CS2_ADDR                   _UL_(0x50000000)    /**< EBI_CS2 base address (type: other)*/
#define EBI_CS3_ADDR                   _UL_(0x58000000)    /**< EBI_CS3 base address (type: other)*/
#define DDR_CS_ADDR                    _UL_(0x60000000)    /**< DDR_CS base address (type: other)*/
#define SECURAM_ADDR                   _UL_(0xe0000000)    /**< SECURAM base address (type: other)*/
#define SDMMC0_ADDR                    _UL_(0xe1204000)    /**< SDMMC0 base address (type: other)*/
#define SDMMC1_ADDR                    _UL_(0xe1208000)    /**< SDMMC1 base address (type: other)*/
#define SDMMC2_ADDR                    _UL_(0xe120c000)    /**< SDMMC2 base address (type: other)*/
#define APB_DBG_S_ADDR                 _UL_(0xe8800000)    /**< APB_DBG_S base address (type: other)*/
#define APB_DBG_ADDR                   _UL_(0xe8900000)    /**< APB_DBG base address (type: other)*/
#define NICGPV_ADDR                    _UL_(0xe8b00000)    /**< NICGPV base address (type: other)*/
#define OTPC_ADDR                      _UL_(0xe8c00000)    /**< OTPC base address (type: other)*/
#define CSI2DC_META_ADDR               _UL_(0xe8c02000)    /**< CSI2DC_META base address (type: other)*/
#define ARM_PERIPH_ADDR                _UL_(0xe8c10000)    /**< ARM_PERIPH base address (type: io)*/
#define PERIPHERALS_ADDR               _UL_(0xe0000000)    /**< PERIPHERALS base address (type: io)*/

/* ************************************************************************** */
/**  DEVICE SIGNATURES FOR SAMA7G54                                           */
/* ************************************************************************** */
#define CHIP_JTAGID                    _UL_(0X05B4203F)
#define CHIP_CIDR                      _UL_(0X80162110)
#define CHIP_EXID                      _UL_(0X00000000)

/* ************************************************************************** */
/**  ELECTRICAL DEFINITIONS FOR SAMA7G54                                      */
/* ************************************************************************** */



#ifdef __cplusplus
}
#endif

/** @}  end of SAMA7G54 definitions */


#endif /* _SAMA7G54_H_ */


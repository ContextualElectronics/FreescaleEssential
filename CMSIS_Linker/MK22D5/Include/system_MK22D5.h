/*
** ###################################################################
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          GNU C Compiler - CodeSourcery Sourcery G++
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K22RM, Rev.4, Feb 2013
**     Version:             rev. 1.7, 2014-05-27
**     Build:               b140603
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright (c) 2014 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2012-06-06)
**         Initial public version.
**     - rev. 1.1 (2012-07-31)
**         Fixed address of SIM_SDID register.
**     - rev. 1.2 (2012-08-29)
**         Update to Rev. 3 of reference manual.
**         Updated UART0, RTC and CRC register definition.
**     - rev. 1.3 (2012-10-11)
**         PDB module update - PDB0_PO1DLY register added.
**     - rev. 1.4 (2013-01-24)
**         Update to Rev. 4 of reference manual.
**     - rev. 1.5 (2013-04-05)
**         Changed start of doxygen comment.
**     - rev. 1.6 (2013-06-24)
**         NV_FOPT register - NMI_DIS bit added.
**     - rev. 1.7 (2014-05-27)
**         Updated to Kinetis SDK support standard.
**         MCG OSC clock select supported (MCG_C7[OSCSEL]).
**
** ###################################################################
*/

/*!
 * @file MK22D5
 * @version 1.7
 * @date 2014-05-27
 * @brief Device specific configuration file for MK22D5 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef SYSTEM_MK22D5_H_
#define SYSTEM_MK22D5_H_                         /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


#define DISABLE_WDOG                   1

#ifndef CLOCK_SETUP
  #define CLOCK_SETUP                  0
#endif

/* MCG mode constants */

#define MCG_MODE_FEI                   0U
#define MCG_MODE_FBI                   1U
#define MCG_MODE_BLPI                  2U
#define MCG_MODE_FEE                   3U
#define MCG_MODE_FBE                   4U
#define MCG_MODE_BLPE                  5U
#define MCG_MODE_PBE                   6U
#define MCG_MODE_PEE                   7U

/* Predefined clock setups
   0 ... Default part configuration
         Multipurpose Clock Generator (MCG) in FEI mode.
         Reference clock source for MCG module: Slow internal reference clock
         Core clock = 20.97152MHz
         Bus clock  = 20.97152MHz
   1 ... Maximum achievable clock frequency configuration
         Multipurpose Clock Generator (MCG) in PEE mode.
         Reference clock source for MCG module: System oscillator 0 reference clock
         Core clock = 50MHz
         Bus clock  = 50MHz
   2 ... Chip internally clocked, ready for Very Low Power Run mode
         Multipurpose Clock Generator (MCG) in BLPI mode.
         Reference clock source for MCG module: Fast internal reference clock
         Core clock = 4MHz
         Bus clock  = 4MHz
   3 ... Chip externally clocked, ready for Very Low Power Run mode
         Multipurpose Clock Generator (MCG) in BLPE mode.
         Reference clock source for MCG module: System oscillator 0 reference clock
         Core clock = 4MHz
         Bus clock  = 4MHz
   4 ... USB clock setup
         Multipurpose Clock Generator (MCG) in PEE mode.
         Reference clock source for MCG module: System oscillator 0 reference clock
         Core clock = 48MHz
         Bus clock  = 48MHz
 */

/* Define clock source values */

#define CPU_XTAL_CLK_HZ                8000000u            /* Value of the external crystal or oscillator clock frequency in Hz */
#define CPU_XTAL32k_CLK_HZ             32768u              /* Value of the external 32k crystal or oscillator clock frequency in Hz */
#define CPU_INT_SLOW_CLK_HZ            32768u              /* Value of the slow internal oscillator clock frequency in Hz  */
#define CPU_INT_FAST_CLK_HZ            4000000u            /* Value of the fast internal oscillator clock frequency in Hz  */
#define CPU_INT_IRC_CLK_HZ             48000000u           /* Value of the 48M internal oscillator clock frequency in Hz  */

/* RTC oscillator setting */
/* #undef RTC_CR_VALUE */                                  /* RTC oscillator not enabled. Commented out for MISRA compliance. */

/* Low power mode enable */
/* SMC_PMPROT: AVLP=1,ALLS=0,AVLLS=0 */
#define SMC_PMPROT_VALUE               0x20U               /* SMC_PMPROT */

/* Internal reference clock trim */
/* #undef SLOW_TRIM_ADDRESS */                             /* Slow oscillator not trimmed. Commented out for MISRA compliance. */
/* #undef SLOW_FINE_TRIM_ADDRESS */                        /* Slow oscillator not trimmed. Commented out for MISRA compliance. */
/* #undef FAST_TRIM_ADDRESS */                             /* Fast oscillator not trimmed. Commented out for MISRA compliance. */
/* #undef FAST_FINE_TRIM_ADDRESS */                        /* Fast oscillator not trimmed. Commented out for MISRA compliance. */

#if (CLOCK_SETUP == 0)
  #define DEFAULT_SYSTEM_CLOCK         20971520u           /* Default System clock value */
  #define MCG_MODE                     MCG_MODE_FEI /* Clock generator mode */
  /* MCG_C1: CLKS=0,FRDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x06U               /* MCG_C1 */
  /* MCG_C2: LOCRE0=0,RANGE0=2,HGO0=0,EREFS0=1,LP=0,IRCS=0 */
  #define MCG_C2_VALUE                 0x24U               /* MCG_C2 */
  /* MCG_C4: DMX32=0,DRST_DRS=0,FCTRIM=0,SCFTRIM=0 */
  #define MCG_C4_VALUE                 0x00U               /* MCG_C4 */
  /* MCG_SC: ATME=0,ATMS=0,ATMF=0,FLTPRSRV=0,FCRDIV=0,LOCS0=0 */
  #define MCG_SC_VALUE                 0x00U               /* MCG_SC */
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
  #define MCG_C5_VALUE                 0x00U               /* MCG_C5 */
/* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
  #define MCG_C6_VALUE                 0x00U               /* MCG_C6 */
/* MCG_C7: OSCSEL=0 */
  #define MCG_C7_VALUE                 0x00U               /* MCG_C7 */
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: LPWUI=0,RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV4=1 */
  #define SIM_CLKDIV1_VALUE            0x00010000U         /* SIM_CLKDIV1 */
/* SIM_SOPT1: USBREGEN=0,USBSSTBY=0,USBVSTBY=0,OSC32KSEL=3,RAMSIZE=0 */
  #define SIM_SOPT1_VALUE              0x000C0000U         /* SIM_SOPT1 */
/* SIM_SOPT2: USBSRC=0,PLLFLLSEL=0,TRACECLKSEL=0,PTD7PAD=0,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SIM_SOPT2_VALUE              0x00U               /* SIM_SOPT2 */
#elif (CLOCK_SETUP == 1)
  #define DEFAULT_SYSTEM_CLOCK         50000000u           /* Default System clock value */
  #define MCG_MODE                     MCG_MODE_PEE /* Clock generator mode */
  /* MCG_C1: CLKS=0,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x1AU               /* MCG_C1 */
  /* MCG_C2: LOCRE0=0,RANGE0=2,HGO0=0,EREFS0=1,LP=0,IRCS=0 */
  #define MCG_C2_VALUE                 0x24U               /* MCG_C2 */
  /* MCG_C4: DMX32=0,DRST_DRS=0,FCTRIM=0,SCFTRIM=0 */
  #define MCG_C4_VALUE                 0x00U               /* MCG_C4 */
  /* MCG_SC: ATME=0,ATMS=0,ATMF=0,FLTPRSRV=0,FCRDIV=0,LOCS0=0 */
  #define MCG_SC_VALUE                 0x00U               /* MCG_SC */
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=1 */
  #define MCG_C5_VALUE                 0x01U               /* MCG_C5 */
/* MCG_C6: LOLIE0=0,PLLS=1,CME0=0,VDIV0=1 */
  #define MCG_C6_VALUE                 0x41U               /* MCG_C6 */
/* MCG_C7: OSCSEL=0 */
  #define MCG_C7_VALUE                 0x00U               /* MCG_C7 */
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: LPWUI=0,RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=1,OUTDIV2=1,OUTDIV4=3 */
  #define SIM_CLKDIV1_VALUE            0x11030000U         /* SIM_CLKDIV1 */
/* SIM_SOPT1: USBREGEN=0,USBSSTBY=0,USBVSTBY=0,OSC32KSEL=3,RAMSIZE=0 */
  #define SIM_SOPT1_VALUE              0x000C0000U         /* SIM_SOPT1 */
/* SIM_SOPT2: USBSRC=0,PLLFLLSEL=0,TRACECLKSEL=0,PTD7PAD=0,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SIM_SOPT2_VALUE              0x00U               /* SIM_SOPT2 */
#elif (CLOCK_SETUP == 2)
  #define DEFAULT_SYSTEM_CLOCK         4000000u            /* Default System clock value */
  #define MCG_MODE                     MCG_MODE_BLPI /* Clock generator mode */
  /* MCG_C1: CLKS=1,FRDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x46U               /* MCG_C1 */
  /* MCG_C2: LOCRE0=0,RANGE0=2,HGO0=0,EREFS0=1,LP=1,IRCS=1 */
  #define MCG_C2_VALUE                 0x27U               /* MCG_C2 */
  /* MCG_C4: DMX32=0,DRST_DRS=0,FCTRIM=0,SCFTRIM=0 */
  #define MCG_C4_VALUE                 0x00U               /* MCG_C4 */
  /* MCG_SC: ATME=0,ATMS=0,ATMF=0,FLTPRSRV=0,FCRDIV=0,LOCS0=0 */
  #define MCG_SC_VALUE                 0x00U               /* MCG_SC */
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
  #define MCG_C5_VALUE                 0x00U               /* MCG_C5 */
/* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
  #define MCG_C6_VALUE                 0x00U               /* MCG_C6 */
/* MCG_C7: OSCSEL=0 */
  #define MCG_C7_VALUE                 0x00U               /* MCG_C7 */
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: LPWUI=0,RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV4=4 */
  #define SIM_CLKDIV1_VALUE            0x00040000U         /* SIM_CLKDIV1 */
/* SIM_SOPT1: USBREGEN=0,USBSSTBY=0,USBVSTBY=0,OSC32KSEL=3,RAMSIZE=0 */
  #define SIM_SOPT1_VALUE              0x000C0000U         /* SIM_SOPT1 */
/* SIM_SOPT2: USBSRC=0,PLLFLLSEL=0,TRACECLKSEL=0,PTD7PAD=0,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SIM_SOPT2_VALUE              0x00U               /* SIM_SOPT2 */
#elif (CLOCK_SETUP == 3)
  #define DEFAULT_SYSTEM_CLOCK         4000000u            /* Default System clock value */
  #define MCG_MODE                     MCG_MODE_BLPE /* Clock generator mode */
  /* MCG_C1: CLKS=2,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x9AU               /* MCG_C1 */
  /* MCG_C2: LOCRE0=0,RANGE0=2,HGO0=0,EREFS0=1,LP=1,IRCS=1 */
  #define MCG_C2_VALUE                 0x27U               /* MCG_C2 */
  /* MCG_C4: DMX32=0,DRST_DRS=0,FCTRIM=0,SCFTRIM=0 */
  #define MCG_C4_VALUE                 0x00U               /* MCG_C4 */
  /* MCG_SC: ATME=0,ATMS=0,ATMF=0,FLTPRSRV=0,FCRDIV=0,LOCS0=0 */
  #define MCG_SC_VALUE                 0x00U               /* MCG_SC */
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
  #define MCG_C5_VALUE                 0x00U               /* MCG_C5 */
/* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
  #define MCG_C6_VALUE                 0x00U               /* MCG_C6 */
/* MCG_C7: OSCSEL=0 */
  #define MCG_C7_VALUE                 0x00U               /* MCG_C7 */
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: LPWUI=0,RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=1,OUTDIV2=1,OUTDIV4=7 */
  #define SIM_CLKDIV1_VALUE            0x11070000U         /* SIM_CLKDIV1 */
/* SIM_SOPT1: USBREGEN=0,USBSSTBY=0,USBVSTBY=0,OSC32KSEL=3,RAMSIZE=0 */
  #define SIM_SOPT1_VALUE              0x000C0000U         /* SIM_SOPT1 */
/* SIM_SOPT2: USBSRC=0,PLLFLLSEL=0,TRACECLKSEL=0,PTD7PAD=0,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SIM_SOPT2_VALUE              0x00U               /* SIM_SOPT2 */
#elif (CLOCK_SETUP == 4)
  #define DEFAULT_SYSTEM_CLOCK         48000000u           /* Default System clock value */
  #define MCG_MODE                     MCG_MODE_PEE /* Clock generator mode */
  /* MCG_C1: CLKS=0,FRDIV=3,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x1AU               /* MCG_C1 */
  /* MCG_C2: LOCRE0=0,RANGE0=2,HGO0=0,EREFS0=1,LP=0,IRCS=0 */
  #define MCG_C2_VALUE                 0x24U               /* MCG_C2 */
  /* MCG_C4: DMX32=0,DRST_DRS=0,FCTRIM=0,SCFTRIM=0 */
  #define MCG_C4_VALUE                 0x00U               /* MCG_C4 */
  /* MCG_SC: ATME=0,ATMS=0,ATMF=0,FLTPRSRV=0,FCRDIV=0,LOCS0=0 */
  #define MCG_SC_VALUE                 0x00U               /* MCG_SC */
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=3 */
  #define MCG_C5_VALUE                 0x03U               /* MCG_C5 */
/* MCG_C6: LOLIE0=0,PLLS=1,CME0=0,VDIV0=0 */
  #define MCG_C6_VALUE                 0x40U               /* MCG_C6 */
/* MCG_C7: OSCSEL=0 */
  #define MCG_C7_VALUE                 0x00U               /* MCG_C7 */
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: LPWUI=0,RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV4=1 */
  #define SIM_CLKDIV1_VALUE            0x00010000U         /* SIM_CLKDIV1 */
/* SIM_SOPT1: USBREGEN=0,USBSSTBY=0,USBVSTBY=0,OSC32KSEL=3,RAMSIZE=0 */
  #define SIM_SOPT1_VALUE              0x000C0000U         /* SIM_SOPT1 */
/* SIM_SOPT2: USBSRC=0,PLLFLLSEL=0,TRACECLKSEL=0,PTD7PAD=0,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SIM_SOPT2_VALUE              0x00U               /* SIM_SOPT2 */
#endif


/**
 * @brief System clock frequency (core clock)
 *
 * The system clock frequency supplied to the SysTick timer and the processor
 * core clock. This variable can be used by the user application to setup the
 * SysTick timer or configure other parameters. It may also be used by debugger to
 * query the frequency of the debug timer or configure the trace clock speed
 * SystemCoreClock is initialized with a correct predefined value.
 */
extern uint32_t SystemCoreClock;

/**
 * @brief Setup the microcontroller system.
 *
 * Typically this function configures the oscillator (PLL) that is part of the
 * microcontroller device. For systems with variable clock speed it also updates
 * the variable SystemCoreClock. SystemInit is called from startup_device file.
 */
void SystemInit (void);

/**
 * @brief Updates the SystemCoreClock variable.
 *
 * It must be called whenever the core clock is changed during program
 * execution. SystemCoreClockUpdate() evaluates the clock register settings and calculates
 * the current core clock.
 */
void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif  /* #if !defined(SYSTEM_MK22D5_H_) */

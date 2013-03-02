//*****************************************************************************
//*****************************************************************************
//  FILENAME: Timer32.h
//   Version: 2.6, Updated on 2012/9/21 at 11:59:43
//  Generated by PSoC Designer 5.3.2710
//
//  DESCRIPTION: Timer32 User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef Timer32_INCLUDE
#define Timer32_INCLUDE

#include <m8c.h>

#pragma fastcall16 Timer32_EnableInt
#pragma fastcall16 Timer32_DisableInt
#pragma fastcall16 Timer32_Start
#pragma fastcall16 Timer32_Stop
#pragma fastcall16 Timer32_ReadTimer               // Read  DR0
#pragma fastcall16 Timer32_ReadTimerSaveCV         // Read  DR0
#pragma fastcall16 Timer32_WritePeriod             // Write DR1
#pragma fastcall16 Timer32_ReadCompareValue        // Read  DR2
#pragma fastcall16 Timer32_WriteCompareValue       // Write DR2

// The following symbols are deprecated.
// They may be omitted in future releases
//
#pragma fastcall16 Timer32_ReadCounter              // Read  DR0 "Obsolete"
#pragma fastcall16 Timer32_CaptureCounter           // Read  DR0 "Obsolete"


//-------------------------------------------------
// Prototypes of the Timer32 API.
//-------------------------------------------------

extern void Timer32_EnableInt(void);                                    // Proxy Class 1
extern void Timer32_DisableInt(void);                                   // Proxy Class 1
extern void Timer32_Start(void);                                        // Proxy Class 1
extern void Timer32_Stop(void);                                         // Proxy Class 1
extern void Timer32_ReadTimer(DWORD * pdwCount);                        // Proxy Class 3
extern void Timer32_ReadTimerSaveCV(DWORD * pdwCount);                  // Proxy Class 3
extern void Timer32_WritePeriod(DWORD dwPeriod);                        // Proxy Class 2
extern void Timer32_ReadCompareValue(DWORD * pdwCompareValue);          // Proxy Class 3
extern void Timer32_WriteCompareValue(DWORD dwCompareValue);            // Proxy Class 2

// The following functions are deprecated.
// They may be omitted in future releases
//
extern void Timer32_ReadCounter(DWORD * pdwCount);          // Obsolete
extern void Timer32_CaptureCounter(DWORD * pdwCount);       // Obsolete


//--------------------------------------------------
// Constants for Timer32 API's.
//--------------------------------------------------

#define Timer32_CONTROL_REG_START_BIT          ( 0x01 )
#define Timer32_INT_REG_ADDR                   ( 0x0e1 )
#define Timer32_INT_MASK                       ( 0x08 )


//--------------------------------------------------
// Constants for Timer32 user defined values
//--------------------------------------------------

#define Timer32_PERIOD                         ( 0x0 )
#define Timer32_COMPARE_VALUE                  ( 0x0 )


//-------------------------------------------------
// Register Addresses for Timer32
//-------------------------------------------------

#pragma ioport  Timer32_COUNTER_LSB_REG:    0x020          //Count register LSB
BYTE            Timer32_COUNTER_LSB_REG;
#pragma ioport  Timer32_COUNTER_ISB1_REG:   0x024          //Count register ISB1
BYTE            Timer32_COUNTER_ISB1_REG;
#pragma ioport  Timer32_COUNTER_ISB2_REG:   0x028          //Count register ISB2
BYTE            Timer32_COUNTER_ISB2_REG;
#pragma ioport  Timer32_COUNTER_MSB_REG:    0x02c          //Count register MSB
BYTE            Timer32_COUNTER_MSB_REG;
#pragma ioport  Timer32_PERIOD_LSB_REG: 0x021              //Period register LSB
BYTE            Timer32_PERIOD_LSB_REG;
#pragma ioport  Timer32_PERIOD_ISB1_REG:    0x025          //Period register ISB1
BYTE            Timer32_PERIOD_ISB1_REG;
#pragma ioport  Timer32_PERIOD_ISB2_REG:    0x029          //Period register ISB2
BYTE            Timer32_PERIOD_ISB2_REG;
#pragma ioport  Timer32_PERIOD_MSB_REG: 0x02d              //Period register MSB
BYTE            Timer32_PERIOD_MSB_REG;
#pragma ioport  Timer32_COMPARE_LSB_REG:    0x022          //Compare register LSB
BYTE            Timer32_COMPARE_LSB_REG;
#pragma ioport  Timer32_COMPARE_ISB1_REG:   0x026          //Compare register ISB1
BYTE            Timer32_COMPARE_ISB1_REG;
#pragma ioport  Timer32_COMPARE_ISB2_REG:   0x02a          //Compare register ISB2
BYTE            Timer32_COMPARE_ISB2_REG;
#pragma ioport  Timer32_COMPARE_MSB_REG:    0x02e          //Compare register MSB
BYTE            Timer32_COMPARE_MSB_REG;
#pragma ioport  Timer32_CONTROL_LSB_REG:    0x023          //Control register LSB
BYTE            Timer32_CONTROL_LSB_REG;
#pragma ioport  Timer32_CONTROL_ISB1_REG:   0x027          //Control register ISB1
BYTE            Timer32_CONTROL_ISB1_REG;
#pragma ioport  Timer32_CONTROL_ISB2_REG:   0x02b          //Control register ISB2
BYTE            Timer32_CONTROL_ISB2_REG;
#pragma ioport  Timer32_CONTROL_MSB_REG:    0x02f          //Control register MSB
BYTE            Timer32_CONTROL_MSB_REG;
#pragma ioport  Timer32_FUNC_LSB_REG:   0x120              //Function register LSB
BYTE            Timer32_FUNC_LSB_REG;
#pragma ioport  Timer32_FUNC_ISB1_REG:  0x124              //Function register ISB1
BYTE            Timer32_FUNC_ISB1_REG;
#pragma ioport  Timer32_FUNC_ISB2_REG:  0x128              //Function register ISB2
BYTE            Timer32_FUNC_ISB2_REG;
#pragma ioport  Timer32_FUNC_MSB_REG:   0x12c              //Function register MSB
BYTE            Timer32_FUNC_MSB_REG;
#pragma ioport  Timer32_INPUT_LSB_REG:  0x121              //Input register LSB
BYTE            Timer32_INPUT_LSB_REG;
#pragma ioport  Timer32_INPUT_ISB1_REG: 0x125              //Input register ISB1
BYTE            Timer32_INPUT_ISB1_REG;
#pragma ioport  Timer32_INPUT_ISB2_REG: 0x129              //Input register ISB2
BYTE            Timer32_INPUT_ISB2_REG;
#pragma ioport  Timer32_INPUT_MSB_REG:  0x12d              //Input register MSB
BYTE            Timer32_INPUT_MSB_REG;
#pragma ioport  Timer32_OUTPUT_LSB_REG: 0x122              //Output register LSB
BYTE            Timer32_OUTPUT_LSB_REG;
#pragma ioport  Timer32_OUTPUT_ISB1_REG:    0x126          //Output register ISB1
BYTE            Timer32_OUTPUT_ISB1_REG;
#pragma ioport  Timer32_OUTPUT_ISB2_REG:    0x12a          //Output register ISB2
BYTE            Timer32_OUTPUT_ISB2_REG;
#pragma ioport  Timer32_OUTPUT_MSB_REG: 0x12e              //Output register MSB
BYTE            Timer32_OUTPUT_MSB_REG;
#pragma ioport  Timer32_INT_REG:       0x0e1               //Interrupt Mask Register
BYTE            Timer32_INT_REG;


//-------------------------------------------------
// Timer32 Macro 'Functions'
//-------------------------------------------------

#define Timer32_Start_M \
   ( Timer32_CONTROL_LSB_REG |=  Timer32_CONTROL_REG_START_BIT )

#define Timer32_Stop_M  \
   ( Timer32_CONTROL_LSB_REG &= ~Timer32_CONTROL_REG_START_BIT )

#define Timer32_EnableInt_M   \
   M8C_EnableIntMask(  Timer32_INT_REG, Timer32_INT_MASK )

#define Timer32_DisableInt_M  \
   M8C_DisableIntMask( Timer32_INT_REG, Timer32_INT_MASK )

#endif
// end of file Timer32.h

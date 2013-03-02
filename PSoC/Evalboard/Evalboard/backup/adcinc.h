//*****************************************************************************
//*****************************************************************************
//  FILENAME: ADCINC.h
//  Version: 1.20, Updated on 2011/6/28 at 6:7:58
//	Generated by PSoC Designer 5.1.2306
//
//  DESCRIPTION:  C declarations for the ADCINC User Module with
//                a 1st-order modulator.
//-----------------------------------------------------------------------------
//      Copyright (c) Cypress Semiconductor 2011. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef ADCINC_INCLUDE
#define ADCINC_INCLUDE

#include <m8c.h>

#pragma fastcall16 ADCINC_Start
#pragma fastcall16 ADCINC_SetPower
#pragma fastcall16 ADCINC_Stop
#pragma fastcall16 ADCINC_GetSamples
#pragma fastcall16 ADCINC_StopADC
#pragma fastcall16 ADCINC_fIsDataAvailable
#pragma fastcall16 ADCINC_iClearFlagGetData
#pragma fastcall16 ADCINC_wClearFlagGetData
#pragma fastcall16 ADCINC_cClearFlagGetData
#pragma fastcall16 ADCINC_bClearFlagGetData
#pragma fastcall16 ADCINC_iGetData
#pragma fastcall16 ADCINC_wGetData
#pragma fastcall16 ADCINC_cGetData
#pragma fastcall16 ADCINC_bGetData
#pragma fastcall16 ADCINC_fClearFlag
#pragma fastcall16 ADCINC_WritePulseWidth

//-------------------------------------------------
// Prototypes of the ADCINC API.
//-------------------------------------------------
extern void  ADCINC_Start(BYTE bPower);
extern void  ADCINC_SetPower(BYTE bPower);
extern void  ADCINC_Stop(void);
extern void  ADCINC_GetSamples(BYTE bNumSamples);
extern void  ADCINC_StopADC(void);
extern BYTE  ADCINC_fIsDataAvailable(void);
extern INT   ADCINC_iClearFlagGetData(void);
extern WORD  ADCINC_wClearFlagGetData(void);
extern CHAR  ADCINC_cClearFlagGetData(void);
extern BYTE  ADCINC_bClearFlagGetData(void);
extern INT   ADCINC_iGetData(void);
extern WORD  ADCINC_wGetData(void);
extern CHAR  ADCINC_cGetData(void);
extern BYTE  ADCINC_bGetData(void);
extern BYTE  ADCINC_fClearFlag(void);
extern void  ADCINC_WritePulseWidth(BYTE bPulseWidthValue);


//-------------------------------------------------
// Defines for ADCINC API's.
//-------------------------------------------------
#define ADCINC_OFF         0
#define ADCINC_LOWPOWER    1
#define ADCINC_MEDPOWER    2
#define ADCINC_HIGHPOWER   3


//-------------------------------------------------
// Hardware Register Definitions
//-------------------------------------------------
#pragma ioport  ADCINC_PWMdr0:  0x028                 //Period reg
BYTE            ADCINC_PWMdr0;
#pragma ioport  ADCINC_PWMdr1:  0x029                 //1_ADDRh   ; Down count reg
BYTE            ADCINC_PWMdr1;               
#pragma ioport  ADCINC_PWMdr2:  0x02a                 //Compare reg
BYTE            ADCINC_PWMdr2;
#pragma ioport  ADCINC_PWMcr0:  0x02b                 //Control reg
BYTE            ADCINC_PWMcr0;
#pragma ioport  ADCINC_PWMfn:   0x128                  //Function reg
BYTE            ADCINC_PWMfn;
#pragma ioport  ADCINC_PWMsl:   0x129                  //Input select reg
BYTE            ADCINC_PWMsl;
#pragma ioport  ADCINC_PWMos:   0x12a                  //Output select reg
BYTE            ADCINC_PWMos;
#pragma ioport  ADCINC_AtoDcr0: 0x080                //SC Block Control Reg 0
BYTE            ADCINC_AtoDcr0;
#pragma ioport  ADCINC_AtoDcr1: 0x081                //SC Block Control Reg 1
BYTE            ADCINC_AtoDcr1;
#pragma ioport  ADCINC_AtoDcr2: 0x082                //SC Block Control Reg 2
BYTE            ADCINC_AtoDcr2;
#pragma ioport  ADCINC_AtoDcr3: 0x083                //SC Block Control Reg 3
BYTE            ADCINC_AtoDcr3;

#endif
// end of file ADCINC.h

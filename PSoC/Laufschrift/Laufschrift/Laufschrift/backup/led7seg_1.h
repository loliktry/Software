//*****************************************************************************
//*****************************************************************************
//  FILENAME: LED7SEG_1.h
//   Version: 1.20, Updated on 2011/6/28 at 6:9:36                                          
//  Generated by PSoC Designer 5.1.2306
//
//  DESCRIPTION: LED7SEG_1 User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2011. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef LED7SEG_1_INCLUDE
#define LED7SEG_1_INCLUDE

#include <m8c.h>


/* Create pragmas to support proper argument and return value passing */
#pragma fastcall16  LED7SEG_1_Dim
#pragma fastcall16  LED7SEG_1_PutHex
#pragma fastcall16  LED7SEG_1_PutPattern
#pragma fastcall16  LED7SEG_1_DP 
#pragma fastcall16  LED7SEG_1_DispInt


//-------------------------------------------------
// Constants for LED7SEG_1 API's.
//-------------------------------------------------
//
//
extern BYTE LED7SEG_1_DigitRAM[];
extern BYTE LED7SEG_1_ScanStatus;

//-------------------------------------------------
// Prototypes of the LED7SEG_1 API.
//-------------------------------------------------
extern void  LED7SEG_1_Start(void);    
extern void  LED7SEG_1_Stop(void);    
extern void  LED7SEG_1_Dim(BYTE bDim);    
extern void  LED7SEG_1_Update(void);    
extern void  LED7SEG_1_PutHex(BYTE bValue, BYTE bDigit);                 
extern void  LED7SEG_1_PutPattern(BYTE bPattern, BYTE bDigit);                 
extern void  LED7SEG_1_DP(BYTE bOnOff, BYTE bDigit);                 
extern void  LED7SEG_1_DispInt(int iValue, BYTE bPos, BYTE bLen);                 

//-------------------------------------------------
// Define global variables.                 
//-------------------------------------------------

#define LED7SEG_1_Digit1   0x01    
#define LED7SEG_1_Digit2   0x02    
#define LED7SEG_1_Digit3   0x04    
#define LED7SEG_1_Digit4   0x08    
#define LED7SEG_1_Digit5   0x10    
#define LED7SEG_1_Digit6   0x20    
#define LED7SEG_1_Digit7   0x40    
#define LED7SEG_1_Digit8   0x80    

#define LED7SEG_1_DimOn    0x01    
#define LED7SEG_1_DimOff   0x00    

#define LED7SEG_1_DpOn     0x01    
#define LED7SEG_1_DpOff    0x00    


#endif

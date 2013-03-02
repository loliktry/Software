//*****************************************************************************
//*****************************************************************************
//  FILENAME: I2CHWMstr.h
//   Version: 1.90, Updated on 2012/9/21 at 11:59:4
//  Generated by PSoC Designer 5.3.2710
//
//  DESCRIPTION: UMName User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************

#include <m8c.h>

#ifndef I2CHW_MSTR_INCLUDE
#define I2CHW_MSTR_INCLUDE
#endif

// Create pragmas to support proper argument and return value passing

#ifdef I2CHW_MMS_INCLUDE
#pragma fastcall16  I2CHW_fReadBytesNoStall
#pragma fastcall16  I2CHW_bWriteBytesNoStall
#pragma fastcall16  I2CHW_bWriteCBytesNoStall
#endif

#pragma fastcall16  I2CHW_fReadBytes
#pragma fastcall16  I2CHW_bWriteBytes
#pragma fastcall16  I2CHW_bWriteCBytes
#pragma fastcall16  I2CHW_fSendStart
#pragma fastcall16  I2CHW_fSendRepeatStart
#pragma fastcall16  I2CHW_SendStop
#pragma fastcall16  I2CHW_fWrite
#pragma fastcall16  I2CHW_bRead

#ifndef I2CHW_MMS_INCLUDE
#pragma fastcall16  I2CHW_bReadBusStatus
#endif

//-------------------------------------------------
// Prototypes of the I2CHW API.
//-------------------------------------------------
// High level commands
#ifdef I2CHW_MMS_INCLUDE
// Read bCnt bytes of data from slave at bSlaveAddr using mode bMode, place data (UCHAR) pbXferData[]
// Returns 0xFF if tst reg[I2CHW_MSCR], I2CM_BUSBUSY is true, else jumps to I2C_BusFree1
extern BYTE  I2CHW_fReadBytesNoStall(BYTE bSlaveAddr, BYTE * pbXferData, BYTE bCnt, BYTE bMode);
// Read bCnt bytes of data from slave at bSlaveAddr using mode bMode, write data from (UCHAR) pbXferData[]
// Returns 0xFF if tst reg[I2CHW_MSCR], I2CM_BUSBUSY is true, else jumps to I2C_BusFree2
extern BYTE  I2CHW_bWriteBytesNoStall(BYTE bSlaveAddr, BYTE * pbXferData, BYTE bCnt, BYTE bMode);
// Read bCnt bytes of data from slave at bSlaveAddr using mode bMode, write data from (const UCHAR) pbXferData[]
// Returns 0xFF if tst reg[I2CHW_MSCR], I2CM_BUSBUSY is true, else jumps to I2C_BusFree1
extern BYTE  I2CHW_bWriteCBytesNoStall(BYTE bSlaveAddr, const BYTE * pcbXferData, BYTE bCnt, BYTE bMode);
#endif

// Read bCnt bytes of data from slave at bSlaveAddr using mode bMode, place data (UCHAR) pbXferData[]
extern void  I2CHW_fReadBytes(BYTE bSlaveAddr, BYTE * pbXferData, BYTE bCnt, BYTE bMode);
// Read bCnt bytes of data from slave at bSlaveAddr using mode bMode, write data from (UCHAR) pbXferData[]
extern void  I2CHW_bWriteBytes(BYTE bSlaveAddr, BYTE * pbXferData, BYTE bCnt, BYTE bMode);
// Read bCnt bytes of data from slave at bSlaveAddr using mode bMode, write data from (const UCHAR) pbXferData[]
extern void  I2CHW_bWriteCBytes(BYTE bSlaveAddr, const BYTE * pcbXferData, BYTE bCnt, BYTE bMode);

// Low level commands
extern BYTE  I2CHW_fSendStart(BYTE bSlaveAddr, BYTE fRW);
extern BYTE  I2CHW_fSendRepeatStart(BYTE bSlaveAddr, BYTE fRW);
extern void  I2CHW_SendStop(void);
extern BYTE  I2CHW_fWrite(BYTE bData);
extern BYTE  I2CHW_bRead(BYTE fACK);

#ifndef I2CHW_MMS_INCLUDE
extern BYTE  I2CHW_bReadBusStatus(void);
#endif

//-------------------------------------------------
// Status variables for I2CHW API's.
//-------------------------------------------------
extern char I2CHW_bStatus;
extern char I2CHW_RsrcStatus;

//
//export only the count values used in the i/o processing routine
//


#define I2CHW_READ_BUFTYPE                   0x0
#define I2CHW_READ_FLASH                     I2CHW_READ_BUFTYPE & 0x01

extern unsigned char     I2CHW_Write_Count;

#if (I2CHW_READ_BUFTYPE)
extern unsigned int    I2CHW_Read_CountHI;

#endif
extern unsigned char    I2CHW_Read_Count;


//-------------------------------------------------
// Constants for I2CHW API's.
//-------------------------------------------------
#define I2CHW_CompleteXfer   0x00 // Perform a complete I2C transfer
#define I2CHW_RepStart       0x01 // Perform a complete transfer with a Repeat Start
#define I2CHW_NoStop         0x02 // Perform a complete transfer, but leave off the stop
#define I2CHW_NAKnextWr      0x04 // Flag to tell slave to NAK next byte from master

#define I2CHW_READ           0x01 // Set the R/W flag after the slave address.
#define I2CHW_WRITE          0x00 // Clear the R/W flag after the slave address.

#define I2CHW_XFER_ERROR     0x00 // Communication error with the slave.
#define I2CHW_NAKslave       0x00 // NAK the slave after a read.
#define I2CHW_ACKslave       0x01 // ACK the slave after a read.

// end of file I2CHWMstr.h


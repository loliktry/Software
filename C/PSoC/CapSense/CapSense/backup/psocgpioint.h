/******************************************************************************
*  Generated by PSoC Designer 5.3.2710
******************************************************************************/
#include <m8c.h>
// CSDCapacitor address and mask defines
#pragma	ioport	CSDCapacitor_Data_ADDR:	0x0
BYTE			CSDCapacitor_Data_ADDR;
#pragma	ioport	CSDCapacitor_DriveMode_0_ADDR:	0x100
BYTE			CSDCapacitor_DriveMode_0_ADDR;
#pragma	ioport	CSDCapacitor_DriveMode_1_ADDR:	0x101
BYTE			CSDCapacitor_DriveMode_1_ADDR;
#pragma	ioport	CSDCapacitor_DriveMode_2_ADDR:	0x3
BYTE			CSDCapacitor_DriveMode_2_ADDR;
#pragma	ioport	CSDCapacitor_GlobalSelect_ADDR:	0x2
BYTE			CSDCapacitor_GlobalSelect_ADDR;
#pragma	ioport	CSDCapacitor_IntCtrl_0_ADDR:	0x102
BYTE			CSDCapacitor_IntCtrl_0_ADDR;
#pragma	ioport	CSDCapacitor_IntCtrl_1_ADDR:	0x103
BYTE			CSDCapacitor_IntCtrl_1_ADDR;
#pragma	ioport	CSDCapacitor_IntEn_ADDR:	0x1
BYTE			CSDCapacitor_IntEn_ADDR;
#define CSDCapacitor_MASK 0x2
#pragma	ioport	CSDCapacitor_MUXBusCtrl_ADDR:	0x1d8
BYTE			CSDCapacitor_MUXBusCtrl_ADDR;
// EzI2CsSDA address and mask defines
#pragma	ioport	EzI2CsSDA_Data_ADDR:	0x4
BYTE			EzI2CsSDA_Data_ADDR;
#pragma	ioport	EzI2CsSDA_DriveMode_0_ADDR:	0x104
BYTE			EzI2CsSDA_DriveMode_0_ADDR;
#pragma	ioport	EzI2CsSDA_DriveMode_1_ADDR:	0x105
BYTE			EzI2CsSDA_DriveMode_1_ADDR;
#pragma	ioport	EzI2CsSDA_DriveMode_2_ADDR:	0x7
BYTE			EzI2CsSDA_DriveMode_2_ADDR;
#pragma	ioport	EzI2CsSDA_GlobalSelect_ADDR:	0x6
BYTE			EzI2CsSDA_GlobalSelect_ADDR;
#pragma	ioport	EzI2CsSDA_IntCtrl_0_ADDR:	0x106
BYTE			EzI2CsSDA_IntCtrl_0_ADDR;
#pragma	ioport	EzI2CsSDA_IntCtrl_1_ADDR:	0x107
BYTE			EzI2CsSDA_IntCtrl_1_ADDR;
#pragma	ioport	EzI2CsSDA_IntEn_ADDR:	0x5
BYTE			EzI2CsSDA_IntEn_ADDR;
#define EzI2CsSDA_MASK 0x1
#pragma	ioport	EzI2CsSDA_MUXBusCtrl_ADDR:	0x1d9
BYTE			EzI2CsSDA_MUXBusCtrl_ADDR;
// EzI2CsSCL address and mask defines
#pragma	ioport	EzI2CsSCL_Data_ADDR:	0x4
BYTE			EzI2CsSCL_Data_ADDR;
#pragma	ioport	EzI2CsSCL_DriveMode_0_ADDR:	0x104
BYTE			EzI2CsSCL_DriveMode_0_ADDR;
#pragma	ioport	EzI2CsSCL_DriveMode_1_ADDR:	0x105
BYTE			EzI2CsSCL_DriveMode_1_ADDR;
#pragma	ioport	EzI2CsSCL_DriveMode_2_ADDR:	0x7
BYTE			EzI2CsSCL_DriveMode_2_ADDR;
#pragma	ioport	EzI2CsSCL_GlobalSelect_ADDR:	0x6
BYTE			EzI2CsSCL_GlobalSelect_ADDR;
#pragma	ioport	EzI2CsSCL_IntCtrl_0_ADDR:	0x106
BYTE			EzI2CsSCL_IntCtrl_0_ADDR;
#pragma	ioport	EzI2CsSCL_IntCtrl_1_ADDR:	0x107
BYTE			EzI2CsSCL_IntCtrl_1_ADDR;
#pragma	ioport	EzI2CsSCL_IntEn_ADDR:	0x5
BYTE			EzI2CsSCL_IntEn_ADDR;
#define EzI2CsSCL_MASK 0x2
#pragma	ioport	EzI2CsSCL_MUXBusCtrl_ADDR:	0x1d9
BYTE			EzI2CsSCL_MUXBusCtrl_ADDR;
// CSDSW1 address and mask defines
#pragma	ioport	CSDSW1_Data_ADDR:	0xc
BYTE			CSDSW1_Data_ADDR;
#pragma	ioport	CSDSW1_DriveMode_0_ADDR:	0x10c
BYTE			CSDSW1_DriveMode_0_ADDR;
#pragma	ioport	CSDSW1_DriveMode_1_ADDR:	0x10d
BYTE			CSDSW1_DriveMode_1_ADDR;
#pragma	ioport	CSDSW1_DriveMode_2_ADDR:	0xf
BYTE			CSDSW1_DriveMode_2_ADDR;
#pragma	ioport	CSDSW1_GlobalSelect_ADDR:	0xe
BYTE			CSDSW1_GlobalSelect_ADDR;
#pragma	ioport	CSDSW1_IntCtrl_0_ADDR:	0x10e
BYTE			CSDSW1_IntCtrl_0_ADDR;
#pragma	ioport	CSDSW1_IntCtrl_1_ADDR:	0x10f
BYTE			CSDSW1_IntCtrl_1_ADDR;
#pragma	ioport	CSDSW1_IntEn_ADDR:	0xd
BYTE			CSDSW1_IntEn_ADDR;
#define CSDSW1_MASK 0x1
#pragma	ioport	CSDSW1_MUXBusCtrl_ADDR:	0x1db
BYTE			CSDSW1_MUXBusCtrl_ADDR;
// CSDSW1 Shadow defines
//   CSDSW1_DataShadow define
extern BYTE Port_3_Data_SHADE;
#define CSDSW1_DataShadow (*(unsigned char*)&Port_3_Data_SHADE)
// CSDSW2 address and mask defines
#pragma	ioport	CSDSW2_Data_ADDR:	0xc
BYTE			CSDSW2_Data_ADDR;
#pragma	ioport	CSDSW2_DriveMode_0_ADDR:	0x10c
BYTE			CSDSW2_DriveMode_0_ADDR;
#pragma	ioport	CSDSW2_DriveMode_1_ADDR:	0x10d
BYTE			CSDSW2_DriveMode_1_ADDR;
#pragma	ioport	CSDSW2_DriveMode_2_ADDR:	0xf
BYTE			CSDSW2_DriveMode_2_ADDR;
#pragma	ioport	CSDSW2_GlobalSelect_ADDR:	0xe
BYTE			CSDSW2_GlobalSelect_ADDR;
#pragma	ioport	CSDSW2_IntCtrl_0_ADDR:	0x10e
BYTE			CSDSW2_IntCtrl_0_ADDR;
#pragma	ioport	CSDSW2_IntCtrl_1_ADDR:	0x10f
BYTE			CSDSW2_IntCtrl_1_ADDR;
#pragma	ioport	CSDSW2_IntEn_ADDR:	0xd
BYTE			CSDSW2_IntEn_ADDR;
#define CSDSW2_MASK 0x2
#pragma	ioport	CSDSW2_MUXBusCtrl_ADDR:	0x1db
BYTE			CSDSW2_MUXBusCtrl_ADDR;
// CSDSW2 Shadow defines
//   CSDSW2_DataShadow define
extern BYTE Port_3_Data_SHADE;
#define CSDSW2_DataShadow (*(unsigned char*)&Port_3_Data_SHADE)
// CSDSW0 address and mask defines
#pragma	ioport	CSDSW0_Data_ADDR:	0xc
BYTE			CSDSW0_Data_ADDR;
#pragma	ioport	CSDSW0_DriveMode_0_ADDR:	0x10c
BYTE			CSDSW0_DriveMode_0_ADDR;
#pragma	ioport	CSDSW0_DriveMode_1_ADDR:	0x10d
BYTE			CSDSW0_DriveMode_1_ADDR;
#pragma	ioport	CSDSW0_DriveMode_2_ADDR:	0xf
BYTE			CSDSW0_DriveMode_2_ADDR;
#pragma	ioport	CSDSW0_GlobalSelect_ADDR:	0xe
BYTE			CSDSW0_GlobalSelect_ADDR;
#pragma	ioport	CSDSW0_IntCtrl_0_ADDR:	0x10e
BYTE			CSDSW0_IntCtrl_0_ADDR;
#pragma	ioport	CSDSW0_IntCtrl_1_ADDR:	0x10f
BYTE			CSDSW0_IntCtrl_1_ADDR;
#pragma	ioport	CSDSW0_IntEn_ADDR:	0xd
BYTE			CSDSW0_IntEn_ADDR;
#define CSDSW0_MASK 0x4
#pragma	ioport	CSDSW0_MUXBusCtrl_ADDR:	0x1db
BYTE			CSDSW0_MUXBusCtrl_ADDR;
// CSDSW0 Shadow defines
//   CSDSW0_DataShadow define
extern BYTE Port_3_Data_SHADE;
#define CSDSW0_DataShadow (*(unsigned char*)&Port_3_Data_SHADE)
// CSDSW3 address and mask defines
#pragma	ioport	CSDSW3_Data_ADDR:	0xc
BYTE			CSDSW3_Data_ADDR;
#pragma	ioport	CSDSW3_DriveMode_0_ADDR:	0x10c
BYTE			CSDSW3_DriveMode_0_ADDR;
#pragma	ioport	CSDSW3_DriveMode_1_ADDR:	0x10d
BYTE			CSDSW3_DriveMode_1_ADDR;
#pragma	ioport	CSDSW3_DriveMode_2_ADDR:	0xf
BYTE			CSDSW3_DriveMode_2_ADDR;
#pragma	ioport	CSDSW3_GlobalSelect_ADDR:	0xe
BYTE			CSDSW3_GlobalSelect_ADDR;
#pragma	ioport	CSDSW3_IntCtrl_0_ADDR:	0x10e
BYTE			CSDSW3_IntCtrl_0_ADDR;
#pragma	ioport	CSDSW3_IntCtrl_1_ADDR:	0x10f
BYTE			CSDSW3_IntCtrl_1_ADDR;
#pragma	ioport	CSDSW3_IntEn_ADDR:	0xd
BYTE			CSDSW3_IntEn_ADDR;
#define CSDSW3_MASK 0x8
#pragma	ioport	CSDSW3_MUXBusCtrl_ADDR:	0x1db
BYTE			CSDSW3_MUXBusCtrl_ADDR;
// CSDSW3 Shadow defines
//   CSDSW3_DataShadow define
extern BYTE Port_3_Data_SHADE;
#define CSDSW3_DataShadow (*(unsigned char*)&Port_3_Data_SHADE)
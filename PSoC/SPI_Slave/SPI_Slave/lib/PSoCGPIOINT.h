/******************************************************************************
*  Generated by PSoC Designer 5.2.2401
******************************************************************************/
#include <m8c.h>
// MISO address and mask defines
#pragma	ioport	MISO_Data_ADDR:	0x0
BYTE			MISO_Data_ADDR;
#pragma	ioport	MISO_DriveMode_0_ADDR:	0x100
BYTE			MISO_DriveMode_0_ADDR;
#pragma	ioport	MISO_DriveMode_1_ADDR:	0x101
BYTE			MISO_DriveMode_1_ADDR;
#pragma	ioport	MISO_DriveMode_2_ADDR:	0x3
BYTE			MISO_DriveMode_2_ADDR;
#pragma	ioport	MISO_GlobalSelect_ADDR:	0x2
BYTE			MISO_GlobalSelect_ADDR;
#pragma	ioport	MISO_IntCtrl_0_ADDR:	0x102
BYTE			MISO_IntCtrl_0_ADDR;
#pragma	ioport	MISO_IntCtrl_1_ADDR:	0x103
BYTE			MISO_IntCtrl_1_ADDR;
#pragma	ioport	MISO_IntEn_ADDR:	0x1
BYTE			MISO_IntEn_ADDR;
#define MISO_MASK 0x1
// SCK address and mask defines
#pragma	ioport	SCK_Data_ADDR:	0x0
BYTE			SCK_Data_ADDR;
#pragma	ioport	SCK_DriveMode_0_ADDR:	0x100
BYTE			SCK_DriveMode_0_ADDR;
#pragma	ioport	SCK_DriveMode_1_ADDR:	0x101
BYTE			SCK_DriveMode_1_ADDR;
#pragma	ioport	SCK_DriveMode_2_ADDR:	0x3
BYTE			SCK_DriveMode_2_ADDR;
#pragma	ioport	SCK_GlobalSelect_ADDR:	0x2
BYTE			SCK_GlobalSelect_ADDR;
#pragma	ioport	SCK_IntCtrl_0_ADDR:	0x102
BYTE			SCK_IntCtrl_0_ADDR;
#pragma	ioport	SCK_IntCtrl_1_ADDR:	0x103
BYTE			SCK_IntCtrl_1_ADDR;
#pragma	ioport	SCK_IntEn_ADDR:	0x1
BYTE			SCK_IntEn_ADDR;
#define SCK_MASK 0x8
// Chipselect address and mask defines
#pragma	ioport	Chipselect_Data_ADDR:	0x0
BYTE			Chipselect_Data_ADDR;
#pragma	ioport	Chipselect_DriveMode_0_ADDR:	0x100
BYTE			Chipselect_DriveMode_0_ADDR;
#pragma	ioport	Chipselect_DriveMode_1_ADDR:	0x101
BYTE			Chipselect_DriveMode_1_ADDR;
#pragma	ioport	Chipselect_DriveMode_2_ADDR:	0x3
BYTE			Chipselect_DriveMode_2_ADDR;
#pragma	ioport	Chipselect_GlobalSelect_ADDR:	0x2
BYTE			Chipselect_GlobalSelect_ADDR;
#pragma	ioport	Chipselect_IntCtrl_0_ADDR:	0x102
BYTE			Chipselect_IntCtrl_0_ADDR;
#pragma	ioport	Chipselect_IntCtrl_1_ADDR:	0x103
BYTE			Chipselect_IntCtrl_1_ADDR;
#pragma	ioport	Chipselect_IntEn_ADDR:	0x1
BYTE			Chipselect_IntEn_ADDR;
#define Chipselect_MASK 0x10
// MOSI address and mask defines
#pragma	ioport	MOSI_Data_ADDR:	0x0
BYTE			MOSI_Data_ADDR;
#pragma	ioport	MOSI_DriveMode_0_ADDR:	0x100
BYTE			MOSI_DriveMode_0_ADDR;
#pragma	ioport	MOSI_DriveMode_1_ADDR:	0x101
BYTE			MOSI_DriveMode_1_ADDR;
#pragma	ioport	MOSI_DriveMode_2_ADDR:	0x3
BYTE			MOSI_DriveMode_2_ADDR;
#pragma	ioport	MOSI_GlobalSelect_ADDR:	0x2
BYTE			MOSI_GlobalSelect_ADDR;
#pragma	ioport	MOSI_IntCtrl_0_ADDR:	0x102
BYTE			MOSI_IntCtrl_0_ADDR;
#pragma	ioport	MOSI_IntCtrl_1_ADDR:	0x103
BYTE			MOSI_IntCtrl_1_ADDR;
#pragma	ioport	MOSI_IntEn_ADDR:	0x1
BYTE			MOSI_IntEn_ADDR;
#define MOSI_MASK 0x20
// LED_Empfangen address and mask defines
#pragma	ioport	LED_Empfangen_Data_ADDR:	0x8
BYTE			LED_Empfangen_Data_ADDR;
#pragma	ioport	LED_Empfangen_DriveMode_0_ADDR:	0x108
BYTE			LED_Empfangen_DriveMode_0_ADDR;
#pragma	ioport	LED_Empfangen_DriveMode_1_ADDR:	0x109
BYTE			LED_Empfangen_DriveMode_1_ADDR;
#pragma	ioport	LED_Empfangen_DriveMode_2_ADDR:	0xb
BYTE			LED_Empfangen_DriveMode_2_ADDR;
#pragma	ioport	LED_Empfangen_GlobalSelect_ADDR:	0xa
BYTE			LED_Empfangen_GlobalSelect_ADDR;
#pragma	ioport	LED_Empfangen_IntCtrl_0_ADDR:	0x10a
BYTE			LED_Empfangen_IntCtrl_0_ADDR;
#pragma	ioport	LED_Empfangen_IntCtrl_1_ADDR:	0x10b
BYTE			LED_Empfangen_IntCtrl_1_ADDR;
#pragma	ioport	LED_Empfangen_IntEn_ADDR:	0x9
BYTE			LED_Empfangen_IntEn_ADDR;
#define LED_Empfangen_MASK 0x1
// LED7SEGa address and mask defines
#pragma	ioport	LED7SEGa_Data_ADDR:	0xc
BYTE			LED7SEGa_Data_ADDR;
#pragma	ioport	LED7SEGa_DriveMode_0_ADDR:	0x10c
BYTE			LED7SEGa_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGa_DriveMode_1_ADDR:	0x10d
BYTE			LED7SEGa_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGa_DriveMode_2_ADDR:	0xf
BYTE			LED7SEGa_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGa_GlobalSelect_ADDR:	0xe
BYTE			LED7SEGa_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGa_IntCtrl_0_ADDR:	0x10e
BYTE			LED7SEGa_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGa_IntCtrl_1_ADDR:	0x10f
BYTE			LED7SEGa_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGa_IntEn_ADDR:	0xd
BYTE			LED7SEGa_IntEn_ADDR;
#define LED7SEGa_MASK 0x1
// LED7SEGb address and mask defines
#pragma	ioport	LED7SEGb_Data_ADDR:	0xc
BYTE			LED7SEGb_Data_ADDR;
#pragma	ioport	LED7SEGb_DriveMode_0_ADDR:	0x10c
BYTE			LED7SEGb_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGb_DriveMode_1_ADDR:	0x10d
BYTE			LED7SEGb_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGb_DriveMode_2_ADDR:	0xf
BYTE			LED7SEGb_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGb_GlobalSelect_ADDR:	0xe
BYTE			LED7SEGb_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGb_IntCtrl_0_ADDR:	0x10e
BYTE			LED7SEGb_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGb_IntCtrl_1_ADDR:	0x10f
BYTE			LED7SEGb_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGb_IntEn_ADDR:	0xd
BYTE			LED7SEGb_IntEn_ADDR;
#define LED7SEGb_MASK 0x2
// LED7SEGc address and mask defines
#pragma	ioport	LED7SEGc_Data_ADDR:	0xc
BYTE			LED7SEGc_Data_ADDR;
#pragma	ioport	LED7SEGc_DriveMode_0_ADDR:	0x10c
BYTE			LED7SEGc_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGc_DriveMode_1_ADDR:	0x10d
BYTE			LED7SEGc_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGc_DriveMode_2_ADDR:	0xf
BYTE			LED7SEGc_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGc_GlobalSelect_ADDR:	0xe
BYTE			LED7SEGc_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGc_IntCtrl_0_ADDR:	0x10e
BYTE			LED7SEGc_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGc_IntCtrl_1_ADDR:	0x10f
BYTE			LED7SEGc_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGc_IntEn_ADDR:	0xd
BYTE			LED7SEGc_IntEn_ADDR;
#define LED7SEGc_MASK 0x4
// LED7SEGd address and mask defines
#pragma	ioport	LED7SEGd_Data_ADDR:	0xc
BYTE			LED7SEGd_Data_ADDR;
#pragma	ioport	LED7SEGd_DriveMode_0_ADDR:	0x10c
BYTE			LED7SEGd_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGd_DriveMode_1_ADDR:	0x10d
BYTE			LED7SEGd_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGd_DriveMode_2_ADDR:	0xf
BYTE			LED7SEGd_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGd_GlobalSelect_ADDR:	0xe
BYTE			LED7SEGd_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGd_IntCtrl_0_ADDR:	0x10e
BYTE			LED7SEGd_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGd_IntCtrl_1_ADDR:	0x10f
BYTE			LED7SEGd_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGd_IntEn_ADDR:	0xd
BYTE			LED7SEGd_IntEn_ADDR;
#define LED7SEGd_MASK 0x8
// LED7SEGe address and mask defines
#pragma	ioport	LED7SEGe_Data_ADDR:	0xc
BYTE			LED7SEGe_Data_ADDR;
#pragma	ioport	LED7SEGe_DriveMode_0_ADDR:	0x10c
BYTE			LED7SEGe_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGe_DriveMode_1_ADDR:	0x10d
BYTE			LED7SEGe_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGe_DriveMode_2_ADDR:	0xf
BYTE			LED7SEGe_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGe_GlobalSelect_ADDR:	0xe
BYTE			LED7SEGe_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGe_IntCtrl_0_ADDR:	0x10e
BYTE			LED7SEGe_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGe_IntCtrl_1_ADDR:	0x10f
BYTE			LED7SEGe_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGe_IntEn_ADDR:	0xd
BYTE			LED7SEGe_IntEn_ADDR;
#define LED7SEGe_MASK 0x10
// LED7SEGf address and mask defines
#pragma	ioport	LED7SEGf_Data_ADDR:	0xc
BYTE			LED7SEGf_Data_ADDR;
#pragma	ioport	LED7SEGf_DriveMode_0_ADDR:	0x10c
BYTE			LED7SEGf_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGf_DriveMode_1_ADDR:	0x10d
BYTE			LED7SEGf_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGf_DriveMode_2_ADDR:	0xf
BYTE			LED7SEGf_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGf_GlobalSelect_ADDR:	0xe
BYTE			LED7SEGf_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGf_IntCtrl_0_ADDR:	0x10e
BYTE			LED7SEGf_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGf_IntCtrl_1_ADDR:	0x10f
BYTE			LED7SEGf_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGf_IntEn_ADDR:	0xd
BYTE			LED7SEGf_IntEn_ADDR;
#define LED7SEGf_MASK 0x20
// LED7SEGg address and mask defines
#pragma	ioport	LED7SEGg_Data_ADDR:	0xc
BYTE			LED7SEGg_Data_ADDR;
#pragma	ioport	LED7SEGg_DriveMode_0_ADDR:	0x10c
BYTE			LED7SEGg_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGg_DriveMode_1_ADDR:	0x10d
BYTE			LED7SEGg_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGg_DriveMode_2_ADDR:	0xf
BYTE			LED7SEGg_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGg_GlobalSelect_ADDR:	0xe
BYTE			LED7SEGg_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGg_IntCtrl_0_ADDR:	0x10e
BYTE			LED7SEGg_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGg_IntCtrl_1_ADDR:	0x10f
BYTE			LED7SEGg_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGg_IntEn_ADDR:	0xd
BYTE			LED7SEGg_IntEn_ADDR;
#define LED7SEGg_MASK 0x40
// LED7SEGdp address and mask defines
#pragma	ioport	LED7SEGdp_Data_ADDR:	0xc
BYTE			LED7SEGdp_Data_ADDR;
#pragma	ioport	LED7SEGdp_DriveMode_0_ADDR:	0x10c
BYTE			LED7SEGdp_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGdp_DriveMode_1_ADDR:	0x10d
BYTE			LED7SEGdp_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGdp_DriveMode_2_ADDR:	0xf
BYTE			LED7SEGdp_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGdp_GlobalSelect_ADDR:	0xe
BYTE			LED7SEGdp_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGdp_IntCtrl_0_ADDR:	0x10e
BYTE			LED7SEGdp_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGdp_IntCtrl_1_ADDR:	0x10f
BYTE			LED7SEGdp_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGdp_IntEn_ADDR:	0xd
BYTE			LED7SEGdp_IntEn_ADDR;
#define LED7SEGdp_MASK 0x80
// LED7SEGDigit0 address and mask defines
#pragma	ioport	LED7SEGDigit0_Data_ADDR:	0x10
BYTE			LED7SEGDigit0_Data_ADDR;
#pragma	ioport	LED7SEGDigit0_DriveMode_0_ADDR:	0x110
BYTE			LED7SEGDigit0_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGDigit0_DriveMode_1_ADDR:	0x111
BYTE			LED7SEGDigit0_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGDigit0_DriveMode_2_ADDR:	0x13
BYTE			LED7SEGDigit0_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGDigit0_GlobalSelect_ADDR:	0x12
BYTE			LED7SEGDigit0_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGDigit0_IntCtrl_0_ADDR:	0x112
BYTE			LED7SEGDigit0_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGDigit0_IntCtrl_1_ADDR:	0x113
BYTE			LED7SEGDigit0_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGDigit0_IntEn_ADDR:	0x11
BYTE			LED7SEGDigit0_IntEn_ADDR;
#define LED7SEGDigit0_MASK 0x1
// LED7SEGDigit0 Shadow defines
//   LED7SEGDigit0_DataShadow define
extern BYTE Port_4_Data_SHADE;
#define LED7SEGDigit0_DataShadow (*(unsigned char*)&Port_4_Data_SHADE)
// LED7SEGDigit1 address and mask defines
#pragma	ioport	LED7SEGDigit1_Data_ADDR:	0x10
BYTE			LED7SEGDigit1_Data_ADDR;
#pragma	ioport	LED7SEGDigit1_DriveMode_0_ADDR:	0x110
BYTE			LED7SEGDigit1_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGDigit1_DriveMode_1_ADDR:	0x111
BYTE			LED7SEGDigit1_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGDigit1_DriveMode_2_ADDR:	0x13
BYTE			LED7SEGDigit1_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGDigit1_GlobalSelect_ADDR:	0x12
BYTE			LED7SEGDigit1_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGDigit1_IntCtrl_0_ADDR:	0x112
BYTE			LED7SEGDigit1_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGDigit1_IntCtrl_1_ADDR:	0x113
BYTE			LED7SEGDigit1_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGDigit1_IntEn_ADDR:	0x11
BYTE			LED7SEGDigit1_IntEn_ADDR;
#define LED7SEGDigit1_MASK 0x2
// LED7SEGDigit1 Shadow defines
//   LED7SEGDigit1_DataShadow define
extern BYTE Port_4_Data_SHADE;
#define LED7SEGDigit1_DataShadow (*(unsigned char*)&Port_4_Data_SHADE)
// LED7SEGDigit2 address and mask defines
#pragma	ioport	LED7SEGDigit2_Data_ADDR:	0x10
BYTE			LED7SEGDigit2_Data_ADDR;
#pragma	ioport	LED7SEGDigit2_DriveMode_0_ADDR:	0x110
BYTE			LED7SEGDigit2_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGDigit2_DriveMode_1_ADDR:	0x111
BYTE			LED7SEGDigit2_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGDigit2_DriveMode_2_ADDR:	0x13
BYTE			LED7SEGDigit2_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGDigit2_GlobalSelect_ADDR:	0x12
BYTE			LED7SEGDigit2_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGDigit2_IntCtrl_0_ADDR:	0x112
BYTE			LED7SEGDigit2_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGDigit2_IntCtrl_1_ADDR:	0x113
BYTE			LED7SEGDigit2_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGDigit2_IntEn_ADDR:	0x11
BYTE			LED7SEGDigit2_IntEn_ADDR;
#define LED7SEGDigit2_MASK 0x4
// LED7SEGDigit2 Shadow defines
//   LED7SEGDigit2_DataShadow define
extern BYTE Port_4_Data_SHADE;
#define LED7SEGDigit2_DataShadow (*(unsigned char*)&Port_4_Data_SHADE)
// LED7SEGDigit3 address and mask defines
#pragma	ioport	LED7SEGDigit3_Data_ADDR:	0x10
BYTE			LED7SEGDigit3_Data_ADDR;
#pragma	ioport	LED7SEGDigit3_DriveMode_0_ADDR:	0x110
BYTE			LED7SEGDigit3_DriveMode_0_ADDR;
#pragma	ioport	LED7SEGDigit3_DriveMode_1_ADDR:	0x111
BYTE			LED7SEGDigit3_DriveMode_1_ADDR;
#pragma	ioport	LED7SEGDigit3_DriveMode_2_ADDR:	0x13
BYTE			LED7SEGDigit3_DriveMode_2_ADDR;
#pragma	ioport	LED7SEGDigit3_GlobalSelect_ADDR:	0x12
BYTE			LED7SEGDigit3_GlobalSelect_ADDR;
#pragma	ioport	LED7SEGDigit3_IntCtrl_0_ADDR:	0x112
BYTE			LED7SEGDigit3_IntCtrl_0_ADDR;
#pragma	ioport	LED7SEGDigit3_IntCtrl_1_ADDR:	0x113
BYTE			LED7SEGDigit3_IntCtrl_1_ADDR;
#pragma	ioport	LED7SEGDigit3_IntEn_ADDR:	0x11
BYTE			LED7SEGDigit3_IntEn_ADDR;
#define LED7SEGDigit3_MASK 0x8
// LED7SEGDigit3 Shadow defines
//   LED7SEGDigit3_DataShadow define
extern BYTE Port_4_Data_SHADE;
#define LED7SEGDigit3_DataShadow (*(unsigned char*)&Port_4_Data_SHADE)

;  Generated by PSoC Designer 5.3.2710
;
include "m8c.inc"
;  Personalization tables 
export LoadConfigTBL_psoc_slave_Bank1
export LoadConfigTBL_psoc_slave_Bank0
export LoadConfigTBL_psoc_slave_Ordered
AREA lit(rom, rel)
LoadConfigTBL_psoc_slave_Bank0:
;  Instance name ADC10, User Module ADC10
;       Instance name ADC10, Block Name ADC(ACE01)
	db		76h, 69h		;ADC10_ACE_CR1(ACE01CR1)
	db		77h, 00h		;ADC10_ACE_CR2(ACE01CR2)
;       Instance name ADC10, Block Name CNT(DCB02)
	db		2bh, 00h		;ADC10_CNT_CR0(DCB02CR0)
	db		29h, 00h		;ADC10_CNT_DR1(DCB02DR1)
	db		2ah, 00h		;ADC10_CNT_DR2(DCB02DR2)
;       Instance name ADC10, Block Name RAMP(ASE11)
	db		69h, 24h		;ADC10_ADC_CR(ADC1_CR)
	db		84h, 00h		;ADC10_ASE_CR0(ASE11CR0)
;  Instance name EzI2Cs, User Module EzI2Cs
;  Instance name PWM16, User Module PWM16
;       Instance name PWM16, Block Name PWM16_LSB(DBB00)
	db		23h, 00h		;PWM16_CONTROL_LSB_REG(DBB00CR0)
	db		21h, 00h		;PWM16_PERIOD_LSB_REG(DBB00DR1)
	db		22h, 00h		;PWM16_COMPARE_LSB_REG(DBB00DR2)
;       Instance name PWM16, Block Name PWM16_MSB(DBB01)
	db		27h, 00h		;PWM16_CONTROL_MSB_REG(DBB01CR0)
	db		25h, 00h		;PWM16_PERIOD_MSB_REG(DBB01DR1)
	db		26h, 00h		;PWM16_COMPARE_MSB_REG(DBB01DR2)
;  Global Register values Bank 0
	db		60h, 05h		; AnalogColumnInputSelect register (AMX_IN)
	db		64h, 00h		; AnalogComparatorControl0 register (CMP_CR0)
	db		66h, 00h		; AnalogComparatorControl1 register (CMP_CR1)
	db		e6h, 20h		; DecimatorControl_0 register (DEC_CR0)
	db		e7h, 00h		; DecimatorControl_1 register (DEC_CR1)
	db		d6h, 44h		; I2CConfig register (I2CCFG)
	db		62h, 00h		; PWM_Control register (PWM_CR)
	db		b0h, 00h		; Row_0_InputMux register (RDI0RI)
	db		b1h, 00h		; Row_0_InputSync register (RDI0SYN)
	db		b2h, 00h		; Row_0_LogicInputAMux register (RDI0IS)
	db		b3h, 33h		; Row_0_LogicSelect_0 register (RDI0LT0)
	db		b4h, 33h		; Row_0_LogicSelect_1 register (RDI0LT1)
	db		b5h, 20h		; Row_0_OutputDrive_0 register (RDI0SRO0)
	db		b6h, 00h		; Row_0_OutputDrive_1 register (RDI0SRO1)
	db		ffh
LoadConfigTBL_psoc_slave_Bank1:
;  Instance name ADC10, User Module ADC10
;       Instance name ADC10, Block Name ADC(ACE01)
;       Instance name ADC10, Block Name CNT(DCB02)
	db		28h, 21h		;ADC10_CNT_FN(DCB02FN)
	db		29h, 55h		;ADC10_CNT_IN(DCB02IN)
	db		2ah, 40h		;ADC10_CNT_OUT(DCB02OU)
;       Instance name ADC10, Block Name RAMP(ASE11)
	db		e6h, 00h		;ADC10_ADC_TR(ADC1_TR)
	db		66h, 00h		;ADC10_(AMD_CR1)
;  Instance name EzI2Cs, User Module EzI2Cs
;  Instance name PWM16, User Module PWM16
;       Instance name PWM16, Block Name PWM16_LSB(DBB00)
	db		20h, 01h		;PWM16_FUNC_LSB_REG(DBB00FN)
	db		21h, 15h		;PWM16_INPUT_LSB_REG(DBB00IN)
	db		22h, c0h		;PWM16_OUTPUT_LSB_REG(DBB00OU)
;       Instance name PWM16, Block Name PWM16_MSB(DBB01)
	db		24h, 21h		;PWM16_FUNC_MSB_REG(DBB01FN)
	db		25h, 35h		;PWM16_INPUT_MSB_REG(DBB01IN)
	db		26h, c5h		;PWM16_OUTPUT_MSB_REG(DBB01OU)
;  Global Register values Bank 1
	db		61h, 00h		; AnalogClockSelect1 register (CLK_CR1)
	db		60h, 00h		; AnalogColumnClockSelect register (CLK_CR0)
	db		62h, 00h		; AnalogIOControl_0 register (ABF_CR0)
	db		67h, 33h		; AnalogLUTControl0 register (ALT_CR0)
	db		64h, 00h		; ComparatorGlobalOutEn register (CMP_GO_EN)
	db		d1h, 00h		; GlobalDigitalInterconnect_Drive_Even_Input register (GDI_E_IN)
	db		d3h, 00h		; GlobalDigitalInterconnect_Drive_Even_Output register (GDI_E_OU)
	db		d0h, 00h		; GlobalDigitalInterconnect_Drive_Odd_Input register (GDI_O_IN)
	db		d2h, 00h		; GlobalDigitalInterconnect_Drive_Odd_Output register (GDI_O_OU)
	db		e1h, 0fh		; OscillatorControl_1 register (OSC_CR1)
	db		e2h, 00h		; OscillatorControl_2 register (OSC_CR2)
	db		dfh, ffh		; OscillatorControl_3 register (OSC_CR3)
	db		deh, 01h		; OscillatorControl_4 register (OSC_CR4)
	db		ddh, 00h		; OscillatorGlobalBusEnableControl register (OSC_GO_EN)
	db		ffh
AREA psoc_config(rom, rel)
LoadConfigTBL_psoc_slave_Ordered:
;  Ordered Global Register values
	M8C_SetBank0
	mov	reg[00h], 00h		; Port_0_Data register (PRT0DR)
	M8C_SetBank1
	mov	reg[00h], 20h		; Port_0_DriveMode_0 register (PRT0DM0)
	mov	reg[01h], 1ch		; Port_0_DriveMode_1 register (PRT0DM1)
	M8C_SetBank0
	mov	reg[03h], 1ch		; Port_0_DriveMode_2 register (PRT0DM2)
	mov	reg[02h], 20h		; Port_0_GlobalSelect register (PRT0GS)
	M8C_SetBank1
	mov	reg[02h], 00h		; Port_0_IntCtrl_0 register (PRT0IC0)
	mov	reg[03h], 00h		; Port_0_IntCtrl_1 register (PRT0IC1)
	M8C_SetBank0
	mov	reg[01h], 00h		; Port_0_IntEn register (PRT0IE)
	mov	reg[04h], 03h		; Port_1_Data register (PRT1DR)
	M8C_SetBank1
	mov	reg[04h], 03h		; Port_1_DriveMode_0 register (PRT1DM0)
	mov	reg[05h], 03h		; Port_1_DriveMode_1 register (PRT1DM1)
	M8C_SetBank0
	mov	reg[07h], 03h		; Port_1_DriveMode_2 register (PRT1DM2)
	mov	reg[06h], 00h		; Port_1_GlobalSelect register (PRT1GS)
	M8C_SetBank1
	mov	reg[06h], 00h		; Port_1_IntCtrl_0 register (PRT1IC0)
	mov	reg[07h], 00h		; Port_1_IntCtrl_1 register (PRT1IC1)
	M8C_SetBank0
	mov	reg[05h], 00h		; Port_1_IntEn register (PRT1IE)
	M8C_SetBank0
	ret


; PSoC Configuration file trailer PsocConfig.asm

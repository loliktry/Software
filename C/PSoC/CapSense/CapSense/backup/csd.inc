;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME:   CSD.inc
;;   Version: 1.70, Updated on 2012/3/2 at 9:13:13
;;  Generated by PSoC Designer 5.3.2710
;;
;;  DESCRIPTION:
;;    Assembler declarations for the CSD user module interface.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

CSD_WITH_PWM:                          equ 01h
CSD_REF_VALUE:                         equ 0x2
CSD_FEEDBACK_PIN:                      equ 0x0
CSD_FEEDBACK_P1_1:                     equ 0
CSD_FEEDBACK_P3_1:                     equ 1
CSD_FEEDBACK_P1_5:                     equ 2
CSD_FEEDBACK_P1_4:                     equ 0x04
CSD_FEEDBACK_P1_0:                     equ 0x08
CSD_FEEDBACK_P3_0:                     equ 0x10

CSD_CAPACITOR_PIN:                     equ 1
CSD_CAPACITOR_P0_1:                    equ 1
CSD_CAPACITOR_P0_3:                    equ 2

CSD_AUTORESET:                         equ 1
CSD_PWM_PERIOD:                        equ 0x7

;--------------------------------------------------
; Constants for Scan Speed values
;--------------------------------------------------
CSD_ULTRA_FAST_SPEED:                  equ 0x00
CSD_FAST_SPEED:                        equ 0x01
CSD_NORMAL_SPEED:                      equ 0x02
CSD_SLOW_SPEED:                        equ 0x03

;--------------------------------------------------
; Constants for Resolution values
;--------------------------------------------------
CSD_MIN_RESOLUTION:                    equ 9
CSD_9_BIT_RESOLUTION:                  equ 9
CSD_10_BIT_RESOLUTION:                 equ 10
CSD_11_BIT_RESOLUTION:                 equ 11
CSD_12_BIT_RESOLUTION:                 equ 12
CSD_13_BIT_RESOLUTION:                 equ 13
CSD_14_BIT_RESOLUTION:                 equ 14
CSD_15_BIT_RESOLUTION:                 equ 15
CSD_16_BIT_RESOLUTION:                 equ 16
CSD_MAX_RESOLUTION:                    equ 16

;--------------------------------------------------
; Constants for CSD API's
;--------------------------------------------------

CSD_ButtonCount:                       equ 4h
CSD_SliderCount:                       equ 0h  + 0h
CSD_TotalSensorCount:                  equ 4h

CSD_BUTTONS_EXIST:                     equ 4h
CSD_SLIDERS_EXIST:                     equ 0h | 0h

CSD_HYSTERESIS:                                  equ ah
CSD_Debounce:                                    equ 3h
CSD_LowBaselineReset:                            equ 32h

CSD_FINGER_THRESHOLD:                            equ 28h
CSD_NOISE_THRESHOLD:                             equ ah
CSD_NEGATIVE_NOISE_THRESHOLD:                    equ 14h
CSD_BASELINE_UPDATE_THRESHOLD:                   equ c8h

CSD_DiplexUsed:                        equ 0

;--------------------------------------------------
; Registers Address Constants for CSD
;--------------------------------------------------

CSD_CNT_FUNC_REG:                      equ 20h              ; CNT Function Reg
CSD_CNT_IN_REG:                        equ 21h              ; CNT Input Reg
CSD_CNT_OUT_REG:                       equ 22h              ; CNT Output Reg
CSD_CNT_COUNTER_REG:                   equ 20h              ; CNT Counter Reg
CSD_CNT_PERIOD_REG:                    equ 21h              ; CNT Period Reg
CSD_CNT_COMPARE_REG:                   equ 22h              ; CNT Compare Reg
CSD_CNT_CONTROL_REG:                   equ 23h              ; CNT Control Reg

CSD_PWM_FUNC_REG:    	                 equ 24h    	         ; PWM Function Reg
CSD_PWM_IN_REG:      	                 equ 25h      	       ; PWM Input Reg
CSD_PWM_OUT_REG:                       equ 26h     	        ; PWM Output Reg
CSD_PWM_CONTROL_REG:                   equ 27h 	            ; PWM Control Reg
CSD_PWM_COUNTER_REG:                   equ 24h   	          ; PWM Counter Reg
CSD_PWM_PERIOD_REG:                    equ 25h    	         ; PWM Period Reg
CSD_PWM_COMPARE_REG:                   equ 26h    	         ; PWM Compare Reg

CSD_PRS_FUNC_REG:                      equ 28h              ; PRS Function Reg
CSD_PRS_IN_REG:                        equ 29h              ; PRS Input Reg
CSD_PRS_OUT_REG:                       equ 2ah              ; PRS Output Reg
CSD_PRS_CONTROL_REG:                   equ 2bh              ; PRS Control Reg
CSD_PRS_SHIFT_REG:                     equ 28h              ; PRS Shift Reg
CSD_PRS_POLY_REG:                      equ 29h              ; PRS Polynimial Reg
CSD_PRS_SEED_REG:                      equ 2ah              ; PRS Seed Reg

CSD_ACE_CONTROL1_REG:                  equ 76h              ; CMP Control Reg
CSD_ACE_CONTROL2_REG:                  equ 77h              ; CMP Control Reg

CSD_ASE_CONTROL_REG:                   equ 84h              ; CMP_REF Conrol Reg
CSD_ADC_TRIM_REG:                      equ e6h              ; ADC Trim Register
CSD_ADC_CONTROL_REG:                   equ 69h              ; ADC Control Reg


DR_OFFSET:                             equ 00h
DM0_OFFSET:                            equ 00h              ; Bank 1
DM1_OFFSET:                            equ 01h              ; Bank 1
DM2_OFFSET:                            equ 03h              ; Bank 0
MUX_OFFSET:                            equ MUX_CR0          ; Bank 1

;--------------------------------------------------
; CSD Macro 'Functions'
;--------------------------------------------------

macro CSD_Counter_Start_M
   or    reg[CSD_CNT_CONTROL_REG],  CSD_CNT_CONTROL_REG_START_BIT
endm

macro CSD_Counter_Stop_M
   and   reg[CSD_CNT_CONTROL_REG], ~CSD_CNT_CONTROL_REG_START_BIT
endm

macro CSD_Counter_EnableInt_M
   M8C_EnableIntMask CSD_CNT_INT_REG, CSD_CNT_INT_MASK
endm

macro CSD_Counter_DisableInt_M
   M8C_DisableIntMask CSD_CNT_INT_REG, CSD_CNT_INT_MASK
endm

;--------------------------------------------------
; Constants for CSD_CMP API's
;--------------------------------------------------
CSD_CMP_CMPIntReg:                     equ  0e0h
CSD_CMP_CMPIntMask:                    equ  04h

CSD_CMP_OFF:                           equ  0
CSD_CMP_ON:                            equ  1

;--------------------------------------------------
; Constants for CSD_Counter API's.
;--------------------------------------------------

CSD_CNT_CONTROL_REG_START_BIT:         equ 0x01             ; Control register start bit
CSD_CNT_INT_REG:                       equ 0x0e1
CSD_CNT_INT_MASK:                      equ 0x01

;--------------------------------------------------
; Constants for CSD_Counter user defined values
;--------------------------------------------------

CSD_CNT_PERIOD:                        equ 0xff
CSD_CNT_COMPARE_VALUE:                 equ 0x00

; end of file CSD.inc

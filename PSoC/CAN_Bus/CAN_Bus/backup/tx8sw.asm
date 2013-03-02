;;*****************************************************************************
;;  FILENAME: TX8SW.asm
;;
;;  Version: 1.2, Updated on 2011/12/1 at 17:23:32
;;  Generated by PSoC Designer 5.2.2401
;;
;;  DESCRIPTION: Routines for Firmware Serial Transmitter
;;
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2011. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"
include "memory.inc"
include "TX8SW.inc"

export   TX8SW_Start
export  _TX8SW_Start
export   TX8SW_Stop
export  _TX8SW_Stop
export   TX8SW_SendData
export  _TX8SW_SendData

;-----------------------------------------------
;  High Level TX functions
;-----------------------------------------------
export  TX8SW_PutSHexByte
export _TX8SW_PutSHexByte
export  TX8SW_PutSHexInt
export _TX8SW_PutSHexInt
export  TX8SW_PutChar
export _TX8SW_PutChar
export  TX8SW_CPutString
export _TX8SW_CPutString
export  TX8SW_PutString
export _TX8SW_PutString
export  TX8SW_Write
export _TX8SW_Write
export  TX8SW_CWrite
export _TX8SW_CWrite
export  TX8SW_PutCRLF
export _TX8SW_PutCRLF

;-----------------------------------------------
AREA InterruptRAM (RAM, REL)
  TX8SW_bData:    blk  1
  TX8SW_bParity:  blk  1
;-----------------------------------------------

AREA UserModules (ROM, REL)

.LITERAL
  Digits:    DS    "0123456789ABCDEF"
.ENDLITERAL

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_Start(void)
;
;  DESCRIPTION:
;     Sets the output pin into high logical level
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: none
;
;  RETURNS:  none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;-----------------------------------------------------------------------------
 TX8SW_Start:
_TX8SW_Start:
   RAM_PROLOGUE RAM_USE_CLASS_4

   RAM_SETPAGE_CUR >Port_0_Data_SHADE
   
   TX8SW_Start_M      ; Set the output pin into Strong DM and into high logical level

   RAM_EPILOGUE RAM_USE_CLASS_4
   ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_Stop
;
;  DESCRIPTION:
;     This function was added for compatibility reason
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:  none
;
;  RETURNS:  none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;-----------------------------------------------------------------------------
 TX8SW_Stop:
_TX8SW_Stop:
   RAM_PROLOGUE RAM_USE_CLASS_1

   TX8SW_Stop_M      ; Set the output pin into HiZ-analog DM

   RAM_EPILOGUE RAM_USE_CLASS_1
   ret
.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_PutChar
;  FUNCTION NAME: TX8SW_SendData
;
;  DESCRIPTION:
;     Sends one byte via TX pin.
;
;  ARGUMENTS:
;     A  => (BYTE) Data/char to transmit
;
;  RETURNS:
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;-----------------------------------------------------------------------------
 TX8SW_PutChar:
_TX8SW_PutChar:
 TX8SW_SendData:
_TX8SW_SendData:

    RAM_PROLOGUE RAM_USE_CLASS_4
    RAM_SETPAGE_CUR >TX8SW_bData

    mov     [TX8SW_bData], A
IF (TX8SW_PARITY)
  IF (TX8SW_DATA_BITS & TX8SW_DATA_BITS_8)

    IF (TX8SW_PARITY & TX8SW_PARITY_ODD)
    mov     [TX8SW_bParity], 1
    ELSE
    mov     [TX8SW_bParity], 0
    ENDIF

    mov     X, 8
.P0:
    rlc     A
    jnc     .P1
    xor     [TX8SW_bParity], 1
.P1:
    dec     X
    jnz     .P0
  ELSE
    IF (TX8SW_PARITY & TX8SW_PARITY_ODD)
    or      [TX8SW_bData], 0x80
    ELSE
    and     [TX8SW_bData], ~0x80
    ENDIF
    mov     X, 8
.P0:
    rlc     A
    jnc     .P1
    xor     [TX8SW_bData], 0x80
.P1:
    dec     X
    jnz     .P0
  ENDIF
ENDIF

    M8C_SetBank1
    mov     A, reg[OSC_CR0]            ; Get the System Oscillator control register
    push    A                          ; and save it on the stack
    and     A, ~OSC_CR0_CPU            ; Clear the CPU clock selects
    or      A, TX8SW_OSC_CR0           ; Set CPU clock according to required baudrate

    M8C_DisableGInt
    mov     reg[OSC_CR0], A            ; set CPU clock
    M8C_SetBank0

    swap    A, X                       ; some delay
    swap    A, X
    swap    A, X
    swap    A, X

    mov      A, [Port_0_Data_SHADE]

;-- Send data
;----------------------------------------------------
IF (TX8SW_CYCL & TX8SW_CYCL_26)
Send_26:                               ; send at 26 cycles per bit
;--- send start bit
    and     A, ~TX8SW_PinMask
    mov     reg[TX8SW_PortDR], A       ; 5

    TX8SW_SendBit                      ; send all data bits
    TX8SW_SendBit
    TX8SW_SendBit
    TX8SW_SendBit
    TX8SW_SendBit
    TX8SW_SendBit
    TX8SW_SendBit

IF (TX8SW_SEND_8)
    TX8SW_SendBit
ENDIF

IF (TX8SW_SEND_9)
    rrc     [TX8SW_bParity]            ; 7
    jc      . + 6                      ; 5
    and     A, ~TX8SW_PinMask          ; 4
    jmp     . + 6                      ; 5
    or      A, TX8SW_PinMask           ; 4
    jmp     . + 2                      ; 5
    mov     reg[TX8SW_PortDR], A       ; 5
ENDIF

    tst     [0],0                      ; 8
    tst     reg[1],0                   ; 9

;--- send stop bit(s)
    or      A, TX8SW_PinMask           ; 4
    mov     reg[TX8SW_PortDR], A       ; 5

IF (TX8SW_SEND_2_STOP)
    mov     X, 4                       ; 4
ELSE
    mov     X, 1                       ; 4
ENDIF
.L0:
    dec     X                          ; 4
    jnz     .L0                        ; 5
ENDIF

;----------------------------------------------------
IF (TX8SW_CYCL & TX8SW_CYCL_39)
Send_39:                               ; send at 39 cycles per bit
;--- send start bit
    and     A, ~TX8SW_PinMask
    mov     reg[TX8SW_PortDR], A       ; 5
IF (TX8SW_SEND_8)
    mov     X, 8                       ; 4
ELSE
    mov     X, 7
ENDIF
    jmp    .L1                         ; 5

.L1:
    nop                                ; 4
    TX8SW_SendBit                      ; 26
    dec    X                           ; 4
    jnz    .L1                         ; 5


IF (TX8SW_SEND_9)
    rrc     [TX8SW_bParity]            ; 7   (26)
    jc      . + 6                      ; 5
    and     A, ~TX8SW_PinMask          ; 4
    jmp     . + 6                      ; 5
    or      A, TX8SW_PinMask           ; 4
    jmp     . + 2                      ; 5
    mov     reg[TX8SW_PortDR], A       ; 5

    nop                                ; 4
    dec     X                          ; 4
    jmp    .+2                         ; 5
ENDIF

    rrc     [TX8SW_bParity]            ; 7
    rrc     [TX8SW_bParity]            ; 7
    rrc     [TX8SW_bParity]            ; 7

;--- send stop bit(s)
    or      A, TX8SW_PinMask           ; 4
    mov     reg[TX8SW_PortDR], A       ; 5

IF (TX8SW_SEND_2_STOP)
    mov     X, 7                       ; 4
ELSE
    mov     X, 3                       ; 4
ENDIF
.L0:
    dec     X                          ; 4
    jnz     .L0                        ; 5
ENDIF

;----------------------------------------------------
IF (TX8SW_CYCL & TX8SW_CYCL_78)
Send_78:                                ; send at 78 cycles per bit
;--- send start bit
    and     A, ~TX8SW_PinMask
    mov     reg[TX8SW_PortDR], A       ; 5
IF (TX8SW_SEND_8)
    mov     X, 8                       ; 4
ELSE
    mov     X, 7
ENDIF
    jmp    .L1                         ; 5

.L1:
    swap    A, X                       ; 5
    swap    A, X                       ; 5
    swap    A, X                       ; 5
    swap    A, X                       ; 5
    swap    A, X                       ; 5
    swap    A, X                       ; 5
    tst     reg[1],0                   ; 9
    nop                                ; 4
    TX8SW_SendBit                      ; 26
    dec    X                           ; 4
    jnz    .L1                         ; 5

IF (TX8SW_SEND_9)
    mov     X, 3                       ; 4
.L2:
    nop                                ; 4
    dec     X                          ; 4
    jnz     .L2                        ; 5

    rrc     [TX8SW_bParity]            ; 7   (26)
    jc      . + 6                      ; 5
    and     A, ~TX8SW_PinMask          ; 4
    jmp     . + 6                      ; 5
    or      A, TX8SW_PinMask           ; 4
    jmp     . + 2                      ; 5
    mov     reg[TX8SW_PortDR], A       ; 5

    tst     reg[1],0                   ; 9
ENDIF
    mov     X, 3                       ; 4
.L3:
    rrc     [TX8SW_bData]              ; 7
    dec     X                          ; 4
    jnz     .L3                        ; 5

    nop                                ; 4
    nop                                ; 4

;--- send stop bit(s)
    or      A, TX8SW_PinMask           ; 4
    mov     reg[TX8SW_PortDR], A       ; 5

IF (TX8SW_SEND_2_STOP)
    mov     X, 16                      ; 4
ELSE
    mov     X, 7                       ; 4
ENDIF
.L0:
    dec     X                          ; 4
    jnz     .L0                        ; 5
ENDIF
;----------------------------------------------------

    pop     A                          ; 5
    M8C_SetBank1                       ; 4
    mov     reg[OSC_CR0], A            ; Restore CPU Clock

    M8C_SetBank0
    M8C_EnableGInt

    RAM_EPILOGUE RAM_USE_CLASS_4
    ret

.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_PutSHexByte
;
;  DESCRIPTION:
;     Send a byte in Hex representation (two characters) via TX pin
;
;  ARGUMENTS:
;     A  => (BYTE) Data/char to be sent
;
;  RETURNS:
;     none.
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;-----------------------------------------------------------------------------
 TX8SW_PutSHexByte:
_TX8SW_PutSHexByte:
    push   A
    asr    A
    asr    A
    asr    A
    asr    A
    and    A, 0x0F
    index  Digits
    call   TX8SW_PutChar
    pop    A
    and    A, 0x0F
    index  Digits
    call   TX8SW_PutChar
    ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_PutSHexInt
;
;  DESCRIPTION:
;     Print an Int in Hex (four characters) to UART Tx
;
;  ARGUMENTS:
;     Pointer to string
;     A  => LSB of Int
;     X  => MSB of Int
;
;  RETURNS:
;     none.
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;
 TX8SW_PutSHexInt:
_TX8SW_PutSHexInt:
    RAM_PROLOGUE RAM_USE_CLASS_1
    push A
    mov  A, X
    call  TX8SW_PutSHexByte            ; Print MSB
    pop   A                            ; Move LSB into position
    call  TX8SW_PutSHexByte            ; Print LSB
    RAM_EPILOGUE RAM_USE_CLASS_1
    ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_CPutString
;
;  DESCRIPTION:
;     Send String out through UART TX port.
;
;
;  ARGUMENTS:
;     Pointer to String
;     A has MSB of string address
;     X has LSB of string address
;
;  RETURNS:
;     none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;-----------------------------------------------------------------------------
 TX8SW_CPutString:
_TX8SW_CPutString:
   RAM_PROLOGUE RAM_USE_CLASS_1
   push  A                             ; Store ROM pointer
   push  X
   romx                                ; Get character from ROM
   jz    .End_CPutString
   call  TX8SW_PutChar                 ; Print character
   pop   X
   pop   A
   inc   X                             ; Inc LSB of pointer
   jnc   TX8SW_CPutString              ; Check for carry
   inc   A                             ; Inc MSB of pointer
   jmp   TX8SW_CPutString


.End_CPutString:
   add   SP, -2
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_PutString
;
;  DESCRIPTION:
;     Send String out through UART TX port.
;
;
;  ARGUMENTS:
;     Pointer to String
;     A has MSB of string address
;     X has LSB of string address
;
;  RETURNS:
;     none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;
;    Currently only the page pointer registers listed below are modified:
;          IDX_PP
;-----------------------------------------------------------------------------
 TX8SW_PutString:
_TX8SW_PutString:
   RAM_PROLOGUE RAM_USE_CLASS_3
   RAM_SETPAGE_IDX A
.PutStringLoop:
   mov   A,[X]                         ; Get value pointed to by X
   jz    End_PutString                 ; Check for end of string
   push  X
   call  TX8SW_PutChar                 ; Send character to Tx port
   pop   X
   inc   X                             ; Advance pointer to next character
   jmp   .PutStringLoop                ; Get next character

End_PutString:
   RAM_EPILOGUE RAM_USE_CLASS_3
   ret
.ENDSECTION


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_PutCRLF
;
;  DESCRIPTION:
;     Send a CR and LF
;
;  ARGUMENTS:
;     none.
;
;  RETURNS:
;     none.
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;-----------------------------------------------------------------------------
_TX8SW_PutCRLF:
 TX8SW_PutCRLF:
    mov    A, 0x0D                        ; Send CR
    call   TX8SW_PutChar
    mov    A, 0x0A                        ; Send LF
    call   TX8SW_PutChar
    ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_Write
;
;  DESCRIPTION:
;     Send String of length X to serial port
;
;
;  ARGUMENTS:
;     Pointer to String
;     [SP-5] Count of characters to send
;     [SP-4] has MSB of string address
;     [SP-3] has LSB of string address
;
;  RETURNS:
;     none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;
;    Currently only the page pointer registers listed below are modified:
;          IDX_PP
;-----------------------------------------------------------------------------
CNT_LEN:    equ -5                         ; Length of data to send
STR_MSB:    equ -4                         ; MSB pointer of string
STR_LSB:    equ -3                         ; LSB pointer of string

 TX8SW_Write:
_TX8SW_Write:
   RAM_PROLOGUE RAM_USE_CLASS_3
   RAM_SETPAGE_IDX2STK
   mov   X, SP

.NextByteLoop:
   mov   A,[X+CNT_LEN]                     ; Get length of string to send
   jz    .End_Write
   dec   [X+CNT_LEN]                       ; Decrement counter

   IF SYSTEM_LARGE_MEMORY_MODEL
   mov   A, [X+STR_MSB]                    ; Load pointer to char to send
   ENDIF

   mov   X, [X+STR_LSB]                    ; Get character to send
   RAM_SETPAGE_IDX A                       ; switch index pages
   mov   A, [X]
   call    TX8SW_PutChar               ; Send character to UART
   mov   X, SP
   RAM_SETPAGE_IDX2STK
   inc   [X+STR_LSB]
   jmp   .NextByteLoop

.End_Write:
   RAM_EPILOGUE RAM_USE_CLASS_3
   ret

.ENDSECTION
.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: TX8SW_CWrite
;
;  DESCRIPTION:
;     Send String of length X to serial port
;
;  ARGUMENTS:
;     Pointer to String
;     [SP-6] MSB of Count of character to send
;     [SP-5] LSB of Count of character to send
;     [SP-4] has MSB of string address
;     [SP-3] has LSB of string address
;
;  RETURNS:
;     none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to preserve their values across calls to fastcall16
;    functions.
;-----------------------------------------------------------------------------
CLEN_MSB:   equ -6           ; MSB Length of data to send
CLEN_LSB:   equ -5           ; LSB Length of data to send
CSTR_MSB:   equ -4           ; MSB pointer of string
CSTR_LSB:   equ -3           ; LSB pointer of string

 TX8SW_CWrite:
_TX8SW_CWrite:
   RAM_PROLOGUE RAM_USE_CLASS_2
   mov   X,SP

.CW_Loop:
                                             ; Check for zero counter
   cmp   [X+CLEN_MSB],0x00
   jnz   .CW_WRITEIT
   cmp   [X+CLEN_LSB],0x00
   jz    .End_CWrite                         ; Leave if done

.CW_WRITEIT:                                 ; Save pointers
   push  X
   mov   A,[X+CSTR_MSB]
   mov   X,[X+CSTR_LSB]
   romx                                     ; Get character from ROM
   call  TX8SW_PutChar
   pop   X

   add   [X+CSTR_LSB],1                     ; Increment the string pointer
   adc   [X+CSTR_MSB],0

                                            ; Dec the counter
   sub   [X+CLEN_LSB],0x01
   sbb   [X+CLEN_MSB],0x00

   jmp   .CW_Loop

.End_CWrite:
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret
.ENDSECTION

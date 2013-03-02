;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: I2CHWCommon.asm
;;   Version: 1.90, Updated on 2011/12/1 at 17:22:49
;;  Generated by PSoC Designer 5.2.2401
;;
;;  DESCRIPTION: I2Cs User Module software implementation file
;;
;;  NOTE: User Module APIs conform to the fastcall16 convention for marshalling
;;        arguments and observe the associated "Registers are volatile" policy.
;;        This means it is the caller's responsibility to preserve any values
;;        in the X and A registers that are still needed after the API functions
;;        returns. For Large Memory Model devices it is also the caller's 
;;        responsibility to perserve any value in the CUR_PP, IDX_PP, MVR_PP and 
;;        MVW_PP registers. Even though some of these registers may not be modified
;;        now, there is no guarantee that will remain the case in future releases.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2011. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"
include "memory.inc"
include "I2CHWCommon.inc"

;-----------------------------------------------
; include instance specific register definitions
;-----------------------------------------------

;-----------------------------------------------
;  Global Symbols
;-----------------------------------------------
;-------------------------------------------------------------------
;  Declare the functions global for both assembler and C compiler.
;
;  Note that there are two names for each API. First name is
;  assembler reference. Name with underscore is name refence for
;  C compiler.  Calling function in C source code does not require
;  the underscore.
;-------------------------------------------------------------------

export    I2CHW_InitWrite
export   _I2CHW_InitWrite
export    I2CHW_InitRamRead
export   _I2CHW_InitRamRead
export    I2CHW_InitFlashRead
export   _I2CHW_InitFlashRead
export    I2CHW_bReadI2CStatus
export   _I2CHW_bReadI2CStatus
export    I2CHW_ClrRdStatus
export   _I2CHW_ClrRdStatus
export    I2CHW_ClrWrStatus
export   _I2CHW_ClrWrStatus


AREA UserModules (ROM, REL)


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: I2CHW_InitWrite
;
;  DESCRIPTION:
;     Initializes a data buffer pointer for the slave to use to deposit data, and
;     zeroes the value of a count byte for the same buffer.
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:  [SP-5]   -- count of bytes to write
;              [SP-4]   -- Hi order part of address Wrbuf
;              [SP-3]   -- Low order part of the address Wrbuf 
;
;  RETURNS:  none
;
;    Write Status bits are cleared
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;          
;    Currently only the page pointer registers listed below are modified: 
;          CUR_PP
;
;    Write Status bits are cleared
;
;  THEORY of OPERATION or PROCEDURE:
;     The C compiler will always place a 0 (the upper order byte of the address pointer) in
;     the accumulator.  X register is the low order pointer.
;     IF a one byte buffer is established, set a flag to NAK the first written data byte.
;

 I2CHW_InitWrite:
_I2CHW_InitWrite:

WrCnt:   equ -5
WrBufHi: equ -4
WrBufLo: equ -3

	RAM_PROLOGUE RAM_USE_CLASS_4
    RAM_PROLOGUE RAM_USE_CLASS_2
	push  X
	mov   X, SP
    dec   X                                                          ;set up the pointer for correct param access
    push  A
    mov   A, reg[I2CHW_INT_REG]
    push  A                                                           ;preserve flags prior to disabling int
    M8C_DisableIntMask I2CHW_INT_REG, I2CHW_INT_MASK

    RAM_SETPAGE_CUR >I2CHW_bStatus						                             ;Set the Page Pointer for LMM
    and    [I2CHW_bStatus], ~fI2C_NAKnextWr                          ;reset the nak-next-written-byte flag.
IF SYSTEM_LARGE_MEMORY_MODEL
    mov   A, [X + WrBufHi]                                           ;move wrbuf addr to A
    mov   [pI2CHW_Write_BufHI], A
ENDIF
    mov   A, [X + WrBufLo]                                           ;move wrbuf addr to A
    mov   [pI2CHW_Write_BufLO], A
    mov   A, [X + WrCnt]                                               ;move Write_count to A
    mov   [I2CHW_Write_Count], A
    cmp   A, 01                                                        ;if data buffer is one byte long or less
    jz    I2CHW_SetNak
    jc    I2CHW_SetNak
    and   [I2CHW_RsrcStatus], ~0x70                                  ;clear the 0x10, 0x20 (Write status bits)
    jmp   I2Cs_1_ResetFlgs

I2CHW_SetNak:
    or    [I2CHW_bStatus], fI2C_NAKnextWr                            ;set the nak-next-written-byte flag.
    and   [I2CHW_RsrcStatus], ~0x70                                  ; clear the 0x10, 0x20 (Write status bits)
    jmp   I2Cs_1_ResetFlgs

I2Cs_1_ResetFlgs:
    pop A
    and A, I2CHW_INT_MASK                                                ; Only enable if it was previously enabled
    jz  . + 5
    M8C_EnableIntMask I2CHW_INT_REG, I2CHW_INT_MASK
    pop A
    pop X
	RAM_EPILOGUE RAM_USE_CLASS_4
    RAM_EPILOGUE RAM_USE_CLASS_2
    ret

.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: I2CHW_InitRamRead
;
;  DESCRIPTION:
;     Initializes a data buffer pointer for the slave to use to retrieve data from,
;     and zeroes the value of a count byte for the same buffer.
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:  [SP-5]  -- count of bytes to read
;              [SP-4]  -- Hi order part of addr to ReadBuf
;              [SP-3]  -- Low order part of the address to ReadBuf
;
;  RETURNS: none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;          
;    Currently only the page pointer registers listed below are modified: 
;          CUR_PP
;
;     Read Status bits are cleared
;
;  THEORY of OPERATION or PROCEDURE:
;     The C compiler will always place a 0 (the upper order byte of the address pointer) in
;     the accumulator.  X register is the low order pointer.
;

 I2CHW_InitRamRead:
_I2CHW_InitRamRead:

RdCnt:     equ   -5
RdBufHi:   equ   -4
RdBufLo:   equ   -3

    RAM_PROLOGUE RAM_USE_CLASS_2
	RAM_PROLOGUE RAM_USE_CLASS_4
	RAM_SETPAGE_CUR >I2CHW_Read_Count
    push  X
	mov   X, SP
    dec   X                                                          ;set up the pointer for correct param access
    push  A
    mov   A, reg[I2CHW_INT_REG]
    push  A                                                            ;preserve flags prior to disabling int
    M8C_DisableIntMask I2CHW_INT_REG, I2CHW_INT_MASK

IF SYSTEM_LARGE_MEMORY_MODEL
    mov   A, [X + RdBufHi]                                           ;move wrbuf addr to A
    mov   [pI2CHW_Read_BufHI], A
ENDIF
    mov   A, [X + RdBufLo]                                             ; move rdbuf addr to A
    mov   [pI2CHW_Read_BufLO], A
    mov   A, [X + RdCnt]                                               ; move RamRead_count to A
    mov   [I2CHW_Read_Count], A
    dec   [I2CHW_Read_Count]                                         ; since we decrement through zero...
    and   [I2CHW_RsrcStatus], ~0x0f                                  ; clear the lower 4 (read status bits)

    pop A
    and A, I2CHW_INT_MASK                                                ; Only enable if it was previously enabled
    jz  . + 5
    M8C_EnableIntMask I2CHW_INT_REG, I2CHW_INT_MASK
    pop A
    pop X

    RAM_EPILOGUE RAM_USE_CLASS_4
    RAM_EPILOGUE RAM_USE_CLASS_2
    ret

.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: I2CHW_InitFlashRead
;
;  DESCRIPTION:
;     Initializes a flash data buffer pointer for the slave to use to retrieve
;     data from, and zeroes the value of a count byte for the same buffer.
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:  [SP-6]   -- Hi order part of flash Read count
;              [SP-5]   -- Low order part of flashRead counts
;              [SP-4]   -- Hi order part of the flash buf address
;              [SP-3]   -- Lo order part of flash buf address
;
;  RETURNS:
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;          
;    Currently only the page pointer registers listed below are modified: 
;          CUR_PP
;
;    Read Status bits are cleared
;
;  THEORY of OPERATION or PROCEDURE:
;     The C compiler will place the upper order address of the buffer in Acc.
;     X register is the low order pointer.  A user module parameter is used to conserve code
;     if flash buffers are un-needed.  The API call is left defined and capable of returning in
;     either case
;
 I2CHW_InitFlashRead:
_I2CHW_InitFlashRead:

FlRdCntHI:     equ   -6
FlRdCntLO:     equ   -5
FlBufAdrHI:    equ   -4
FlBufAdrLO:    equ   -3

IF I2CHW_READ_FLASH
    RAM_PROLOGUE RAM_USE_CLASS_4
    RAM_PROLOGUE RAM_USE_CLASS_2
    RAM_SETPAGE_CUR >pI2CHW_Read_BufLO   
	push  X
	mov   X, SP
    dec   X                                                            ;set up the pointer for correct param access
    push  A
    mov   A, reg[I2CHW_INT_REG]
    push  A                                                            ;preserve flags prior to disabling int
    M8C_DisableIntMask I2CHW_INT_REG, I2CHW_INT_MASK

    mov   A, [X + FlBufAdrLO]                                          ; move flrdbuf LOaddr to A
    mov   [pI2CHW_Read_BufLO], A
    mov   A, [X + FlBufAdrHI]                                          ; move flrdbuf HIaddr to A
    mov   [pI2CHW_Read_BufHI], A
    mov   A, [X + FlRdCntLO]                                           ; move flrdbuf LOcount to A
    mov   [I2CHW_Read_Count], A
    mov   A, [X + FlRdCntHI]                                           ; move flrdbuf HIcount to A
    mov   [I2CHW_Read_CountHI], A

    dec   [I2CHW_Read_Count]                                         ; since this will count throu zero
    jnc    . + 4                                                       ; only Read_CountHI if Read_Count rolled to 0xff
    dec   [I2CHW_Read_CountHI]

    and   [I2CHW_RsrcStatus], ~0x07                                  ; clear the lower 3 (read status bits)
    or    [I2CHW_RsrcStatus],I2CHW_READFLASH                         ; set the flash status bit

    pop A
    and A, I2CHW_INT_MASK                                                ; Only enable if it was previously enabled
    jz  . + 5
    M8C_EnableIntMask I2CHW_INT_REG, I2CHW_INT_MASK
    pop A
	pop X
    RAM_EPILOGUE RAM_USE_CLASS_2
	RAM_EPILOGUE RAM_USE_CLASS_4
ENDIF
    ret

.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: I2CHW_bReadI2CStatus
;
;  DESCRIPTION:
;     Returns the value in the the RsrcStatus variable.
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:
;
;  RETURNS:
;     BYTE  bI2CStatus -  status data.  Use the following defined bits
;     returned in A.
;         I2CHW_RD_NOERR:                   equ 1
;         I2CHW_RD_OVERFLOW:                equ 2
;         I2CHW_RD_INCOMPLETE:              equ 4
;         I2CHW_READFLASH:                  equ 8
;         I2CHW_WR_NOERR:                   equ 10h
;         I2CHW_WR_OVERFLOW:                equ 20h
;         I2CHW_WR_COMPLETE:                equ 40h
;         I2CHW_ISR_ACTIVE:                 equ 80h
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;          
;    Currently only the page pointer registers listed below are modified: 
;          CUR_PP
;          
 I2CHW_bReadI2CStatus:
_I2CHW_bReadI2CStatus:
    RAM_PROLOGUE RAM_USE_CLASS_4
	RAM_SETPAGE_CUR >I2CHW_RsrcStatus
    mov   A, [I2CHW_RsrcStatus]                                      ;return the status in A
    RAM_EPILOGUE RAM_USE_CLASS_4
    ret

.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: I2CHW_ClrRdStatus
;
;  DESCRIPTION:
;     Clears the Status bits in the Control/Status register, doesn't alter buffer
;     addresses or counts, leaves the Flash/Ram Read bit alone too
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: none
;
;  RETURNS: none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;          
;    Currently only the page pointer registers listed below are modified: 
;          CUR_PP
;          
 I2CHW_ClrRdStatus:
_I2CHW_ClrRdStatus:
    RAM_PROLOGUE RAM_USE_CLASS_4
	RAM_SETPAGE_CUR >I2CHW_RsrcStatus
    and   [I2CHW_RsrcStatus], ~0x07                                  ; clear the lower 3 (read status bits)
    RAM_EPILOGUE RAM_USE_CLASS_4
    ret

.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: I2CHW_ClrWrStatus
;
;  DESCRIPTION:
;     Clears the Status bits in the Control/Status register, doesn't alter buffer
;     addresses or counts, leaves the Flash/Ram Read bit alone too
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: none
;
;  RETURNS: none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;          
;    Currently only the page pointer registers listed below are modified: 
;          CUR_PP
;          
 I2CHW_ClrWrStatus:
_I2CHW_ClrWrStatus:
    RAM_PROLOGUE RAM_USE_CLASS_4
	RAM_SETPAGE_CUR >I2CHW_RsrcStatus
    and   [I2CHW_RsrcStatus], ~0x70                                  ; clear bits 10,20 (write status bits)
    RAM_EPILOGUE RAM_USE_CLASS_4
    ret

.ENDSECTION
; End of File I2CHW.asm

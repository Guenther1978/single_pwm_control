;;
; @file
; @fn uart_init
; @brief Initializes the UART.
;
; Registers in Bank 0: RCSTA, TXREG
; Registers in Bank 1: TXl, SPBRG, TRISC
;;

uart_init:
; switch to bank 1
        bsf     STATUS, RP0
        bcf     STATUS, RP1
        bsf     TRISC, 6
        bsf     TRISC, 7
        movlw   0x19
        movwf   SPBRG
        bcf     TXSTA, TX9
        bsf     TXSTA, TXEN
        bcf     TXSTA, SYNC
        bsf     TXSTA, BRGH
        bsf     PIE1, RCIE

; switch to bank 3
        bsf     STATUS, RP0
        bsf     STATUS, RP1
        bcf     BAUDCTL, SCKP

; switch to bank 0
        bcf     STATUS, RP0
        bcf     STATUS, RP1
        bsf     RCSTA, CREN
        bsf     RCSTA, SPEN
        return

uart_read:
        movf    RCREG, w
        movwf   received_byte
        return

uart_send:
        movlw   SEND
        subwf   received_byte
        btfss   STATUS, Z
        goto    return_uart_send
        movlw   0x20
        movwf   FSR
next_byte:    
        btfss   PIR1, TXIF
        goto    next_byte
        movf    INDF, w
        movwf   TXREG
        incf    FSR, f
        movlw   0x31
        subwf   FSR, w
        btfss   STATUS, Z
        goto    next_byte
        movlw   WAIT
        movwf   received_byte
return_uart_send:
        return

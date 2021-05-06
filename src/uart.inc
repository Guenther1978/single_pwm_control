;;
; @file
; @fn uart_init
; @brief Initializes the UART.
;;

uart_init:
; switch to bank 0
        bsf     STATUS, RP0

; set baudrate  
        movlw   0x81
        movwf   SPBRG
        bcf             TXSTA, SYNC
        bsf             RCSTA, SPEN
        bsf     STATUS, RP0
        bsf             TXSTA, TXEN
        bcf             TXSTA, SYNC
        movlw   0x81
        movwf   SPBRG
        bsf     TRISC, 6
        bsf     TRISC, 7
        bcf             STATUS, RP0
        bsf             RCSTA, SPEN
        return

uart_send:
        movlw   0x20
        movwf   FSR
next_byte:    
        btfss   PIR1, TXIF
        goto    next_byte
        movf    INDF, w
        movwf   TXREG
        incf    FSR, f
        movlw   0x32
        subwf   FSR, w
        btfss   STATUS, Z
        goto    next_byte
        return

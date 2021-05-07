;;
; @file
; @fn isr_uart
; @brief This is the receive interrupt handler.
;;

isr_uart:
        movf    RCREG, w
        movwf   received_byte
        return


;;
; @file
; @fn new_max_pointer
; @brief Calculates a new duration
;
; After changing from decreasing to increasing
; a new maximal pointer is calculated.
;;

new_max_pointer:
        call    random16
        movf    RandLo, w
        andlw   0xF0
        iorwf   0x80
        movwf   pointer_max
        return


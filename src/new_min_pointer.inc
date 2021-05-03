;;
; @file
; @fn new_min_pointer
; @brief Calculates a new duration
;
; After changing fro increasing to decreasing
; a new minimal pointer is calculated.
;;

new_min_pointer:
        call    random16
        movf    RandLo, w
        andlw   0x7F
        movwf   pointer_min
        return


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
        movf    RandHi, w
        subwf   pointer_max, w
        btfss   STATUS, C
        goto    new_min_pointer
        movf    RandHi, w
        movwf   pointer_min
        return


;;
; @file
; @fn new_min_pointer
; @brief Calculates a new duration
;
; After changing fro increasing to decreasing
; a new minimal pointer is calculated. The high
; byte of the pseudo random generator is substracted
; from the maximal pointer. If no underflow occured,
; this difference is the new minimal pointer.
;;

new_min_pointer:
        call    random16
        movf    pointer_max, w
        subwf   RandHi, w
        btfss   STATUS, C
        movwf   pointer_min
        return
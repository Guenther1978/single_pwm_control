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
        movf    pointer_min, w
        subwf   RandHi, w
        btfsc   STATUS, C
        goto    new_max_pointer
        movwf   pointer_max
        return


;;
; @file
; @fn Random16
; @brief Calculates a random number
;
; The random number is a pseudo random number.
; It is stored in two general purpose registers,
; which are defined in register.inc.
;;
random16:
        rlf     RandHi, W
        xorwf   RandHi, W
        rlf     W, F
        swapf   RandHi, F
        swapf   RandLo, W
        rlf     W, F
        xorwf   RandHi, W
        swapf   RandHi, F
        andlw   0x01
        rlf     RandLo, F
        xorwf   RandLo, F
        rlf     RandHi, F
        return


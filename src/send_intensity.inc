send_intensity:
    movf    intensity_high, w
    movwf   CCPR1L
    btfsc   intensity_low, 1
    bsf     CCP1CON, DC1B1
    btfsc   intensity_low, 0
    bsf     CCP1CON, DC1B0

    return


change_pointer:
        btfsc   darker, LED
        goto    dimm_LED
        incf    pointer, f
        incf    pointer, w
        subwf   pointer_max, w
        btfss   STATUS, Z
        goto    return_change_pointer
        bsf     darker, LED
        call    new_duration
        call    new_min_pointer

        goto    return_change_pointer 

dimm_LED:
        decf    pointer, f
        incf    pointer_min, w
        subwf   pointer, w
        btfss   STATUS, Z
        goto    return_change_pointer
        bcf     darker, LED
        call    new_duration
        call    new_max_pointer

return_change_pointer:
        return


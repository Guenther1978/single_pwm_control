change_pointer:
        btfsc   darker, LED
        goto    dimm_LED
        incf    pointer, f
        incf    pointer, w
        subwf   pointer_max, w  ; pointer_max - (pointer + 1)
        btfsc   STATUS, C       ; return if pointer > pointer_max
        goto    return_change_pointer
        bsf     darker, LED
        call    new_duration
        call    new_min_pointer

        goto    return_change_pointer 

dimm_LED:
        decf    pointer, f
        decf    pointer, w
        subwf   pointer_min, w  ; pointer_min - (pointer - 1)
        btfss   STATUS, C       ; return if pointer > pointer_min
        goto    return_change_pointer
        bcf     darker, LED
        call    new_duration
        call    new_max_pointer

return_change_pointer:
        return


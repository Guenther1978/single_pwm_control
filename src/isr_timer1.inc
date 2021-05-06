;;
; @file
; @fn isr_timer1
; @brief This is the timer 1 interupt handler.
;
; The routine deals with the timer 1
; overflow interrupt, the intensities
; are decreased or increased
;;

isr_timer1:
        movwf   w_temp
        swapf   STATUS,w
        bcf     STATUS,RP0
        bcf     STATUS,RP1
        movwf   status_temp
        
        btfsc   PIR1,TMR1IF
        goto    handle_isr_timer_1
        goto    Exit_ISR

handle_isr_timer_1:
        call    speed_control
        btfss   sCflag, LED
        goto    Exit_ISR
        
        call    stop_pwm
        call    change_pointer
        call    load_intensity
        call    send_intensity
        call    start_pwm
        call    uart_send

Exit_ISR:
        swapf   status_temp,w       ; Restore context
        movwf   STATUS
        swapf   w_temp,f            ; swapf doesn't affect Status bits, but MOVF would
        swapf   w_temp,w
        retfie


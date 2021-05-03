;;
; @file
; @fn single_pwm_control
; @brief Main function of the project single PWM control
;
; This main function initializes the registers. The interrupt of timer 1
; is enabled.
;;

#define	__16F882
#include <p16f882.inc>

	__CONFIG    _CONFIG1, _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_OFF & _CPD_OFF & _CP_OFF & _MCLRE_ON & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT
	__CONFIG    _CONFIG2, _WRT_OFF & _BOR21V

#include "registers.inc"
#include "constants.inc"


	org 0
	goto	table_read_test

	org 4

#include "isr_timer1.inc"
#include "stop_pwm.inc"
#include "change_pointer.inc"
#include "load_intensity.inc"
#include "send_intensity.inc"
#include "start_pwm.inc"
#include "random16.inc"
#include "speed_control.inc"
#include "new_duration.inc"
#include "new_min_pointer.inc"
#include "new_max_pointer.inc"

table_read_test:
    	bcf	    STATUS, RP0
	    bcf     STATUS, RP1

        #include "timer1Config.inc"
        #include "timer2Config.inc"

        clrf    darker
        clrf    pointer
        clrf    intensity_high
        clrf    intensity_low
        movlw   SIZE
        movwf   pointer_max
        movlw   0
        movwf   pointer_min

        ; Enable global interrupts
        bsf     INTCON, GIE
        bsf     INTCON, PEIE

        ; Start the PWM
        call    start_pwm

mainloop:
        goto    mainloop

#include "intensities_high.inc"
#include "intensities_low.inc"
        
        end

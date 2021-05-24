;;
; @file
; @fn single_pwm_control
; @brief Main function of the project single PWM control
;
; This main function initializes the registers. The interrupt of timer 1
; is enabled.
;;

#define	__16F627A
#include <p16f627A.inc>

	__CONFIG   _CP_OFF & _LVP_OFF  & _WDT_OFF & _PWRTE_ON & _INTOSC_OSC_NOCLKOUT & _BOREN_OFF & _MCLRE_OFF

#include "registers.inc"
#include "constants.inc"


	org 0
	goto	single_pwm_control

	org 4

#include "isr_caller.inc"
#include "isr_uart.inc"
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
#include "uart.inc"

single_pwm_control:
	bcf     STATUS, RP0
	bcf     STATUS, RP1

        #include "timer1Config.inc"
        #include "timer2Config.inc"
        call    random_init
        call    uart_init        

        clrf    darker
        clrf    pointer
        clrf    intensity_high
        clrf    intensity_low
        movlw   MAX
        movwf   pointer_max
        movlw   1
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


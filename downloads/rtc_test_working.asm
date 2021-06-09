
	list    p=16f877       		;PIC16F877 is the target processor
        INCLUDE "P16f877.INC" 		 
;------------------------------------------------------------------------------------
	__config _XT_OSC & _PWRTE_OFF & _WDT_OFF &_LVP_OFF 

#DEFINE LCD_RS 	PORTA, 2            ;  RA0 is RS line of LCD
#DEFINE LCD_E  	PORTA, 0            ;  RA1 is E line of LCD
#DEFINE	LCD_RW	PORTA,1
#DEFINE	LCD_DATA	PORTD			;  RD0-RD7 are D0-D7 of LCD
#DEFINE	SCL		PORTC,3
#DEFINE	SDA		PORTC,4		
#DEFINE	FOSC	d'4000000'
#DEFINE	BITRATE	d'100000'
#DEFINE	I2CRATE	(FOSC/BITRATE)/4-1

; Macros
	fcall macro subroutine_name
	local here
	lcall subroutine_name
	pagesel	 here
here:
	endm
; register definition

	cblock	0x21
hour
min
day
mode
st_hour1
st_hour2
st_hour3
st_hour4
end_hour1
end_hour2
end_hour3
end_hour4

en_1
en_2
en_3
en_4

flag
Temp
ten
ten_val
total
single
default
delay1	
delay2
delay3
disp_flag
flag_rtc
st_min1
st_min2
st_min3
st_min4
end_min1
end_min2
end_min3
end_min4


	endc
	
	cblock		0xa0

st_thu_min1
st_thu_hr1
end_thu_hr1
end_thu_min1
st_thu_min2
st_thu_hr2
end_thu_hr2
end_thu_min2
st_thu_min3
st_thu_hr3
end_thu_hr3
end_thu_min3
st_thu_min4
st_thu_hr4
end_thu_hr4
end_thu_min4
en_thu_1
en_thu_2
en_thu_3
en_thu_4



	endc



;------------------------------------------------------------------------------------

			org	0x00
 			goto start
                            
;------------------------------------------------------------------------------------
start
		bsf 	STATUS, RP0 		; Bank1 
;		errorlevel 1,-302      ; Don't warn me about bank 1
		movlw 	b'00000000'			; Defining input and output pins 
		movwf 	TRISA 				; Writing to TRISA register 
		movlw 	b'11111111'			; Defining input and output pins 
		movwf	TRISB 				 ;Writing to TRISB register 1-input,0-output
		movlw	b'00011000'
		movwf	TRISC
		movlw	b'00000000'
		movwf	TRISD
		movlw	b'00000000'
		movwf	TRISE
		movlw   b'10000110'			; TMR0,prescaler-128
		movwf   OPTION_REG
		movlw	0x07
		movwf	ADCON1
		call	I2Cinit
		bcf 	STATUS, RP0 		; Bank0 
		clrf 	PORTA				; porta,portb initially set to low
		clrf	PORTB
		clrf	PORTC
		clrf	PORTD
		clrf	PORTE
		clrf	mode
		clrf	day
		clrf	flag
	
		clrf	reset1
		clrf	disp_flag
		
		
		
		call	clear_variable
		movlw	0xff
		movwf	hour
		movwf	min
		fcall	clear_thu
		call	lcd_init
		call	set_time
		call	day_disp
		call	hour_set
		call	min_set

repeat1
		fcall	copy_limits
		
		goto	repeat1

	

			
		org    0x800

clear_thu
		banksel	st_thu_min1
		clrf	st_thu_min1
		banksel	st_thu_hr1
		clrf	st_thu_hr1
		banksel	end_thu_hr1
		clrf	end_thu_hr1
		banksel	end_thu_min1
		clrf	end_thu_min1
		banksel	st_thu_min2
		clrf	st_thu_min2
		banksel	st_thu_hr2
		clrf	st_thu_hr2
		banksel	end_thu_hr2
		clrf	end_thu_hr2
		banksel	end_thu_min2
		clrf	end_thu_min2
		banksel	st_thu_min3
		clrf	st_thu_min3
		banksel	st_thu_hr3
		clrf	st_thu_hr3
		banksel	end_thu_hr3
		clrf	end_thu_hr3
		banksel	end_thu_min3
		clrf	end_thu_min3
		banksel	st_thu_min4
		clrf	st_thu_min4
		banksel	st_thu_hr4
		clrf	st_thu_hr4
		banksel	end_thu_hr4
		clrf	end_thu_hr4
		banksel	end_thu_min4
		clrf	end_thu_min4
		banksel	en_thu_1
		clrf	en_thu_1
		banksel	en_thu_2
		clrf	en_thu_2
		banksel	en_thu_3
		clrf	en_thu_3
		banksel	en_thu_4
		clrf	en_thu_4
		return


copy_limits
		movlw	0x00
		subwf	day,0
		btfsc	STATUS,Z
		goto	copy_sun
		movlw	0x01
		subwf	day,0
		btfsc	STATUS,Z
		goto	copy_mon
		movlw	0x02
		subwf	day,0
		btfsc	STATUS,Z
		goto	copy_tue
		movlw	0x03
		subwf	day,0
		btfsc	STATUS,Z
		goto	copy_wed
		movlw	0x04
		subwf	day,0
		btfsc	STATUS,Z
		goto	copy_thu
		movlw	0x05
		subwf	day,0
		btfsc	STATUS,Z
		goto	copy_fri
		movlw	0x06
		subwf	day,0
		btfsc	STATUS,Z
		goto	copy_sat
		return

copy_thu
		banksel	st_hour1
		movf	st_hour1,0
		banksel	st_thu_hr1
		movwf	st_thu_hr1
		banksel	end_hour1
		movf	end_hour1,0
		banksel	end_thu_hr1
		movwf	end_thu_hr1
		banksel	en_1
		movf	en_1,0
		banksel	en_thu_1
		movwf	en_thu_1
		
		banksel	st_min1
		movf	st_min1,0
		banksel	st_thu_min1
		movwf	st_thu_min1
		banksel	end_min1
		movf	end_min1,0
		banksel	end_thu_min1
		movwf	end_thu_min1
	
		banksel	st_hour2
		movf	st_hour2,0
		banksel	st_thu_hr2
		movwf	st_thu_hr2
		banksel	end_hour2
		movf	end_hour2,0
		banksel	end_thu_hr2
		movwf	end_thu_hr2
		banksel	en_2
		movf	en_2,0
		banksel	en_thu_2
		movwf	en_thu_2

		banksel	st_min2
		movf	st_min2,0
		banksel	st_thu_min2
		movwf	st_thu_min2
		banksel	end_min2
		movf	end_min2,0
		banksel	end_thu_min2
		movwf	end_thu_min2

		banksel	st_hour3
		movf	st_hour3,0
		banksel	st_thu_hr3
		movwf	st_thu_hr3
		banksel	end_hour3
		movf	end_hour3,0
		banksel	end_tue_hr3
		movwf	end_tue_hr3

		banksel	st_min3
		movf	st_min3,0
		banksel	st_thu_min3
		movwf	st_thu_min3
		banksel	end_min3
		movf	end_min3,0
		banksel	end_thu_min3
		movwf	end_thu_min3
		banksel	en_3
		movf	en_3,0
		banksel	en_thu_3
		movwf	en_thu_3
	
	
		banksel	st_hour4
		movf	st_hour4,0
		banksel	st_thu_hr4
		movwf	st_thu_hr4
		banksel	end_hour4
		movf	end_hour4,0
		banksel	end_thu_hr4
		movwf	end_thu_hr4
		
		banksel	st_min4
		movf	st_min4,0
		banksel	st_thu_min4
		movwf	st_thu_min4
		banksel	end_min4
		movf	end_min4,0
		banksel	end_thu_min4
		movwf	end_thu_min4
		banksel	en_4
		movf	en_4,0
		banksel	en_thu_4	
		movwf	en_thu_4
		return

	end
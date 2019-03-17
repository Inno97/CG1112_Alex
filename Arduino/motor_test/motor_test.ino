#include "Arduino.h"
#include <avr/io.h>
#include <avr/interrupt.h>

char i;

void setup() {
  DDRD |= ((1 << DDD6) | (1 << DDD5)); //DDRD |= 0b01000000; 
  DDRB |= ((1 << DDB3) | (1 << DDB2));
  //DDRB |= 0b00001100;
  TCNT0 = 0;
  OCR0A = 0;
  OCR0B = 0;
  TIMSK0 |= 0b110; // OCIEA = 1 OCIEB = 1
  TCCR0B = 0b00000011;
  sei();
}

ISR(TIMER0_COMPA_vect) {
  OCR0A = 128;
}

ISR(TIMER0_COMPB_vect) {
  OCR0B = 128;
}

void right_motor_forward(void) {
  TCCR0A = 0b10000001;
  PORTD &= 0b11011111;
  PORTB &= 0b11111011;  
}

void right_motor_reverse(void) {
  TCCR0A = 0b00100001;
  PORTD &= 0b10111111;
  PORTD &= 0b11110111;
}

void loop() {
  for(i = 0; i < 100; i++) {
    right_motor_forward();
    delay(500);
  }
  for(i = 0; i < 100; i++) {
    right_motor_reverse();
    delay(500);
  }
}

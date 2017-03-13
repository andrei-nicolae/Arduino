// PWM output @ 25 kHz, only on pins 9 and 10.
// Output value should be between 0 and 320, inclusive.
void analogWrite25k(int pin, int value)
{
  // changing OCR1x value changes the duty cycle to = value / ICR1
    switch (pin) {
        case 9:
            OCR1A = value;
            break;
        case 10:
            OCR1B = value;
            break;
        default:
            // no other pin will work
            break;
    }
}

void setup()
{
    // Configure Timer 1 for PWM @ 25 kHz.
//    TCCR1A = 0;           // undo the configuration done by...
//    TCCR1B = 0;           // ...the Arduino core library
//    TCNT1  = 0;           // reset timer
//    TCCR1A = _BV(COM1A1)  // non-inverted PWM on ch. A
//           | _BV(COM1B1)  // same on ch; B
//           | _BV(WGM11);  // mode 10: ph. correct PWM, TOP = ICR1
//    TCCR1B = _BV(WGM13)   // ditto
//           | _BV(CS10);   // prescaler = 1

// this configures   TCCR1A = B10100010;  TCCR1B = B00010001;

  TCCR1A = B10100010;
  TCCR1B = B0001001; // 001 (no prescale) for 25kHz PWM;
  
  ICR1   = 320;         // TOP = 320
  
  // frequency seems to be 16,000,000 / prescale / ICR1 / 2 

  // Set the PWM pins as output.
  pinMode( 9, OUTPUT);
  pinMode(10, OUTPUT);
 
}

void loop()
{
    // Just an example:
    //analogWrite25k( 9, 110);
    delay(3000);
    analogWrite25k(10, 30);
    delay(3000);
    analogWrite25k(10, 310);
    
    // other pins still work as default!
    
}

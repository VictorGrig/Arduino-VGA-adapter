#define NOP asm("nop")
#define BLACK    PORTB = B00000000;
#define BLUE     PORTB = B00010000;
#define GREEN    PORTB = B00100000;
#define CYAN     PORTB = B00110000;
#define RED      PORTB = B01000000;
#define MAGENTA  PORTB = B01010000;
#define YELLOW   PORTB = B01100000;
#define WHITE    PORTB = B01110000;
 
unsigned int linecount = 1;
 
void setup() {
  /* Pin assignment
  10 - PB2 - R
  9  - PB1 - G
  8  - PB0 - B
  7  - PD7 - HSYNC
  6  - PD6 - VSYNC  
  */
  
  DDRB |= B01110000;
  
  DDRH |= B01100000;
  PORTH |= B01100000; 
  
  //set timer  
  TCCR2A = 0x02;                         // WGM22 = 0 + WGM21 = 1 + WGM20 = 0 -> Mode2 (CTC)
  TCCR2B |= (1 << CS20);                 //
  TCCR2B |= (1 << CS21);                 // Set prescaler
  TCCR2B &= ~(1 << CS22);                //
 
  TCNT2 = 0;                             // clean counter
 
  TIMSK2 &= ~(1<<OCIE2A);                // set comparison interrupt  
  TIMSK2 |= (1<<TOIE2);                  // set overflow interrupt  
}
 
void loop() {
  noInterrupts();
  do {
    BLACK;
    if (TCNT2 > 0x0f){
 
      delayMicroseconds(1);
      NOP;NOP;NOP;NOP;
     
      TCNT2 = 0x00;
                       
      // #### HSYNC ###
      PORTH &= ~(1 << 6);      
      if (++linecount >= 525) { //525 lines
        linecount = 1;
      }      
      PORTH |= (1 << 6);
 
      // ### VSYNC ###
      if ((linecount == 1)||(linecount == 2)) {
        PORTH &= ~(1 << 5);      
      } 
      else {
        PORTH |= (1 << 5);
       
        /*NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
        NOP;NOP;NOP;*/NOP;NOP;NOP;NOP;NOP;NOP;
        NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
        NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
       
        if ((linecount >= 9) && (linecount <= 489)) {
                WHITE;
                delayMicroseconds(3);
                NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                
                BLACK;
                delayMicroseconds(3);
                NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                
                BLUE;
                delayMicroseconds(3);
                NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                
                GREEN;
                delayMicroseconds(3);
                NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                
                CYAN;
                delayMicroseconds(3);
                NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                
                RED;
                delayMicroseconds(3);
                NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                
                MAGENTA;
                delayMicroseconds(3);
                NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                
                YELLOW;
                delayMicroseconds(3);
                NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;
                
                BLACK;
                NOP;NOP;NOP;NOP;
        }
      }
    }
  } while(1);
}

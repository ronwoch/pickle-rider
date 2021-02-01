#ifndef IO_H
#define	IO_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* IO_H */
// PORT A


// Give PORT A human-friendly names
#define PIN_A0 PORTAbits.RA0
#define PIN_A1 PORTAbits.RA1
#define PIN_A2 PORTAbits.RA2
#define PIN_A3 PORTAbits.RA3
#define PIN_A4 PORTAbits.RA4
#define PIN_A5 PORTAbits.RA5
#define PIN_A6 PORTAbits.RA6
#define PIN_A7 PORTAbits.RA7

// Configure PORTA pin as input or output
#define IO_A_0 TRISAbits.TRISA0
#define IO_A_1 TRISAbits.TRISA1
#define IO_A_2 TRISAbits.TRISA2
#define IO_A_3 TRISAbits.TRISA3
#define IO_A_4 TRISAbits.TRISA4
#define IO_A_5 TRISAbits.TRISA5
#define IO_A_6 TRISAbits.TRISA6
#define IO_A_7 TRISAbits.TRISA7

// PORT B 


// Give PORT B human-friendly names
#define PIN_B0 PORTBbits.RB0
#define PIN_B1 PORTBbits.RB1
#define PIN_B2 PORTBbits.RB2
#define PIN_B3 PORTBbits.RB3
#define PIN_B4 PORTBbits.RB4
#define PIN_B5 PORTBbits.RB5
#define PIN_B6 PORTBbits.RB6
#define PIN_B7 PORTBbits.RB7

// Configure PORTB pin as input or output
#define IO_B0 TRISBbits.TRISB0
#define IO_B1 TRISBbits.TRISB1
#define IO_B2 TRISBbits.TRISB2
#define IO_B3 TRISBbits.TRISB3
#define IO_B4 TRISBbits.TRISB4
#define IO_B5 TRISBbits.TRISB5
#define IO_B6 TRISBbits.TRISB6
#define IO_B7 TRISBbits.TRISB7

// Add labels to match the Velleman P8048 programmer/experimenter

// Six LED's labeled LD1-LD6, on PORTB

#define LD1 PIN_B0
#define LD2 PIN_B1
#define LD3 PIN_B2
#define LD4 PIN_B3
#define LD5 PIN_B4
#define LD6 PIN_B5

// 4 Buttons labeled SW1-SW4, on PORTA

#define SW1 PIN_A0
#define SW2 PIN_A1
#define SW3 PIN_A2
#define SW4 PIN_A3




// Define useable values: ON/OFF, INPUT/OUTPUT, etc.
#define OFF 0
#define ON 1
#define INPUT 1
#define OUTPUT 0

/* Example usage: Configure LED to be output, and toggle it on/off - 
 *      IO_B0 = OUTPUT; // Set to pin to output. Should be able to do this
 *    once per program unless you have some need to toggle back and forth (Or toggle other functions on shared pin)
 *
 *      LD1 = ON; // Toggle LED on
 *      LD1 = OFF; // Toggle LED off
 * 
*/

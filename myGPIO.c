/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
      /*Initialization of Button L1*/
                P1DIR = P1DIR & ~ LaunchpadS1;
                P1REN = P1REN |  LaunchpadS1;
                P1OUT = P1OUT | LaunchpadS1;

                P1DIR = P1DIR & ~ LaunchpadS2;
                P1REN = P1REN | LaunchpadS2;
                P1OUT = P1OUT | LaunchpadS2;

       //Initialization of Button B1*/
                P5DIR &= ~BoosterpackS1;
                P5REN |= BoosterpackS1;
                P5OUT |= BoosterpackS1;

       /*Initialization of Button B2*/
                P3DIR &= ~BoosterpackS2;
                P3REN |= BoosterpackS2;
                P3OUT |= BoosterpackS2;



      /*Initialization of LED2*/
                 P2DIR = P2DIR | LED2_RED ;     /*  // RED COLOR      MAKES IT OUTPUT*/
                 P2DIR = P2DIR | LED2_GREEN;    /*  //GREEN COLOR      MAKES IT OUTPUT*/
                 P2DIR = P2DIR | LED2_BLUE;     /*  //BLUE COLOR         MAKES IT OUTPUT*/

      /*/Initialization of BLED*/
                 P2DIR = P2DIR | BLED2_RED;     /*   //RED COLOR          MAKES IT OUTPUT*/
                 P2DIR = P2DIR | BLED2_GREEN;    /*  //GREEN COLOR          MAKES IT OUTPUT*/
                 P5DIR = P5DIR | BLED2_BLUE;     /*  //BLUE COLOR           MAKES IT OUTPUT*/

    // Turn off all LEDs at the start.
                 P2OUT = P2OUT & ~LED2_RED ;     /*  // RED COLOR      MAKES IT OUTPUT*/
                 P2OUT = P2OUT & ~LED2_GREEN;    /*  //GREEN COLOR      MAKES IT OUTPUT*/
                 P2OUT = P2OUT & ~LED2_BLUE;

                 P2OUT = P2OUT & ~BLED2_RED ;     /*  // RED COLOR      MAKES IT OUTPUT*/
                 P2OUT = P2OUT & ~BLED2_GREEN;    /*  //GREEN COLOR      MAKES IT OUTPUT*/
                 P5OUT = P2OUT & ~BLED2_BLUE;
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LaunchpadS1) == LaunchpadS1);      /*//pull-down resistor.......... DEFAULT STATE:0*/

}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & LaunchpadS2) == LaunchpadS2);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & BoosterpackS1) == BoosterpackS1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BoosterpackS2) == BoosterpackS2);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
                    P1OUT = P1OUT | LED1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
                    P1OUT &= ~LED1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
                   P2OUT |= LED2_RED;
                   P2OUT &= ~LED2_BLUE;
                   P2OUT &= ~LED2_GREEN;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
                   P2OUT &= ~LED2_RED;
                   P2OUT &= ~LED2_BLUE;
                   P2OUT  &= ~LED2_GREEN;

}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
                    P2OUT &= ~LED2_RED;
                    P2OUT &= ~LED2_BLUE;
                    P2OUT |= LED2_GREEN;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
                    P2OUT  &= ~LED2_GREEN;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
                   P2OUT &= ~LED2_RED;
                   P2OUT &= ~LED2_GREEN;
                   P2OUT |= LED2_BLUE;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{

                   P2OUT &= ~LED2_BLUE;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
                    P2OUT |= BLED2_RED;
                    P5OUT &= ~BLED2_BLUE;
                    P2OUT &= ~BLED2_GREEN;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
                    P2OUT &= ~BLED2_RED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
                   P2OUT &= ~BLED2_RED;
                   P5OUT &= ~BLED2_BLUE;
                   P2OUT |= BLED2_GREEN;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{

                   P2OUT &= ~BLED2_GREEN;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
                    P2OUT &= ~BLED2_RED;
                    P2OUT &= ~BLED2_GREEN;
                    P5OUT |= BLED2_BLUE;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{

                P5OUT &= ~BLED2_BLUE;
}
void turnOn_LaunchpadLED2Yellow()
{
                       P2OUT  |= LED2_RED;
                     P2OUT &= ~LED2_BLUE;
                      P2OUT |= LED2_GREEN;
   }
void turnOn_LaunchpadLED2Cyan()
{
                           P2OUT  |= LED2_BLUE;
                         P2OUT &= ~LED2_RED;
                          P2OUT |= LED2_GREEN;
}
void turnOn_LaunchpadLED2Magneta()
{
                        P2OUT  |= LED2_RED;
                        P2OUT |= LED2_BLUE;
                         P2OUT &= ~LED2_GREEN;

}
void turnOn_LaunchpadLED2White()
{
                        P2OUT  |= LED2_RED;
                        P2OUT  |= LED2_BLUE;
                         P2OUT |= LED2_GREEN;
      }

void turnOff_LaunchpadLED2Yellow()
{
                        P2OUT  &= ~BLED2_BLUE;
                        P2OUT &= ~BLED2_RED;
                         P2OUT &= ~BLED2_GREEN;
}
void turnOff_LaunchpadLED2Cyan()
{

                            P2OUT  &= ~BLED2_BLUE;
                            P2OUT &= ~BLED2_RED;
                             P2OUT &= ~BLED2_GREEN; }
void turnOff_LaunchpadLED2Magneta()
{
                            P2OUT  |= LED2_RED;
                            P2OUT |= LED2_BLUE;
                             P2OUT |= LED2_GREEN;
}
void turnOff_LaunchpadLED2White()

{
                            P2OUT  &= ~LED2_BLUE;
                            P2OUT &= ~LED2_RED;
                             P2OUT &= ~LED2_GREEN; }







void turnOn_BoosterpackLEDCyan()
{

   P5OUT  |= BLED2_BLUE;
   P2OUT &= ~BLED2_RED;
   P2OUT |= BLED2_GREEN;
}

void turnOn_BoosterpackLEDMagneta()
{
                            P2OUT  |= BLED2_RED;
                            P5OUT |= BLED2_BLUE;
                            P2OUT &= ~BLED2_GREEN;
}

void turnOn_BoosterpackLEDWhite()
{
                               P2OUT  |= BLED2_RED;
                               P5OUT |= BLED2_BLUE;
                               P2OUT |= BLED2_GREEN;
}
void turnOn_BoosterpackLEDYellow()
{
                        P2OUT  |= BLED2_RED;
                        P5OUT &= ~BLED2_BLUE;
                        P2OUT |= BLED2_GREEN;
}

void turnOff_BoosterpackLEDYellow()
{

                        P5OUT  &= ~BLED2_BLUE;
                            P2OUT &= ~BLED2_RED;
                             P2OUT &= ~BLED2_GREEN;
}

void turnOff_BoosterpackLEDCyan()
{
                        P5OUT  &= ~BLED2_BLUE;
                         P2OUT &= ~BLED2_RED;
                          P2OUT &= ~BLED2_GREEN;
}

void turnOff_BoosterpackLEDMagneta()
{
                            P2OUT  &= ~ BLED2_RED;
                            P5OUT &= ~ BLED2_BLUE;
                             P2OUT &= ~ BLED2_GREEN;
}

void turnOff_BoosterpackLEDWhite()
{

                            P5OUT  &= ~BLED2_BLUE;
                            P2OUT &= ~BLED2_RED;
                             P2OUT &= ~BLED2_GREEN;
}
void turnOff_BoosterpackLED()
{
                                P5OUT  &= ~BLED2_BLUE;
                                P2OUT &= ~BLED2_RED;
                                 P2OUT &= ~BLED2_GREEN;
}
void turnOff_LaunchpadLED2()
{
                                P2OUT  &= ~LED2_BLUE;
                                P2OUT &= ~LED2_RED;
                                 P2OUT &= ~LED2_GREEN;
}

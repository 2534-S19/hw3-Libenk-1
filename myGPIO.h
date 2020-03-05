/*
 * myGPIO.h
 *
 *  Created on:
 *      Author:
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_
#define LaunchpadS1    BIT1                   /*Initialization for bit postion and valuesN  */
#define LaunchpadS2   BIT4
#define BoosterpackS1    BIT1
#define BoosterpackS2   BIT5
#define LED1  BIT0
#define LED2_RED    BIT0
#define LED2_GREEN    BIT1
#define LED2_BLUE    BIT2
#define BLED2_RED    BIT6
#define BLED2_GREEN    BIT4
#define BLED2_BLUE    BIT6
#define PRESSED   0

// This function initializes the peripherals used in the program.
void initGPIO();
// This function returns the value of Launchpad S1.
unsigned char checkStatus_LaunchpadS1();
// This function returns the value of Launchpad S2.
unsigned char checkStatus_LaunchpadS2();
// This function returns the value of Boosterpack S1.
unsigned char checkStatus_BoosterpackS1();
// This function returns the value of Boosterpack S2.
unsigned char checkStatus_BoosterpackS2();
// This function turns on Launchpad LED1.
void turnOn_LaunchpadLED1();
// This function turns off Launchpad LED1.
void turnOff_LaunchpadLED1();
// This function turns on Launchpad Red LED2.
void turnOn_LaunchpadLED2Red();
// This function turns off Launchpad Red LED2.
void turnOff_LaunchpadLED2Red();
// This function turns on Launchpad Blue LED2.
void turnOn_LaunchpadLED2Blue();
// This function turns off Launchpad Blue LED2.
void turnOff_LaunchpadLED2Blue();
// This function turns on Launchpad Green LED2.
void turnOn_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOff_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOn_LaunchpadLED2Yellow();
void turnOn_LaunchpadLED2Cyan();
void turnOn_LaunchpadLED2Magneta();
void turnOn_LaunchpadLED2White();
void turnOff_LaunchpadLED2Yellow();
void turnOff_LaunchpadLED2Cyan();
void turnOff_LaunchpadLED2Magneta();
void turnOff_LaunchpadLED2White();










// This function turns on Boosterpack Red LED.
void turnOn_BoosterpackLEDRed();
// This function turns off Boosterpack Red LED.
void turnOff_BoosterpackLEDRed();
// This function turns on Boosterpack Green LED.
void turnOn_BoosterpackLEDGreen();
// This function turns off Boosterpack Green LED.
void turnOff_BoosterpackLEDGreen();
// This function turns on Boosterpack Blue LED.
void turnOn_BoosterpackLEDBlue();
// This function turns off Boosterpack Blue LED.
void turnOff_BoosterpackLEDBlue();



void turnOn_BoosterpackLEDCyan();
void turnOn_BoosterpackLEDMagneta();
void turnOn_BoosterpackLEDWhite();
void turnOn_BoosterpackLEDYellow();
void turnOff_BoosterpackLEDYellow();
void turnOff_BoosterpackLEDCyan();
void turnOff_BoosterpackLEDMagneta();
void turnOff_BoosterpackLEDWhite();


// TODO: Define any constants that are local to myGPIO.c using #define


#endif /* MYGPIO_H_ */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

 // typedef enum   {U,D} buffer;
  // static buffer  buttonhistory=U;
   //unsigned int sample;
 //   unsigned char buttonhistory=0;
    // TODO: Declare the variables that main uses to interact with your state machine.
    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {

        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);


        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);


        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
            if(timer0Expired())
                    count0++;

        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
            if(timer0Expired())
                sample++;


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
             fsmBoosterpackButtonS1(button);



        // TODO: If a completed, debounced button press has occurred, increment count1.
             if (fsmBoosterpackButtonS1(button))
             count1++;


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.

void changeLaunchpadLED2(unsigned int count)
{



 switch(sample & 7)
            {
                 case 0:
                     //turnOff_LaunchpadLED2Cyan();
                     break;
                 case 1:
                    turnOn_LaunchpadLED2Red();
                    break;
                 case 2:
                     turnOn_LaunchpadLED2Yellow();
                      break;
                 case 3:
                     turnOn_LaunchpadLED2Green();

                     break;
                 case 4:
                     turnOn_LaunchpadLED2Cyan();

                     break;
                 case 5:
                     turnOn_LaunchpadLED2Blue();

                     break;
                 case 6:
                     turnOn_LaunchpadLED2White();

                     break;
                 case 7:
                     turnOn_LaunchpadLED2Magneta();
                     break;
                 default:
                     break;
            }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
switch(count & 7)
{
                    case 0:
                       turnOff_BoosterpackLED();
                        break;
                    case 1:
                       turnOn_BoosterpackLEDRed();

                       break;
                    case 2:
                        turnOn_BoosterpackLEDYellow();
                         break;
                    case 3:
                        turnOn_BoosterpackLEDGreen();

                        break;
                    case 4:
                        turnOn_BoosterpackLEDBlue();

                        break;
                    case 5:
                        turnOn_BoosterpackLEDMagneta();
                        break;
                    case 6:
                        turnOn_BoosterpackLEDWhite();
                        break;
                    case 7:
                        turnOn_BoosterpackLEDCyan();
                        break;
                    default:
                        break;
               }

}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char button)
{

    bool pressed = false;
    switch (button)
    {
        case U:
              if(checkStatus_BoosterpackS1()==PRESSED)
              {
                  button=D;
                  return true;
              }
              break;

        case D:
            if(checkStatus_BoosterpackS1()==UNPRESSED)
            {
            button=U;
            }
          break;
    }
return pressed;
}

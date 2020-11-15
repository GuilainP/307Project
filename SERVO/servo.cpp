#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_THETA 50
#define MAX_THETA 240

int main (int argc, char** argv)
{
    int theta = MIN_THETA;

    if(argv[1]!=NULL){
	if(atoi(argv[1]) > MAX_THETA)
	    theta = MAX_THETA;
	else if(atoi(argv[1]) > MIN_THETA ) 
	    theta = atoi(argv[1]);
    }

    printf ("Raspberry Pi wiringPi : Going at %d°\n",theta);
    printf("Angle Span : %d° to %d°\n", MIN_THETA, MAX_THETA);

    wiringPiSetupGpio(); // Initialisation
    pinMode (18, PWM_OUTPUT) ; // Pin 12 , GPIO 18 en mode PMW
    pwmSetMode (PWM_MODE_MS);  // PWM en mode "mark:space"
    pwmSetRange (2000);
    pwmSetClock (192);
    pwmWrite(18, theta); // Ecriture de la position désirée
    delay(1000);

   return 0;
}

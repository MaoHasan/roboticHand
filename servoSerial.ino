#include <Servo.h>

Servo thumbOut;
Servo indexOut;
Servo middleOut;
Servo ringOut;
Servo pinkyOut;

/*
 * in this part of the code we are defining the fingers as INs and OUTS
 * INs = flex sensor pin layout, representing inputs
 * OUTs = servos representing outputs
 */
const int thumbInPin = A0;
const int thumbOutPin = 3;

const int indexInPin = A1;
const int indexOutPin = 5;

const int middleInPin = A2;
const int middleOutPin = 6;

const int ringInPin = A3;
const int ringOutPin = 9;

const int pinkyInPin = A4;
const int pinkyOutPin = 10;

/*
 * we assign variables to read the analog readings coming from the flex sensor.
 */
int thumbIn;
int indexIn;
int middleIn;
int ringIn;
int pinkyIn;

int fingers[] = {thumbOutPin, indexOutPin, middleOutPin, ringOutPin, pinkyOutPin};

int input1;
int input2;
int fingerNo;
void setup()
{
    // initializing serial communications at 9600 bps:
    Serial.begin(9600);
    Serial.println("Serial communicationn initialized");

    //attaching each servo motor to it's arduino pin.
    thumbOut.attach(thumbOutPin);
    indexOut.attach(indexOutPin);
    middleOut.attach(middleOutPin);
    ringOut.attach(ringOutPin);
    pinkyOut.attach(pinkyOutPin);

                    thumbOut.write(0);
    delay(50); //delay for ux purposes.

                indexOut.write(0);
    delay(50); //delay for ux purposes.

                middleOut.write(0);
    delay(50); //delay for ux purposes.

                ringOut.write(0);
    delay(50); //delay for ux purposes.

                pinkyOut.write(0);
    delay(500); //delay for ux purposes.
    
}

void loop()
{
    Serial.println("enter finger number 1-5");
    while (!Serial.available())
    {
        input1 = Serial.parseInt();
        Serial.print("enter finger angle");
        while (Serial.available() > 0)
        {
            input2 = Serial.parseInt();
            switch (input1){
                case 1:
                thumbOut.write(input2);
                break;
                case 2:
                indexOut.write(input2);
                break;
                case 3:
                middleOut.write(input2);
                break;
                case 4:
                ringOut.write(input2);
                break;
                case 5:
                pinkyOut.write(input2);
                break;
            }
            Serial.println(input2);
            delay(1000);
    }}
}
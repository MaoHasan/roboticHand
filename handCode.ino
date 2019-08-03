/*
 Controlling a robotic hand using flex sensors for the purposes of 
 biomdeical solutions.

 written on July 31 2019
 modified on July 31 2019
*/

#include <Servo.h> //importing the servo library

/*
 * we assign 5 servos to 5 finger names.
 * for more about finger names: https://www.simplybodylanguage.com/finger-names.html
 * 
 */
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
    delay(500); //delay for ux purposes.

    Serial.println("Fingers attached.");
    delay(500); //delay for ux purposes.
    Serial.println("send 1 to power the hand");
    while (serial.available()){
        if(serial.read() == '1'){
            break;
        }
    }
}

void loop()
{
    /*
    * the process goes as follows:
    * we read the flex sensor using the analog read command.
    * we map the read value from the flex to be between the min read value and the max read value
    * to be mapped to the curresponding servo angles resulting in the same hand movement.
    */

    thumbIn = map(analogRead(thumbInPin), 730, 950, 0, 180); //read the flex and map it
    Serial.print("Thumb: "); //printing the result of the mapping command.
    Serial.print("flex reading: ");
    Serial.print(analogRead(thumbInPin));
    Serial.print(", currepending angle: ");
    Serial.println(thumbIn);

    indexIn = map(analogRead(indexInPin), 730, 950, 0, 180);
    // Serial.print("Index: ");
    // Serial.print("flex reading: ");
    // Serial.print(analogRead(indexInPin));
    // Serial.print(", currepending angle: ");
    // Serial.println(indexIn);

    middleIn = map(analogRead(middleInPin), 730, 950, 0, 180);
    // Serial.print("Middle: ");
    // Serial.print("flex reading: ");
    // Serial.print(analogRead(middleInPin));
    // Serial.print(", currepending angle: ");
    // Serial.println(middleIn);

    ringIn = map(analogRead(ringInPin), 730, 950, 0, 180);
    // Serial.print("Ring: ");
    // Serial.print("flex reading: ");
    // Serial.print(analogRead(ringInPin));
    // Serial.print(", currepending angle: ");
    // Serial.println(ringIn);

    pinkyIn = map(analogRead(pinkyInPin), 730, 950, 0, 180);
    // Serial.print("Pinky: ");
    // Serial.print("flex reading: ");
    // Serial.print(analogRead(pinkyInPin));
    // Serial.print(", currepending angle: ");
    // Serial.println(pinkyIn);
    
    Serial.println("");
    Serial.println("---------------------------------------");

    // we write the gotten values from the map command to the servos to achieve the requested angles.
    thumbOut.write(thumbIn);
    indexOut.write(indexIn);
    middleOut.write(middleIn);
    ringOut.write(ringIn);
    pinkyOut.write(pinkyIn);

    delay(500); //delay for PWM purposes.
}

int inPin = 0;
int outPin = 1;
int state = 2;
int reading = 3;
int previous = 4;

int pinMatrix[6][5] = {
 {2, 8, LOW, 0, HIGH},
 {3, 9, LOW, 0, HIGH},
 {4, 10, LOW, 0, HIGH},
 {5, 11, LOW, 0, HIGH},
 {6, 12, LOW, 0, HIGH},
 {7, 13, LOW, 0, HIGH}
};

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;          // the last time the output pin was toggled
long debounce = 200;    // the debounce time, increase if the output flickers

void setup()
{
 // pinMode(inPin, INPUT);
 // pinMode(outPin, OUTPUT);
 for (int i = 0; i < 6; i++) {
   pinMode(pinMatrix[i][inPin], INPUT);
   pinMode(pinMatrix[i][outPin], OUTPUT);
 }
}

void loop()
{
 for (int j = 0; j < 6; j++) {
   pinMatrix[j][reading] = digitalRead(pinMatrix[j][inPin]);

   // if the input just went from LOW and HIGH and we've waited long enough
   // to ignore any noise on the circuit, toggle the output pin and remember
   // the time
   if (pinMatrix[j][reading] == HIGH && pinMatrix[j][previous] == LOW && millis() - time > debounce) {
     if (pinMatrix[j][state] == HIGH)
       pinMatrix[j][state] = LOW;
     else
       pinMatrix[j][state] = HIGH;

     time = millis();
   }

   digitalWrite(pinMatrix[j][outPin], pinMatrix[j][state]);

   pinMatrix[j][previous] = pinMatrix[j][reading];

 }
}

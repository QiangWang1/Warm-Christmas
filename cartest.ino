
const int buttonPin = 12;    // the number of the pushbutton pin

int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  // digitalWrite(9, LOW);
  // digitalWrite(10, LOW);
  analogWrite(9, 0);



}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(
    buttonPin);
  Serial.println(reading);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

     
      if (buttonState == HIGH) {
        count ++;
        Serial.println(count);
      }
    }
  }

 
  

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  if(count >= 3){
    delay(3000); 
    //bluetooth master send 1
    digitalWrite(9, HIGH);
    //digitalWrite(10, LOW);
    //analogWrite(9, 175);
    //analogWrite(10, 0);
    delay(5000);
    digitalWrite(9, LOW);
    //bluetooth master send 0
    count = 0;
  }
}

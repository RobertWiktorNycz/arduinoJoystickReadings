// Code for getting readings from Joystick using arduino
// and turning on 13 LED if the button is pressed
// according to tutorial from website: https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-joystick-with-serial-monitor-1f04f0
// Description of joystick inputs:
// VCC - power
// GND - ground
// VRx - Variable resistance x
// VRy - variable resistance y
// SW - switch / button
// Connection desciption:
// VCC - 5V
// GND - GND
// VRx - A0
// VRy - A1
// SW - Pin 2

// Enjoy :)

// definition of variablesand pins connected
int LEDPin = 13;
int VRx = A0;
int VRy = A1;
int SW = 2;

// definition of starting mapping
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  xPosition = analogRead(VRx); // reading position X
  yPosition = analogRead(VRy); // reading position Y
  SW_state = digitalRead(SW); // reading if button if pressed
  //mapping readings to variables
  mapX = map(xPosition,0,1023,-512,512);
  mapY = map(yPosition,0,1023,-512,512);
  //printing out variables
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.print(SW_state);
  // if button is pressed, turn on onboard LED (pin 13)
  if(SW_state == 0){
    digitalWrite(LEDPin, HIGH);
    Serial.println(" | LED ON");
  }else{
    digitalWrite(LEDPin,LOW);
    Serial.println(" | LED OFF");
  }
}

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>


const int pushbutton1 =5;
const int pushbutton2 =6;
const int pushbutton3 =7;
const int trigPin = 10;
const int echoPin = 9;

Servo pulley;
LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
int current;
int floorheight;
int direct;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pushbutton1, INPUT_PULLUP);
pinMode(pushbutton2, INPUT_PULLUP);
pinMode(pushbutton3, INPUT_PULLUP);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);

//Initialize the LCD
lcd.begin();
lcd.backlight();
lcd.clear();
lcd.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  // constantly checks to see if the button is pressed
int buttonState1 = digitalRead(pushbutton1);
Serial.println(buttonState1);
int buttonState2 = digitalRead(pushbutton2);
Serial.println(buttonState2);
int buttonState3 = digitalRead(pushbutton3);
Serial.println(buttonState3);

if (buttonState1==1){
  Serial.println("B1:");
  Serial.print(buttonState1);
  //Sets the necessary floor height
  floorheight=8;

  //Gets an initial height reading
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  current = pulseIn(echoPin, HIGH);
  current = current * 0.034 / 2;
  Serial.println(current);

//Decides direction servo should spin
//2 spins clockwise, 358 spins counter clockwise, 180 doesn't spin
  if ((current-floorheight)<-1){
    direct=30;
  }
  else if ((current-floorheight)>1){
    direct=330;
  }
  else{
    direct=180;
  }
  
  Serial.println(direct);

  //realism delay
  delay(4000);

  //LCD identifies what floor is about to be approached
    
    lcd.clear();
    lcd.print(" Approaching: F1");
    lcd.setCursor(0,0);

  //Tells servo to spin in required direction if below needed height, updates height reading
  
  while (current!=floorheight){
    pulley.attach(3);
    pulley.write(direct);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    current = pulseIn(echoPin, HIGH);
    current = current * 0.034 / 2;
    Serial.println (current);

  }
  //When while loop condition fulfilled, stops servo, LCD prints the current floor
  pulley.detach();
  lcd.clear();
  lcd.print(" YOU ARE ON: F1");
  lcd.setCursor(0,1);
  lcd.print(" WH:1 BL:2 BR:3");
  
  //realism delay
  delay(4000);

}
else if (buttonState2==1){
  Serial.println("B2:");
  Serial.print(buttonState2);
  //Sets the necessary floor height
  floorheight=24;

  //Gets an initial height reading
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  current = pulseIn(echoPin, HIGH);
  current = current * 0.034 / 2;
  Serial.println(current);

//Decides direction servo should spin
//2 spins clockwise, 358 spins counter clockwise, 180 doesn't spin
  if ((current-floorheight)<-1){
    direct=30;
    floorheight=25;
  }
  else if ((current-floorheight)>1){
    direct=330;
  }
  else{
    direct=180;
  }
  
  Serial.println(direct);

  //realism delay
  delay(4000);

  //LCD identifies what floor is about to be approached
    
  lcd.clear();
  lcd.print(" Approaching: F2");
  lcd.setCursor(0,0);
    
  //Tells servo to spin in required direction if below needed height, updates height reading
  
  while (current!=floorheight){
    pulley.attach(3);
    pulley.write(direct);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    current = pulseIn(echoPin, HIGH);
    current = current * 0.034 / 2;
    Serial.println (current);

  }
  //When while loop condition fulfilled, stops servo, LCD prints the current floor
  pulley.detach();
  lcd.clear();
  lcd.print(" YOU ARE ON: F2");
  lcd.setCursor(0,1);
  lcd.print(" WH:1 BL:2 BR:3");
  
  //realism delay
  delay(4000);

}
else if (buttonState3==1){
  Serial.println("B3:");
  Serial.print(buttonState3);
  //Sets the necessary floor height
  floorheight=36;

  //Gets an initial height reading
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  current = pulseIn(echoPin, HIGH);
  current = current * 0.034 / 2;
  Serial.println(current);

//Decides direction servo should spin
//2 spins clockwise, 358 spins counter clockwise, 180 doesn't spin
  if ((current-floorheight)<-1){
    direct=30;
  }
  else if ((current-floorheight)>1){
    direct=330;
  }
  else{
    direct=180;
  }
  
  Serial.println(direct);

  //realism delay
  delay(4000);

  //LCD identifies what floor is about to be approached
    
  lcd.clear();
  lcd.print(" Approaching: F3");
  lcd.setCursor(0,0);

  //Tells servo to spin in required direction if below needed height, updates height reading
  
  while (current!=floorheight){
    pulley.attach(3);
    pulley.write(direct);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    current = pulseIn(echoPin, HIGH);
    current = current * 0.034 / 2;
    Serial.println (current);
   
  }
  //When while loop condition fulfilled, stops servo, LCD prints the current floor 
  pulley.detach();
  lcd.clear();
  lcd.print(" YOU ARE ON: F3");
  lcd.setCursor(0,1);
  lcd.print(" WH:1 BL:2 BR:3");
  
  //realism delay
  delay(4000);

}
}

/*
 * Overhead Tank Intelligent Water Level Controller
 * Date: 14.05.2020
 * This code was developed by Prof. Dattaraj Vidyasagar
 * www.vsa.edu.in
 * License: You can use it for any purpose as long as you don't 
 * claim that you are the author of this program and
 * you don't alter License terms and 
 * formulations (lines 1-10 of this file). 
 */

/************************************
Important Note:
Refer the circuit of this project, before using this code.
The analog input pins (A0 & A1) must be returned to ground via 100k resistor each.
Then apply the water level signal to these two pins: Full or Empty
*************************************/

// Declaration of variables
int Pump=13; // variable for pump relay conntected at pin-9
int Buzzer=7; // buzzer for audio indication 
int Full=A1; // the maximum level of water in tank, Analog pin-1
int Empty=A0; // the 1/4 level of water in tank, Analog pin-0
int f, e, p; // status variables, f=Full, e=Empty, p=Pump

// boolean alreadyBeeped = false; // the flag

void setup()
{
  pinMode(Pump,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(Full,INPUT);
  pinMode(Empty,INPUT);
  digitalWrite(Pump,LOW); // initially we keep the water pump OFF
  digitalWrite(Buzzer,HIGH); // initial audio indication
  delay(1000);
  digitalWrite(Buzzer,LOW);
}

void loop()
{
  // reading the water level status of tank
  f=digitalRead(Full); // reading pin value at A1
  e=digitalRead(Empty); // reading pin value at A0

  // reading the pump status
  p=digitalRead(Pump);

  // creating conditions of water level

  if(f==HIGH && e==HIGH && p==LOW) // tank is full
  {
    delay(1000); // just a perceptible pause 
    digitalWrite(Pump,LOW);
  }

  if(f==LOW && e==HIGH && p==LOW) 
  {
    delay(1000); // just a perceptible pause 
    digitalWrite(Pump,LOW);
  }

  if(f==LOW && e==LOW && p==LOW) 
  {
    delay(2000); // just a perceptible pause
    digitalWrite(Pump,HIGH); // now switching the pump ON
  }

  // reading the pump status again
  p=digitalRead(Pump);
  
  if(f==LOW && e==HIGH && p==HIGH) // tank water is greater than 1/4 but NOT FULL
  {
    delay(1000); // just a perceptible pause 
    // now we have to read status of "e" input again.
    // because, when tank is filling up through a water tap, 
    // there might be splashes in water level, which may create false alarm.
    // so to avoid false alarm, we read the status of input "e" for 10 seconds.
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);
    e=digitalRead(Empty); 
    delay(1000);

    if(f==LOW && e==HIGH && p==HIGH)
    {
      delay(1000);
      digitalWrite(Pump,HIGH);
    }
  }

  if(f==HIGH && e==HIGH && p==HIGH) // tank is full so pump is off
  {
    delay(2000); // just a perceptible pause 
    // now we have to read status of "e" input again.
    // because, when tank is filling up through a water tap, 
    // there might be splashes in water level, which may create false alarm.
    // so to avoid false alarm, we read the status of input "e" for 10 seconds.
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);
    f=digitalRead(Full); 
    delay(1000);

    if(f==HIGH && e==HIGH && p==HIGH)
    {
      delay(100); // just a perseptible pause
      digitalWrite(Pump,LOW);
    } 
  }
}

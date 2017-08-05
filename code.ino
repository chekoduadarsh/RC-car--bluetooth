/*******************************************************************/
 /* Written by Adarsh C// 14-01-2016 V.1.3
 /* Project: Controlling RC car Via ANDROID using HC05 and ARDUINO

/*******************************************************************/

//Buzzer / Speaker to Arduino UNO Pin 12
  const int buzzer = 13 ;   
//Bluetooth (HC-06 JY-MCU) State pin on pin 2 of Arduino
  const int BTState = 2;
  const int pinfrontLights = 11;    //Pin that activates the Front lights.
  const int pinbackLights  = 12;   //Pin that activates the Back lights.  

  int state;
  int vSpeed=255;     // Default speed, from 0 to 255
/****************************************************************/
//Motor based on L298N motor drive module
// motor A
int enA = 5;
int in1 = 6;
int in2 = 7;
// motor B
int enB = 8;
int in3 = 9;
int in4 = 10;
String readString;
/*****************************************************************/
  void setup() {
    
    pinMode(pinfrontLights, OUTPUT); 
    pinMode(pinbackLights, OUTPUT); 
    pinMode(buzzer, OUTPUT); 
    pinMode(BTState, INPUT);   
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
 // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
 
/***********************************Bluetooth**********************************************/
  //Stop car when connection lost or bluetooth disconnected
     if(digitalRead(BTState)==LOW) { 
     state='S'; 
  }
  //Save income data to variable 'state'
    if(Serial.available() > 0){     
      state = Serial.read();   
      delay(15);
    }
  //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
      else   if((state >= 48) && (state <= 57))
          { 
            //Subtracting 48 changes the range from 48-57 to 0-9.
            //Multiplying by 28 changes the range from 0-9 to 0-255(L298N max speed)
            vSpeed = (state - 48)*28.3;       
          //  yellowCar.SetSpeed_4W(velocity);
          Serial.println(vSpeed);
          }
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
   // turn on motor A         
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3,HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, vSpeed);
  Serial.println("Going forward");
     }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    if (state == 'I') {
  // turn on motor A     
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, vSpeed);
  Serial.println("Forward left");
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    if (state == 'G') {
  // turn on motor A     
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, vSpeed);
  Serial.println("Going forward-right");
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    if (state == 'B') {
   // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, vSpeed);
  Serial.println("Going backward");    
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
    if (state == 'H') {
   // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, vSpeed);
  Serial.println("Going backward-left"); 
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
    if (state == 'J') {
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, vSpeed);
  Serial.println("Going backward-right"); 
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    if (state == 'R') {
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, vSpeed);
  Serial.println("Rotating left"); 
    }
 /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    if (state == 'L') {
   // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, vSpeed);
  Serial.println("Rotating right"); 
    }
 /************************front Lights*****************************/
  //If state is equal with letter 'W', turn front leds on 
    if (state == 'W') {
       digitalWrite(pinfrontLights, HIGH); 
       Serial.println("Frontlight  on");
        }
    if (state == 'w') {
         digitalWrite(pinfrontLights, LOW); 
         Serial.println("Frontlight  off"); 
        }
 /************************Back Lights*****************************/
    //If state is equal with letter 'W', turn front leds on 
    if (state == 'U') {
       digitalWrite(pinbackLights, HIGH); 
       Serial.println("Backlight  on"); 
        }
    if (state == 'u') {
       digitalWrite(pinbackLights, LOW); 
       Serial.println("Backlight  off"); 
        }
   
  /**********************Horn sound***************************/
  //If state is equal with letter 'V', play (or stop) horn sound
    if (state == 'V'){
       tone(buzzer, 1000);//Speaker on 
       Serial.println("Horn on"); 
      }
    if (state == 'v'){
       noTone(buzzer);    //Speaker off 
       Serial.println("Horn off"); 
      }
 /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    if (state == 'S'){
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, vSpeed);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, vSpeed);
    }
 
}//void loop()end



char speed0 = 240;                       //Geschwindigkeit ohne Sensor
char speed1 = 255;                       //Geschwindigkeit ab Sensor 1
char speed2 = 255;                       //Geschwindigkeit ab Sensor 2
char speed3 = 220;                       //Geschwindigkeit ab Sensor 3
char speed4 = 110;                       //Geschwindigkeit ab Sensor 4

int arySensor [] = {4,6,7,8,11};        // Sensorinput pins: 4,6,7,8,11

int pinRead;                            // returnwert der Sensoren wird hier gespeichert (high oder low) 
int speedOut = 9;                       // PWM ausgang
int VoltageDoubler = 5;                 // PWM ausgang
int pause = 200;                        // Wartezeit (in Millisekunden) nach Geschwindigkeitsänderung 
unsigned char roundCounter = 0;         // zum Zählen der Runden (Sensor 1)

void setup() 
{
  Serial.begin(9600);                   //seriellen monitor "starten"  
  for (int i=0;i<5;i++)
  {
    pinMode(arySensor[i], INPUT);
    delay(1);
  }
  
  for (int a=0;a<5;a++)
  {
    digitalWrite(arySensor[a], LOW);     
    delay(1);
  }
  
  pinMode(speedOut, OUTPUT); 
  analogWrite(speedOut, speed0);        //geschwindigkeit ohne sensorkontakt

  pinMode(VoltageDoubler,OUTPUT);
  analogWrite(VoltageDoubler, 145);               
}

void loop() 
{
  int sensorStatus = LOW;
  pinRead = 0;
  for (pinRead=0;pinRead<5;pinRead++) 
    {
      sensorStatus = digitalRead(arySensor[pinRead]);
      if (sensorStatus == HIGH)
      {
        break;
      }
      else
      {
        sensorStatus = LOW;
      }
      delay(1);
    }
  
  switch(pinRead)
    {
      case 0: 
        Serial.println("Sensor 1 durchfahren");
        Serial.print("Die Geschwindigkeit ist jetzt bei: ");
        Serial.println(speed1);
        analogWrite(speedOut, speed1);
        delay(pause);
        /*
        roundcounter++;
        Serial.print("Runde: ");
        Serial.println(roundCounter);
        if (roundCounter >= 3)
        {
          while (digitalRead(arySensor[0]) == HIGH)
          {
            Serial.println("low");
            analogWrite(speedOut, 130);
          }
          analogWrite(speedOut, 0);
        }
        */
      break;
      case 1:
        Serial.println("Sensor 2 durchfahren");
        Serial.print("Die Geschwindigkeit ist jetzt bei: ");
        Serial.println(speed2);
        analogWrite(speedOut, speed2);
        delay(pause);
      break;
      case 2:
        Serial.println("Sensor 3 durchfahren");
        Serial.print("Die Geschwindigkeit ist jetzt bei: ");
        Serial.println(speed3);
        analogWrite(speedOut, speed3);
        delay(pause);
      break;
      case 3: 
        Serial.println("Sensor 4 durchfahren");
        Serial.print("Die Geschwindigkeit ist jetzt bei :");
        Serial.println(speed4);
        analogWrite(speedOut, speed4);
        delay(pause+20);
        analogWrite(speedOut, speed0);
      break;
      default:
      break;   
    }
}

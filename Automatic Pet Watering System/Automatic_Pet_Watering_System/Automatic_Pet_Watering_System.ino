//Automatic watering ystem//


const int trigPin = A3;
const int echoPin = A2;

int rele = 3;
int normaldrift = 5;
int fyller = 8;

long duration;
int distance;

int releDrift = 0;
int sensorValue = 0;  
int fullStatus = 0;
int startfylling = 0;
int tell =0;



#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 6, 9, 10, 7);




void setup() 
{

  
//Utganger og innganger//
pinMode (trigPin, OUTPUT);
pinMode (echoPin, INPUT);


pinMode (rele, OUTPUT);
pinMode (normaldrift,OUTPUT);
pinMode (fyller , OUTPUT);



//level sensor
Serial.begin(9600);



  lcd.begin(16, 2);
  // Print a message to the LCD.

digitalWrite(rele,LOW);

}





void loop() 
{

 

  
  
  
   //               LEVEL SENSOR                 //
  //---------------------------------------------//
 
  // read the analog in value:

  
int avstand = (distance);
avstand = constrain(avstand, 1, 8);
avstand = map (avstand,1,8,8,1);




digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);



duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;



int vannlevel = avstand;



  // print the results to the serial monitor:

Serial.println(releDrift);

  delay(200);
 
  releDrift = digitalRead(rele);





if ( vannlevel < 3 )
 {tell++;}


if (tell >=111) // 30sekunder
{ startfylling = 1;
}





  if ( startfylling == 1 && vannlevel < 6) 
  {
   digitalWrite(rele, HIGH);
  }
  
   if ( vannlevel >= 6) 
  {
   digitalWrite(rele, LOW); 
   tell = 0;
   startfylling = 0;
   }
  

  

//-------------------------------------------------//








//                   LOW LEVEL                     //
// ------------------------------------------------//




//---------------------------------------------------//









//      Forigling  (for å sikre tørrkjøring          //
//--------------------------------------------------//





//---------------------------------------------------//










//                     Display                       //
//---------------------------------------------------//




if (releDrift == LOW)
{
lcd.clear();
lcd.setCursor(4, 0);
lcd.print("Vannstand");
lcd.setCursor(8, 1);
lcd.print(vannlevel);
lcd.setCursor(10, 1);
lcd.print("cm");
delay(50);
lcd.clear();
lcd.setCursor(4, 0);
lcd.print("Vannstand");
lcd.setCursor(8, 1);
lcd.print(vannlevel);
lcd.setCursor(10, 1);
lcd.print("cm");
digitalWrite (normaldrift, HIGH);


  }



if (releDrift == HIGH)
{
lcd.clear();
lcd.setCursor(5, 0);
lcd.print("Fyller");
lcd.setCursor(7, 1);
lcd.print(vannlevel);
lcd.setCursor(3, 1);
lcd.print("~");
lcd.setCursor(11, 1);
lcd.print("~");
digitalWrite (normaldrift, LOW);
digitalWrite (fyller, HIGH);
delay(50);
digitalWrite (fyller, LOW);
delay(50);
}






//--------------------------------------------//


}
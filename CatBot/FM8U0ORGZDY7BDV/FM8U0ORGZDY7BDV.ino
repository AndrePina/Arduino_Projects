//CatBot.ino- An autonomous cat toy.
//version 0.1 2012/03/04 
//Joe McManus josephmc@cmu.edu
//Copyright (C) 2012 Joe McManus
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include <Servo.h>

Servo vert; 
Servo hor;

void setup() { 
  vert.attach(10);
  hor.attach(9); 
}

void migrate(Servo &myServo, int newPos) {
  int wait=random(30,60); //randomize the wait to make it more interesting
  int pos = myServo.read(); //Read the current servo position
  if (pos < newPos) { 
    for (int i=pos; i < newPos; i++) {
      myServo.write(i);
      delay(wait); 
    }
  } else { 
    for (int i=pos; i > newPos; i--) { 
      myServo.write(i);
      delay(wait);
    }
  }
}
    
  
void randomPosition() {
  int rand=random(40,120); //The range is limited to 60 deg for better cat action
  migrate(hor, rand);
  
  rand=random(90,135); //The vertical range is limited to 45 deg also for better cat action. 
  migrate(vert, rand);
}
   
void loop() { 
  randomPosition();
  delay(2000);
}

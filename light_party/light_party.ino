void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 LED led;
 Timer timer;
 led.turn_on_all(GREEN);
 timer.pause(500);
 led.turn_on_all (MAGENTA);
 timer.pause(500);
 led.turn_on_all(WHITE);
 timer.pause(500);
 led.turn_on_all(BLUE);
 timer.pause(500);
 led.turn_on_all (CYAN);
 timer.pause(500);
 led.turn_on_all(WHITE);
 timer.pause(500);
}
  

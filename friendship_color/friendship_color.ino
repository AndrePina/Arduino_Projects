void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  LED led;
  Timer timer;
if (see_cyan_friends()) {
  // led.turn_on_all(CYAN);
  timer.pause(500);
}
if (see_green_friends()) {
  // led.turn_on_all(GREEN);
  timer.pause(500);
}
if (see_RED_friends()) {
  // led.turn_on_all(RED);
  timer.pause(500);
}
}

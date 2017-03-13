volatile int tach = 0;

void setup() 
{
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, count, CHANGE); // for pin 2 attach pin 0
  Serial.begin(9600);
}

void loop() {
 //Serial.println(tach);
 //delay(800);
}

void count() 
{
  tach++; // yellow wire from 3 pin computer fan
  Serial.println(tach);
}

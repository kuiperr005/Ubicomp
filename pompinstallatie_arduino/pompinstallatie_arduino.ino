#define trigPin 13
#define echoPin 12
#define trigPin2 10
#define echoPin2 9
const int pomp = 11;
int lampswitch = 0;
int thisDistance = 0;
int newDistance = 0;
int meters = 25000;
int walkedDistance = 0;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(pomp, OUTPUT);
}
// Counts the amount of meters and prints to serial
int countMeters() {
  thisDistance = meters;
  newDistance = meters - 10;
  for (int i = thisDistance; i >= newDistance; i = i - 1) {
    meters = i;
    Serial.println(meters);
    delay(1000);
  }
  return meters;
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;

  // ALS EEN PERSOON DOOR DE EERSTE SENSOR HEENLOOPT
  if (distance < 10) {
    // functie die het aantal meters omlaag gaat tellen (max 10)  
    countMeters();
    lampswitch = 1;  // This is where the LED On/Off happens
//    Serial.println("pomp gaat aan");
  }
  // ALS EEN PERSOON DOOR DE TWEEDE SENSOR HEENLOOPT
  if (distance2 < 10) {
    lampswitch = 0;  // This is where the LED On/Off happens
//    Serial.println("pomp gaat uit");
    walkedDistance = walkedDistance + 10;
//    Serial.println(walkedDistance);
  }
  if (lampswitch == 1) {
    digitalWrite(pomp,HIGH);
  }
  else {
    digitalWrite(pomp,LOW);
  }
  //  Serial.print(distance);
  //    Serial.println(" cm");
  //Serial.println(meters);
}


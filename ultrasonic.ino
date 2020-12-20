const int trigPin = 11;
const int echoPin = 12;
const int buzzPin = 7;
const int ledPin = 8;
// defines variables
long duration;
int distance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzPin, OUTPUT);
pinMode(ledPin, OUTPUT);

Serial.begin(9600); // Starts the serial communication
}


void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);


  if(distance <= 430){
    Serial.print("close!!");
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzPin, LOW);
  }
}

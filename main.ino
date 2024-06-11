// Arduino Code to read water sensor value from A5 and send it to serial port
const int sensorPin = A5; // Pin where the water sensor is connected
const int led = 2;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  pinMode(led, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the analog value from sensor
  Serial.println(sensorValue); // Send the value to serial port
  delay(200); // Wait for a second before taking another reading
  if(sensorValue > 400){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
}

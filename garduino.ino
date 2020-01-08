int waterLevel = 0;
int waterLevelThreshold = 200;
int waterLevelSensorPin = A0;

int soilMoisture = 0;
int soilSensorPin = A1;
int soilMoistureThreshold = 500; // 380 when dunked in water, 540 sitting in dry area. Yes.

int motorPin = 7;
int motorCycleMilliseconds = 1000; // turn on for 1 second.

int loopSpeed = 1000;

void setup() {
  Serial.begin(9600);

  // sets the motor's serial pin as output
  pinMode(motorPin, OUTPUT);
}

void loop() {
  //Check moisture sensor.
  soilMoisture = analogRead(soilSensorPin);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);

  //If moisture sensor is low, turn on motor for X seconds.
  if (soilMoisture > soilMoistureThreshold)
  {
    Serial.println("Turn on Motor");
    //TODO
    //TurnOnWaterPump(motorCycleMilliseconds);
  }

  // Check water resveour
  waterLevel = analogRead(waterLevelSensorPin);

  //If water level is really low, send alert.
  if (waterLevel < waterLevelThreshold)
  {
    Serial.println("Water resevour is empty. Send alert. TODO");
  }

  delay(loopSpeed);
}

// Turn on water pump for X amount of time.
void TurnOnWaterPump(int milliseconds) {
  digitalWrite(motorPin, HIGH); // sets the digital pin 13 on
  delay(milliseconds);          // waits for a spec
  digitalWrite(motorPin, LOW);  // sets the digital pin 13 off
}


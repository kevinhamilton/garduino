int waterLevel = 0; 
int waterLevelThreshold = 200;
int waterLevelSensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  waterLevel = analogRead(waterLevelSensorPin);
  if(waterLevel <= waterLevelThreshold){
    Serial.println("water is empty");
  } else {
    Serial.println("water exists");
    
  }
  
  delay(1000);
}

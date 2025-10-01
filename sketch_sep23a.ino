#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

int ldrPin = 32;  // LM393 DO pin

void setup() {
  Serial.begin(115200);

  // Init MPU6050
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1);
  }
  pinMode(ldrPin, INPUT);

  // Tell Edge Impulse Data Forwarder what fields we’re sending
  // format: “name1 name2 …”
  // Must end with newline
  Serial.println("Edge Impulse Data Forwarder");
  Serial.println("tilt,light"); // 2 features: tilt, light
}

void loop() {
  // Get MPU6050 data
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Calculate tilt
  float tilt = atan2(a.acceleration.x, a.acceleration.z) * 180 / 3.14;

  // Light state
  int lightState = digitalRead(ldrPin); // 1=bright, 0=dark

  // Print CSV line with sensor values
  // Edge Impulse Data Forwarder expects comma-separated floats
  Serial.print(tilt, 2);
  Serial.print(",");
  Serial.println(lightState);

  delay(100); // 10 samples/sec
}

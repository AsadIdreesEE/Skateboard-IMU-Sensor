#include <Wire.h>
#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa mpu;

void setup() {
  Serial.begin(115200);

  // Initialize MPU-9250
  while (!mpu.beginMag()) {
    Serial.println("Failed to initialize MPU-9250. Please check your connections.");
    delay(5000);
  }

  // Calibrate gyro and accelerometers
  mpu.calibrateGyro();
  mpu.calibrateAccel();

  // Set the gyro sensitivity to ±500 dps
  mpu.setGyroRange(MPU9250_GYRO_RANGE_500DPS);

  // Set the accelerometer sensitivity to ±2 g
  mpu.setAccelRange(MPU9250_ACCEL_RANGE_2G);
}

void loop() {
  // Read sensor data
  mpu.readSensor();

  // Print accelerometer, gyroscope, and magnetometer data
  Serial.print("Accel (m/s^2): ");
  Serial.print(mpu.getAccelX_mss());
  Serial.print("\t");
  Serial.print(mpu.getAccelY_mss());
  Serial.print("\t");
  Serial.print(mpu.getAccelZ_mss());
  Serial.println();

  Serial.print("Gyro (deg/s): ");
  Serial.print(mpu.getGyroX_rads() * 180 / PI);
  Serial.print("\t");
  Serial.print(mpu.getGyroY_rads() * 180 / PI);
  Serial.print("\t");
  Serial.print(mpu.getGyroZ_rads() * 180 / PI);
  Serial.println();

  Serial.print("Mag (uT): ");
  Serial.print(mpu.getMagX_uT());
  Serial.print("\t");
  Serial.print(mpu.getMagY_uT());
  Serial.print("\t");
  Serial.print(mpu.getMagZ_uT());
  Serial.println();

  Serial.println();

  delay(1000);
}

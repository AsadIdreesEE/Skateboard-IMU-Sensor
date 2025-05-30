#include <MPU9250_WE.h>
#include <Wire.h>
#define MPU9250_ADDR 0x68

MPU9250_WE myMPU9250 = MPU9250_WE(MPU9250_ADDR);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  if(!myMPU9250.init()){
    Serial.println("MPU9250 does not respond");
  }
  else{
    Serial.println("MPU9250 is connected");
  }

  Serial.println("Position you MPU9250 flat and don't move it - calibrating...");
  delay(1000);
  myMPU9250.autoOffsets();
  Serial.println("Done!");
  
  myMPU9250.enableGyrDLPF();
  myMPU9250.setGyrDLPF(MPU9250_DLPF_6);
  myMPU9250.setSampleRateDivider(99);
  myMPU9250.setGyrRange(MPU9250_GYRO_RANGE_250); 
}

void loop() {
  xyzFloat gyrRaw = myMPU9250.getGyrRawValues();
  xyzFloat corrGyrRaw = myMPU9250.getCorrectedGyrRawValues();
  xyzFloat gyr = myMPU9250.getGyrValues();
  
  // Serial.println("Gyroscope raw values (x,y,z):");
  //Serial.print(gyrRaw.x);
  //Serial.print("   ");
  //Serial.print(gyrRaw.y);
  //Serial.print("   ");
  //Serial.println(gyrRaw.z);

  //Serial.println("Corrected gyroscope raw values (x,y,z):");
  //Serial.print(corrGyrRaw.x);
  //Serial.print("   ");
  //Serial.print(corrGyrRaw.y);
  //Serial.print("   ");
  //Serial.println(corrGyrRaw.z);

  //Serial.println("Gyroscope Data in degrees/s (x,y,z):");
  Serial.println(gyr.x);
  Serial.print ('\n');
  //Serial.print("   ");
  //Serial.println(gyr.y);
  //Serial.print ('\n');
  //Serial.println(gyr.z);

  //Serial.println("*********************************");

  delay(10);
}

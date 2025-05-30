
#include <MPU9250_WE.h>
const int csPin = 4;  // Chip Select Pin
bool useSPI = true;    // SPI use flag

MPU9250_WE myMPU9250 = MPU9250_WE(&SPI, csPin, useSPI);

void setup() {
  Serial.begin(115200);
  if(!myMPU9250.init()){
    Serial.println("MPU9250 does not respond");
  }
  else{
    Serial.println("MPU9250 is connected");
  }
  
  myMPU9250.enableGyrDLPF();
  myMPU9250.setGyrDLPF(MPU9250_DLPF_6);
  myMPU9250.setSampleRateDivider(5);
  myMPU9250.setGyrRange(MPU9250_GYRO_RANGE_250);
  myMPU9250.setAccRange(MPU9250_ACC_RANGE_2G);
  myMPU9250.enableAccDLPF(true);
  myMPU9250.setAccDLPF(MPU9250_DLPF_6);
  myMPU9250.setMagOpMode(AK8963_CONT_MODE_100HZ);
  delay(200);
}

void loop() {
  
  xyzFloat gyr = myMPU9250.getGyrValues();

  delay(500);
}

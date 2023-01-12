
#include <MPU6050_tockn.h>// This line includes the header file for the MPU6050 library, which provides functions for interacting with the MPU-6050 motion tracking device
#include <Wire.h> // This line includes the Wire library, which provides functions for communication over I2C (Inter-Integrated Circuit)

int angle = 0;// This line declares an integer variable called "angle" and initializes it to 0
MPU6050 mpu6050(Wire);// This line creates an instance of the MPU6050 class, using the Wire object as a parameter. This allows the code to communicate with the MPU-6050 over I2C.

void setup() {
Serial.begin(9600);// This line initializes the serial port at a baud rate of 9600, which is the speed at which data is transmitted over the serial connection
Wire.begin();// This line starts the I2C communication using the Wire object
mpu6050.begin();// This line initializes the MPU-6050 using the begin function from the MPU6050 library
mpu6050.calcGyroOffsets(true);// This line uses the calcGyroOffsets function to calibrate the gyroscope in the MPU-6050. 
//The "true" parameter indicates that the device should enter a sleep mode during the calibration process to improve accuracy.
}

void loop() {
mpu6050.update();// This line updates the data from the MPU-6050 using the update function from the MPU6050 library
Serial.print("\tangleX : ");
Serial.println(mpu6050.getAngleX());// These lines print the angle in the X axis to the serial port using the getAngleX function from the MPU6050 library
Serial.print("\tangleY : ");
Serial.println(mpu6050.getAngleY());// These lines print the angle in the Y axis to the serial port using the getAngleY function from the MPU6050 library
Serial.print("\tangleZ : ");
Serial.println(mpu6050.getAngleZ());// These lines print the angle in the Z axis to the serial port using the getAngleZ function from the MPU6050 library
}


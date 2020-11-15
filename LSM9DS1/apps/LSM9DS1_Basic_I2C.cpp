#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <string>
#include "LSM9DS1_Types.h"
#include "LSM9DS1.h"

int main(int argc, char *argv[]) {
    LSM9DS1 imu(IMU_MODE_I2C, 0x6b, 0x1e);
    imu.begin();
    if (!imu.begin()) {
        fprintf(stderr, "Failed to communicate with LSM9DS1.\n");
        exit(EXIT_FAILURE);
    }
    imu.calibrate();
    char buffer[100];
    std::string command = "mosquitto_pub -h mojito.homedruon.com -t guilain -m \"";
    std::string str;
    for (;;) {
        while (!imu.gyroAvailable()) ;
        imu.readGyro();
        while(!imu.accelAvailable()) ;
        imu.readAccel();
        while(!imu.magAvailable()) ;
        imu.readMag();
	
	str = command + "-------------------------\"";
	system(str.c_str());
        sprintf(buffer, "Gyro: %f, %f, %f [deg/s] %c", 
            imu.calcGyro(imu.gx), imu.calcGyro(imu.gy), imu.calcGyro(imu.gz), '"');
	str = command + buffer;
	system(str.c_str());
        sprintf(buffer, "Accel: %f, %f, %f [Gs] %c", 
            imu.calcAccel(imu.ax), imu.calcAccel(imu.ay), imu.calcAccel(imu.az), '"');
	str = command + buffer;
	system(str.c_str());
	sprintf(buffer, "Mag: %f, %f, %f [gauss] %c", 
            imu.calcMag(imu.mx), imu.calcMag(imu.my), imu.calcMag(imu.mz), '"');
	str = command + buffer;
	system(str.c_str());
	sleep(1.0);
    }

    exit(EXIT_SUCCESS);
}

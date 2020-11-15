CC = g++
.PHONY: all
all: LSM9DS1_Basic_I2C

LSM9DS1_Basic_I2C: LSM9DS1_Basic_I2C.cpp
	$(CC) -Wall -O2 LSM9DS1_Basic_I2C.cpp -o lsm9ds1 -llsm9ds1

clean:
	rm -f lsm9ds1

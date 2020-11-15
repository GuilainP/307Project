LSM9DS1_BINARY_DIR=LSM9DS1/apps
BMP180_BINARY_DIR=BMP180
SERVO_BINARY_DIR=SERVO
BINARY_DIR=bin

ROOT_DIR = $(CURDIR)

sensor1=lsm9ds1
sensor2=bmp180
actuator=servo

all: $(sensor1) $(sensor2) $(actuator)

$(sensor1) :
	cd $(LSM9DS1_BINARY_DIR) && $(MAKE)
	cd $(ROOT_DIR)
	mv $(LSM9DS1_BINARY_DIR)/$(sensor1) $(BINARY_DIR)

$(sensor2):
	cd $(BMP180_BINARY_DIR) && $(MAKE)
	cd $(ROOTDIR)
	mv $(BMP180_BINARY_DIR)/$(sensor2) $(BINARY_DIR)

$(actuator):
	cd $(SERVO_BINARY_DIR) && $(MAKE)
	cd $(ROOT_DIR)
	mv $(SERVO_BINARY_DIR)/$(actuator) $(BINARY_DIR)

clean:
	rm -rf bin/*

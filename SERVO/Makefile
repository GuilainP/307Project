CC = g++
CFLAGS = -g -Wall

TARGET = servo
CLIBRARY = -lwiringPi

all: servo

servo: $(TARGET).cpp
	$(CC) $(FLAGS) -o $(TARGET) $(TARGET).cpp $(CLIBRARY)

clean:
	rm -f $(TARGET)
    

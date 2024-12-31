CC = gcc
CFLAGS = -Wall
TARGET = student_management

all: $(TARGET)

$(TARGET): main.c student.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c student.c

clean:
	rm -f $(TARGET)

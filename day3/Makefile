.PHONY: all folders clean

# change if you have different compilers
CC=g++
CFLAGS=-g -Wall -Wextra
LDFLAGS=
TARGET=day3

# normal build config.
all: folders $(TARGET)
	mv build/$(TARGET) .

$(TARGET): $(TARGET).o
	$(CC) $(LDFLAGS) -o build/$@ build/$<

$(TARGET).o: $(TARGET).cpp
	$(CC) $(CFLAGS) -c -o build/$@ $<

folders:
	mkdir -p build/

clean:
	rm -rf build/* build $(TARGET);

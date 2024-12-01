.PHONY: all folders clean

# change if you have different compilers
CC=g++
CFLAGS=-g -Wall -Wextra
LDFLAGS=

# normal build config.
all: folders day1
	mv build/day1 .

day1: day1.o
	$(CC) $(LDFLAGS) -o build/$@ build/$<

day1.o: day1.cpp
	$(CC) $(CFLAGS) -c -o build/$@ $<

folders:
	mkdir -p build/

clean:
	rm -rf build/* build day1;

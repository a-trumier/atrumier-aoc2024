.PHONY: all folders clean

# change if you have different compilers
CC=g++
CFLAGS=-g -Wall -Wextra
LDFLAGS=

# normal build config.
all: folders day2
	mv build/day2 .

day2: day2.o
	$(CC) $(LDFLAGS) -o build/$@ build/$<

day2.o: day2.cpp
	$(CC) $(CFLAGS) -c -o build/$@ $<

folders:
	mkdir -p build/

clean:
	rm -rf build/* build day2;

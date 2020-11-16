CPPFLAGS = -I include -g -Wall -Wextra -pedantic -std=c++17 -O3 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

.PHONY: all
all: build/main.o
	g++ -o null_ build/main.o

build/main.o: build source/main.cpp
	g++ $(CPPFLAGS) -c -o build/main.o source/main.cpp

build:
	mkdir build

clean:
	rm -rf build/ null_
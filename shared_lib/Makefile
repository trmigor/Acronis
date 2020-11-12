CPPFLAGS = -I include -g -Wall -Wextra -pedantic -std=c++17 -O3 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

.PHONY: all
all: lib/libintegrate.so build/main.o
	g++ build/main.o -o integrate -lintegrate -L lib

build/main.o: build source/main.cpp
	g++ $(CPPFLAGS) -c -o build/main.o source/main.cpp

lib/libintegrate.so: create_lib

.PHONY: create_lib
create_lib: lib build/libintegrate.o
	gcc -g -shared -o lib/libintegrate.so build/libintegrate.o

build/libintegrate.o: build source/integrate.cpp
	g++ $(CPPFLAGS) -fPIC -c -o build/libintegrate.o source/integrate.cpp

build:
	mkdir build

lib:
	mkdir lib

clean:
	rm -rf build/ lib/ integrate

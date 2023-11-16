all: build/pong

build/pong: src/pong.cpp | build
	g++ src/pong.cpp -o $@ -s -Wall -std=c++17 -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl
	echo "Successfully compiled";

build:
	mkdir -p build;

clean:
	rm -r build

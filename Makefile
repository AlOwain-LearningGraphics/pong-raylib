all: build/pong

build/pong: src/pong.cpp src/gameController.cpp src/gameController.h src/ball.cpp src/ball.h src/player.cpp src/player.h | build
	g++ src/*.cpp -o $@ -s -Wall -std=c++17 -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl
	echo "Successfully compiled";

build:
	mkdir -p build;

clean:
	rm -r build

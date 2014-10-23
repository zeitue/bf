all: release

debug: 	 main.cpp Interpreter.cpp Utilities.cpp
	g++ -g -Wall main.cpp Interpreter.cpp Utilities.cpp -o bf

release: main.cpp Interpreter.cpp Utilities.cpp
	g++ -O3 main.cpp Interpreter.cpp Utilities.cpp -o bf

clean:
	rm bf

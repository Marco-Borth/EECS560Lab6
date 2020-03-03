Program: main.o Executive.o Pokedex.o Pokemon.o TestPokedex.o
	g++ -std=c++11 -g -Wall main.o Executive.o Pokedex.o Pokemon.o TestPokedex.o -o Program

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Pokedex.o: Pokedex.h Pokedex.cpp
	g++ -std=c++11 -g -Wall -c Pokedex.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

TestPokedex.o: TestPokedex.h TestPokedex.cpp
	g++ -std=c++11 -g -Wall -c TestPokedex.cpp

clean:
	rm *.o Program

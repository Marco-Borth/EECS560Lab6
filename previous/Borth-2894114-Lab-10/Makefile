Program: main.o Executive.o Hospital.o Patient.o
	g++ -std=c++11 -g -Wall main.o Executive.o Hospital.o Patient.o -o Program

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Hospital.o: Hospital.h Hospital.cpp
	g++ -std=c++11 -g -Wall -c Hospital.cpp

Patient.o: Patient.h Patient.cpp
	g++ -std=c++11 -g -Wall -c Patient.cpp

clean:
	rm *.o Program

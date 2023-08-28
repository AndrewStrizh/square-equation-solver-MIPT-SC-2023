all: start

start: read.o solve.o tests.o main.o
	g++ main.o read.o solve.o tests.o -o result.exe

read.o: read.cpp
	g++ -c read.cpp

solve.o: solve.cpp
	g++ -c solve.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

main.o: main.cpp
	g++ -c main.cpp
all: animal main
	g++ Animal.o main.o -o Animal

animal: Animal.cpp
	g++ -c Animal.cpp

main: main.cpp
	g++ -c main.cpp

clean:
	rm -f Animal main.o Animal.o

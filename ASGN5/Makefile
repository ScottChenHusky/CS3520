all: linkedlist main
	g++ LinkedList.o main.o -o LinkedList

linkedlist: LinkedList.cpp
	g++ -c LinkedList.cpp

main: main.cpp
	g++ -c main.cpp

clean:
	rm -f LinkedList main.o LinkedList.o

all: compile run

compile:
	g++ -I ./include/ -o ./lib/Hucre.o -c ./src/Hucre.cpp
	g++ -I ./include/ -o ./lib/Doku.o -c ./src/Doku.cpp
	g++ -I ./include/ -o ./lib/ReadAndAdd.o -c ./src/ReadAndAdd.cpp	
	g++ -I ./include/ -o ./lib/Queue.o -c ./src/Queue.cpp
	g++ -I ./include/ -o ./lib/RadixSort.o -c ./src/RadixSort.cpp
	g++ -I ./include/ -o ./lib/BinarySearchTree.o -c ./src/BinarySearchTree.cpp
	g++ -I ./include/ -o ./lib/Organ.o -c ./src/Organ.cpp
	g++ -I ./include/ -o ./lib/Sistem.o -c ./src/Sistem.cpp
	g++ -I ./include/ -o ./lib/Organizma.o -c ./src/Organizma.cpp
	g++ -I ./include/ -o ./lib/Control.o -c ./src/Control.cpp

	g++ -I ./include/ -o ./bin/main ./lib/Hucre.o ./lib/Doku.o ./lib/ReadAndAdd.o  ./lib/Queue.o ./lib/RadixSort.o ./lib/BinarySearchTree.o ./lib/Organ.o ./lib/Sistem.o ./lib/Organizma.o ./lib/Control.o ./src/main.cpp
run:
	./bin/main
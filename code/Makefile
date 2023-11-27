O_FILES = ./build/main.o ./build/interface/Interface.o

main: main.cpp Interface
	c++ -o ./build/main.o -c main.cpp
	c++ $(O_FILES)
	./a.out

Interface: ./src/interface/Interface.cpp
	c++ -o ./build/interface/Interface.o -c ./src/interface/Interface.cpp

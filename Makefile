# Компилятор
CC=g++

# Стандарт
STD=c++11

all: exec clean

exec: main.o SingletonDetectorFactory.o
	$(CC) SingletonDetectorFactory.o main.o -o exec
main.o: main.cpp
	$(CC) -std=$(STD) -c main.cpp
SingletonDetectorFactory.o: SingletonDetectorFactory.cpp SingletonDetectorFactory.hpp
	$(CC) -std=$(STD) -c SingletonDetectorFactory.cpp
clean:
	rm -rf *.o

CC    = g++
FLAGS = -std=c++11

all: Test.cpp Queue.o Snake.o
	@$(CC) $(FLAGS) Test.cpp Queue.o Snake.o -o Test.o
	./Test.o

%.o: %.cpp 
	@$(CC) $(FLAGS) -c $^ -o $@ 

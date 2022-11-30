TARGET = wordWrap
CC = g++
CFLAGS = -Wall -ggdb

all: $(TARGET)

test: $(TARGET)
	./wordWrap input.txt output.txt 

gdb: $(TARGET)
	gdb wordWrap
	r  input.txt output.txt 2

$(TARGET): main.o Problem.o Solution.o Dp.o Greedy.o
	$(CC) $(CFLAGS) -o $@ Problem.o Solution.o Dp.o Greedy.o main.o

Greedy.o: greedy.cpp
	$(CC) $(CFLAGS) -c *.cpp

Dp.o: dp.cpp
	$(CC) $(CFLAGS) -c *.cpp

Solution.o: solution.cpp solution.h
	$(CC) $(CFLAGS) -c *.cpp

Problem.o: problem.cpp problem.h
	$(CC) $(CFLAGS) -c *.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c *.cpp

clean:
	rm -rf *.o output.txt $(TARGET)
all: test1

test: test1.o
	g++ -o test1 test1.o

test.o: test1.cpp Part1.h
	g++ -c test1.cpp

clean:
	rm -f test1 *.o

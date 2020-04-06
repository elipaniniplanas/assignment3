all: test1

test: test1.o
	g++ test1.o -o test1
	./test1

test.o: test1.cpp Part1.h
	g++ -Wall -Wextra -Werror -c test1.cpp

clean:
	rm -f test1 *.o


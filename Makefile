all: test1

test1: test1.o
	g++ test1.o -o test1
	./test1

test1.o: test1.cpp Qsort.h
	g++ -Wall -Wextra -Werror -c test1.cpp

clean:
	rm -f test1 *.o

all: test1 test2

test1: test1.o
	g++ -o test1 test1.o
	@echo "Test1"
	./test1

test1.o: test1.cpp Qsort.h
	g++ -c test1.cpp

test2: test2.o
	g++ -o test2 test2.o
	@echo "Test2"
	./test2

test2.o: test2.cpp Isort.h
	g++ -c test2.cpp

clean:
	rm -f test1 test2 *.o

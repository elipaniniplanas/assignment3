all: test1

test: test1.o
	g++ test1.o -o test1
	./test1

test.o: test1.cpp Part1.h
	g++ -Wall -Wextra -Werror -c test1.cpp

clean:
	rm -f test1 *.o


#compile and link the application
all: testLeaves testDeep testBalance

testLeaves: TestLeaves.o
	g++ TestLeaves.o -o testLeaves
	./testLeaves

TestLeaves.o: TestLeaves.cpp
	g++ -c TestLeaves.cpp

testDeep: TestDeep.o
	g++ TestDeep.o -o testDeep
	./testDeep

TestDeep.o: TestDeep.cpp
	g++ -c TestDeep.cpp

testBalance: TestBalance.o
	g++ TestBalance.o -o testBalance
	./testBalance

TestBalance.o: TestBalance.cpp
	g++ -c TestBalance.cpp

clean:
	@echo "Cleaning up..."
	rm -f testLeaves testDeep testBalance *.o

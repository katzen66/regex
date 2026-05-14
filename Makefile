compare.o: compare.cpp compare.h
	gcc -fPIC -c compare.cpp -o compare.o
test.o: compare.o test.cpp
	gcc -fPIC -c test.cpp -o test.o
test: test.o
	g++ test.o compare.o -o test
clean:
	rm test test.o compare.o

.PHONY: clean

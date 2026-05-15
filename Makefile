compare.o: compare.cpp compare.h
	gcc -fPIC -c compare.cpp -o compare.o

interpret.o: interpret.cpp
	gcc -fPIC -c interpret.cpp -o interpret.o
interpret: compare.o interpret.o
	g++ interpret.o compare.o -o interpret

clean:
	rm test test.o interpret interpret.o compare.o > /dev/null 2>&1

.PHONY: clean

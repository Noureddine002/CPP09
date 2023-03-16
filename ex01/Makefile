all: RPN

RPN: main.o RPN.o
	g++ -o RPN main.o RPN.o

main.o: main.cpp RPN.hpp
	g++ -c main.cpp

RPN.o: RPN.cpp RPN.hpp
	g++ -c RPN.cpp

clean:
	rm -f RPN *.o
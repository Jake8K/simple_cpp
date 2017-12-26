#all: linearSearch bubbleSort binarySearch

CXX = main.cpp
CXX += RPNcalc.cpp
CXX += RPNcalc.hpp
CXX += Stack.cpp
CXX += Stack.hpp
CXX += Queue.cpp
CXX += Queue.hpp


labFb: main.cpp RPNcalc.cpp RPNcalc.hpp Stack.cpp Stack.hpp Queue.cpp Queue.hpp
	g++ -std=c++0x main.cpp RPNcalc.cpp Stack.cpp Queue.cpp -o rpn

clean:
	rm rpn



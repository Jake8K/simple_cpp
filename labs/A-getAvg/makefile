
all: static dynamic


CXX = LabAa.cpp 
CXX += LabAec.cpp 
CXX += average.cpp 
CXX += summation.cpp 
CXX += average.hpp 
CXX += summation.hpp

static: LabAa.cpp average.cpp average.hpp summation.cpp summation.hpp
	g++ -std=c++0x LabAa.cpp average.cpp summation.cpp -o avg_s

dynamic: LabAec.cpp average.cpp average.hpp summation.cpp summation.hpp
	g++ -std=c++0x LabAec.cpp average.cpp summation.cpp -o avg_d


clean:
	rm avg_s avg_d
#all: 

CXX = main.cpp
CXX += recursiveMergeSort.cpp
CXX += recursiveMergeSort.hpp
CXX += iterativeMergeSort.cpp
CXX += iterativeMergeSort.hpp
CXX += OpenFiles.cpp
CXX += OpenFiles.hpp

labH: main.cpp recursiveMergeSort.cpp recursiveMergeSort.hpp iterativeMergeSort.cpp iterativeMergeSort.hpp OpenFiles.cpp OpenFiles.hpp
	g++ -std=c++0x  -std=c++11 main.cpp recursiveMergeSort.cpp iterativeMergeSort.cpp OpenFiles.cpp -o ms


clean:
	rm ms

cleanall:
	rm ms *.in mergeSort.txt



#all: linearSearch bubbleSort binarySearch

CXX = main.cpp
CXX += LinearSearchMain.cpp
CXX += mainQueue.cpp
CXX += labg.cpp
CXX += BinarySearch.cpp
CXX += BinarySearch.hpp
CXX += BubbleSort.cpp
CXX += BubbleSort.hpp
CXX += LinearSearch.cpp
CXX += LinearSearch.hpp
CXX += QueueClass.cpp
CXX += QueueClass.hpp
CXX += OpenFiles.cpp
CXX += OpenFiles.hpp

labG: main.cpp BinarySearch.cpp BinarySearch.hpp BubbleSort.cpp BubbleSort.hpp LinearSearch.cpp LinearSearch.hpp QueueClass.cpp QueueClass.hpp OpenFiles.cpp OpenFiles.hpp
	g++ -std=c++0x main.cpp BinarySearch.cpp BubbleSort.cpp LinearSearch.cpp QueueClass.cpp OpenFiles.cpp -o search


#linearSearch: LinearSearchMain.cpp BinarySearch.cpp BinarySearch.hpp BubbleSort.cpp BubbleSort.hpp LinearSearch.cpp LinearSearch.hpp QueueClass.cpp QueueClass.hpp OpenFiles.cpp OpenFiles.hpp
#	g++ -std=c++0x LinearSearchMain.cpp BinarySearch.cpp BubbleSort.cpp LinearSearch.cpp QueueClass.cpp OpenFiles.cpp -o linearSearch

#bubbleSort: labG.cpp BinarySearch.cpp BinarySearch.hpp BubbleSort.cpp BubbleSort.hpp LinearSearch.cpp LinearSearch.hpp QueueClass.cpp QueueClass.hpp OpenFiles.cpp OpenFiles.hpp
#	g++ -std=c++0x labG.cpp BinarySearch.cpp BubbleSort.cpp LinearSearch.cpp QueueClass.cpp OpenFiles.cpp -o bubbleSort

#binarySearch: main.cpp BinarySearch.cpp BinarySearch.hpp BubbleSort.cpp BubbleSort.hpp LinearSearch.cpp LinearSearch.hpp QueueClass.cpp QueueClass.hpp 
#	g++ -std=c++0x main.cpp BinarySearch.cpp BubbleSort.cpp LinearSearch.cpp QueueClass.cpp -o binarySearch

clean:
	rm search
#	rm linearSearch bubbleSort binarySearch



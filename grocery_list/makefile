#all: groceryList clean

CXX = GroceryList.cpp 
CXX += Item.cpp 
CXX += List.cpp 
CXX += Item.hpp 
CXX += List.hpp



groceryList: GroceryList.cpp Item.cpp Item.hpp List.cpp List.hpp
	g++ -std=c++0x GroceryList.cpp Item.cpp List.cpp -o list

clean:
	rm list

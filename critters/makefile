
CXX = predatorPreyFuncs.cpp 
CXX += Critter.cpp 
CXX += DoodleBug.cpp 
CXX += Ant.cpp
CXX += Critter.hpp 
CXX += DoodleBug.hpp 
CXX += Ant.hpp


critters: predatorPreyFuncs.cpp Critter.cpp DoodleBug.cpp Ant.cpp Critter.hpp DoodleBug.hpp Ant.hpp
	g++ -std=c++0x predatorPreyFuncs.cpp Critter.cpp DoodleBug.cpp Ant.cpp -o critters

clean:
	rm critters 



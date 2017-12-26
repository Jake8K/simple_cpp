
CXX = diceMain.cpp 
CXX += Dice.hpp 
CXX += Dice.cpp 
CXX += LoadedDice.hpp 
CXX += LoadedDice.cpp



dice: diceMain.cpp Dice.cpp Dice.hpp LoadedDice.cpp LoadedDice.hpp
	g++ -std=c++0x diceMain.cpp Dice.cpp LoadedDice.cpp -o dice

clean:
	rm dice

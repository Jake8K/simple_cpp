CXX = battleMain.cpp
CXX += Dice.cpp
CXX += Dice.hpp
CXX += Creature.cpp
CXX += Creature.hpp
CXX += Medusa.cpp
CXX += Medusa.hpp
CXX += Gollum.cpp
CXX += Gollum.hpp
CXX += ReptilePeople.cpp
CXX += ReptilePeople.hpp
CXX += BlueMen.cpp
CXX += BlueMen.hpp
CXX += HarryPotter.cpp
CXX += HarryPotter.hpp

battle: battleMain.cpp Dice.cpp Dice.hpp Creature.cpp Creature.hpp Medusa.cpp Medusa.hpp Gollum.cpp Gollum.hpp ReptilePeople.cpp ReptilePeople.hpp BlueMen.cpp BlueMen.cpp BlueMen.hpp HarryPotter.cpp
	g++ -c -o battleMain.o battleMain.cpp
	g++ -c -o Dice.o Dice.cpp
	g++ -c -o Creature.o Creature.cpp
	g++ -c -o Medusa.o Medusa.cpp
	g++ -c -o ReptilePeople.o ReptilePeople.cpp
	g++ -c -o BlueMen.o BlueMen.cpp
	g++ -c -o HarryPotter.o HarryPotter.cpp
	g++ -c -o Gollum.o Gollum.cpp
	g++ -std=c++0x battleMain.o Dice.o Creature.o Medusa.o Gollum.o ReptilePeople.o BlueMen.o HarryPotter.o -o battle
	rm *.o

#valgrind:
#    g++ -g -Wall -pedantic-errors main.cpp Transformer.cpp Copy.cpp Encryption.cpp #ToUpper.cpp OrderedOutput.cpp -o main ; \
#    valgrind --leak-check=yes ./main


clean:
	rm battle



#rm -f main *.o Copy.txt Encryption.txt ToUpper.txt OrderedOutput.txt *~



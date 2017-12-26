# Simple Programs in C++: Critters
###  A simple cellular automata program that simulates a simple predator-prey model via a 2D array populated by Ants, Doodlebugs and empty spaces. The Critters (Ants and Doodlebugs) move around, periodically creating offspring. If a Doodlebug moves into a square containing an Ant it will eat the Ant. If a Doodlebug does not eat for 3 steps it dies. Ants eat whatever is in the space and will die after 10 time steps.

To run the simulation simply compile with ```make``` and the executable with ```critters```. Enter the number of Ants and Doodlebugs to populate the 20x20 board with, then the space will be randomly populated with creatures. Enter "y" to move forward one timestep and enter any other key to exit. Enter ```make clean``` to remove the executable.


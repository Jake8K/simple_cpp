# Simple Programs in C++: Dice Battle Game
- ### A fantasy combat game where each turn dice are automatically rolled by the program for both players and the offensive/defensive impacts of their rolls are automatically incurred by their player.

The creatures and their roll values are:  
| Type                                           |  Attack           | Defense | Armor   | Strength Points |  
| :----------------------------------- |:---------------: | :-------: | :-------: | :-----------------: |  
| Medusa<sup>1</sup>              |2d6 *Glare        | 1d6      | 3          | 8                         |  
| Gollum<sup>2</sup>               | 1d6 *Ring        | 1d6      | 3          | 8                         |  
| Reptile People<sup>3</sup>   | 3d6                  | 1d6      | 7          | 18                       |  
|  Blue Men<sup>4</sup>          | 2d10                | 3d6\*   | 3          | 12\*Mob              |  
|  Harry Potter<sup>5</sup>      | 2d6                  | 2d6     | 0          | 10/20\*Hogwarts |  
*3d6 == rolling 3 6-sided dice, 2d10 == rolling 2 10-sided dice*   

<sup>1</sup>  Glare: If a Medusa rolls a 12 in attack then the target has looked her in the eyes and is turned to stone. The Medusa wins!

<sup>2</sup> Ring: Gollum has the one ring, it can make him invisible. That is essentially his defense! It also allows him to occasionally get behind his opponent and jump on their back. There is a 5% chance he makes an attack with 3d6.

<sup>3</sup> These guys are big and powerfule with tough scaly skin... they're also pretty slow.

<sup>4</sup> Mob: The Blue Men are actually a swarm of small (6” tall), fast, and tough individuals. For every 4 points of damage (round down) they lose one defense die. For example, when they reach strength of 8 they only have 2d6 for defense. So they are hard to hit and can take some damage. As for the attack value, you can do a LOT of damage when can crawl inside the armor or clothing of your opponent. They are also known as the Nac Mac Feegle of Discworld

<sup>5</sup> Hogwarts: If Harry dies (i.e. strength >=0) he immediately recovers. His strength becomes 10 again, for a max of 20 for the fight. If he were to die again then he’s dead.

An attack generates 2 dice rolls. The attacker rolls the appropriate number and type of dice under Attack. That amount of damage is passed to the defender in the defender object’s defense function. The defender rolls the appropriate number and type of dice under Defense.

The damage incurred is the Attack roll minus the Defense roll, this damage is then applied by subtracting it from the Armor value. The result of this is then subtracted from the Strength Points. That value becomes the new Strength Points for the next round. If Strength Points goes to 0 or less then the character is out of the combat (dead).

### To Do:
- [ ] make the game less automated (ie maybe choices of attacks/defense?)
- [ ] add more fun creatures

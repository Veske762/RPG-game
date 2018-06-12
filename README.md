# RPG-game


Problems:<br />
vector problem:<br />
If aoe ability kills 2 or more vector erase problem<br />
in function int Player::Combat(Player& player,Map &map)<br />
for (int i = 0; i < monster.size(); i++)<br />
			{ <br />
				if (monster[i].isDead()) //isDead() checks if monster hp is <=0<br />
				{<br />
    //some non problem code<br />
    
					monster.erase(monster.begin() +i);//here is the problem<br />
     
     if enemies die 1 per turn it works fine but if Aoe attack kills 2 or more enemies this happens:<br />
     example:<br />
     player vs 3 enemies<br />
     if aoe kills all of them at once<br />
     monster vector index(0,1,2)<br />
     first iteration i = 0 deletes monster at index 0<br />
     now vector looks like this(0,1) 1,2 shift to 0,1<br />
     second iteration i = 1 3rd monster gets deleted and 2nd one gets skipped<br />
     and it leaves me with 2nd monster with -hp against the player<br />
     
				}<br />
Load problem:<br />
function void Player::Load(Player &player,Map map)<br />
Im saving stuff to the text file line by line (not fully yet) it works<br />
Loading works if strings dont have spaces example Double Edged Axe messes up loading<br />
but DoubleEdgedAxe works <br />







Im C++ noob.<br />
Tips and advice are welcome.<br />
Console game inspired by exercise from Game Institute module 1 book chapter Chapter 5 Classes and Object Oriented Programming<br />
Work in progress.<br />
Feature list:<br />
-inventory system<br />
-combat with up to 3 random enemies at once;<br />
-leveling <br />
-shops<br />
-classes/races(currently no big difference)<br />
-buying/selling items<br />
-area specific enemies<br />
-quests<br />
-equip/unequip items<br />
-dungeons<br />
-loot chests<br />
-enterable areas<br />
-monsters drop gold/items<br />
-monsters level affect stats<br />
-boss fights<br />
-2d<br />
-abilities added (replacing spells)<br />


 TBD:<br />
-more abilities<br />
-fix input(bugs out if you enter a character when it expects int)<br />
-skill point distribution(currently its random fighter gets more hp ,wizard gets more mana)<br />
-arena (location to be changed)<br />
-betting (done)<br />
-more quests/bosses/items/places/monsters/<br />
-health/mana potions<br />
-resting system rework<br />
-balance<br />
-common/rare/legendary loot stats<br />
-save/load system(saving works not fully implemented,loading problem with spaces when reading from text file,works without space)<br /> 
-code cleanup(some leftover stuff)<br />
-item limits so wizard cant equip heavy armor and weapon same for fighter and spells<br />



#include "functions.h"


int main() 
{
	srand(time(NULL));

	struct Warrior w1;
	w1.name = "Chuck Norris";
	w1.life_units = 100;

	w1.set_of_weapons[0].name = "Chopsticks";
	w1.set_of_weapons[0].damage = randVal(1, 25);

	w1.set_of_weapons[1].name = "Baseball bat";
	w1.set_of_weapons[1].damage = randVal(1, 25);

	w1.set_of_weapons[2].name = "Himself";
	w1.set_of_weapons[2].damage = 100;

	
	struct Warrior w2;
	w2.name = "Bruce Lee";
	w2.life_units = 100;

	w2.set_of_weapons[0].name = "Sword";
	w2.set_of_weapons[0].damage = randVal(1, 25);

	w2.set_of_weapons[1].name = "Gun";
	w2.set_of_weapons[1].damage = randVal(1, 25);

	w2.set_of_weapons[2].name = "Axe";
	w2.set_of_weapons[2].damage = randVal(1, 25);

	//  Game's loop

	int round = 1;

	while (w1.life_units > 0 && w2.life_units > 0) {
		system("CLS");
		printf("-- Round %d --\n\n", round);
		struct Warrior wAttacks = getRandomWarrior(w1, w2);
		if (wAttacks.name == w1.name) {
			
			printf("%s attacks!!!\n", w1.name);
			w2.life_units = lifeWarrior2AfterAttack(w1, w2);
		}
		else {
			printf("%s attacks!!!\n", w2.name);
			w1.life_units = lifeWarrior2AfterAttack(w2, w1);
		}

		printWarrior(w1);
		printWarrior(w2);
		round++;
		Sleep(2000);
	}

	if (w1.life_units == 0) {
		printf("%s WINS!!!\n", w2.name);
	}
	else {
		printf("%s WINS!!!\n", w1.name);
	}





	return 0;
}
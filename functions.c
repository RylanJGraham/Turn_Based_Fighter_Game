#include "functions.h"


int randVal(int min, int max) {

	return (rand() % (max - min + 1)) + min;
}

struct Weapon getRandomWeapon(struct Warrior w) {
	int randomIDX = randVal(0, 2);
	return w.set_of_weapons[randomIDX];
}

void printWeapon(struct Weapon wp) {
	printf("Weapon: %s %d\n", wp.name,
		wp.damage);
	printf("\n");
}

void printWarrior(struct Warrior w) {

	printf("-- Warrior %s --\n", w.name);
	printf("Life units: %d\n", w.life_units);

	for (int i = 0; i < 3; ++i) {
		printf("Weapon %d: %s %d\n", i, w.set_of_weapons[i].name,
			w.set_of_weapons[i].damage);
	}

	printf("\n");
}


int lifeWarrior2AfterAttack(struct Warrior w1, struct Warrior w2) {
	struct Weapon wp = getRandomWeapon(w1);

	int blocking = randVal(1, 5);

	if (blocking == 1) {

		Sleep(1000);

		printf("\n");

		printWeapon(wp);

		Sleep(1000);

		printf("%s BLOCKED THE ATTACK!!!\n\n", w2.name);

		Sleep(1000);

		return w2.life_units;
	}
	else {
		if (wp.damage > w2.life_units) {
			w2.life_units = 0;
		}
		else {
			w2.life_units -= wp.damage;
		}

		Sleep(1000);

		printf("\n");

		printWeapon(wp);

		Sleep(1000);

		return w2.life_units;
	}



}

struct Warrior getRandomWarrior(struct Warrior w1, struct Warrior w2) {
	int randWarrior = randVal(1, 2);

	if (randWarrior == 1) {
		return w1;
	}
	else {
		return w2;
	}

}
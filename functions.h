#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef unsigned char byte;

struct Weapon {
	char* name;
	byte damage;
};

struct Warrior {
	char* name;
	byte life_units;
	struct Weapon set_of_weapons[3];
};


int randVal(int min, int max);
struct Weapon getRandomWeapon(struct Warrior w);
void printWeapon(struct Weapon wp);
void printWarrior(struct Warrior w);
int lifeWarrior2AfterAttack(struct Warrior w1, struct Warrior w2);
struct Warrior getRandomWarrior(struct Warrior w1, struct Warrior w2);


#endif // !_FUNCTIONS_H_


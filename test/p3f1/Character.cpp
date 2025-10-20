#include <iostream>
#include "Character.h"

void DisplayCharacter(const Character* character)
{
	std::cout << "Nom : " << character->name << "\0Niveau : " << character->level << "\0Points de vie : " << character->currentHP << " / " << character->maxHP << std::endl;
}

void HealCharacter(Character* character, int amount)
{
	(character->currentHP + amount > character->maxHP) ? character->currentHP = character->maxHP : character->currentHP += amount;
}

bool IsAlive(const Character* character)
{
	return character->currentHP > 0;
}

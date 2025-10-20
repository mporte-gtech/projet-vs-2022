#pragma once

struct Character
{
	const char* name;
	int level, maxHP, currentHP;
};

// Affiche les informations d’un personnage(nom, niveau, points de vie).
void DisplayCharacter(Character* character);


// Soigne un personnage en augmentant ses points de vie d’une certaine valeur.
// Les points de vie ne peuvent pas dépasser le maximum.
void HealCharacter(Character* character, int amount);

// Vérifie si un personnage est encore en vie(retourne un booléen).
bool IsAlive(Character* character);

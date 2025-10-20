#pragma once

struct Character
{
	const char* name;
	int level, maxHP, currentHP;
};

// Affiche les informations d�un personnage(nom, niveau, points de vie).
void DisplayCharacter(Character* character);


// Soigne un personnage en augmentant ses points de vie d�une certaine valeur.
// Les points de vie ne peuvent pas d�passer le maximum.
void HealCharacter(Character* character, int amount);

// V�rifie si un personnage est encore en vie(retourne un bool�en).
bool IsAlive(Character* character);

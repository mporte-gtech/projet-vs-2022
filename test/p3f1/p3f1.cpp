#include <iostream>
#include "Character.h"
#include "Inventory.h"

int main()
{
	// Exercice 1 — Personnage de jeu vidéo
	std::cout << "Exercice 1 , Personnage de jeu video" << std::endl;
	
	Character testCharacter;

	testCharacter.name = "test";
	testCharacter.level = 5;
	testCharacter.maxHP = 10;
	testCharacter.currentHP = 8;

	// Exercice 2 — Inventaire et Objets
	std::cout << "Exercice 2 , Inventaire et Objets" << std::endl;

	Inventory* testInventory = CreateInventory(10);
}

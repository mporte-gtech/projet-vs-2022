#pragma once
#include "Item.h"

struct Inventory
{
	int inventorySize;
	Item* items;
};

// Cr�er une struct Inventory
Inventory* CreateInventory(int inventorySize);

// Supprimer une struct Inventory
void DeleteInventory(Inventory* inventory);

// Ajoute un objet � l�inventaire. Renvoie true si l'objet a �t� ajout�, false sinon.
bool AddItem(Inventory* inventory, Item* item);

// Recherche un objet dans l�inventaire par son nom, retourne un bool�en indiquant s�il a �t� trouv�.
bool FindItemByName(Inventory* inventory, char* itemName);

// Affiche tous les objets de l�inventaire.
void DisplayInventory(Inventory* inventory);

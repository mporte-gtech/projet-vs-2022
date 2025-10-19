#pragma once
#include "Item.h"

struct Inventory
{
	int inventorySize;
	Item* items;
};

// Créer une struct Inventory
Inventory* CreateInventory(int inventorySize);

// Supprimer une struct Inventory
void DeleteInventory(Inventory* inventory);

// Ajoute un objet à l’inventaire. Renvoie true si l'objet a été ajouté, false sinon.
bool AddItem(Inventory* inventory, Item* item);

// Recherche un objet dans l’inventaire par son nom, retourne un booléen indiquant s’il a été trouvé.
bool FindItemByName(Inventory* inventory, char* itemName);

// Affiche tous les objets de l’inventaire.
void DisplayInventory(Inventory* inventory);

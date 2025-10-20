#include <iostream>
#include "Inventory.h"

Inventory* CreateInventory(int inventorySize)
{
	Item* items = (Item*)malloc(sizeof(Item) * inventorySize);

	Inventory* newInventory = (Inventory*)malloc(sizeof(Inventory));

	if (newInventory == nullptr || items == nullptr)
		exit(1);

	newInventory->inventorySize = inventorySize;
	newInventory->items = items;

	for (int i = 0; i < inventorySize; i++)
	{
		newInventory->items[i] = Item{NULL, 0, 0};
	}

	return newInventory;
}

void DeleteInventory(Inventory* inventory)
{
	free(inventory->items);
	free(inventory);
}

bool AddItem(Inventory* inventory, Item* item)
{
	int inventorySize = inventory->inventorySize;

	for (int i = 0; i < inventorySize; i++)
	{
		if (inventory->items[i].name == NULL)
		{
			inventory->items[i] = *item;
			return true;
		}
	}

	std::cout << "Inventaire plein";
	return false;
}

bool FindItemByName(Inventory* inventory, const char* itemName)
{
	int inventorySize = inventory->inventorySize;

	for (int i = 0; i < inventorySize; i++)
	{
		int isItemFound = strcmp(inventory->items[i].name, itemName);
		if (isItemFound == 0)
		{
			return true;
		}
	}
	return false;
}

void DisplayInventory(Inventory* inventory)
{
	int inventorySize = inventory->inventorySize;

	for (int i = 0; i < inventorySize; i++)
	{
		Item* currentItem = &inventory->items[i];
		DisplayItem(currentItem);
	}
}

#include "Item.h"
#include <iostream>


void DisplayItem(Item* item)
{
	std::cout << item->name << "\nValeur : " << item->goldValue << "\nNiveau requis : " << item->useRequiredLevel << std::endl;
}

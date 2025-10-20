#pragma once

struct Item
{
	char* name;
	int goldValue, useRequiredLevel;
};

void DisplayItem(Item* item);

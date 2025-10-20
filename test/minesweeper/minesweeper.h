#pragma once
#include "Grid.h"

void DisplayInterface(Grid* grid);

int* AskCoordinates();

char AskAction(Grid* grid, std::string coordX, std::string coordY);


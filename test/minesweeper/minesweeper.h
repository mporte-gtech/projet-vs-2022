#pragma once
#include "Grid.h"

void GameLoop(int step, Grid* grid = NULL)

int* AskCoordinates();

char AskAction(Grid* grid, std::string coordX, std::string coordY);


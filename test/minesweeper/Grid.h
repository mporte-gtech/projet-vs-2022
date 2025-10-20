#pragma once
#include "Cell.h"
#include <iostream>

struct Grid
{
	Cell** grid;
	int columnAmount, linesAmount, totalMinesAmount, availableFlags;
};

Grid* CreateGrid(int difficulty);

void SetMines(Grid* grid);

void DisplayGrid(Grid* grid);

int AskDifficulty();

int* AskGridSize();

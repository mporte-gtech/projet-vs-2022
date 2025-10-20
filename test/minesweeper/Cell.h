#pragma once

struct Cell
{
	bool containsMine, revealedCell, flagOnCell, adjacentMinesAmount;
};

void GetAdjacentMines(Cell* cell);

// 0 = case vide, 1 = mine
int revealMine();

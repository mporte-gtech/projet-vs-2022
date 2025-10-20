#include <iostream>
#include <string>
#include "minesweeper.h"


int main()
{

    return 0;
}

void DisplayInterface(int step, Grid* grid)
{
	std::cout << "Minesweeper" << std::endl;
	std::cout << std::endl;

	switch (step)
	{
		case 1:
			break;
		default:
			break;
	}


	DisplayGrid(grid);
	std::cout << std::endl;

	std::cout << "Drapeaux : " << grid->availableFlags << " / " << grid->totalMinesAmount << std::endl;
	std::cout << std::endl;
}

int* AskCoordinates()
{
	int* coordinates = (int*)malloc(sizeof(int) * 2);

	if (coordinates == nullptr)
		exit(1);

	std::cout << "Entrez des coordonnees pour effectuer une action :";
	std::cout << "X :\n-> ";
	std::cin >> coordinates[0];

	std::cout << "Y :\n-> ";
	std::cin >> coordinates[1];

	return coordinates;
}

char AskAction(Grid* grid, std::string coordX, std::string coordY)
{
	char userInput;

	std::cout << "Effectuer une action pour la case " << coordX << coordY << std::endl << " : ()\n-> ";
	std::cin >> userInput;
	std::cin.clear();

	return userInput;
}


// https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key

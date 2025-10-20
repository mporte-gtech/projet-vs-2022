#include <iostream>
#include <string>
#include "minesweeper.h"


int main()
{
	bool replay = true;
	int gameStep = 1;

	do
	{
	
		replay = AskReplay();
	} while (replay);

    return 0;
}

bool AskReplay()
{
	char isReplaying = 'n';

	std::cout << "Rejouer ? (y/n)\n-> " << std::endl;
	std::cin >> isReplaying;

	return tolower(isReplaying) == 'y';
}

void GameLoop(int step, Grid* grid = NULL)
{
	std::cout << "Minesweeper" << std::endl;
	std::cout << std::endl;

	if (step == 1) // début de partie, demander difficulté
	{

	}
	else if (step == 2) // affichage de la grille, et actions sur la grille
	{
		DisplayGrid(grid);
		std::cout << std::endl;

		std::cout << "Drapeaux : " << grid->availableFlags << " / " << grid->totalMinesAmount << std::endl;
		std::cout << std::endl;
	}
	else if (step == 3) // demander à rejouer
	{

	}

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

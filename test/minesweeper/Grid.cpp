#include "Grid.h"

Grid* CreateGrid(int difficulty)
{
	Grid* grid = (Grid*)malloc(sizeof(Grid));

	if (grid == nullptr)
		exit(1);

	switch (difficulty)
	{
		case 1:
			grid->linesAmount = 9;
			grid->columnAmount = 9;
			break;
		case 2:
			grid->linesAmount = 16;
			grid->columnAmount = 16;
			break;
		case 3:
			grid->linesAmount = 30;
			grid->columnAmount = 16;
			break;
		case 4:
			int* gridSize = {0};

			do
			{
				int* gridSize = AskGridSize();

			} while (gridSize[0] < 1 || gridSize[1] < 1);

			grid->linesAmount = gridSize[0];
			grid->columnAmount = gridSize[1];
			break;
		default:
			break;
	}

}

void SetMines(Grid* grid)
{
	int MinesAmount = grid->totalMinesAmount;
	//grid->
}

void DisplayGrid(Grid* grid)
{
	for (int i = 0; i < grid->linesAmount; i++)
	{
		for (int i = 0; i < grid->columnAmount; i++)
		{
			std::cout << "+---";
		}
		std::cout << "+\n";
		for (int i = 0; i < grid->columnAmount; i++)
		{
			std::cout << "| ";
			std::cout << " "; // <- afficher contenu
			std::cout << " ";
		}
		std::cout << "|\n";
	}
	for (int i = 0; i < grid->columnAmount; i++)
	{
		std::cout << "+---";
	}
	std::cout << "+" << std::endl;
	std::cout << std::endl;
}

int AskDifficulty()
{
	int difficulty;
	std::cout << "Choisissez une difficulté : (1 = Facile, 2 = Normal, 3 = Difficile, 4 = Personnalise)\n-> ";
	std::cin >> difficulty;

	return difficulty;
}

int* AskGridSize()
{
	int* gridSize = (int*)malloc(sizeof(int) * 2);

	if (gridSize == nullptr)
		exit(1);

	std::cout << "Nombre de colonnes :\n-> ";
	std::cin >> gridSize[0];

	std::cout << "Nombre de lignes :\n-> ";
	std::cin >> gridSize[1];

	return gridSize;
}

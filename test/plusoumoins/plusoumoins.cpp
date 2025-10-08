#include <iostream>
#include <cstdlib>
#include <time.h>

int GenerateRandomNumber(int min, int max);
int GetPlayerGuess();
int CheckGuess(int guess, int mysteryNumber);
int PlayGame();
int ChooseDifficulty();
int GetAttemptsAmount(int difficulty);
int CalculateScore(int attemptsLeft, int difficulty);
int AskToPlayAgain();

int main()
{
	// Partie 1 , Mini-projet , Jeu du Plus ou Moins
	std::cout << "Partie 1 , Mini-projet , Jeu du Plus ou Moins" << std::endl;

	int isReplaying = 1;

	while (isReplaying == 1)
	{
		isReplaying = 0;
		isReplaying = PlayGame();
	}

}

int GenerateRandomNumber(int min, int max)
{
	srand(time(NULL));
	return rand() % (max - min + 1) + min;
}

int GetPlayerGuess()
{
	int askedNumber;

	do
	{
		std::cout << "Saisir un nombre entre 1 et 100 : \n-> ";
		std::cin >> askedNumber;
	} while (!(1 <= askedNumber <= 100));

	return askedNumber;
}

int CheckGuess(int guess, int mysteryNumber)
{
	if (guess < mysteryNumber)
	{
		return -1;
	}
	else if (guess == mysteryNumber)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

int PlayGame()
{
	int mysteryNumber = GenerateRandomNumber(1, 100);
	int attemptAmount = 5;
	int playerGuess = 0;
	int checkedGuess = NULL;
	int difficulty;
	int attemptsAmount;
	int isReplaying;

	difficulty = ChooseDifficulty();
	attemptsAmount = GetAttemptsAmount(difficulty);

	while (attemptsAmount > 0)
	{
		attemptsAmount--;
		playerGuess = GetPlayerGuess();
		checkedGuess = CheckGuess(playerGuess, mysteryNumber);

		if (checkedGuess < 0)
		{
			std::cout << "Trop bas !" << std::endl;
		}
		else if (checkedGuess > 0)
		{
			std::cout << "Trop haut !" << std::endl;
		}
		else
		{
			std::cout << "Bravo, vous avez trouve le nombre mystere !" << std::endl;
			break;
		}
	}

	if (attemptsAmount == 0 && checkedGuess != 0)
	{
		std::cout << "Vous avez utilise tous vos essais, dommage..." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Score : " << CalculateScore(attemptsAmount, difficulty) << std::endl;

	isReplaying = AskToPlayAgain();

	return isReplaying;
}

int ChooseDifficulty()
{
	int difficultyChoice;

	do
	{
		std::cout << "Choisir un niveau de difficulte (1 : facile, 2 : moyen, 3 : difficile) : \n-> ";
		std::cin >> difficultyChoice;
	} while (difficultyChoice < 1 || 3 < difficultyChoice);

	return difficultyChoice;
}

int GetAttemptsAmount(int difficulty)
{
	if (difficulty == 1)
	{
		return 8;
	}
	else if (difficulty == 2)
	{
		return 5;
	}
	else if (difficulty == 3)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}


int CalculateScore(int attemptsLeft, int difficulty)
{
	int finalScore;

	finalScore = attemptsLeft * (difficulty * 10);

	return finalScore;
}

int AskToPlayAgain()
{
	int isReplaying;

	std::cout << "Voulez-vous rejouer ? (1 : Oui, 0 : Non) : \n-> ";
	std::cin >> isReplaying;
	std::cout << std::endl;

	return isReplaying;
}

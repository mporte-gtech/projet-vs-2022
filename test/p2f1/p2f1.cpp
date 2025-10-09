#include <iostream>

void IncrementBy(int* intAddress, int delta);
void ToggleCase(char* letter);
void Swap(int* firstNumber, int* secondNumber);

int main()
{
	// Exercice 1 — Modification indirecte
	std::cout << "Exercice 1 , Modification indirecte" << std::endl;

	int firstNumber;
	int secondNumber;
	int userChoice;
	int* numberPointer = NULL;
	int delta;
	int factor;

	std::cout << "a ? \n-> ";
	std::cin >> firstNumber;

	std::cout << "b ? \n-> ";
	std::cin >> secondNumber;

	std::cout << "choix (1 = a, 2 = b) ? \n-> ";
	std::cin >> userChoice;

	if (userChoice == 1)
	{
		numberPointer = &firstNumber;
	}
	else if (userChoice == 2)
	{
		numberPointer = &secondNumber;
	}

	std::cout << "delta ? \n-> ";
	std::cin >> delta;

	std::cout << "facteur ? \n-> ";
	std::cin >> factor;

	if (numberPointer != NULL)
	{
		*numberPointer = (*numberPointer + delta) * factor;
	}

	std::cout << "a = " << firstNumber << ", b = " << secondNumber << std::endl;


	std::cout << std::endl;
	// Exercice 2 — Incrément paramétré
	std::cout << "Exercice 2 , Increment parametre" << std::endl;

	int secondUserInput;
	int secondDelta;

	std::cout << "n ? \n-> ";
	std::cin >> secondUserInput;
	
	std::cout << "delta ? \n-> ";
	std::cin >> secondDelta;

	IncrementBy(&secondUserInput, secondDelta);

	std::cout << "Valeur : " << secondUserInput << std::endl;


	std::cout << std::endl;
	// Exercice 3 — Basculer la casse
	std::cout << "Exercice 3 , Basculer la casse" << std::endl;

	char letterInput;

	std::cout << "Caractere ? \n-> ";
	std::cin >> letterInput;

	ToggleCase(&letterInput);

	std::cout << "Resultat : " << letterInput << std::endl;


	std::cout << std::endl;
	// Exercice 4 — Échange
	std::cout << "Exercice 4 , Echange" << std::endl;

	int numberX;
	int numberY;

	std::cout << "x ? \n-> ";
	std::cin >> numberX;

	std::cout << "y ? \n-> ";
	std::cin >> numberY;

	Swap(&numberX, &numberY);

	std::cout << "Apres echange : x = " << numberX << ", y = " << numberY << std::endl;
}

void IncrementBy(int* intAddress, int delta)
{
	*intAddress = *intAddress + delta;
}

void ToggleCase(char* letter)
{
	if ((int)*letter > 96)
	{
		*letter -= 32;
	}
	else
	{
		*letter += 32;
	}
}

void Swap(int* firstNumber, int* secondNumber)
{
	int swapTemp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = swapTemp;
}

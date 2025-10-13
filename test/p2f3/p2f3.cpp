#include <iostream>

int* Allocate(int value);
void FreeMemory(int** pointerAddress);


int main()
{
	// Exercice 1 — Premier malloc
	std::cout << "Exercice 1 , Premier malloc" << std::endl;

	int* firstMalloc = (int*) malloc(sizeof(int));

	if (firstMalloc == nullptr) exit(1);

	std::cout << "Entier ? \n-> ";
	std::cin >> *firstMalloc;

	std::cout << "Valeur : " << *firstMalloc << std::endl;

	free(firstMalloc);

	firstMalloc = nullptr;


	std::cout << std::endl;
	// Exercice 2 — Allocation via fonction
	std::cout << "Exercice 2 , Allocation via fonction" << std::endl;

	int numberFirstInput;
	int numberSecondInput;
	int* numberFirstPointer;
	int* numberSecondPointer;

	std::cout << "Valeur 1 ? \n-> ";
	std::cin >> numberFirstInput;

	numberFirstPointer = Allocate(numberFirstInput);

	std::cout << "Valeur 1 ? \n-> ";
	std::cin >> numberSecondInput;

	numberSecondPointer = Allocate(numberSecondInput);

	std::cout << "a = " << *numberFirstPointer << ", b = " << *numberSecondPointer << std::endl;

	free(numberFirstPointer);
	free(numberSecondPointer);


	std::cout << std::endl;
	// Exercice 3 — Libération sécurisée
	std::cout << "Exercice 3 , Liberation securisee" << std::endl;

	int* variableToFree = (int*)malloc(sizeof(int));

	if (variableToFree == nullptr) exit(1);

	std::cout << "Valeur ? \n-> ";
	std::cin >> *variableToFree;

	FreeMemory(&variableToFree);

	if (variableToFree == nullptr)
		std::cout << "Liberation effectuee";
}

int* Allocate(int value)
{
	int* mallocValue = (int*)malloc(sizeof(int));

	if (mallocValue == nullptr) exit(1);

	*mallocValue = value;

	return mallocValue;
}

void FreeMemory(int** pointerAddress)
{
	free(*pointerAddress);
	*pointerAddress = nullptr;
}

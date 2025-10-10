#include <iostream>

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
}
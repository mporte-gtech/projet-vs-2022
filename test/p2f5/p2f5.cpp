#include <iostream>

void InverseArray(int* array, int size);

int FindMaxIndex(int* array, int size);

int FindClosestElement(int* array, int size, int referenceValue);

void InverseArray(int* array, int size)
{
	int temp;

	for (int i = 0; i < (size / 2); i++)
	{
		temp = array[i];

		array[i] = array[size - i - 1];

		array[size - i - 1] = temp;
	}
}

int FindMaxIndex(int* array, int size)
{
	int indexMax = array[0];

	for (int i = 0; i < size; i++)
	{
		if (array[i] > array[indexMax])
		{
			indexMax = array[i];
		}
	}

	return indexMax;
}

int main()
{
	// Exercice 1 — Lecture et affichage d’un tableau
	std::cout << "Exercice 1 , Lecture et affichage d un tableau" << std::endl;

	int tableSize;

	std::cout << "Taille ? \n-> ";
	std::cin >> tableSize;

	int* table = (int*) malloc(sizeof(int) * tableSize);

	if (table == nullptr) exit(1);

	for (int i = 0; i < tableSize; i++)
	{
		std::cout << "Element " << i << " du tableau ? \n-> ";
		std::cin >> table[i];
	}

	std::cout << "Tableau : ";
	for (int i = 0; i < tableSize; i++)
	{
		std::cout << table[i] << " ";
	}
	std::cout << std::endl;

	free(table);
	table = nullptr;


	std::cout << std::endl;
	// Exercice 2 — Inversion d’un tableau
	std::cout << "Exercice 2 , Inversion d un tableau" << std::endl;

	int secondTable[]{ 1, 2, 3, 4 };
	int secondTableSize = sizeof(secondTable) / sizeof(int);

	InverseArray(secondTable, secondTableSize);

	std::cout << "Resultat : ";
	for (int i = 0; i < secondTableSize; i++)
	{
		std::cout << secondTable[i] << " ";
	}
	std::cout << std::endl;


	std::cout << std::endl;
	// Exercice 3 — Recherche du maximum
	std::cout << "Exercice 2 , Recherche du maximum" << std::endl;

	int thirdTable[]{ 3, 5, 2, 8, 4 };

	int maximumIndex = FindMaxIndex(thirdTable, sizeof(thirdTable) / sizeof(int));

	std::cout << "Maximum : " << thirdTable[maximumIndex] << " a l indice " << maximumIndex << std::endl;


	std::cout << std::endl;
	// Exercice 4 — Élément le plus proche
	std::cout << "Exercice 2 , Element le plus proche" << std::endl;

}

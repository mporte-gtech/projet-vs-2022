#include <iostream>

void InverseArray(int* array, int size);

int FindMaxIndex(int* array, int size);

int FindClosestElement(int* array, int size, int referenceValue);

void RotateArrayRight(int* array, int size);

void MoveZerosToEnd(int* array, int size);

int* InsertInSortedArray(int* array, int size, int newElement);

int* MergeSortedArrays(int* firstSetTable, int firstSetTableSize, int* secondSetTable, int secondSetTableSize);

void SortArray(int* array, int size);

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

int FindClosestElement(int* array, int size, int referenceValue)
{
	int closestElement = NULL;
	int smallestdiff = NULL;

	for (int i = 0; i <= size-1; i++)
	{
		int diff;

		if (referenceValue - array[i] >= 0)
		{
			diff = referenceValue - array[i];
		}
		else
		{
			diff = array[i] - referenceValue;
		}

		if (smallestdiff == NULL || diff < smallestdiff)
		{
			closestElement = array[i];
			smallestdiff = diff;
		}
	}

	return closestElement;
}

void RotateArrayRight(int* array, int size)
{
	int temp = array[size-1];

	for (int i = size-1; i > 0 ; i--)
	{
		array[i] = array[i-1];
	}

	array[0] = temp;
}

void MoveZerosToEnd(int* array, int size)
{
	int lastIndex = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] != 0)
		{
			array[lastIndex] = array[i];
			lastIndex++;
		}
	}

	for (int i = lastIndex; i < size; i++)
	{
		array[i] = 0;
	}

}

int* InsertInSortedArray(int* array, int size, int newElement)
{
	int* newTable = (int*)malloc(sizeof(int) * (size + 1));
	int newElementSet = 0;

	if (newTable == nullptr)
		exit(1);

	for (int i = 0; i < size + 1; i++)
	{
		if (!newElementSet && (i == size || array[i] > newElement))
		{
			newElementSet = 1;
			newTable[i] = newElement;
		}
		else
		{
			newTable[i] = array[i - newElementSet];
		}
	}

	return newTable;
}

int* MergeSortedArrays(int* firstSetTable, int firstSetTableSize, int* secondSetTable, int secondSetTableSize)
{
	int* newTable = (int*)malloc(sizeof(int) * (firstSetTableSize + secondSetTableSize));

	if (newTable == nullptr)
		exit(1);

	for (int i = 0; i < firstSetTableSize; i++)
	{
		newTable[i] = firstSetTable[i];
	}

	for (int i = 0; i < secondSetTableSize; i++)
	{
		newTable[i + firstSetTableSize] = secondSetTable[i];
	}

	return newTable;
}

void SortArray(int* array, int size)
{
	SortArray(array, size);
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
	std::cout << "Exercice 3 , Recherche du maximum" << std::endl;

	int thirdTable[]{ 3, 5, 2, 8, 4 };

	int maximumIndex = FindMaxIndex(thirdTable, sizeof(thirdTable) / sizeof(int));

	std::cout << "Maximum : " << thirdTable[maximumIndex] << " a l indice " << maximumIndex << std::endl;


	std::cout << std::endl;
	// Exercice 4 — Élément le plus proche
	std::cout << "Exercice 4 , Element le plus proche" << std::endl;

	int fourthTable[]{ 1, 5, 9, 15 };
	int referenceValue;
	int closestValue;

	std::cout << "Valeur ? \n-> ";
	std::cin >> referenceValue;

	closestValue = FindClosestElement(fourthTable, sizeof(fourthTable) / sizeof(int), referenceValue);

	std::cout << "Plus proche : " << closestValue << std::endl;


	std::cout << std::endl;
	// Exercice 5 — Rotation du tableau
	std::cout << "Exercice 5 , Rotation du tableau" << std::endl;

	int fifthTable[]{ 1, 2, 3, 4, 5 };
	int fifthTableSize = sizeof(fifthTable) / sizeof(int);

	RotateArrayRight(fifthTable, fifthTableSize);

	std::cout << "Resultat : ";
	for (int i = 0; i < fifthTableSize; i++)
	{
		std::cout << fifthTable[i] << " ";
	}
	std::cout << std::endl;


	std::cout << std::endl;
	// Exercice 6 — Déplacement des zéros
	std::cout << "Exercice 5 , Deplacement des zeros" << std::endl;

	int sixthTable[]{ 0, 1, 0, 3, 12 };
	int sixthTableSize = sizeof(sixthTable) / sizeof(int);

	MoveZerosToEnd(sixthTable, sixthTableSize);
	
	std::cout << "Resultat : ";
	for (int i = 0; i < sixthTableSize; i++)
	{
		std::cout << sixthTable[i] << " ";
	}
	std::cout << std::endl;

	
	std::cout << std::endl;
	// Exercice 7 — Insertion dans un tableau trié
	std::cout << "Exercice 7 , Insertion dans un tableau trie" << std::endl;

	int seventhTable[]{ 1, 2, 4, 5 };
	int seventhTableSize = sizeof(seventhTable) / sizeof(int);
	int newElement;

	std::cout << "Valeur a inserer ? \n-> ";
	std::cin >> newElement;

	int* newTableAddress = InsertInSortedArray(seventhTable, seventhTableSize, newElement);

	std::cout << "Resultat : ";
	for (int i = 0; i < seventhTableSize + 1; i++)
	{
		std::cout << newTableAddress[i] << " ";
	}
	std::cout << std::endl;


	std::cout << std::endl;
	// Exercice 8 — Fusion de deux tableaux triés
	std::cout << "Exercice 8 , Fusion de deux tableaux tries" << std::endl;

	int firstSetTable[]{ 1, 2, 3 };
	int secondSetTable[]{ 4, 5, 6 };
	int firstSetTableSize = sizeof(firstSetTable) / sizeof(int);
	int secondSetTableSize = sizeof(secondSetTable) / sizeof(int);

	int* newSetTableAddress = MergeSortedArrays(firstSetTable, firstSetTableSize, secondSetTable, secondSetTableSize);

	std::cout << "Fusion : ";
	for (int i = 0; i < firstSetTableSize + secondSetTableSize; i++)
	{
		std::cout << newSetTableAddress[i] << " ";
	}
	std::cout << std::endl;


	std::cout << std::endl;
	// Exercice 9 — Tri d’un tableau
	std::cout << "Exercice 9 , Tri d un tableau" << std::endl;

	int lastTable[]{ 4, 2, 3, 1 };
	int lastTableSize = sizeof(lastTable) / sizeof(int);

	std::cout << "Sortie : ";
	for (int i = 0; i < lastTableSize; i++)
	{
		std::cout << lastTable[i] << " ";
	}
	std::cout << std::endl;
}

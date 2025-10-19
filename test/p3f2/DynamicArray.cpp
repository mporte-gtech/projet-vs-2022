#include "DynamicArray.h"
#include <iostream>

DynamicArray* CreateDynamicArray(int size)
{
	DynamicArray* dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));

	if (dynamicArray == nullptr)
		exit(1);

	dynamicArray->tableau = (int*)malloc(sizeof(int) * size);

	dynamicArray->taille = 0;

	dynamicArray->capacit� = size;

	return dynamicArray;
}

void AddElement(DynamicArray* dynamicArray, int newElement)
{
	if (dynamicArray->taille == dynamicArray->capacit�)
	{
		int* newTable = (int*)malloc(sizeof(int) * (dynamicArray->capacit� * 2));
		int* oldTableAddress = dynamicArray->tableau;

		if (newTable == nullptr)
			exit(1);

		std::copy(dynamicArray->tableau, dynamicArray->tableau + dynamicArray->capacit�, newTable);

		dynamicArray->tableau = newTable;
		dynamicArray->capacit� *= 2;
		free(dynamicArray->tableau);
	}

	dynamicArray->taille++;

	dynamicArray->tableau[dynamicArray->taille] = newElement;
}

void InsertElement(DynamicArray* dynamicArray, int index, int newElement)
{
	if (index < 0 || index > dynamicArray->taille)
		return;

	if (dynamicArray->taille == dynamicArray->capacit�)
	{
		int* newTable = (int*)malloc(sizeof(int) * (dynamicArray->capacit� * 2));

		if (newTable == nullptr)
			exit(1);

		std::copy(dynamicArray->tableau, dynamicArray->tableau + dynamicArray->taille, newTable);
		free(dynamicArray->tableau);

		dynamicArray->tableau = newTable;
		dynamicArray->capacit� *= 2;
	}

	for (int i = dynamicArray->taille; i > index; i--)
	{
		dynamicArray->tableau[i] = dynamicArray->tableau[i - 1];
	}

	dynamicArray->tableau[index] = newElement;
	dynamicArray->taille++;
}

void RemoveElement(DynamicArray* dynamicArray, int index)
{
	if (index > 0 && index <= dynamicArray->capacit�)
	{
		dynamicArray->tableau[index] = NULL;

		for (int i = index; i < dynamicArray->capacit� - 1; i++)
		{
			dynamicArray->tableau[i] = dynamicArray->tableau[i + 1];
		}

		dynamicArray->taille--;
	}
}

void DisplayArray(DynamicArray* dynamicArray)
{
	for (int i = 0; i < dynamicArray->taille; i++)
	{
		std::cout << dynamicArray->tableau[i] << std::endl;
	}
}

void Set(DynamicArray* dynamicArray, int index, int newElement)
{
	if (index > 0 && index <= dynamicArray->capacit�)
	{
		dynamicArray->tableau[index] = newElement;
	}
}

int Get(DynamicArray* dynamicArray, int index)
{
	if (index > 0 && index <= dynamicArray->capacit�)
	{
		return dynamicArray->tableau[index];
	}
}

void FreeArray(DynamicArray* dynamicArray)
{
	free(dynamicArray->tableau);
	free(dynamicArray);
}



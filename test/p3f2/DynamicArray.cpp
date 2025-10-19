#include "DynamicArray.h"
#include <iostream>

DynamicArray* CreateDynamicArray(int size)
{
	DynamicArray* dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));

	if (dynamicArray == nullptr)
		exit(1);

	dynamicArray->tableau = (int*)malloc(sizeof(int) * size);

	dynamicArray->taille = 0;

	dynamicArray->capacité = size;

	return dynamicArray;
}

void AddElement(DynamicArray* dynamicArray, int newElement)
{
	if (dynamicArray->taille == dynamicArray->capacité)
	{
		int* newTable = (int*)malloc(sizeof(int) * (dynamicArray->capacité * 2));
		int* oldTableAddress = dynamicArray->tableau;

		if (newTable == nullptr)
			exit(1);

		std::copy(dynamicArray->tableau, dynamicArray->tableau + dynamicArray->capacité, newTable);

		dynamicArray->tableau = newTable;
		dynamicArray->capacité *= 2;
		free(dynamicArray->tableau);
	}

	dynamicArray->taille++;

	dynamicArray->tableau[dynamicArray->taille] = newElement;
}

void InsertElement(DynamicArray* dynamicArray, int index, int newElement)
{
	if (index < 0 || index > dynamicArray->taille)
		return;

	if (dynamicArray->taille == dynamicArray->capacité)
	{
		int* newTable = (int*)malloc(sizeof(int) * (dynamicArray->capacité * 2));

		if (newTable == nullptr)
			exit(1);

		std::copy(dynamicArray->tableau, dynamicArray->tableau + dynamicArray->taille, newTable);
		free(dynamicArray->tableau);

		dynamicArray->tableau = newTable;
		dynamicArray->capacité *= 2;
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
	if (index > 0 && index <= dynamicArray->capacité)
	{
		dynamicArray->tableau[index] = NULL;

		for (int i = index; i < dynamicArray->capacité - 1; i++)
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
	if (index > 0 && index <= dynamicArray->capacité)
	{
		dynamicArray->tableau[index] = newElement;
	}
}

int Get(DynamicArray* dynamicArray, int index)
{
	if (index > 0 && index <= dynamicArray->capacité)
	{
		return dynamicArray->tableau[index];
	}
}

void FreeArray(DynamicArray* dynamicArray)
{
	free(dynamicArray->tableau);
	free(dynamicArray);
}



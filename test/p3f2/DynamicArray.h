#pragma once


struct DynamicArray
{
	// pointeur vers le tableau dynamique d�entiers
	int* tableau;

	// nombre d��l�ments actuellement pr�sents
	int taille;

	// capacit� maximale du tableau (espace m�moire allou�)
	int capacit�;
};


DynamicArray* CreateDynamicArray(int size);

void AddElement(DynamicArray* dynamicArray, int newElement);

void InsertElement(DynamicArray* dynamicArray, int index, int newElement);

void RemoveElement(DynamicArray* dynamicArray, int index);

void DisplayArray(DynamicArray* dynamicArray);

void Set(DynamicArray* dynamicArray, int index, int newElement);

int Get(DynamicArray* dynamicArray, int index);

void FreeArray(DynamicArray* dynamicArray);

#pragma once


struct DynamicArray
{
	// pointeur vers le tableau dynamique d’entiers
	int* tableau;

	// nombre d’éléments actuellement présents
	int taille;

	// capacité maximale du tableau (espace mémoire alloué)
	int capacité;
};


DynamicArray* CreateDynamicArray(int size);

void AddElement(DynamicArray* dynamicArray, int newElement);

void InsertElement(DynamicArray* dynamicArray, int index, int newElement);

void RemoveElement(DynamicArray* dynamicArray, int index);

void DisplayArray(DynamicArray* dynamicArray);

void Set(DynamicArray* dynamicArray, int index, int newElement);

int Get(DynamicArray* dynamicArray, int index);

void FreeArray(DynamicArray* dynamicArray);

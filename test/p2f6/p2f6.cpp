#include <iostream>

char* ConcatenateStrings(char* firstString, char* secondString);
int FindCharacter(char* firstString, char searchingChar);
bool CompareStrings(char* firstString, char* secondString, bool caseSensitive);
int CountCharacterFrequency(char* countFromWord, char letterToCount);
bool IsPalindrome(char* string);
char* Substring(char* string, int startingPosition, int length);
bool ContainsSequence(char* stringContainer, char* stringContained);
void ToLowerCase(char* string);
void ToUpperCase(char* string);
char* RemoveSpaces(char* string);
char* ReverseString(char* string);

char* ConcatenateStrings(char* firstString, char* secondString)
{
	int lengthFirst = std::strlen(firstString);
	int lengthSecond = std::strlen(secondString);
	char* newString = (char*)malloc(sizeof(char) * (lengthFirst + lengthSecond + 1));

	if (newString == nullptr)
		exit(1);

	for (int i = 0; i < lengthFirst; i++)
	{
		newString[i] = firstString[i];
	}
	for (int i = 0; i < lengthSecond; i++)
	{
		newString[i + lengthFirst] = secondString[i];
	}
	newString[lengthFirst + lengthSecond] = '\0';

	return newString;
}

int FindCharacter(char* string, char searchingChar)
{
	int stringLength = std::strlen(string);

	for (int i = 0; i < stringLength; i++)
	{
		if (string[i] == searchingChar)
			return i;
	}

	return -1;
}

bool CompareStrings(char* firstString, char* secondString, bool caseSensitive)
{
	if (caseSensitive)
	{
		if (firstString == secondString)
		{
			return false;
		}
		else
			return true;
	}
	else
	{
		if (tolower(*firstString) == tolower(*secondString))
		{
			return false;
		}
		else
			return true;
	}

}

int CountCharacterFrequency(char* countFromWord, char letterToCount)
{
	int stringLength = std::strlen(countFromWord);
	int letterAmount = 0;

	for (int i = 0; i < stringLength; i++)
	{
		if (countFromWord[i] == letterToCount)
			letterAmount++;
	}

	return letterAmount;
}

bool IsPalindrome(char* string)
{
	int stringLength = std::strlen(string);;

	for (int i = 0; i < (stringLength / 2); i++)
	{
		if (tolower(string[i]) != tolower(string[stringLength - 1 - i]))
		{
			return false;
		}
	}

	return true;
}

char* Substring(char* string, int startingPosition, int length)
{
	char* subString = (char*)malloc(sizeof(char) * (length + 1));

	if (subString == nullptr)
		exit(1);

	for (int i = 0; i < length; i++)
	{
		subString[i] = string[i + startingPosition];
	}
	subString[length] = '\0';

	return subString;

}

bool ContainsSequence(char* stringContainer, char* stringContained)
{
	int lengthContainer = std::strlen(stringContainer);
	int lengthContained = std::strlen(stringContained);
	int lengthTryContains = 0;

	for (int i = 0; i < lengthContainer; i++)
	{
		if (lengthContainer - i < lengthContained)
			return false;

		if (stringContainer[i] == stringContained[0])
		{
			lengthTryContains = 0;
			for (int a = 0; a < lengthContained; a++)
			{
				if (stringContainer[i + a] == stringContained[a])
				{
					lengthTryContains++;
				}
				else
				{
					std::cout << std::endl;
					break;
				}

				if (lengthTryContains == lengthContained)
					return true;
			}
		}
		else
		{
			lengthTryContains = 0;
		}
	}

	return false;
}


void ToLowerCase(char* string)
{
	int stringLength = std::strlen(string);

	for (int i = 0; i < stringLength; i++)
	{
		string[i] = tolower(string[i]);
	}
}

void ToUpperCase(char* string)
{
	int stringLength = std::strlen(string);

	for (int i = 0; i < stringLength; i++)
	{
		string[i] = toupper(string[i]);
	}
}

char* RemoveSpaces(char* string)
{
	int stringLength = std::strlen(string);
	int spaceAmount = CountCharacterFrequency(string, ' ');
	char* noSpaceString = (char*)malloc(sizeof(char) * (stringLength - spaceAmount + 1));

	if (noSpaceString == nullptr)
		exit(1);

	int backtrack = 0;
	for (int i = 0; i < stringLength; i++)
	{
		if (string[i] == ' ')
		{
			backtrack++;
		}
		else
		{
			noSpaceString[i - backtrack] = string[i];
		}
	}
	noSpaceString[stringLength - spaceAmount] = '\0';

	return noSpaceString;
}

char* ReverseString(char* string)
{
	int stringLength = std::strlen(string);
	char* reversedString = (char*)malloc(sizeof(char) * (stringLength + 1));

	if (reversedString == nullptr)
		exit(1);

	for (int i = 0; i < stringLength; i++)
	{
		reversedString[i] = string[stringLength - 1 - i];
	}
	reversedString[stringLength] = '\0';

	return reversedString;
}


int main()
{
	// Exercice 1 — Concaténation de chaînes
	std::cout << "Exercice 1 , Concatenation de chaines" << std::endl;

	char hello[] = "Hello";
	char world[] = "world";

	char* concatenated = ConcatenateStrings(hello, world);

	int concatenatedLength = std::strlen(concatenated);

	std::cout << "" << concatenated << std::endl;


	std::cout << std::endl;
	// Exercice 2 — Recherche d’un caractère
	std::cout << "Exercice 2 , Recherche d un caractere" << std::endl;

	char findFromWord[] = "abcdef";
	char letterToFind;

	std::cout << "Lettre a trouver ? \n-> ";
	std::cin >> letterToFind;

	int index = FindCharacter(findFromWord, letterToFind);

	std::cout << "Indice : " << index << std::endl;


	std::cout << std::endl;
	// Exercice 3 — Comparaison de chaînes
	std::cout << "Exercice 3 , Comparaison de chaines" << std::endl;

	char test[] = "test";
	char testMaj[] = "Test";

	std::cout << "case sensitive : " << (CompareStrings(test, testMaj, true) ? "different" : "identique") << std::endl;

	std::cout << "pas case sensitive : " << (CompareStrings(test, testMaj, false) ? "different" : "identique") << std::endl;


	std::cout << std::endl;
	// Exercice 4 — Fréquence d’un caractère
	std::cout << "Exercice 4 , Frequence d un caractere" << std::endl;

	char countFromWord[] = "hello world";
	char letterToCount;

	std::cout << "Lettre a compter ? \n-> ";
	std::cin >> letterToCount;

	int frequency = CountCharacterFrequency(countFromWord, letterToCount);

	std::cout << "Occurrences : " << frequency << std::endl;


	std::cout << std::endl;
	// Exercice 5 — Vérification de palindrome
	std::cout << "Exercice 5 , Verification de palindrome" << std::endl;

	char testPalyndrome[] = "Radar";

	bool isPal = IsPalindrome(testPalyndrome);

	std::cout << "Palyndrome : " << (isPal ? "oui" : "non") << std::endl;


	std::cout << std::endl;
	// Exercice 6 — Extraction d’un sous-texte
	std::cout << "Exercice 6 , Extraction d un sous-texte" << std::endl;

	char subStrString[] = "abcdef";
	int startingPosition;
	int length;

	std::cout << "Depart ? \n-> ";
	std::cin >> startingPosition;

	std::cout << "Longueur ? \n-> ";
	std::cin >> length;

	char* output = Substring(subStrString, startingPosition, length);

	std::cout << output << std::endl;


	std::cout << std::endl;
	// Exercice 7 — Recherche d’une séquence
	std::cout << "Exercice 7  , Recherche d une sequence" << std::endl;

	char longString[] = "aaaabaababb";
	char shortString[] = "bab";

	std::cout << "Contient : " << (ContainsSequence(longString, shortString) ? "oui" : "non") << std::endl;


	std::cout << std::endl;
	// Exercice 8 — Conversion de casse
	std::cout << "Exercice 8  , Conversion de casse" << std::endl;

	char changeCase[] = "Bonjour Le Monde";

	std::cout << changeCase << std::endl;
	ToUpperCase(changeCase);
	std::cout << changeCase << std::endl;
	ToLowerCase(changeCase);
	std::cout << changeCase << std::endl;


	std::cout << std::endl;
	// Exercice 9 — Suppression des espaces
	std::cout << "Exercice 9  , Suppression des espaces" << std::endl;

	char spaceDeletion[] = "a b c d";

	char* spacesRemoved = RemoveSpaces(spaceDeletion);

	std::cout << spacesRemoved << std::endl;


	std::cout << std::endl;
	// Exercice 10 — Inversion d’une chaîne
	std::cout << "Exercice 10  , Inversion d une chaine" << std::endl;

	char normalString[] = "Bonjour";

	char* reversedString = ReverseString(normalString);

	std::cout << reversedString << std::endl;
}

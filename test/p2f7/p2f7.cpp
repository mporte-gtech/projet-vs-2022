#include <iostream>

int GetSecretWordIndex(int* guessedWordsIndexes, int wordsAmount);
bool IsIndexUsed(int* guessedWordsIndexes, int wordIndex, int wordsAmount);
void AddUsedIndex(int* usedWordsList, int usedWordIndex, int wordsAmount);
std::string GetPlayerGuess(int wordLength);
bool CompareWords(std::string* guessAttempt, std::string* secretWord, int wordLength);
void PlayOneWord(int maxTryAmount, int wordsAmount, int wordLength, std::string* availableWords, int* guessedWordsIndexes);

int main()
{
	const int wordLength = 5;
	const int maxTryAmount = 6;
	std::string availableWords[] = {"pomme", "table", "livre", "chaud", "arbre"};
	int* guessedWordsIndexes = (int*)malloc(sizeof(int) * (sizeof(availableWords) / sizeof(*availableWords)));
	int wordsAmount = sizeof(availableWords) / sizeof(*availableWords);

	srand(time(NULL));
}

int GetSecretWordIndex(int* guessedWordsIndexes, int wordsAmount)
{
	int remainingWords = 0;
	
	for (int a = 0; a < wordsAmount; a++)
	{
		if (guessedWordsIndexes[a] == 0)
		{
			remainingWords++;
		}
	}
	if (remainingWords <= 0)
		return -1;

	int* availableIndexes = (int*)malloc(sizeof(int) * remainingWords);
	if (availableIndexes == nullptr) exit(1);
	int availableIndexesAmount = sizeof(*availableIndexes) / sizeof(int);
	int guessedWordsOffsets = 0;
	for (int a = 0; a < wordsAmount; a++)
	{
		if (guessedWordsIndexes[a] == 0)
		{
			availableIndexes[a - guessedWordsOffsets] = guessedWordsIndexes[a];
		}
		else
		{
			guessedWordsOffsets++;
		}
	}

	return availableIndexes[rand() % (0, availableIndexesAmount)];
}

bool IsIndexUsed(int* guessedWordsIndexes, int wordIndex, int wordsAmount)
{
	for (int i = 0; i < wordsAmount; i++)
	{
		if (guessedWordsIndexes[i] == wordIndex)
		{
			return true;
		}
	}
	return false;
}

void AddUsedIndex(int* usedWordsList, int usedWordIndex, int wordsAmount)
{
	for (int i = 0; i < wordsAmount; i++)
	{
		if (usedWordsList[i] == NULL)
		{
			usedWordsList[i] = usedWordIndex;
			return;
		}
	}
}

std::string GetPlayerGuess(int wordLength)
{
	std::string stringInput = "";
	bool validWord = false;

	do
	{
		std::cout << "Entrez un mot de " << wordLength << " lettres\n-> ";
		std::cin >> stringInput;

		if (stringInput.length() == wordLength)
		{
			validWord = true;
		}

		for (int i = 0; i < wordLength; i++)
		{
			if (toupper(stringInput[i]) == tolower(stringInput[i]))
			{
				validWord = false;
			}
		}

	} while (validWord == false);

	return stringInput;
}

bool CompareWords(std::string* guessAttempt, std::string* secretWord, int wordLength)
{
	int guessedLetters = 0;

	for (int i = 0; i < wordLength; i++)
	{
		if (guessAttempt[i] == secretWord[i])
		{
			guessedLetters++;
			std::cout << "\033[32m" << guessAttempt[i] << "\033[0m" << std::endl;
		}
		else
		{
			int isLetterInWord = NULL;

			for (int a = 0; a < wordLength; a++)
			{
				if (secretWord[a] == guessAttempt[i])
				{
					isLetterInWord = 1;
				}
			}

			if (isLetterInWord != NULL)
			{
				std::cout << "\033[33m" << guessAttempt[i] << "\033[0m" << std::endl;
			}
			else
			{
				std::cout << "\033[31m" << guessAttempt[i] << "\033[0m" << std::endl;
			}
		}
	}

	return guessedLetters == wordLength ? true: false;
}

void PlayOneWord(int maxTryAmount, int wordsAmount, int wordLength, std::string* availableWords, int* guessedWordsIndexes)
{
	int secretWordIndex = GetSecretWordIndex(guessedWordsIndexes, wordsAmount);
	std::string userWordInput;
	bool isRightWord;

	do
	{
		maxTryAmount--;

		userWordInput = GetPlayerGuess(wordLength);

		isRightWord = CompareWords(userWordInput, availableWords[secretWordIndex]);

		if (isRightWord == true)
		{
			std::cout << ;//mot trouvé
			// mettre mot trouvé mettre dans array mots trouvés
			return;
		}
	} while (maxTryAmount > 0);

	std::cout << ;//mot pas trouvé

	// afficher mot trouvé
}


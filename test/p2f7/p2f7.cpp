#include <iostream>

int GetSecretWordIndex(int* guessedWordsIndexes, int wordsAmount);
bool IsIndexUsed(int* guessedWordsIndexes, int wordIndex, int wordsAmount);
void AddUsedIndex(int* usedWordsList, int usedWordIndex, int wordsAmount, int* foundWordsAmount);
std::string GetPlayerGuess(int wordLength);
bool CompareWords(std::string guessAttempt, std::string secretWord, int wordLength);
void PlayOneWord(int maxTryAmount, int wordsAmount, int wordLength, int* foundWordsAmount, std::string* availableWords, int* guessedWordsIndexes);

int main()
{
	const int wordLength = 5;
	const int maxTryAmount = 6;
	std::string availableWords[] = {"pomme", "table", "livre", "chaud", "arbre"};
	int guessedWordsIndexes[sizeof(int) * (sizeof(availableWords) / sizeof(*availableWords))] = { };
	int wordsAmount = sizeof(availableWords) / sizeof(*availableWords);
	int foundWordsAmount = 0;

	srand(time(NULL));

	std::cout << "-> WORDLE" << std::endl << std::endl;
	do
	{
		std::cout << "Vous avez " << maxTryAmount << " tentatives pour trouver un mot de " << wordLength << " lettres." << std::endl;
		std::cout << "lettre \033[32mverte\033[0m -> lettre correcte\nlettre \033[33mjaune\033[0m -> lettre au mauvais endroit\nlettre \033[31mrouge\033[0m -> mauvaise lettre\n" << std::endl;
		PlayOneWord(maxTryAmount, wordsAmount, wordLength, &foundWordsAmount, availableWords, guessedWordsIndexes);
	} while (foundWordsAmount < wordsAmount);
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
	int guessedWordsOffsets = 0;
	for (int a = 0; a < wordsAmount; a++)
	{
		if (guessedWordsIndexes[a] == 0)
		{
			availableIndexes[a - guessedWordsOffsets] = a;
		}
		else
		{
			guessedWordsOffsets++;
		}
	}
	int wordIndex = availableIndexes[rand() % remainingWords];
	free(availableIndexes);

	return wordIndex;
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

void AddUsedIndex(int* guessedWordsIndexes, int usedWordIndex, int wordsAmount, int* foundWordsAmount)
{
	for (int i = 0; i < wordsAmount; i++)
	{
		if (guessedWordsIndexes[i] == NULL)
		{
			guessedWordsIndexes[i] = usedWordIndex;
			*foundWordsAmount += 1;
			return;
		}
	}
}

std::string GetPlayerGuess(int wordLength)
{
	std::string stringInput = "azert";
	bool validWord = false;

	do
	{
		std::cout << "Entrez un mot de " << wordLength << " lettres\n-> ";
		std::cin >> stringInput;

		if (stringInput.length() == wordLength)
		{
			validWord = true;
		}

		for (int i = 0; i < stringInput.length(); i++)
		{
			if (!isalpha(stringInput[i]))
			{
				validWord = false;
			}
		}

	} while (validWord == false);

	return stringInput;
}

bool CompareWords(std::string guessAttempt, std::string secretWord, int wordLength)
{
	secretWord = "mmmee";
	int guessedLetters = 0;

	for (int i = 0; i < wordLength; i++)
	{
		if (guessAttempt[i] == secretWord[i])
		{
			guessedLetters++;
			std::cout << "\033[32m" << guessAttempt[i] << "\033[0m";
			continue;
		}
		else
		{
			int isLetterInWord = 0;

			for (int a = 0; a < wordLength; a++)
			{
				if (secretWord[a] == guessAttempt[i])
				{
					isLetterInWord = 1;
				}
			}

			if (isLetterInWord != 0)
			{
				std::cout << "\033[33m" << guessAttempt[i] << "\033[0m";
			}
			else
			{
				std::cout << "\033[31m" << guessAttempt[i] << "\033[0m";
			}
		}
	}
	std::cout << std::endl;

	return guessedLetters == wordLength ? true: false;
}

void PlayOneWord(int maxTryAmount, int wordsAmount, int wordLength, int* foundWordsAmount, std::string* availableWords, int* guessedWordsIndexes)
{
	int secretWordIndex = GetSecretWordIndex(guessedWordsIndexes, wordsAmount);
	if (secretWordIndex == -1)
		return;

	std::string userWordInput;
	bool isRightWord;

	do
	{
		maxTryAmount--;
		//std::cout << "secretWordIndex " << secretWordIndex << " - " << availableWords[secretWordIndex] << std::endl;

		userWordInput = GetPlayerGuess(wordLength);

		isRightWord = CompareWords(userWordInput, availableWords[secretWordIndex], wordLength);

		if (isRightWord == true)
		{
			std::cout << "Le mot a ete trouve en " << maxTryAmount << " tentatives !" << std::endl;
			AddUsedIndex(guessedWordsIndexes, secretWordIndex, wordsAmount, foundWordsAmount);
			return;
		}
	} while (maxTryAmount > 0);

	std::cout << std::endl;

	std::cout << "Toutes les tentatives ont ete utilisees. Le mot n a pas ete trouve" << std::endl;
	std::cout << "Le mot etait " << availableWords[secretWordIndex] << std::endl;
}

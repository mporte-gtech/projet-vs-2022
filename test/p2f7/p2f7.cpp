#include <iostream>

int GetSecretWordIndex(std::string*, int* guessedWords, int wordsAmount);
bool IsIndexUsed(int index, int* guessedWords);
void AddUsedIndex(int* usedWordsList, int usedWordIndex);
void GetPlayerGuess();
bool CompareWords(std::string* guessAttempt, std::string* secretWord, int wordLength);
void PlayOneWord();

int main()
{
	const int wordLength = 5;
	const int maxTryAmount = 6;
	std::string availableWords[] = {"pomme", "table", "livre", "chaud", "arbre"};
	int* guessedWordsIndexes = (int*)malloc(sizeof(int) * (sizeof(availableWords) / sizeof(*availableWords)));
	int wordsAmount = sizeof(availableWords) / sizeof(*availableWords);

	srand(time(NULL));
	int secretWordIndex = GetSecretWordIndex(availableWords, guessedWordsIndexes, wordsAmount);

}

int GetSecretWordIndex(std::string* wordsToGuess, int* guessedWords, int wordsAmount)
{
	int wordToGuessIndex = NULL;
	int remainingWords = 0;
	
	for (int a = 0; a < wordsAmount; a++)
	{
		if (guessedWords[a] == 0)
		{
			remainingWords++;
		}
	}

	if (remainingWords == 0)
		return -1;


	do
	{
		wordToGuessIndex = rand() % (0, wordsAmount);
		if (IsIndexUsed(wordToGuessIndex, guessedWords))
		{
				wordToGuessIndex = NULL;
		}
	} while (wordToGuessIndex == NULL);

	return wordToGuessIndex;
}

bool IsIndexUsed(int index, int* guessedWords)
{
	if (guessedWords[index] == 0)
	{
		return false;
	}
	return true;
}

void AddUsedIndex(int* usedWordsList, int usedWordIndex)
{
	usedWordsList[usedWordIndex] = 1;
}

bool CompareWords(std::string* guessAttempt, std::string* secretWord, int wordLength)
{
	int guessedLetters = 0;

	for (int i = 0; i < wordLength; i++)
	{
		bool rightLetter = guessAttempt[i] == secretWord[i];
		if (rightLetter)
			guessedLetters++;

		if (rightLetter)
		{
			// affiche vert
		}
		else
		{
			for (i = 0; i < strlen(guessAttempt); i++)
			{
				if (foundalpha = isalpha(instring[i]))
				{
					break;
				}
			}

			if ()
			{
				// affiche jaune
			}
			else
			{
				// affiche rouge
			}
		}
	}

	return guessedLetters == wordLength ? true: false;
}



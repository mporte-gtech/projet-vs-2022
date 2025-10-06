#include <iostream>

int main()
{
	// Exercice 1 – Afficher les entiers pairs
	std::cout << "Exercice 1 , Afficher les entiers pairs" << std::endl;

	int intN;
	int currentEvenNumber;

	std::cout << "Entier n ? \n-> ";
	std::cin >> intN;

	if (intN < 0)
	{
		std::cout << "Aucun nombre a afficher" << std::endl;
	}
	else
	{
		currentEvenNumber = 0;

		std::cout << "Nombres pairs :";
		
		while (currentEvenNumber <= intN)
		{
			std::cout << " " << currentEvenNumber;

			currentEvenNumber += 2;
		}

		std::cout << std::endl;
	}


	std::cout << std::endl;
	// Exercice 2 – Boutique
	std::cout << "Exercice 2 , Boutique" << std::endl;

	int itemAmount;
	int isPremium;
	int currentItemNumber;
	float currentItemPrice;
	int currentItemAmount;
	float totalPrice;

	std::cout << "Nombre d articles ? \n-> ";
	std::cin >> itemAmount;

	currentItemNumber = 0;
	totalPrice = 0;
	while (currentItemNumber < itemAmount)
	{
		currentItemNumber++;
		
		std::cout << "Prix de l article " << currentItemNumber << " ? \n-> ";
		std::cin >> currentItemPrice;

		std::cout << "Quantite de l article " << currentItemNumber << " ? \n-> ";
		std::cin >> currentItemAmount;

		totalPrice += (float)currentItemPrice * currentItemAmount;
	}

	std::cout << "Premium ? \n-> ";
	std::cin >> isPremium;

	if (totalPrice >= 100 || (isPremium && totalPrice >= 50))
	{
		totalPrice = totalPrice * 0.9;
	}

	std::cout << "Total a payer : " << totalPrice << std::endl;


	std::cout << std::endl;
	// Exercice 3 – Distributeur de billets
	std::cout << "Exercice 3 , Distributeur de billets" << std::endl;

	int remainingWithdraw;
	int fiveHundredNotes;
	int hundredNotes;
	int fiftyNotes;
	int twentyNotes;
	int tenNotes;

	std::cout << "Combien voulez vous retirer ? \n-> ";
	std::cin >> remainingWithdraw;

	if (remainingWithdraw >= 10)
	{
		std::cout << "Voici ";

		fiveHundredNotes = 0;
		while (remainingWithdraw >= 500)
		{
			fiveHundredNotes += 1;
			remainingWithdraw -= 500;
		}
		if (fiveHundredNotes > 0)
		{
			std::cout << fiveHundredNotes << "billet(s) de 500euro ";

			if (remainingWithdraw >= 10)
			{
				std::cout << ", ";
			}
		}

		hundredNotes = 0;
		while (remainingWithdraw >= 100)
		{
			hundredNotes += 1;
			remainingWithdraw -= 100;
		}
		if (hundredNotes > 0)
		{
			std::cout << hundredNotes << "billet(s) de 100euro ";

			if (remainingWithdraw >= 10)
			{
				std::cout << ", ";
			}
		}

		fiftyNotes = 0;
		while (remainingWithdraw >= 50)
		{
			fiftyNotes += 1;
			remainingWithdraw -= 50;
		}
		if (fiftyNotes > 0)
		{
			std::cout << fiftyNotes << "billet(s) de 50euro ";

			if (remainingWithdraw >= 10)
			{
				std::cout << ", ";
			}
		}

		twentyNotes = 0;
		while (remainingWithdraw >= 20)
		{
			twentyNotes += 1;
			remainingWithdraw -= 20;
		}
		if (twentyNotes > 0)
		{
			std::cout << twentyNotes << "billet(s) de 20euro ";

			if (remainingWithdraw >= 10)
			{
				std::cout << ", ";
			}
		}

		tenNotes = 0;
		while (remainingWithdraw >= 10)
		{
			tenNotes += 1;
			remainingWithdraw -= 10;
		}
		if (tenNotes > 0)
		{
			std::cout << tenNotes << "billet(s) de 10euro ";
		}

		std::cout << std::endl;
	}


	std::cout << std::endl;
	// Exercice 4 – Connexion sécurisée
	std::cout << "Exercice 4 , Connexion securisee" << std::endl;

	int secretCode;
	int codeAttempt;
	int loopCode;

	std::cout << "Definir le code secret ? \n-> ";
	std::cin >> secretCode;

	loopCode = 1;
	while (loopCode == 1)
	{
		std::cout << "Saisir le code ? \n-> ";
		std::cin >> codeAttempt;

		if (codeAttempt == secretCode)
		{
			loopCode = 0;
			std::cout << "Connexion reussie." << std::endl;
			continue;
		}
	}


	return 0;
}

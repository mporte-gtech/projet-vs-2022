#include <iostream>


int main()
{
	// Exercice 1 – Duel e-sport
	std::cout << "Exercice 1 , Duel e-sport" << std::endl;

	int scorePlayer1;
	int scorePlayer2;

	std::cout << "Score du joueur 1 : \n-> ";
	std::cin >> scorePlayer1;

	std::cout << "Score du joueur 2 : \n-> ";
	std::cin >> scorePlayer2;

	if (scorePlayer1 > scorePlayer2)
	{
		std::cout << "Le joueur 1 a le meilleur score." << std::endl;
	}
	else
	{
		std::cout << "Le joueur 2 a le meilleur score." << std::endl;
	}


	std::cout << std::endl;
	// Exercice 2 – Podium
	std::cout << "Exercice 2 , Podium" << std::endl;

	int score1;
	int score2;
	int score3;

	std::cout << "Score 1 : \n-> ";
	std::cin >> score1;

	std::cout << "Score 2 : \n-> ";
	std::cin >> score2;

	std::cout << "Score 3 : \n-> ";
	std::cin >> score3;

	if (score2 < score1 && score3 < score1)
	{
		std::cout << "Le meilleur score est " << score1 << std::endl;
	}
	else if (score1 < score2 && score3 < score2)
	{
		std::cout << "Le meilleur score est " << score2 << std::endl;
	}
	else if (score1 < score3 && score2 < score3)
	{
		std::cout << "Le meilleur score est " << score3 << std::endl;
	}


	std::cout << std::endl;
	// Exercice 3 – Matchmaking
	std::cout << "Exercice 3 , Matchmaking" << std::endl;

	int playerAmount;

	std::cout << "Saisir le nombre de joueurs : \n-> ";
	std::cin >> playerAmount;

	if (playerAmount % 2 == 0)
	{
		std::cout << "Le nombre de joueurs est pair." << std::endl;
	}
	else
	{
		std::cout << "Le nombre de joueurs est impair." << std::endl;
	}


	std::cout << std::endl;
	// Exercice 4 – Année
	std::cout << "Exercice 4 , Annee" << std::endl;

	int year;

	std::cout << "Annee : \n-> ";
	std::cin >> year;

	if (year % 4 == 0 && year % 100 != 0 || (year % 4 == 0 && year % 400 == 0))
	{
		std::cout << "L année est bissextile." << std::endl;
	}
	else
	{
		std::cout << "L annee n est pas bissextile." << std::endl;
	}


	return 0;
}

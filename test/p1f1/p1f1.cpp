#include <iostream>


int main()
{
	// Exercice 1 – Aire et périmètre d’un terrain de sport
	std::cout << "Exercice 1 , Aire et perimetre d un terrain de sport" << std::endl;

	float width;
	float length;
	float perimeter;
	float surface;

	std::cout << "Quelle est la longueur du terrain ? \n -> ";
	std::cin >> length;

	std::cout << "Quelle est la largeur ? \n -> ";
	std::cin >> width;

	perimeter = (float)width * 2 + length * 2;
	surface = (float)width * length;

	std::cout << "Surface : " << surface << " m carre, perimetre : " << perimeter << " m." << std::endl;


	std::cout << std::endl;
	// Exercice 2 – Euros et centimes
	std::cout << "Exercice 2 , Euros et centimes" << std::endl;

	float totalEuro;
	int calculEuro;
	int calculCents;

	std::cout << "Quel est le prix en euros ? \n -> ";
	std::cin >> totalEuro;

	calculEuro = (int)totalEuro;
	calculCents = (totalEuro - calculEuro) * 100;

	std::cout << "Montant total : " << calculEuro << " euros et " << calculCents << " centimes" << std::endl;


	std::cout << std::endl;
	// Exercice 3 – Partage de pizzas
	std::cout << "Exercice 3 , Partage de pizzas" << std::endl;

	int totalPizza;
	int totalFriends;
	int totalPizzaSlices;
	int pizzaSlicesPerPerson;
	int pizzaSlicesRemaining;

	std::cout << "Combien de pizzas ont ete commandees ? \n -> ";
	std::cin >> totalPizza;

	totalPizzaSlices = totalPizza * 8;

	std::cout << "Combien d amis sont presents ? \n -> ";
	std::cin >> totalFriends;

	pizzaSlicesPerPerson = totalPizzaSlices / totalFriends;
	pizzaSlicesRemaining = totalPizzaSlices % totalFriends;

	std::cout << pizzaSlicesPerPerson << " parts par personne, il reste " << pizzaSlicesRemaining << " parts en plus." << std::endl;


	std::cout << std::endl;
	// Exercice 4 – Temps de jeu en heures, minutes, secondes
	std::cout << "Exercice 4 , Temps de jeu en heures, minutes, secondes" << std::endl;

	int totalGameTimeSeconds;
	int gametimeseconds;
	int gametimeminutes;
	int gametimeHours;

	std::cout << "Combien de secondes de jeu au total ? \n -> ";
	std::cin >> totalGameTimeSeconds;

	gametimeseconds = totalGameTimeSeconds % 60;
	gametimeminutes = totalGameTimeSeconds % 3600;
	gametimeHours = totalGameTimeSeconds / 3600;

	std::cout << "Temps total : " << gametimeHours << "h " << gametimeminutes << "min " << gametimeseconds << "s." << std::endl;


	std::cout << std::endl;
	// Exercice 5 – ASCII voisins
	std::cout << "Exercice 5 , ASCII voisins" << std::endl;

	char charInput;
	int charAscii;
	int charAsciiNext;
	int charAsciiBefore;

	std::cout << "Saisir un caractere : \n -> ";
	std::cin >> charInput;

	charAscii = (int)charInput;
	charAsciiNext = charAscii + 1;
	charAsciiBefore = charAscii - 1;

	std::cout << "Code ASCII de " << charInput << " : " << charAscii << ". Avant : " << (char)charAsciiBefore << ", apres : " << (char)charAsciiNext << "." << std::endl;

	return 0;
}

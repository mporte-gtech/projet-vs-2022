#include <iostream>

void ShowPercentage(int percentage);
int scoreCalcul(int kills, int deaths);

int main()
{
    /*int fileOriginalSize = 0;
    int fileOctetSize = 0;
    int fileBiteSize = 0;

    std::cout << "Quelle est la taille du fichier en kilo-octets ? : \n -> ";
    std::cin >> fileOriginalSize;

    fileOctetSize = fileOriginalSize * 1024;
    fileBiteSize = fileOctetSize * 8;

    std::cout << "Fichier : " << fileOctetSize << " octets, soit " << fileBiteSize << " bits." << std::endl;*/


    /*
    float f = 1.5f;
    int i = (int)f;

    std::cout << i << std::endl;


    /*
    float spentAmount;
    int gamesBought;

    std::cout << "Quel est le montant total depense ? \n -> ";
    std::cin >> spentAmount;

    std::cout << "Combien de jeux ont ete achetes ? \n -> ";
    std::cin >> gamesBought;

    float moneyPerGame = (float) spentAmount / gamesBought;

    std::cout << "Prix moyen par jeu : " << moneyPerGame << " euros." << std::endl;*/


    /*
    char charInput;
    int charAscii;

    std::cout << "Saisir un caractere : \n-> ";
    std::cin >> charInput;

    charAscii = (int)charInput;

    std::cout << "Code ASCII du caractere " << charInput << " : " << charAscii << std::endl;*/


    /*
    int victoryProportion;

    std::cout << "Taux de réussite sur 100 : \n-> ";
    std::cin >> victoryProportion;

    if (victoryProportion < 50)
    {
        std::cout << "Rang :" << "Bronze" << std::endl;
    }
    else if (victoryProportion < 70)
    {
        std::cout << "Rang :" << "Argent" << std::endl;
    }
    else if (victoryProportion < 90)
    {
        std::cout << "Rang :" << "Or" << std::endl;
    }
    else
    {
        std::cout << "Rang :" << "Legende" << std::endl;
    }*/


    /*
    int currentBooked;
    int premiumCard;

    std::cout << "Nombre d’emprunts en cours ? \n-> ";
    std::cin >> currentBooked;

    if (currentBooked < 3)
    {
        std::cout << "Autorise \n-> ";
    }
    else
    {
        std::cout << "Carte premium ? 1 ou 0 \n-> ";
        std::cin >> premiumCard;

        if (premiumCard == 1 && currentBooked < 5)
        {
            std::cout << "Autorise \n-> ";
        }
        else
        {
            std::cout << "Refuse \n-> ";
        }
    }*/


    /*
    int firstInput;
    int secondInput;
    char calcul;
    int result = NULL;

    std::cout << "a ? \n-> ";
    std::cin >> firstInput;

    std::cout << "b ? \n-> ";
    std::cin >> secondInput;

    std::cout << "operateur (+ - * /) ? \n-> ";
    std::cin >> calcul;

    if (calcul == '+')
    {
        result = firstInput + secondInput;
    }
    else if (calcul == '-')
    {
        result = firstInput - secondInput;
    }
    else if (calcul == '*')
    {
        result = firstInput * secondInput;
    }
    else if (calcul == '/')
    {
        result = firstInput / secondInput;
    }

    std::cout << firstInput << " " << calcul << " " << secondInput << " = " << result << std::endl;*/


    /*
    int lastInput = -1;

    while (lastInput < 0)
    {
        std::cout << "Nombre ? \n-> ";
        std::cin >> lastInput;
    }

    std::cout << "Dernier nombre saisi : " << lastInput << std::endl;*/

    /*
    int missionAmount;
    int scoreMission;
    int totalScore = 0;

    std::cout << "Nombre de missions ? \n-> ";
    std::cin >> missionAmount;

    for (int i = 1; i <= missionAmount; i++)
    {
        std::cout << "Score de la mission " << i << " ? \n->";
        std::cin >> scoreMission;

        totalScore += scoreMission;
    }

    std::cout << "Score total : " << totalScore << std::endl;*/
    
    /*
    int percentage;

    std::cout << "Pourcentage ? \n-> ";
    std::cin >> percentage;

    ShowPercentage(percentage);*/


    /**/
    int killsFirstRound;
    int deathsFirstRound;
    int killsSecondRound;
    int deathsSecondRound;
    int totalScore = 0;

    std::cout << "Kills (manche 1) ? \n-> ";
    std::cin >> killsFirstRound;
    std::cout << "Deaths (manche 1) ? \n-> ";
    std::cin >> deathsFirstRound;

    std::cout << "Kills (manche 2) ? \n-> ";
    std::cin >> killsSecondRound;
    std::cout << "Deaths (manche 2) ? \n-> ";
    std::cin >> deathsSecondRound;

    totalScore = scoreCalcul(killsFirstRound, deathsFirstRound) + scoreCalcul(killsSecondRound, deathsSecondRound);

    std::cout << "Score total : " << totalScore << std::endl;



    return 0;
}

void ShowPercentage(int percentage)
{
    std::cout << "[";

    for (int i = 10; i <= percentage && i <= 100; i +=10)
    {
        std::cout << "#";
    }
    for (int i = percentage; i < 100; i += 10)
    {
        std::cout << ".";
    }

    std::cout << "] " << percentage << "%" << std::endl;
}

int scoreCalcul(int kills, int deaths)
{
    int points = kills * 50 - deaths * 30;

    if (points < 0)
    {
        points = 0;
    }

    if (points > 1000)
    {
        points = 1000;
    }

    return ;
}



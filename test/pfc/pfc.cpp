#include <iostream>
#include <cstdlib>
#include <time.h>

void PlayGame();
void GetPlayerMove(int* movePointer);
void GetAiMove(int* movePointer);

int main()
{
    std::cout << "Hello World!\n";
}


void PlayGame()
{
    
}

void GetPlayerMove(int* movePointer)
{
    int playerMove;

    do
    {
        std::cout << "Pierre, Papier,  ? \n-> ";
        std::cin >> playerMove;

        if ()
        {

        }
        else if ()
        {

        }
        else if ()
        {

        }
        else
        {

        }
    } while (!playerMove || playerMove < 1 || 3 < playerMove);
}

void GetAiMove(int* movePointer)
{
    srand(time(NULL));
    *movePointer = (rand() % 3)+1;
}

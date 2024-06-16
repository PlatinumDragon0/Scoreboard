#include <iostream>
#include <string>
#include <algorithm>


class PlayerScoreboard
{
private:

    std::string Names;
    int Scores;

public:

    PlayerScoreboard(int count)
    {
        std::cout << "Name of player " << count + 1 << " is: ";
        std::cin >> Names;
        std::cout << "Score of player " << count + 1 << " is: ";
        std::cin >> Scores;
    }
    
    int GetScore()
    {
        return Scores;
    }

    void GetNames()
    {
        std::cout << Names;
    }
};

// An optimized version of Bubble Sort
void bubbleSort(PlayerScoreboard* arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j]->GetScore() > arr[j + 1]->GetScore())
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}


int main()
{
    //Initialization
    int S;
    std::cout << "Number of player: ";
    std::cin >> S ;

    PlayerScoreboard** PlayerArray = new PlayerScoreboard*[S];

    //Get values
    for (int i = 0 ; i < S ; i++)
    {
        PlayerArray[i] = new PlayerScoreboard(i);
    }

    //Call a function
    bubbleSort(PlayerArray, S);

    std::cout << "\n" << "Scoreboard:" << "\n";

    //Output
    for (int i = S-1; i >= 0; --i)

    {

        PlayerArray[i]->GetNames();
        std::cout << ": ";
        std::cout << PlayerArray[i]->GetScore()<< "\n";

    }

    //Memory cleaning
    delete[S] PlayerArray;
    PlayerArray = nullptr;
}
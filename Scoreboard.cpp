#include <iostream>
#include <string>
#include <algorithm>


// An optimized version of Bubble Sort
void bubbleSort(int arr[], std::string sarr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                std::swap(sarr[j], sarr[j + 1]);
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

    std::string* NameArray = new std::string[S];
    int* ScoreArray = new int[S];


    
    //Get values
    for (int i = 0 ; i < S ; i++)
    {
        std::cout << "Name of player "<< i + 1 <<" is: ";
        std::cin >> NameArray[i];
        std::cout << "Score of player " << i + 1 << " is: ";
        std::cin >> ScoreArray[i];
    }

    //Call a function
    bubbleSort(ScoreArray, NameArray, S);

    std::cout << "\n" << "Scoreboard:" << "\n";

    //Output
    int n = 0;
    for (int i = S-1; i >= 0; i--)
    {
        n++;
        std::cout << n << ". " << NameArray[i] << ": " << ScoreArray[i];
        if (ScoreArray[i] < 10) 
        {
            std::cout << " (skill issue)";
        }
        std::cout << "\n";
    }

    //Memory cleaning
    delete[S] NameArray;
    delete[S] ScoreArray;
    NameArray = nullptr;
    ScoreArray = nullptr;
}
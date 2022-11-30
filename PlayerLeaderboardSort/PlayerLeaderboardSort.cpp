#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <chrono>

#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "TablePrint.h"

using namespace std::chrono;

void printMenu();
void activateSort(int chosenSortMethod);

std::vector<int> sortedKeys;
std::unordered_map<int, std::pair<std::string,int>> playerMap; //int is playerID

std::vector<std::string> sortTypeList = { "Selection Sort",
                                          "Bubble Sort",
                                          "Insertion Sort",
                                          "Quick Sort",
                                          "Merge Sort" };

int main()
{
    std::cout << "Obtaining player list file..." << std::endl;
    std::ifstream playersFile;
    playersFile.open("PlayerList.txt");
    if (!playersFile.is_open()) {
        std::cout << "Player list failed to open!";
        return 1;
    }

    //Get line count of file and convert each line into a map<playerID,pair<"playerName",playerScore>>
    int lineCount = 0;
    std::string tempString;
    while (!playersFile.eof()) {
        std::getline(playersFile, tempString);
        lineCount++;
        
        size_t firstWhitespace = tempString.find(' ');
        size_t lastWhitespace = tempString.rfind(' ');
        int playerID = stoi(tempString.substr(0, firstWhitespace));
        int playerScore = stoi(tempString.substr(lastWhitespace + 1));
        
        //lastWhitespace changes due to if playerID gets larger, so have to substract firstWhitespace from it since that changes correctly, why? Also why do I have to subtract 5 afterwards too?
        std::string playerName = tempString.substr(firstWhitespace + 3, lastWhitespace - firstWhitespace - 5);
        std::pair<std::string, int > playerStats;
        playerStats.first = playerName;
        playerStats.second = playerScore;

        playerMap[lineCount] = (playerID, playerStats);
    }
    
    playersFile.close();

    std::cout << "Player list Obtained." << std::endl
        << "The list has " << lineCount << " number of entries." << std::endl
        << "Which sorting algorithm do you want to use?" << std::endl;

    printMenu();

    int choice;
    std::cin >> choice;

    
    system("CLS"); //Clears the console window

    //Using chrono in the main cpp allows simplicity, but is understood that the activateSort() and its switch statement will add to the time.
    auto chronoOld = steady_clock::now();

    activateSort(choice);

    auto chronoDuration = steady_clock::now() - chronoOld;

    printTable(playerMap,sortedKeys);

    std::cout << "\nDuration of Sort: " << duration_cast<microseconds>(chronoDuration).count() << " microseconds\n";

    return 0;
}

void printMenu() {
    int count = 1;
    for (std::string sortType : sortTypeList) {
        std::cout << " " << std::setw(2) << std::left << count << ": " << sortTypeList[count - 1] << std::endl;
        count++;
    }
}

void activateSort(int chosenSortMethod) { //What is a better way to do this? What if I want to add more choices ro the menu? I wouldn't want a huge switch statement...
    if (chosenSortMethod > sortTypeList.size()) {
        std::cout << "Bad Input.";
        return;
    }
    
    switch (chosenSortMethod) { //Activates corresponding sort method based on int input
    case 1:
        sortedKeys = SelectionSort(playerMap);
        break;
    case 2:
        sortedKeys = BubbleSort(playerMap);
        break;
    case 3:
        sortedKeys = InsertionSort(playerMap);
        break;
    case 4:
        sortedKeys = QuickSort(playerMap);
        break;
    case 5:
        sortedKeys = MergeSort(playerMap);
        break;
    }
    std::cout << "Sorting using " << sortTypeList[chosenSortMethod - 1] << "..." << std::endl;
}
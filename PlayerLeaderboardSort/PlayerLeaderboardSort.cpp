#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include "BucketSort.h"
#include "CombSort.h"
#include "ShellSort.h"

void printMenu();
void activateSort(int chosenSortMethod);

std::unordered_map<int, std::pair<std::string,int>> playerMap; //int is playerID

std::vector<std::string> sortTypeList = { "Selection Sort",
                                          "Bubble Sort",
                                          "Insertion Sort",
                                          "Quick Sort",
                                          "Merge Sort",
                                          "Counting Sort",
                                          "Radix Sort",
                                          "Bucket Sort",
                                          "Comb Sort",
                                          "Shell Sort" };

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
    }

    //playersFile.clear();
    playersFile.close();

    std::cout << "Player list Obtained." << std::endl
        << "The list has " << lineCount << " number of entries." << std::endl
        << "Which sorting algorithm do you want to use?" << std::endl;

    printMenu();

    int choice;
    std::cin >> choice;

    
    system("CLS"); //Clears the console window

    activateSort(choice);

    system("pause");

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
        SelectionSort();
        break;
    case 2:
        BubbleSort();
        break;
    case 3:
        InsertionSort();
        break;
    case 4:
        QuickSort();
        break;
    case 5:
        MergeSort();
        break;
    case 6:
        CountingSort();
        break;
    case 7:
        RadixSort();
        break;
    case 8:
        BucketSort();
        break;
    case 9:
        CombSort();
        break;
    case 10:
        ShellSort();
        break;
    }
    std::cout << "Sorting using " << sortTypeList[chosenSortMethod - 1] << "..." << std::endl;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "SelectionSort.h"
#include "BubbleSort.h"

//#include "sortingMethods.h"

void printMenu();
void activateSort(int chosenSortMethod);

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

    //Get line count of file
    int lineCount = 0;
    std::string tempString;
    while (!playersFile.eof()) {
        std::getline(playersFile, tempString);
        lineCount++;
    }

    playersFile.clear(); //Resets pointer to be back at the beginning of the file
    playersFile.seekg(0);

    std::cout << "Player list Obtained." << std::endl
        << "The list has " << lineCount << " number of entries." << std::endl
        << "Which sorting algorithm do you want to use?" << std::endl;

    printMenu();

    int choice;
    std::cin >> choice;

    
    system("CLS"); //Clears the console window

    activateSort(choice);

    system("pause");

    playersFile.close();
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
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    }
    std::cout << "Sorting using " << sortTypeList[chosenSortMethod - 1] << "..." << std::endl;
}
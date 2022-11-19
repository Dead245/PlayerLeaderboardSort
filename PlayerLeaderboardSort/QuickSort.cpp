#include <string>
#include <vector>
#include <unordered_map>
#include "QuickSort.h"

void QuickSortRecursion(std::unordered_map<int, std::pair<std::string, int>>& mp, int low, int high);

std::vector<int> keySort; //keys are the PlayerIDs - will be sorted by highest playerScore

std::vector<int> QuickSort(std::unordered_map<int, std::pair<std::string, int>>& mp) {

	//convert map keys into vector to use Quick Sort
	for (auto item : mp) {
		keySort.push_back(item.first);
	}

	//Quick Sort by highest playerScore
	QuickSortRecursion(mp, 0, mp.size()-1);

	return keySort;
}

void QuickSortRecursion(std::unordered_map<int, std::pair<std::string, int>>& mp, int low, int high) {
	if (low >= high) {
		return;
	}

	//Find pivot
	int pivot = keySort[high];
	int pivotIndex = low;

	for (int i = low; i < high; i++) {
		if (mp[keySort[i]].second > mp[pivot].second) {
			std::swap(keySort[i], keySort[pivotIndex]);
			pivotIndex++;
		}
	}
	std::swap(keySort[high], keySort[pivotIndex]);

	//Recursion
	QuickSortRecursion(mp,low, pivotIndex - 1);
	QuickSortRecursion(mp, pivotIndex + 1,high);
}
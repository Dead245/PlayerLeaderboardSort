#include <vector>
#include <unordered_map>
#include <string>
#include "BubbleSort.h"

std::vector<int> BubbleSort(std::unordered_map<int, std::pair<std::string, int>>& mp) {
	std::vector<int> keySort; //keys are the PlayerIDs - will be sorted by highest playerScore

	//convert map keys into vector to use Bubble Sort
	for (auto item : mp) {
		keySort.push_back(item.first);
	}

	//Bubble sort by highest playerScore
	for (int a = 0; a < mp.size() - 1; a++) {
		for (int b = 0; b < mp.size() - a - 1; b++) {
			if (mp[keySort[b]].second < mp[keySort[b + 1]].second) {
				std::swap(keySort[b], keySort[b + 1]);
			}
		}
	}
	return keySort;
}
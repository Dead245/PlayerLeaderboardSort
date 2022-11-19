#include <string>
#include <vector>
#include <unordered_map>
#include "InsertionSort.h"

std::vector<int> InsertionSort(std::unordered_map<int, std::pair<std::string, int>>& mp) {
	std::vector<int> keySort; //keys are the PlayerIDs - will be sorted by highest playerScore
	int index, value;

	//convert map keys into vector to use Insertion Sort
	for (auto item : mp) {
		keySort.push_back(item.first);
	}

	//Insertion Sort by highest playerScore
	for (int i = 0; i < mp.size(); i++) {
		value = keySort[i];
		index = i;
		while (index > 0 && mp[keySort[index-1]].second < mp[value].second) {
			keySort[index] = keySort[index - 1];
			index--;
		}
		keySort[index] = value;
	}
	return keySort;
}

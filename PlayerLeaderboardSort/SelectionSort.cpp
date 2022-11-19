#include <string>
#include <vector>
#include <unordered_map>
#include "SelectionSort.h"

//Creates a sorted vector of keys for the unordered_map using Selection Sort
std::vector<int> SelectionSort(std::unordered_map<int, std::pair<std::string, int>> &mp) {
	std::vector<int> keySort; //keys are the PlayerIDs - will be sorted by highest playerScore
	int highestNum;

	//convert map keys into vector to use Selection Sort
	for (auto item : mp) {
		keySort.push_back(item.first);
	}

	//Selection Sort by highest playerScore
	for (int a = 0; a < mp.size() - 1; a++) {
		highestNum = a;
		for (int b = a + 1; b <= mp.size() - 1; b++) {
			if (mp[keySort[b]].second > mp[keySort[highestNum]].second) {
				highestNum = b;
			}
		}
		std::swap(keySort[highestNum],keySort[a]);
	}
	return keySort;
}
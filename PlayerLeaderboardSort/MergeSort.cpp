#include <string>
#include <vector>
#include <unordered_map>
#include "MergeSort.h"

void MergeSortRecursion(std::unordered_map<int, std::pair<std::string, int>>& mp, std::vector<int>& keySort, int left, int right);
void Merge(std::unordered_map<int, std::pair<std::string, int>>& mp, std::vector<int>& keySort, int left, int middle, int right);


std::vector<int> MergeSort(std::unordered_map<int, std::pair<std::string, int>>& mp) {
	std::vector<int> keySort; //keys are the PlayerIDs - will be sorted by highest playerScore
	
	//convert map keys into vector to use Merge Sort
	for (auto item : mp) {
		keySort.push_back(item.first);
	}

	//Merge Sort by highest playerScore
	MergeSortRecursion(mp,keySort,0,mp.size()-1);

	return keySort;
}

void MergeSortRecursion(std::unordered_map<int, std::pair<std::string, int>>& mp, std::vector<int>& keySort, int left, int right) {
	if (left >= right) return;

	int middle = left + (right - left) / 2;
	MergeSortRecursion(mp, keySort, left, middle);
	MergeSortRecursion(mp, keySort, middle + 1, right);
	Merge(mp, keySort, left, middle, right);
}

void Merge(std::unordered_map<int, std::pair<std::string, int>>& mp, std::vector<int>& keySort, int left,int middle, int right) {

	int leftLength = middle - left + 1;
	int rightLength = right - middle;
	
	std::vector<int> tempLeft;
	tempLeft.resize(leftLength);
	
	std::vector<int> tempRight;
	tempRight.resize(rightLength);

	for (int i = 0; i < leftLength; i++) {
		tempLeft[i] = keySort[left + i];
	}

	for (int i = 0; i < rightLength; i++) {
		tempRight[i] = keySort[middle + 1 + i];
	}

	int a, b, c;
	for (a = 0, b = 0, c = left; c <= right; c++) {
		if ((a < leftLength) && (b >= rightLength || mp[tempLeft[a]].second >= mp[tempRight[b]].second)) {
			keySort[c] = tempLeft[a];
			a++;
		}
		else {
			keySort[c] = tempRight[b];
			b++;
		}
	}
}
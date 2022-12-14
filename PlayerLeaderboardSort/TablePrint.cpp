#include <unordered_map>
#include <iostream>
#include <iomanip>

//Doesn't break as long as no input in the map is greater than 15 characters...
void printTable(std::unordered_map<int, std::pair<std::string, int>> mp, std::vector<int> sortedKeys) {
	std::cout << std::setw(15) << std::left<< "Player ID"
		<< "|" << std::setw(15) << std::left << "Player Name"
		<< "|" << std::setw(15) << std::left << "Player Score" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "" << std::endl << std::setfill(' ');

	for (int key : sortedKeys) {
		std::cout << std::setw(15) << std::left << key
			<< "|" << std::setw(15) << std::left << mp[key].first
			<< "|" << std::setw(15) << std::left << mp[key].second << std::endl;
	}
}
#include <map>
#include <iostream>
#include <iomanip>

//Doesn't break as long as no input in the map is greater than 15 characters...
void printTable(std::map<int, std::pair<std::string, int>> mp) {
	std::cout << std::setw(15) << std::left<< "Player ID"
		<< "|" << std::setw(15) << std::left << "Player Name"
		<< "|" << std::setw(15) << std::left << "Player Score" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "" << std::endl << std::setfill(' ');

	for (auto item : mp) {
		std::cout << std::setw(15) << std::left << item.first
			<< "|" << std::setw(15) << std::left << item.second.first
			<< "|" << std::setw(15) << std::left << item.second.second << std::endl;
	}
}
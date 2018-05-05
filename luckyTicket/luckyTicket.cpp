// luckyTicket.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <regex>

#define FORWARD 1
#define BACKWARDS 0

int max = 999999;
int min = 0;

std::regex checkMask("(\\d\\d\\d\\d\\d\\d)");
std::regex splitMask("\\d\\d\\d");
std::regex numberMask("\\d");

std::string fixStr(std::string data)
{
	int difference = 6 - data.size();
	for (int i = 0; i != difference; i++) {
		data.insert(0, "0");
	}
	return data;
}

bool checkInput(int &value)
{
	std::string data = std::to_string(value);
	data = fixStr(data);
	return std::regex_match(data, checkMask);
}

std::vector<int> splitInput(int value)
{
	std::vector<int> numbers;
	std::smatch match;
	std::string data = std::to_string(value);
	data = fixStr(data);
	while (std::regex_search(data, match, splitMask)) {
		numbers.push_back(std::stoi(match[0]));
		data = match.suffix().str();
	}

	return numbers;
}

int calculateSumVal(int input)
{
	int result = 0;
	std::smatch match;
	std::string data = std::to_string(input);
	data = fixStr(data);
	while (std::regex_search(data, match, numberMask)) {
		result += std::stoi(match[0]);
		data = match.suffix().str();
	}
	return result;
}

bool isLuckyNumber(int value)
{
	std::vector<int> splitValues = splitInput(value);
	
	if (calculateSumVal(splitValues[0]) == calculateSumVal(splitValues[1]))
		return true;
	else
		return false;
}

int find(int baseValue, bool d)
{
	int step = 0;
	int direction = 1;

	if (d)
		direction = 1;
	else
		direction = -1;

	while (true)
	{
		if (!isLuckyNumber(baseValue)) {
			baseValue += direction;
		} else if(baseValue > max || baseValue < min){
			std::cout << "Error. No lucky ticket found\n";
			break;
		} else {
			std::string strValue = fixStr(std::to_string(baseValue));
			std::cout << (d ? " + " : " - ") << std::to_string(step) << " = " << strValue << std::endl;
			break;
		}
		step++;
	}
	return baseValue;
}

int main(int argc, char *argv[])
{
	
	if (argc != 2) {
		std::cout << "Erorr. Invalid input.\n";
		return 0;
	}

	int input = std::stoi(argv[1]);

	if (!checkInput(input)) {
		std::cout << "Erorr. Invalid input.\n";
		return 0;
	}

	std::cout << fixStr(std::to_string(input));
	find(input, FORWARD);

	std::cout << fixStr(std::to_string(input));
	find(input, BACKWARDS);
	system("pause");
    return 0;
}
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

//1 zad
std::unordered_map<std::string, unsigned> countWords(const std::vector<std::string>& words)
{
	std::unordered_map<std::string, unsigned> table;
	for (const std::string& word : words)
		table[word]++;
	return table;
}
void printWordCount(const std::unordered_map<std::string, unsigned>& words)
{
	for (const std::pair<std::string, unsigned>& el : words)
		std::cout << el.first << ": " << el.second << std::endl;
}

//2 zad
std::unordered_map<std::string, std::vector<std::string>> categorize(const std::vector<std::pair<std::string, std::string>>& objects)
{
	std::unordered_map<std::string, std::vector<std::string>> table;
	for (const std::pair<std::string, std::string>& el : objects)
		table[el.second].push_back(el.first);
	return table;
}

void printCategories(const std::unordered_map<std::string, std::vector<std::string>>& table)
{
	for (const std::pair<std::string, std::vector<std::string>>& el : table)
	{
		std::cout << el.first << ": {";
		for (const std::string& obj : el.second)
			std::cout << obj << " ";
		std::cout << "}" << std::endl;
	}

}

using std::string;
using std::vector;
using std::unordered_map;
using std::pair;
//3 zad
unordered_map<char, char> insertRules(const vector<pair<char, char>>& rules)
{
	unordered_map<char, char> systematicRules;
	for (const pair<char, char>& rule : rules)
		systematicRules[rule.first] = rule.second;
	return systematicRules;
}

void changeText(const unordered_map<char, char>& rules, string& text)
{
	for (char& symbol : text)
	{
		unordered_map<char, char>::const_iterator it = rules.find(symbol);
		if (it != rules.end())
			symbol = (*it).second;
	}
}

//5 zad
void printPair(pair<int, int> pair)
{
	std::cout << "(" << pair.first << ", " << pair.second << ") ";
}
void findAllSymmetricalPairs(const vector<pair<int, int>>& pairs)
{
	std::unordered_map<int, int> map;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		int first = pairs[i].first;
		int second = pairs[i].second;
		if (map.find(second) != map.end() && map[second] == first)
		{

			printPair(pair<int, int>(second, first));
			printPair(pairs[i]);
			std::cout << std::endl;
		}
		map[first] = second;
	}
}

//6 zad
bool areIzomorph(const string& word1, const string& word2)
{
	unordered_map<char, char> map;
	if (word1.size() != word2.size())
		return false;
	for (size_t i = 0; i < word1.size(); i++)
	{
		if (map.find(word1[i]) != map.end() && map[word1[i]] != word2[i])
			return false;
		if (map.find(word2[i]) != map.end() && map[word2[i]] != word1[i])
			return false;
		map[word1[i]] = word2[i];
		map[word2[i]] = word1[i];
	}
	return true;
}

int main()
{
	//1 zad
	std::vector<std::string> words = { "apple", "banana", "apple", "orange", "banana", "apple" };
	std::unordered_map<std::string, unsigned> table1 = countWords(words);
	printWordCount(table1);

	//2 zad
	std::vector<std::pair<std::string, std::string>> objects = { {"apple", "fruit"}, {"carrot", "vegetable"}, {"banana", "fruit"}, {"broccoli", "vegetable"} };
	printCategories(categorize(objects));

	//3 zad
	string text = "hello world";
	vector<pair<char, char>> rules = { {'h', 'H'}, {'o', '0'}, {'e', '3'} };
	unordered_map<char, char> tableRules = insertRules(rules);
	changeText(tableRules, text);
	std::cout << text << std::endl;

	//4 zad
	vector<int> numbers = { 8, 7, 2, 5, 3, 1 };
	int sum = 10;
	unordered_map<int, size_t> map;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		int complement = sum - numbers[i];
		if (map.find(complement) != map.end())
		{
			std::cout << "(" << map[complement] << ", " << i << ") ";
		}
		map[numbers[i]] = i;
	}
	std::cout << std::endl;

	//5 zad
	vector<pair<int, int>> pairs = { {3, 4}, {1, 2}, {5, 2}, {7, 10}, {4, 3}, {2, 5} };
	findAllSymmetricalPairs(pairs);

	//6 zad
	string word1 = "ACAB", word2 = "XCXX";
	string word3 = "ACCB", word4 = "XBBY";
	std::cout << areIzomorph(word1, word2) << areIzomorph(word3, word4) << std::endl;

	return 0;
}
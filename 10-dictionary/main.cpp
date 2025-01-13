#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::pair;
/*
class PublicTransportSystem
{
	struct BusStop;

	struct BusLine
	{
		int number;
		vector<BusStop*> path;
		vector<vector<int>> courses;
	};

	struct BusStop
	{
		int number;
		vector<BusLine*> lines;
	};
};
*/
//1 zad
vector<pair<int, int>> findAllPairs(const vector<int>& numbers, int X)
{
	unordered_map<int, vector<int>> map;
	vector<pair<int, int>> result;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (map.count(numbers[i]) == 0)
		{
			map.insert({ numbers[i], {i} });
		}
		else
		{
			map[numbers[i]].push_back(i);
		}
	}

	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (map.count(X - numbers[i]))
		{
			for (size_t j = 0; j < map[X - numbers[i]].size(); j++)
			{
				result.push_back({ i, map[X - numbers[i]][j]});
			}
		}
	}
	return result;
}

//2 zad
bool containsAll(const string& word, const unordered_set<char>& set)
{
	for (size_t i = 0; i < word.size(); i++)
	{
		if (set.count(word[i]) == 0)
			return false;
	}
	return true;
}
vector<string> allOneLineStrings(const vector<string>& words)
{
	vector<string> result;
	string line1 = "qwertyuiopQWERTYUIOP";
	string line2 = "asdfghjklASDFGHJKL";
	string line3 = "zxcvbnmZXCVBNM";
	unordered_set<char> set1;
	unordered_set<char> set2;
	unordered_set<char> set3;
	for (size_t i = 0; i < line1.size(); i++)
	{
		set1.insert(line1[i]);
	}
	for (size_t i = 0; i < line2.size(); i++)
	{
		set2.insert(line2[i]);
	}
	for (size_t i = 0; i < line3.size(); i++)
	{
		set3.insert(line3[i]);
	}
	for (size_t i = 0; i < words.size(); i++)
	{
		if (containsAll(words[i], set1) || containsAll(words[i], set2) || containsAll(words[i], set3))
			result.push_back(words[i]);
	}
	return result;
}

//3 zad
int differentCandies(const vector<int>& candyTypes)
{
	size_t candyNumber = candyTypes.size() / 2;
	unordered_set<int> differentTypes;
	for (size_t i = 0; i < candyTypes.size(); i++)
	{
		if (differentTypes.count(candyTypes[i]) == 0)
			differentTypes.insert(candyTypes[i]);
	}
	return std::min(candyNumber, differentTypes.size());
}

//4 zad
bool areAnagram(const string& word1, const string& word2)
{
	if (word1.size() != word2.size())
		return false;
	unordered_map<char, int> map1, map2;
	for (size_t i = 0; i < word1.size(); i++)
	{
		if (map1.count(word1[i]) == 0)
			map1.insert({ word1[i], 1 });
		else
			++map1[word1[i]];
	}

	for (size_t i = 0; i < word2.size(); i++)
	{
		if (map2.count(word2[i]) == 0)
			map2.insert({ word2[i], 1 });
		else
			++map2[word2[i]];
	}
	if (map1.size() != map2.size())
		return false;
	for (pair<char, int> elem : map1)
	{
		if (map2[elem.first] != elem.second)
			return false;
	}

	return true;
}

vector<vector<string>> anagrams(const vector<string>& words)
{
	vector<vector<string>> res;
	unordered_set<string> anagrams;
	for (size_t i = 0; i < words.size(); i++)
	{
		if (anagrams.count(words[i]) == 0)
			anagrams.insert(words[i]);
	}
	return res;
}

int main()
{
	//1 zad
	int X = 10;
	vector<int> numbers = { 1, 1, 9, 9 };
	vector<pair<int, int>> result = findAllPairs(numbers, X);
	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << numbers[result[i].first] << " " << numbers[result[i].second] << std::endl;
	}

	//2 zad
	vector<string> words = { "adsdf", "sfd" };
	vector<string> result2 = allOneLineStrings(words);
	for (size_t i = 0; i < result2.size(); i++)
	{
		std::cout << result2[i] << std::endl;
	}

	//3 zad
	vector<int> types = { 6, 6, 6, 6 };
	std::cout << differentCandies(types) << std::endl;

	//4 zad
	return 0;
}
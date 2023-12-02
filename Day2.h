#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Day2
{
public:
	void Part1();
	void Part2();
	bool possible(string val);
	vector<string> readData();

	int maxcubepossible[3] = { 12, 13, 14 };
	string colors[3] = { "red", "green", "blue" };
};


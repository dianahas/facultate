#include "Utils.h"
#pragma once
#include <sstream>
vector<string> tokenize(const string & str, char delimeter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimeter))
		result.push_back(token);
	return result;
}
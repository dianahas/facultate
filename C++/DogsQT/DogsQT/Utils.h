#pragma once
#include <string>
#include <vector>

/*
Trims leading and trailing spaces from a string.
Input: s - string
Output: a string, with no leading and trailing spaces.
*/
std::string trim(const std::string& s);

/*
Tokenizes a string.
Input:	str - the string to be tokenized.
delimiter - char - the delimiter used for tokenization
Output: tokens - an array of strings, containing the tokens
length - the length of the tokens' array.
*/
std::vector<std::string> tokenize(const std::string& str, char delimiter);

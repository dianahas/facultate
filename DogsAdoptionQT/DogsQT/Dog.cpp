#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>
#include <vector>
#include <iostream>
#include "Utils.h"

using namespace std;

Dog::Dog() : breed(""), name(""), age(-1), photograph("") {}

Dog::Dog(const std::string & breed, const std::string & name, const int age, const std::string & photograph)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}

void Dog::show()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}

istream & operator >> (istream & is, Dog & d)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4) // make sure all the starship data was valid
		return is;

	d.breed = tokens[0];
	d.name = tokens[1];
	//vector<string> ageTokens = tokenize(tokens[2], ',');
	d.age = (stod(tokens[2]));
	d.photograph = tokens[3];
	return is;
}

ostream & operator<<(ostream & os, const Dog & d)
{
	os << d.breed << "," << d.name << "," << d.age << "," << d.photograph << endl;
	return os;
}

#include "User.h"
#include <fstream>
#include "Utils.h"
using namespace std;

User::User() {}

User::User(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
}

istream & operator >> (istream & is, User & u)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 2)
		return is;
	u.name = tokens[0];
	u.type = tokens[1];

	return is;
}

ostream & operator<<(ostream & os, User & u)
{
	os << u.name << "," << u.type << "," << endl;
	return os;
}

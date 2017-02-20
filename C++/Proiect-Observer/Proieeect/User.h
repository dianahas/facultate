#pragma once
#include <string>
using namespace std;

class User
{
private:
	std::string name;
	std::string type;

public:
	User();
	User(std::string name, std::string type);

	std::string getName()
	{
		return name;
	}

	std::string getType()
	{
		return type;
	}
	
	friend istream &operator >> (istream &is, User &u);
	friend ostream &operator << (ostream &os, User &u);
};
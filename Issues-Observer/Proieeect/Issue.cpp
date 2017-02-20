#include "Issue.h"
#include "Utils.h"

Issue::Issue() {}

Issue::Issue(std::string description, std::string status, std::string reporter, std::string solver)
{
	this->description = description;
	this->reporter = reporter;
	this->status = status;
	this->solver = solver;
}

istream & operator >> (istream & is, Issue & u)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;
	u.description = tokens[0];
	u.status = tokens[1];
	u.reporter = tokens[2];
	u.solver = tokens[3];

	return is;
}

ostream & operator<<(ostream & os, Issue & u)
{
	os << u.description << "," << u.status << "," << u.reporter << "," << u.solver << endl;
	return os;
}

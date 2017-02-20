#pragma once
#include <string>
#include <fstream>
using namespace std;
class Issue
{
private:
	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;

public:
	Issue();
	Issue(std::string description, std::string status, std::string reporter, std::string solver);

	std::string getDescription()
	{
		return description;
	}

	std::string getStatus()
	{
		return status;
	}

	std::string getReporter()
	{
		return reporter;
	}

	std::string getSolver()
	{
		return solver;
	}

	void setSolver(std::string solvr)
	{
		this->solver = solvr;
	}

	void setStatus(std::string stat)
	{
		this->status = stat;
	}

	friend istream &operator >> (istream &is, Issue &u);
	friend ostream &operator << (ostream &os, Issue &u);
};
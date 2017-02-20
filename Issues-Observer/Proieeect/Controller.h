#pragma once
#include "Repository.h"
#include "Observer.h"

class Controller :public Observable
{
private:
	Repository &repo;

public:
	Controller(Repository &repo) :repo{ repo } {};

	Repository getRepo()
	{
		return repo;
	}

	void addIssue(std::string &description, std::string &status, std::string &reporter, std::string &solver);
	void removeIssue(std::string &description, std::string &status, std::string &reporter, std::string &solver);
	void updateIssue(std::string &description, std::string &status, std::string &reporter, std::string &solver);
};
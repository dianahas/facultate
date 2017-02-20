#pragma once
#include "User.h"
#include "Issue.h"
#include <vector>
#include "exe.h"

class Repository
{
private:
	std::vector<User> users;
	std::vector<Issue> issues;
	std::string filename1;
	std::string filename2;

public:
	Repository(std::string filename1, std::string filename2);
	std::vector<User> getUsers()
	{
		return users;
	}
	std::vector<Issue> getIssues()
	{
		return sort(issues);
	}
	int find(std::string &descr);
	void readFromFile1();
	void readFromFile2();
	/*
	description: adds an object of type issue to the list of issues
	input: i of type issue
	output: the element is added only if its not already in the list
	*/
	void addIssue(Issue &i);
	/*
	description: removes an object of type issue from the list of issues
	input: i of type issue
	output: the element is removed only if its in the list
	*/
	void removeIssue(Issue &i);
	/*
	description: adds an object of type issue to the list of issues
	input: i of type issue
	output: the element is added only if its not already in the list
	*/
	void updateIssue(Issue &i);
	void writeToFile();
	vector<Issue> sort(vector<Issue> iss);
};
#include "Controller.h"

void Controller::addIssue(std::string &description, std::string &status, std::string &reporter, std::string &solver)
{
	Issue i{ description,status,reporter,solver };
	this->repo.addIssue(i);
	this->notify();
}

void Controller::removeIssue(std::string & description, std::string & status, std::string & reporter, std::string & solver)
{
	Issue i{ description,status,reporter,solver };
	this->repo.removeIssue(i);
	this->notify();
}

void Controller::updateIssue(std::string & description, std::string & status, std::string & reporter, std::string & solver)
{
	Issue i{ description,status,reporter,solver };
	this->repo.updateIssue(i);
	this->notify();
}

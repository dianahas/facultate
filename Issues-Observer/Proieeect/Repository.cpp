#include "Repository.h"
#include <qmessagebox.h>
#include <assert.h>
Repository::Repository(std::string filename1, std::string filename2)
{
	this->filename1=filename1;
	this->readFromFile1();
	this->filename2 = filename2;
	this->readFromFile2();
}

int Repository::find(std::string & descr)
{
	for (int i = 0; i < this->issues.size(); i++)
		if (this->issues[i].getDescription() == descr)
			return i;
	return -1;
}

void Repository::readFromFile1()
{
	ifstream file("users.txt");

	if (!file.is_open())
		throw exception("Couldn't load file");

	User u;
	while(file >> u)
		this->users.push_back(u);
	
	file.close();
}

void Repository::readFromFile2()
{
	ifstream file1("issues.txt");

	if (!file1.is_open())
		throw exception("Couldn't load file");
	Issue t;
	while(file1>>t)
		this->issues.push_back(t);

	file1.close();
}

void Repository::addIssue(Issue & i)
{
	try {
		if (i.getDescription() == "-")
			throw CustomException{ "Another issues with same descr exists" };
		int idx = this->find(i.getDescription());
		if (idx != -1)
			throw CustomException{ "Another issues with same descr exists" };
		this->issues.push_back(i);
		this->writeToFile();
	}
	catch (CustomException &e)
	{
		QMessageBox::warning(NULL, "Error", e.what());
	}
	
}

void Repository::removeIssue(Issue & i)
{
	try {
		int idx = this->find(i.getDescription());
		if (idx == -1)
			throw CustomException{ "no issue with same descr exists" };
		this->issues.erase(this->issues.begin() + idx);
		this->writeToFile();

	}
	catch (CustomException &e)
	{
		QMessageBox::warning(NULL, "Error", e.what());
	}
	
}

void Repository::updateIssue(Issue & i)
{
	try {
		int idx = this->find(i.getDescription());
		if (idx == -1)
			throw CustomException{ "no issue with same descr exists" };
		this->issues[idx].setStatus("closed");
		this->issues[idx].setSolver(i.getSolver());
		this->writeToFile();

	}
	catch (CustomException &e)
	{
		QMessageBox::warning(NULL, "Error", e.what());
	}
	
}

void Repository::writeToFile()
{
	ofstream file_2("issues.txt");

	if (!file_2.is_open())
		throw exception("Couldn't load file");

	for (auto t : this->issues)
	{
		file_2 << t;
	}

	file_2.close();
}

vector<Issue> Repository::sort(vector<Issue> iss)
{
	//vector<Issue> iss = this->issues;
	Issue aux;
	int sort = 0;
	do {
		sort = 0;
		for (int ii = 0; ii < iss.size() - 1; ii++)
			if(this->issues[ii].getStatus()>this->issues[ii + 1].getStatus())
			{
				aux = this->issues[ii];
				this->issues[ii] = this->issues[ii + 1];
				this->issues[ii + 1] = aux;
				sort = 1;
			}
			else if (this->issues[ii].getStatus()==this->issues[ii + 1].getStatus())
					if (this->issues[ii].getDescription()>this->issues[ii+1].getDescription())
				{
					aux = this->issues[ii];
					this->issues[ii] = this->issues[ii + 1];
					this->issues[ii + 1] = aux;
					sort = 1;
				}
	} while (sort == 1);
	return this->issues;
}

void test_repo()
{
	Repository repo{ "users.txt","issues.txt" };
	repo.removeIssue(Issue{ "remove", "closed", "Bianca","ALabala" });
	assert(repo.getIssues().size() == 7);
	repo.addIssue(Issue{ "do", "open", "tt","-" });;
	assert(repo.getIssues().size() == 8);
}

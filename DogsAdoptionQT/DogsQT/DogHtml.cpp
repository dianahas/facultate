#include "DogHtml.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void DogHtml::openFile()
{
	ShellExecuteA(NULL, NULL, "firefox.exe", this->filename.c_str(), NULL, SW_MAXIMIZE);
}

DogHtml::DogHtml()
{
}

DogHtml::DogHtml(std::vector<Dog> list, std::string filename)
{
	this->adoptii = list;
	this->filename = filename;
}

DogHtml::~DogHtml()
{
}

void DogHtml::addAdopt(Dog & d)
{
	this->adoptii.push_back(d);
	this->Write();
}

void DogHtml::Write()
{
	cout << "Am scris\n";
	ofstream f(filename);
	if (!f.is_open())
		cout << "Nu deschis";
	f << "<!DOCTYPE html>\n";
	f << "<html>" << "\n";
	f << "<head>" << "\n";
	f << "<title>Watchlist</title>" << "\n";
	f << "</head>" << "\n";
	f << "<body>" << "\n";
	f << "<table border = 1>" << "\n";
	f << "<tr>" << "\n";
	f << "<td>Breed</td>" << "\n";
	f << "<td>Name</td>" << "\n";
	f << "<td>Age</td>" << "\n";
	f << "<td>Photograph</td>" << "\n";
	f << "</tr>" << "\n";
	for (auto i : this->getAdopt())
	{
		f << "<tr>";
		f << "<td>" << i.getBreed() << "</td>" << "\n";
		f << "<td>" << i.getName() << "</td>" << "\n";
		f << "<td>" << i.getAge() << "</td>" << "\n";
		f << "<td>" << i.getPhoto() << "</td>" << "\n";
		f << "</tr>";
	}
	f << "</table>" << "\n";
	f << "</body>" << "\n";
	f << "</html>" << "\n";
	f.close();
}

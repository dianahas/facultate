#include "DogCSV.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

DogCSV::DogCSV()
{
}

DogCSV::DogCSV(std::vector<Dog> list, std::string filename)
{
	this->adoptii = list;
	this->filename = filename;
}

DogCSV::~DogCSV()
{
}

void DogCSV::addAdopt(Dog& d)
{
	this->adoptii.push_back(d);
	this->Write();
}

void DogCSV::Write()
{
	ofstream f(filename);
	if (!f.is_open())
		cout << "Nu deschis";

	for (auto s : this->adoptii)
	{
		f << s;
	}

	f.close();
}


void DogCSV::openFile()
{
	ShellExecuteA(NULL, NULL, "notepad.exe", this->filename.c_str(), NULL, SW_MAXIMIZE);
}


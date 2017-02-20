#include "DogRepo.h"
#include "Utils.h"
#include <fstream>
#include <string>
#include <algorithm>
#include "RepoExceptions.h"
#include "DogValidator.h"
using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
	this->current = 0;
}

Dog Repository::findByBreedAndName(const std::string& breed, const std::string& name) const
{
	for (auto d : this->dogs)
		if (d.getBreed() == breed && d.getName() == name)
			return d;
	return Dog{};
}

int Repository::addDog(const std::string & breed, const std::string & name, const int age, const std::string & photograph)
{
	Dog d{ breed,name,age,photograph };

	//if (this->findByBreedAndName(breed, name).getBreed() != "")
	if (find(d) != -1)
		throw DuplicateDogException();
	this->dogs.push_back(d);
	this->writeToFile();
	return 1;
}

int Repository::find(Dog & s)
{
	for (int i = 0; i < this->dogs.size(); i++)
		if (this->dogs[i] == s)
			return i;
	return -1;
}

int Repository::deleteDog(const std::string & breed, const std::string & name)
{
	auto pos = std::find_if(this->dogs.begin(), this->dogs.end(), [&](Dog& dog1) {
		if (dog1.getBreed().compare(breed) == 0 && dog1.getName().compare(name) == 0) return 1;
		return 0;
	});
	if (pos != dogs.end())
	{
		this->dogs.erase(pos);
		this->writeToFile();
		return 1;
	}
	else return 0;
}

Dog Repository::returnCurrentDog()
{
	if (this->current == this->dogs.size())
		this->current = 0;
	return this->dogs[this->current];

}

void Repository::nextDog()
{
	this->current++;
	this->current %= this->dogs.size();
	showDog();
}

void Repository::setCurrent()
{
	this->current--;
}

void Repository::showDog()
{
	Dog currentDog = this->returnCurrentDog();
	currentDog.show();
}

int Repository::updateDog(const std::string& newBreed, const std::string& newName, const int newAge, const std::string& newPhotograph)
{
	Dog d{ newBreed, newName, newAge, newPhotograph };
	auto pos = std::find_if(this->dogs.begin(), this->dogs.end(), [&](Dog& dog1) {
		if (dog1.getBreed().compare(newBreed) == 0 && dog1.getName().compare(newName) == 0) return 1;
		return 0;
	});
	//auto poss = std::find(this->dogs.begin(), this->dogs.end(), d);
	if (pos != dogs.end())
	{
		this->dogs[pos - this->dogs.begin()] = d;
		this->writeToFile();
		return 1;
	}
	return 0;
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Dog d;
	while (file >> d)
		this->dogs.push_back(d);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto d : this->dogs)
	{
		file << d;
	}

	file.close();
}

#pragma once
#include "Dog.h"
#include <vector>
class AdoptSortRepo
{
private:
	std::vector<Dog> sorti;
	//std::vector<Dog> repo;
	int curent;
public:
	AdoptSortRepo();

	/*
	Adds a dog to the repository of dogs filtered by breed
	Input: d - An element of type Dog
	Output: 1 - if the dog was sucessfully added
	0 - if the dog could not be added
	*/

	void setDogs(std::vector<Dog> newVector) { sorti = newVector; }

	int addSortAdopt(Dog d);
	Dog returnCurrentDog2();
	void nextDog2();
	void showDog2();

	std::vector<Dog> getSortAdopt() const
	{
		return sorti;
	}
	virtual void openFile();
private:
	virtual void Write();
};


#pragma once
#include "Dog.h"
#include <vector>
//#include <iterator>

class Repository
{
private:
	std::vector<Dog> dogs;
	std::string filename;
	int current;

public:
	Repository(const std::string& filename);

	/// <summary>
	/// Finds the dog with the given name and breed.
	/// </summary>
	/// <param name = "breed">string, the breed of the dog.</param>
	/// <param name = "breed">string, the breed of the dog.</param>
	/// <returns>pos - the position on which the medicine with the given symbols is in the MedRepo; -1 - if the medicine does not exist.</returns>
	Dog findByBreedAndName(const std::string& breed, const std::string& name) const;
	/*
	Adds a dog to the repository of dogs
	Input: d - An element of type Dog
	Output: 1 - if the dog was sucessfully added
	0 - if the dog could not be added
	*/
	int addDog(const std::string & breed, const std::string & name, const int age, const std::string & photograph);
	int find(Dog &s);
	/*
	Removes a dog from the repository of dogs
	Input: d - An element of type Dog
	Output: 1 - if the dog was sucessfully removed
	0 - if the dog was not found in the repository
	*/
	int deleteDog(const std::string & breed, const std::string & name);

	void setCurrent();

	/*
	Updates a dog in the repository of dogs.
	Input: name[] - a string containing the name of the dog
	breed - a string containing the name of the dog
	d - An element of type Dog
	Output: 1 - if the dog was sucessfully updated
	0 - if the dog was not found in the repository
	*/
	int updateDog(const std::string& newBreed, const std::string& newName, const int newAge, const std::string& newPhotograph);

	Dog returnCurrentDog();

	void nextDog();

	void showDog();

	std::vector<Dog>& getDogs()
	{
		return this->dogs;
	}

private:
	void readFromFile();
	void writeToFile();
};

#pragma once
#include <iostream>
#include <string>
#include <vector>

class Dog
{
private:
	std::string breed;
	std::string name;
	int age;
	std::string photograph;

public:
	Dog();
	/*
	Creates a Dog.
	Input: name - name of the dog, string
	breed - breed of the dog, string
	age - positive integer indicating the age of the dog
	photograph - link to the photo of the dog
	Output: a dog
	*/
	Dog(const std::string& breed, const std::string& name, const int age, const std::string& photograph);

	/*
	Gets the breed of the dog.
	Input: -
	Output: string, the breed
	*/
	std::string getBreed() const
	{
		return breed;
	}

	/*
	Gets the name of the dog.
	Input: -
	Output: string, the name
	*/
	std::string getName() const
	{
		return name;
	}

	/*
	Gets the age of the dog.
	Input: -
	Output: int, the age
	*/
	int getAge() const
	{
		return age;
	}

	/*
	Gets the link of the dog.
	Input: -
	Output: string, the link
	*/
	std::string getPhoto() const { return photograph; }

	/*
	Sets a new breed to the dog.
	newBreed - new breed of the dog, string
	Output: -
	*/
	std::string setBreed(std::string& newBreed) { this->breed = newBreed; }

	/*
	Sets a new name to the dog.
	newName - new name of the dog, string
	Output: -
	*/
	std::string setName(std::string& newName) { this->name = newName; }

	/*
	Sets a new age to the dog.
	newAge - new age of the dog, int
	Output: -
	*/
	int setAge(int newAge) { this->age = newAge; }

	/*
	Sets a new link to the dog.
	newPhoto - new link of the dog, string
	Output: -
	*/
	std::string setPhoto(std::string& newPhoto) { this->photograph = newPhoto; }

	void show();

	friend std::istream& operator >> (std::istream& is, Dog& s);
	friend std::ostream& operator<<(std::ostream& os, const Dog& s);

	bool operator==(const Dog& that) {
		return true;
	}
};

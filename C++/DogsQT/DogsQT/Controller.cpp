#include "Controller.h"
#include <algorithm>

int Controller::addDogtoRepo(const std::string & breed, const std::string & name, const int age, const std::string & photograph)
{
	return this->repo.addDog(breed, name, age, photograph);
}

int Controller::removeDogFromRepo(const std::string & breed, const std::string & name)
{
	return this->repo.deleteDog(breed, name);
}

int  Controller::updateDogInRepo(const std::string& newBreed, const std::string& newName, const int newAge, const std::string& newPhotograph)
{
	return this->repo.updateDog(newBreed, newName, newAge, newPhotograph);
}




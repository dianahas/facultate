#pragma once
#include "DogRepo.h"
#include "DogValidator.h"
#include "AdoptRepo.h"
#include "AdoptSortRepo.h"

class Controller
{
private:
	Repository repo;

public:
	Controller(const Repository& r) : repo{ r } {}

	Repository getRepo() { return repo; }

	int addDogtoRepo(const std::string & breed, const std::string & name, const int age, const std::string & photograph);

	int removeDogFromRepo(const std::string & breed, const std::string & name);

	int updateDogInRepo(const std::string& newBreed, const std::string& newName, const int newAge, const std::string& newPhotograph);

};
#pragma once
#include "DogRepo.h"
#include "AdoptRepo.h"
#include "AdoptSortRepo.h"
#include "DogCSV.h"
#include "DogHtml.h"

class ControlUser
{
private:
	Repository repo;
	AdoptRepo* repo2;
	AdoptSortRepo repo3;

public:
	ControlUser(Repository r1, AdoptRepo* r2, AdoptSortRepo r3) : repo{ r1 }, repo2{ r2 }, repo3{ r3 } {}

	std::vector<Dog>& getAdoptRepo() { return this->repo2->getAdopt(); }

	AdoptSortRepo getSortRepo() { return repo3; }

	void setCurrent();

	void addAdoptDog(Dog d);

	int addAdoptSortDog(Dog d);

	std::vector<Dog> sortDogs(const std::string& breed, int age);

	void nextAdoptDog();

	void showCurrent();

	void nextAdoptDog2();

	void showCurrent2();

	void openWatch();
};
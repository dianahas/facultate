#include "ControlUser.h"
#include <algorithm>

void ControlUser::setCurrent()
{
	this->repo.setCurrent();
}

void ControlUser::addAdoptDog(Dog d)
{
	this->repo2->addAdopt(d);
}

int ControlUser::addAdoptSortDog(Dog d)
{
	return this->repo3.addSortAdopt(d);
}

std::vector<Dog> ControlUser::sortDogs(const std::string & breed, int age)
{

	std::vector<Dog> dogs = this->repo.getDogs();
	if (breed.empty())
		for (auto d : dogs)
			this->repo3.addSortAdopt(d);
	else
		for (auto d : dogs)
			if (d.getBreed().compare(breed) == 0 && d.getAge() < age)
				this->repo3.addSortAdopt(d);
	return repo3.getSortAdopt();
}

void ControlUser::nextAdoptDog()
{
	this->repo.nextDog();
}

void ControlUser::showCurrent()
{
	this->repo.showDog();
}

void ControlUser::nextAdoptDog2()
{
	this->repo3.nextDog2();
}

void ControlUser::showCurrent2()
{
	this->repo3.showDog2();
}

void ControlUser::openWatch()
{
	this->repo2->openFile();
}

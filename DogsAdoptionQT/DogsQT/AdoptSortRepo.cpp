#include "AdoptSortRepo.h"

AdoptSortRepo::AdoptSortRepo()
{
	this->curent = 0;
}

int AdoptSortRepo::addSortAdopt(Dog d)
{
	this->sorti.push_back(d);
	return 1;
}

Dog AdoptSortRepo::returnCurrentDog2()
{
	if (this->curent == this->sorti.size())
		this->curent = 0;
	return this->sorti[this->curent];
}

void AdoptSortRepo::nextDog2()
{
	this->curent++;
	showDog2();
}

void AdoptSortRepo::showDog2()
{
	Dog currentDog = this->returnCurrentDog2();
	currentDog.show();
}

void AdoptSortRepo::openFile()
{
}

void AdoptSortRepo::Write()
{
}

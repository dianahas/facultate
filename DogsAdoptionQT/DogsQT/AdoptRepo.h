#pragma once
#include "Dog.h"
#include <vector>
class AdoptRepo
{
protected:
	std::vector<Dog> adoptii;
public:

	AdoptRepo() {}
	void setDogs(std::vector<Dog> newVector) { adoptii = newVector; }
	virtual void addAdopt(Dog& d);

	std::vector<Dog>& getAdopt()
	{
		return this->adoptii;
	}

	virtual void openFile();
private:
	virtual void Write();
};


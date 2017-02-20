#pragma once
#include "AdoptRepo.h"
#include <iostream>
#include <string>
#include <vector>

class DogHtml : public AdoptRepo
{
private:
	std::string filename;
public:
	void openFile() override;
	DogHtml();
	DogHtml(std::vector<Dog> list, std::string filename);
	~DogHtml();
	void addAdopt(Dog& d) override;
private:
	void Write() override;
};
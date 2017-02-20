#pragma once
#include "AdoptRepo.h"
#include <iostream>
#include <string>
#include <vector>

class DogCSV : public AdoptRepo
{
private:
	std::string filename;
public:
	void openFile() override;
	DogCSV();
	DogCSV(std::vector<Dog> list, std::string filename);
	~DogCSV();
	void addAdopt(Dog& d) override;
private:
	void Write() override;
};
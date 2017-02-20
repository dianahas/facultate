#include "DogValidator.h"
using namespace std;

DogException::DogException(std::vector<std::string> _errors)
{
	this->errors = _errors;
}

std::vector<std::string> DogException::getErrors() const
{
	return this->errors;
}

std::string DogException::getErrorsAsString() const
{
	string err;
	for (auto e : this->errors)
		err += e;
	return err;
}

void DogValidator::validate(const Dog & s)
{
	vector<string> errors;
	cout << s.getBreed().size();
	if (s.getBreed().size() < 3)
		errors.push_back("The breed of the dog cannot be less than 2 characters!\n");
	if (!isupper(s.getName()[0]))
		errors.push_back(string("The name of the dog must start with a capital letter!\n"));
	if (s.getAge() == 0)
		errors.push_back(string("The age cannot be 0!\n"));

	// search for "www" or "http" at the beginning of the source string
	int posWww = s.getPhoto().find("www");
	int posHttp = s.getPhoto().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw DogException(errors);
}


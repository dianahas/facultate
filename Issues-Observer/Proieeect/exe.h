#pragma once
#include <stdexcept>
#include <string>

class CustomException : std::exception
{
protected:
	std::string message;

public:
	CustomException(const std::string &msg);
	virtual const char* what();
};
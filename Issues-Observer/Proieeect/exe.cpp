#include "exe.h"

CustomException::CustomException(const std::string & msg) : message{ msg } {}

const char* CustomException::what()
{
	return message.c_str();
}

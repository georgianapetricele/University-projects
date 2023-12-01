#include "Exceptions.h"
#include <string>

//DO EXCEPTIONS FOR REPOSITORY
//UnexistentException

FileException::FileException(std::string message) : message{ message }
{
}

const char* FileException::what() const noexcept
{
	return message.c_str();
}

DuplicateException::DuplicateException(std::string message) : message{ message }
{
}

const char* DuplicateException::what() const noexcept
{
	return message.c_str();
}

InvalidNumberException::InvalidNumberException(std::string message) : message{ message }
{
}

const char* InvalidNumberException::what() const noexcept
{
	return message.c_str();
}

TutorialExceptions::TutorialExceptions(vector<string> errors)
{
	this->errors = errors;
}

vector<string> TutorialExceptions::get_errors() const
{
	return this->errors;
}

UnexistentTutorialException::UnexistentTutorialException(string message) : message{ message }
{

}

const char* UnexistentTutorialException::what() const noexcept
{
	return message.c_str();
}

AppError::AppError(string message) : message{ message }
{

}

const char* AppError::what() const noexcept
{
	return message.c_str();
}
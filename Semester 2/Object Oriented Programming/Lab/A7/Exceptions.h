#pragma once
#include <exception>
#include <string>
#include <vector>

using namespace std;

class FileException : public std::exception
{
private:
	string message;
public:
	FileException(string message);
	const char* what() const noexcept override;
};

class DuplicateException : public std::exception
{
private:
		string message;
public:
	DuplicateException(string message);
	const char* what() const noexcept override;
};;

class InvalidNumberException : public std::exception
{
private:
	string message;
public:
	InvalidNumberException(string message);
	const char* what() const noexcept override;
};

class TutorialExceptions
{
private:
	vector<string> errors;
public:
	TutorialExceptions(vector<string> errors);
	vector<string> get_errors() const;
};

class UnexistentTutorialException : public std::exception
{
private:
	string message;
public:
	UnexistentTutorialException(string message);
	const char* what() const noexcept override;
};
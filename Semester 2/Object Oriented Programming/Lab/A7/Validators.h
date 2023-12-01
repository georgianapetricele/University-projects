#pragma once
#include <string>
using namespace std;
#include "Exceptions.h"
#include "Domain.h"

class Validators
{
public:
	int validate_number_input(string input_number);
	void validate_tutorial(const Tutorial& tutorial);
};
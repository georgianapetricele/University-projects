
// Validate user option
#include "Validators.h"

int Validators::validate_number_input(string input_number)
{
	for (int index = 0; index < input_number.length(); index++)
		if (!isdigit(input_number[index]) && input_number[index] != '\n' && input_number[index] != ' ' && input_number[index] != '-')
		{
			throw InvalidNumberException("\nError! The input isn't a number!");
			return 0;
		}
	return 1;
}

void Validators::validate_tutorial(const Tutorial& tutorial)
{
	vector<string>errors;
	if (tutorial.get_presenter() == "")
		errors.push_back("\nError! The presenter can't be empty!");
	if (tutorial.get_title() == "")
		errors.push_back("\nError! The title can't be empty!");
	if (tutorial.get_number_likes() < 0)
		errors.push_back("\nError! The number of likes can't be negative!");
	if (tutorial.get_duration_minutes() < 0)
		errors.push_back("\nError! The number of minutes can't be negative!");
	if (tutorial.get_duration_seconds() < 0)
		errors.push_back("\nError! The number of seconds can't be negative!");
	if (tutorial.get_link() == "")
		errors.push_back("\nError! The link can't be empty!");

	if (errors.size() > 0)
		throw TutorialExceptions(errors);
}
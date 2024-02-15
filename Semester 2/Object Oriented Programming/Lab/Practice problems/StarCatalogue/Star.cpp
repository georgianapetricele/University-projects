#include "Star.h"
#include <sstream>


vector<string> tokenize1(const string& string, char delimiter)
{
	vector <std::string> result;
	stringstream stream(string);
	std::string token;
	while (getline(stream, token, delimiter))
		result.push_back(token);

	return result;
}

std::istream& operator>>(std::istream& stream, Star& d)
{
	string line;
	getline(stream, line);

	vector<string> tokens = tokenize1(line, ',');
	if (tokens.size() == 5)
	{
		d.name = tokens[0];
		d.constel = tokens[1];
		d.RA = stoi(tokens[2]);
		d.Dec = stoi(tokens[3]);
		d.diam = stoi(tokens[4]);
		return stream;
	}
	else
	{
		return stream;
	}
}

std::ostream& operator<<(std::ostream& stream, const Star& d)
{
	stream << d.name << "," << d.constel << "," << d.RA << "," << d.Dec << "," << d.diam << "\n";
	return stream;
}

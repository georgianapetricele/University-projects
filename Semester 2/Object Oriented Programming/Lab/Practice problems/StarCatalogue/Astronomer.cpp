#include "Astronomer.h"
#include <sstream>


vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}


istream& operator>>(std::istream& stream, Astronomer& d)
{
	string line;
	getline(stream, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() == 2)
	{
		d.name = tokens[0];
		d.constel = tokens[1];

		return stream;
	}
	else
	{
		return stream;
	}
}

std::ostream& operator<<(std::ostream& stream, const Astronomer& d)
{
	stream << d.name << "," << d.constel << "\n";
	return stream;
}
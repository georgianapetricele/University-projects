#include "Equation.h"

Equation::Equation()
{

}

Equation::Equation(double a, double b, double c)
{
    this->a = a;
	this->b = b;
	this->c = c;
}

double Equation::get_a()
{
	return this->a;
}

double Equation::get_b()
{
	return this->b;
}

double Equation::get_c()
{
	return this->c;
}

void Equation::set_coefficients(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}


string Equation::toString()
{
	string result = "";
	if(this->a<0)
			result += "-";
	else
		if(this->a>0)
		result += "+";
	result += to_string(abs(this->a));
	result += "x^2 ";
	if (this->b < 0)
		result += "-";
	else
		if (this->b > 0)
			result += "+";
	result += to_string(abs(this->b));
	result += "x ";
	if (this->c < 0)
		result += "-";
	else
		if (this->c > 0)
			result += "+";
	result += to_string(abs(this->c));
	return result;

}

vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Equation& eq)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 3)
		return is;
	eq.a = stod(tokens[0]);
	eq.b = stod(tokens[1]);
	eq.c = stod(tokens[2]);
	return is;
}
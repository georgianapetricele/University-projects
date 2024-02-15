#include "Service.h"


Service::Service()
{
}

vector<Equation> Service::get_equations()
{
	return this->equations;
}

void Service::read_from_file()
{
	ifstream file("equations.txt");
	Equation equation;
	while (file >> equation)
	{
		equations.push_back(equation);
	}
	file.close();
}

void Service::update_coefficients(int index, double a, double b, double c)
{
	this->equations[index].set_coefficients(a, b, c);
}

double Service::compute_delta(Equation equation)
{
	return equation.get_b() * equation.get_b() - 4 * equation.get_a() * equation.get_c();
}

string Service::compute_solutions(Equation equation)
{
	double delta = compute_delta(equation);
	string result = "";
		if (delta == 0)
		{
			result += "x1 = x2 = ";
			result += to_string(-equation.get_b() / (2 * equation.get_a()));
		}
		else
		if(delta>0)
		{
			result += "x1 = ";
			result += to_string((-equation.get_b() + sqrt(delta)) / (2 * equation.get_a()));
			result += " x2 = ";
			result += to_string((-equation.get_b() - sqrt(delta)) / (2 * equation.get_a()));
		}
		else
			if(delta<0)
		{
				result += "x1 = ";
				result += to_string((-equation.get_b() / (2 * equation.get_a())));
				result += "+";
				result += to_string(sqrt(abs(delta)) / (2 * equation.get_a()));
				result += "i";
				result += " x2 = ";
				result += to_string((-equation.get_b() / (2 * equation.get_a())));
				result += "-";
				result += to_string(sqrt(abs(delta)) / (2 * equation.get_a()));
				result += "i";
		}
	return result;
}


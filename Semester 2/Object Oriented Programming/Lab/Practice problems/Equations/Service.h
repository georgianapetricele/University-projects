#pragma once
#include "Equation.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
class Service
{
	private:
	vector<Equation> equations;
	public:
		Service();
		vector<Equation> get_equations();
		void read_from_file();
		void update_coefficients(int index, double a, double b, double c);
		double compute_delta(Equation equation);
		string compute_solutions(Equation equation);
		~Service()
		{

		}

};


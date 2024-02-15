#pragma once
#include <string>
#include <sstream>
#include <vector>


using namespace std;

class Equation
{
	private:
	double a;
	double b;
	double c;
	public:
		Equation();
		Equation(double a, double b, double c);
		double get_a();
		double get_b();
		double get_c();
		void set_coefficients(double a, double b, double c);
		string toString();
		friend istream& operator>>(istream& is, Equation& eq);

};


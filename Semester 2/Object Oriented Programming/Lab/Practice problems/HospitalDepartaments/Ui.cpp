#include "Ui.h"


using namespace std;

Ui::Ui()
{
}

void Ui::add_departament()
{
	string type, hospital_name, number_doctors, number_patients, number_mothers, number_babies, average_grade;
	cout << "Enter hospital name: ";
	getline(cin, hospital_name);
	cout << "Enter number of doctors: ";
	getline(cin, number_doctors);
	cout << "Enter the type of departament: ";
	getline(cin, type);
	if (type == "1")
	{
		cout << "Enter number of patients: ";
		getline(cin, number_patients);
		HospitalDepartament* departament = new Surgery(hospital_name, stoi(number_doctors), stoi(number_patients));
		this->service.add_departament(departament);

	}
	else
	{
		cout << "Enter number of mothers: ";
		getline(cin, number_mothers);
		cout << "Enter number of babies: ";
		getline(cin, number_babies);
		cout << "Enter average grade: ";
		getline(cin, average_grade);
		HospitalDepartament* departament = new NeonatalUnit(hospital_name, stoi(number_doctors), stoi(number_mothers), stoi(number_babies), stod(average_grade));
		this->service.add_departament(departament);
	}
}

void Ui::show_departaments()
{
	vector<HospitalDepartament*> departaments = this->service.get_all();
	for (auto departament : departaments)
		cout << departament->toString() << endl;
}

void Ui::save_to_file()
{
	string file_name;
	cout << "Enter file name: ";
	getline(cin, file_name);
	this->service.save_to_file(file_name);
}

void Ui::show_efficient_departaments()
{
		vector<HospitalDepartament*> efficient_departaments = this->service.get_efficient();
	for (auto departament : efficient_departaments)
		cout << departament->toString() << endl;
}

void Ui::run()
{

	HospitalDepartament * departament1 = new Surgery("Surgery1", 10, 15);
	HospitalDepartament * departament2 = new Surgery("Surgery2", 10, 20);
	HospitalDepartament * departament3 = new NeonatalUnit("NeonatalUnit1", 10, 20, 10, 9.5);
	this->service.add_departament(departament1);
	this->service.add_departament(departament2);
	this->service.add_departament(departament3);
	while (true)
	{

		cout<<"\n1. Add a new departament\n";
		cout<<"2. Show all departaments\n";
		cout<<"3. Show all efficient departaments\n";
		cout<<"4. Save all departaments to a file\n";

		string command;
		cout << "Enter command: ";
		getline(cin, command);
		if (command == "1")
			add_departament();
		else
			if (command == "2")
				show_departaments();
			else if (command == "3")
				show_efficient_departaments();
			else
				save_to_file();
	}
}
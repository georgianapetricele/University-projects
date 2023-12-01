#pragma once
#include <iostream>
#include <string>
#include "Agency.h"
#include "Dwelling.h"
#include "Client.h"
#include "TypesClients.h"
using namespace std;

class Ui
{
private:
	Agency agency;
public:
	Ui();
	~Ui();
	void start();
	void add_dwelling();
	void list_clients_and_dwellings();
	void remove_client();
};
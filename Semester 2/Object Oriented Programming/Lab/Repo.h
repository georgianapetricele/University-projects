#pragma once
#include "Domain.h"

typedef struct
{
	int size;
	Country arr[105];
}Countries;

Countries initialize_countries_repo();

void add_country_repo(char* country_name, char* continent, int population);

int find_country_repo(char country_name[], Countries Vect);

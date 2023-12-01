#include "Repo.h"
#include "Domain.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

Countries Vect;

void create_new_country()


void add_country_repo(char* country_name, char given_continent[], int population)
{
	Country new_country;
	for(int i=0;i<5;i++)

	//strcpy_s(new_country.continent,sizeof(new_country.continent),continent);
	int length = strlen(given_continent);
	for (int i = 0; i < length; i++)
		new_country.continent[i] = given_continent[i];
	new_country.population = population;
	Vect.arr[Vect.size] = new_country;
	Vect.size++;
}


/*
void delete_country_repo(char country_name_to_delete[], Countries Vect)
{
	int position = find_country_repo(country_name_to_delete, Vect)-1;
	Country current_country_to_update, new_value = Vect.arr[Vect.size];
	for (int index = Vect.size; index >= 0; index--)
	{
		current_country_to_update = Vect.arr[index - 1];
		Vect.arr[index - 1] = new_value;
		new_value = current_country_to_update;
	}
	Vect.size--;
}

void update_country_repo(Country new_country, Countries *Vect)
{
	for (int index = 0; index < Vect->size; index++)
		if (strcmp(Vect->arr[index].name, new_country.name) == 0)
			strcpy_s(Vect->arr[index].name, sizeof Vect->arr[index].name,new_country.name);
}
*/

int find_country_repo(char country_name[],Countries Vect)
{
	for (int index = 0; index < Vect.size; index++)
		if (strcmp(Vect.arr[index].name, country_name) == 0)
			return index+1;
	return 0;
}
#include "Controller.h"
#include "Repo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void initialize_countries()
{
	return 0;
}

void add_country(char country_name[], char continent[], char population[])
{	
	int population_integer = atoi(population);
	add_country_repo(country_name, continent, population_integer);
}

/*
void delete_country(char country_name_to_delete[])
{
	delete_country_repo(country_name_to_delete);
}

void update_country(char country_name[],char country_where_population_goes[],int new_population)
{
	update_country_repo(country_name, country_where_population_goes, new_population);
}
*/
int validate_country_name(char country_name[])
{
	size_t name_length = strlen(country_name);
	for (int index = 0; index < name_length; index++)
		if (!isalpha(country_name[index]) && country_name[index] != ' ')
			return 0;
	return 1;
}

int validate_continent(char continent[])
{
	size_t continent_length = strlen(continent);
	char valid_continents[6][15] = { "Europe","America","Africa","Australia","Asia" };
	for (int index = 0; index < continent_length; index++)
		if (!isalpha(continent[index]) && continent[index] != ' ')
			return 0;
	return 1;
}

int validate_population(char population[])
{
	int population_length = strlen(population);
	for (int index = 0; index < population_length; index++)
		if (!isdigit(population[index]))
			return 0;
	return 1;
}

int find_country(char country_name[], Countries Vect)
{
	return find_country_repo(country_name,Vect);
}

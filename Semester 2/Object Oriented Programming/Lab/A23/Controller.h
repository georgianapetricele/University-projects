#pragma once

void add_country(char country_name, char continent, char population[]);

void update_country(char country_name[], char country_where_population_goes[], int new_population);

void delete_country(char country_name_to_delete[]);

void initialize_countries();

int validate_country(char country_name[], char continent[], char population[]);

int validate_country_name(char country_name[]);

void delete_country(char country_name_to_delete[]);

int find_country(country_name);

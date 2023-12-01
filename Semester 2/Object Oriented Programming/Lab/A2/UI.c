#include <stdio.h>
#include <string.h>
#include "Controller.h"
#include "Domain.h"

/*
The World Population Monitoring Organisation needs an application to help keep track of countries’ populations.
Each Country has a unique name, the continent it belongs to (one of Europe, America, Africa, Australia or Asia),
and a population (stored in millions). The employees of the organisation need the application to help them in the following ways:
(a) Add, delete or update a country. Updating must also consider the case of migration: a given number of people leave one country to migrate to another.
(b) Display all countries whose name contains a given string (if the string is empty, all the countries should be considered).
(c) Display all countries on a given continent (if the continent is empty, all countries will be considered), whose populations are greater than a given value, sorted ascending by population.
(d) Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.
*/

void ui_add_a_country()
{
    char country_name[51], continent[51], population[51];
    int valid_name = 0, valid_continent = 0, valid_population = 0;

    printf("Enter the name of the country you want to add: ");
    gets(country_name);
    if (validate_country_name(country_name))
        valid_name = 1;
    else
        printf("Enter a valid name for country!");

    printf("Enter the continent the country belongs to: ");
    gets(continent);
    if (validate_continent(continent))
        valid_continent = 1;
    else
        printf("Enter a valid continent for country!");

    printf("Enter the population of the given country: ");
    gets(population);
    if (validate_population(population))
        valid_population = 1;
    else
        printf("Enter a valid population for country!");

    if (valid_name&&valid_continent&&valid_population)
        add_country(country_name, continent, population);
    else
        printf("Enter valid data!");

}
/*
void ui_delete_a_country()
{
    int country_name_to_delete[51];
    printf("Enter the name of the country you want to delete: ");
    if (validate_name(country_name_to_delete))
    {
        if (find_country(country_name_to_delete))
            gets(country_name_to_delete);
    }
    else
        printf("Enter a valid country!");
 
}
void ui_update_a_country()
{
    char country_name[51], country_where_population_goes[51],new_population[51];
    int valid_name = 0,valid_population =0, valid_country_where_population_goes = 0,new_population_integer = 1;
    printf("Enter the name of the country you want to update: ");
    gets(country_name);
    if (validate_name(country_name))
        valid_name = 1;
    else
        printf("Enter a valid country!");

    printf("Enter the how many people migrate: ");
    gets(new_population);
    if (validate_population(new_population))
        valid_population = 1;
    else
        printf("Enter a valid population!");

    printf("Enter the country in which population migrates: ");
    gets(country_where_population_goes);
    if (validate_country_name(country_where_population_goes))
        valid_country_where_population_goes = 1;
    else
        printf("Enter a valid country!");

    if (valid_name && valid_population && valid_country_where_population_goes)
    {
        new_population_integer = atoi(new_population);
        update_country(country_name, country_where_population_goes, new_population_integer);
    }
    else
        printf("Enter valid data!");

}*/
void print_menu()
{
    printf("Choose your option:\n");
    printf("a. Add, delete or update a country.\n");
    printf("b. Display all countries whose name contains a given string.\n");
    printf("c. Display all countries on a given continent.\n");
    printf("d. Provide multiple undo and redo functionality.\n");
}
void print_submenu1()
{
    printf("1. Add a country.\n");
    printf("2. Delete a country.\n");
    printf("3. Update a country. Updating must also consider the case of migration: a given number of people leave one country to migrate to another.\n");
}
int main()
{
    
    int not_finished = 1,length;
    char option[11],sub_option[21],continent[34];
    option[10] ;
    sub_option[20] ;
    print_menu();
    initialize_countries();
    while (not_finished)
    {
        printf("Enter your option: ");
        gets(option);
        if (strcmp(option, "a") == 0)
        {
            print_submenu1();
            printf("Enter your option: ");
            gets(sub_option);
            if (strcmp(sub_option, "add") == 0)
                //ui_add_a_country();
                gets(continent);
            length = strlen(continent);
            /*
            else
                if (strcmp(sub_option, "delete") == 0)
                    ui_delete_a_country();
                else
                    if (strcmp(sub_option, "update") == 0)
                        ui_update_a_country();
            */
        }


    }
    return 0;
}

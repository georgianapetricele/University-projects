#include <stdio.h>
#include <math.h>
#pragma warning(suppress : 4996)



// Non - UI

int check_if_given_number_is_prime(int number_to_check)
{
	if (number_to_check < 2)
		return 0;
	else
		if (number_to_check == 2)
			return 1;
		else
			for (int index = 2; index <= sqrt(number_to_check); index++)
				if (number_to_check % index == 0)
					return 0;
	return 1;
}

int check_if_numbers_are_relatively_prime(int first_number, int second_number)
{
	int minimum;
	if (first_number < second_number)
		minimum = first_number;
	else
		minimum = second_number;
	int maximum_divisor = minimum;
	for (int index = 2; index <= maximum_divisor; index++)
		if (first_number % index == 0 && second_number % index == 0)
			return 0;
	return 1;
}


// UI

void print_longest_subsequence_of_relatively_prime_numbers(int array[], int start_position, int max_length_subsequence)
{
	if (max_length_subsequence == -1)
		printf("There is no subsequence of relative prime numbers!\n");
	else
	{
		printf("The longest subsequence of relative prime numbers is:\n");
		for (int index = start_position; index <= start_position + max_length_subsequence; index++)
			printf("%d\n", array[index]);
	}
}

void find_the_longest_continuous_subsequence_of_relatively_prime_numbers(int size, int array[], int* start_position, int* max_length_subsequence)
{
	int current_length = 0,partial_position=0;
	*max_length_subsequence = -1;
	for (int index = 0; index < size - 1; index++)
		if (check_if_numbers_are_relatively_prime(array[index], array[index + 1]))
		{
			current_length++;
			if (current_length > *max_length_subsequence)
			{
				*max_length_subsequence = current_length;
				*start_position = partial_position;
			}
			if (current_length == 1)
				partial_position = index;
		}
		else
			current_length = 0;

}

void generate_the_first_n_prime_numbers(int* total_of_prime_numbers)
{
	int current_number = 2, count = 0, total_prime_numbers = *total_of_prime_numbers;
	printf("The first %d prime numbers are:\n", total_prime_numbers);
	printf("%d%s", current_number, "\n");
	current_number++;
	count = 2;
	while (count <= total_prime_numbers)
	{
		if (check_if_given_number_is_prime(current_number))
		{
			printf("%d%s", current_number, "\n");
			count++;
		}
		current_number++;
	}

}

int get_first_functionality_input(int* how_many_prime_numbers_to_print)
{
	printf("Enter how many prime numbers to generate: ");
	scanf_s("%d", how_many_prime_numbers_to_print);
	return *how_many_prime_numbers_to_print;
}

void read_vector(int* size, int *array)
{
	printf("Enter the size of the vector: ");
	scanf_s("%d", size);
	printf("Enter the elements of the vector: ");
	for (int index = 0; index < *size; index++)
		scanf_s("%d", &array[index]);
}

void print_menu()
{
	printf("Choose option:\n1- Generate the first n prime numbers (n is a given natural number);\n2- Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime;\n3- Read a vector from console;\n0- Exit program\n");
}

int main()
{

	/*
	a. Generate the first n prime numbers (n is a given natural number).
	b. Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.
	*/
	int not_finished = 1, option, size=0, array[100] = { 0 };
	int start_position, max_length_subsequence;
	while (not_finished)
	{
		print_menu();
		printf("Enter your option: ");
		scanf_s("%d", &option);
		if (option == 1)
		{
			int how_many_prime_numbers_to_print;
			how_many_prime_numbers_to_print = get_first_functionality_input(&how_many_prime_numbers_to_print);
			generate_the_first_n_prime_numbers(&how_many_prime_numbers_to_print);
		}
		else
			if (option == 2)
			{
				find_the_longest_continuous_subsequence_of_relatively_prime_numbers(size, array, &start_position, &max_length_subsequence);
				print_longest_subsequence_of_relatively_prime_numbers(array, start_position, max_length_subsequence);
			}
			else
				if (option == 3)
				{
					read_vector(&size, array);
				}
				else
				if (option == 0)
					break;
				else
					printf("Wrong command!\n");


	}
	return 0;
}
"""
Implement a menu-driven console application to help visualize the way sorting algorithms work.
You will be given two of the algorithms from the list below to implement (one from each set).
When started, the program will print a menu with the following options:

Generate a list of n random natural numbers. Generated numbers must be between 0 and 100.
Sort the list using the first algorithm. (see NB! below)
Sort the list using the second algorithm. (see NB! below)
Exit the program
"""

import random
import timeit
import texttable


def generate_list_of_numbers_to_sort(number_of_terms, list_to_sort):
    for current_index in range(0, number_of_terms):
        list_to_sort.append(random.randint(0, 100))
    print(list_to_sort)


def sort_the_list_with_bubble_sort(list_to_sort):
    number_of_terms = len(list_to_sort)
    list_is_sorted = False
    for i in range(number_of_terms):
        list_is_sorted = True  # suppose the list is sorted
        for current_index in range(0, number_of_terms - i - 1):
            if list_to_sort[current_index] > list_to_sort[current_index + 1] and current_index < number_of_terms - 1:
                list_is_sorted = False
                aux = list_to_sort[current_index]
                list_to_sort[current_index] = list_to_sort[current_index + 1]
                list_to_sort[current_index + 1] = aux
        if list_is_sorted:
            break


def sort_the_list_with_stooge_sort(list_to_sort, left, right):
    if left >= right:  # if there is 1 term in recursion
        return
    if list_to_sort[left] > list_to_sort[right]:
        aux = list_to_sort[left]
        list_to_sort[left] = list_to_sort[right]
        list_to_sort[right] = aux

    if right - left + 1 > 2:
        ratio = int((right - left + 1) / 3)
        # Sort recursively the first 2/3 elements of the list
        sort_the_list_with_stooge_sort(list_to_sort, left, right - ratio)
        # Sort recursively the last 2/3 elements of the list
        sort_the_list_with_stooge_sort(list_to_sort, left + ratio, right)
        # Sort recursively again the first 2/3 elements of the list
        sort_the_list_with_stooge_sort(list_to_sort, left, right - ratio)


def generate_list_of_numbers_in_increasing_order(number_of_terms):
    list_to_sort = []
    for current_index in range(0, number_of_terms):
        value = current_index + 1
        list_to_sort.append(value)
    return list_to_sort


def generate_list_of_numbers_in_random_order(number_of_terms):
    list_to_sort = []
    for current_index in range(0, number_of_terms):
        list_to_sort.append(random.randint(0, 100))
    return list_to_sort


def generate_list_of_numbers_in_decreasing_order(number_of_terms):
    list_to_sort = []
    for current_index in range(number_of_terms - 1, -1, -1):
        value = current_index + 1
        list_to_sort.append(value)
    return list_to_sort


def sort_the_lists_in_worst_case():
    number_of_terms_for_every_list = [50, 100, 200, 400, 800]
    table = texttable.Texttable()
    table.add_row(['The Worst Case', ' ', ' '])
    table.add_row(['Term', 'Bubble Sort', 'Stooge Sort'])
    for current_number in number_of_terms_for_every_list:
        list_to_sort_for_bubble_sort = generate_list_of_numbers_in_decreasing_order(current_number)
        list_to_sort_for_stooge_sort = generate_list_of_numbers_in_increasing_order(current_number)
        # Sort with Bubble Sort
        start_bubble = timeit.default_timer()
        sort_the_list_with_bubble_sort(list_to_sort_for_bubble_sort)
        end_bubble = timeit.default_timer()
        # Sort with Stooge Sort
        current_number = len(list_to_sort_for_stooge_sort)
        start_stooge = timeit.default_timer()
        sort_the_list_with_stooge_sort(list_to_sort_for_stooge_sort, 0, current_number - 1)
        end_stooge = timeit.default_timer()
        table.add_row([current_number, end_bubble - start_bubble, end_stooge - start_stooge])
    return table


def sort_the_lists_in_average_case():
    number_of_terms_for_every_list = [50, 100, 200, 400, 800]
    table = texttable.Texttable()
    table.add_row(['The Average Case', ' ', ' '])
    table.add_row(['Term', 'Bubble Sort', 'Stooge Sort'])
    for current_number in number_of_terms_for_every_list:
        list_to_sort_for_bubble_sort = generate_list_of_numbers_in_random_order(current_number)
        list_to_sort_for_stooge_sort = generate_list_of_numbers_in_random_order(current_number)
        # Sort with Bubble Sort
        start_bubble = timeit.default_timer()
        sort_the_list_with_bubble_sort(list_to_sort_for_bubble_sort)
        end_bubble = timeit.default_timer()
        # Sort with Stooge Sort
        current_number = len(list_to_sort_for_stooge_sort)
        start_stooge = timeit.default_timer()
        sort_the_list_with_stooge_sort(list_to_sort_for_stooge_sort, 0, current_number - 1)
        end_stooge = timeit.default_timer()
        table.add_row([current_number, end_bubble - start_bubble, end_stooge - start_stooge])
    return table


def sort_the_lists_in_best_case():
    number_of_terms_for_every_list = [50, 100, 200, 400, 800]
    table = texttable.Texttable()
    table.add_row(['The Best Case', ' ', ' '])
    table.add_row(['Term', 'Bubble Sort', 'Stooge Sort'])
    for current_number in number_of_terms_for_every_list:
        list_to_sort_for_bubble_sort = generate_list_of_numbers_in_increasing_order(current_number)
        list_to_sort_for_stooge_sort = generate_list_of_numbers_in_random_order(current_number)
        # Sort with Bubble Sort
        start_bubble = timeit.default_timer()
        sort_the_list_with_bubble_sort(list_to_sort_for_bubble_sort)
        end_bubble = timeit.default_timer()
        # Sort with Stooge Sort
        current_number = len(list_to_sort_for_stooge_sort)
        start_stooge = timeit.default_timer()
        sort_the_list_with_stooge_sort(list_to_sort_for_stooge_sort, 0, current_number - 1)
        end_stooge = timeit.default_timer()
        table.add_row([current_number, end_bubble - start_bubble, end_stooge - start_stooge])
        """print("For", current_number, "numbers, Bubble sort will take", end_bubble - start_bubble)
        print("For", current_number, "numbers, Stooge sort will take", end_stooge - start_stooge)"""
    return table


def start():
    list_to_sort = []
    while True:
        print("1. Generate a list of n random natural numbers.")
        print("2. Sort the list using the first algorithm -> Bubble Sort")
        print("3. Sort the list using the second algorithm -> Stooge Sort")
        print("4. Print time for Best Case!")
        print("5. Print time for Average Case!")
        print("6. Print time for Worst Case!")
        print("0. Exit the program")

        option = input("Enter your option here:")
        if option == "1":
            number_of_terms = int(input("Enter how many numbers to generate: "))
            generate_list_of_numbers_to_sort(number_of_terms, list_to_sort)
        elif option == "2":
            # list_to_sort=[2, 26, 60, 68, 56, 5]
            number_of_terms = len(list_to_sort)
            sort_the_list_with_bubble_sort(list_to_sort)
        elif option == "3":
            # list_to_sort = [2, 26, 60, 68, 56, 5]
            number_of_terms = len(list_to_sort)
            sort_the_list_with_stooge_sort(list_to_sort, 0, number_of_terms - 1)
        elif option == "4":
            print(sort_the_lists_in_best_case().draw())
        elif option == "5":
            print(sort_the_lists_in_average_case().draw())
        elif option == "6":
            print(sort_the_lists_in_worst_case().draw())
        elif option == "0":
            return
        else:
            print("Bad command!")


start()

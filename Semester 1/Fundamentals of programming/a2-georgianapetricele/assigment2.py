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


def sort_the_list_with_bubble_sort(list_to_sort, current_step, step_to_check):
    number_of_terms = len(list_to_sort)
    list_is_sorted = False
    while not list_is_sorted:
        list_is_sorted = True  # suppose the list is sorted
        for current_index in range(0, number_of_terms - 1):
            if list_to_sort[current_index] > list_to_sort[current_index + 1] and current_index < number_of_terms - 1:
                list_is_sorted = False
                aux = list_to_sort[current_index]
                list_to_sort[current_index] = list_to_sort[current_index + 1]
                list_to_sort[current_index + 1] = aux
                current_step += 1
                if current_step % step_to_check == 0:   # after step operations
                    print(list_to_sort)


def sort_the_list_with_stooge_sort(list_to_sort, left_bound, right_bound, current_step, step_to_check):
    if left_bound >= right_bound:   # if there is 1 term in recursion
        return
    if list_to_sort[left_bound] > list_to_sort[right_bound]:
        current_step += 1
        aux = list_to_sort[left_bound]
        list_to_sort[left_bound] = list_to_sort[right_bound]
        list_to_sort[right_bound] = aux
        if current_step % step_to_check == 0:
            print(list_to_sort)

    if right_bound - left_bound > 1:
        ratio = int((right_bound - left_bound + 1) / 3)
        # Sort recursively the first 2/3 elements of the list
        sort_the_list_with_stooge_sort(list_to_sort, left_bound, right_bound - ratio, current_step, step_to_check)
        # Sort recursively the last 2/3 elements of the list
        sort_the_list_with_stooge_sort(list_to_sort, left_bound + ratio, right_bound, current_step, step_to_check)
        # Sort recursively again the first 2/3 elements of the list
        sort_the_list_with_stooge_sort(list_to_sort, left_bound, right_bound - ratio, current_step, step_to_check)


def generate_list_of_numbers_to_sort(number_of_terms, list_to_sort):
    for current_index in range(0, number_of_terms):
        list_to_sort.append(random.randint(0, 100))
    print(list_to_sort)


def start():
    list_to_sort = []
    while True:
        print("1.Generate a list of n random natural numbers.")
        print("2.Sort the list using the first algorithm -> Bubble Sort")
        print("3.Sort the list using the second algorithm -> Stooge Sort")
        print("0.Exit the program")

        option = input("Enter your option here:")
        if option == "1":
            number_of_terms = int(input("Enter how many numbers to generate: "))
            generate_list_of_numbers_to_sort(number_of_terms, list_to_sort)
        elif option == "2":
            step = int(input("Enter the step for displaying the partially sorted list after step operations: "))
            # list_to_sort=[2, 26, 60, 68, 56, 5]
            if step == 0:
                print(list_to_sort)
            else:
                sort_the_list_with_bubble_sort(list_to_sort, 0, step)
        elif option == "3":
            step = int(input("Enter the step for displaying the partially sorted list after step operations: "))
            # list_to_sort = [2, 26, 60, 68, 56, 5]
            # number_of_terms=len(list_to_sort)
            if step == 0:
                print(list_to_sort)
            else:
                number_of_terms = len(list_to_sort)
                sort_the_list_with_stooge_sort(list_to_sort, 0, number_of_terms - 1, 0, step)
        elif option == "0":
            return
        else:
            print("Bad command!")


start()

"""
A group of n (n<=10) persons, numbered from 1 to n are placed on a row of chairs, but between every two neighbor persons
(e.g. persons 3 and 4, or persons 7 and 8) some conflicts appeared. Display all the possible modalities to replace the
persons, such that between any two persons in conflict stay one or at most two other persons.


"""


# import timeit

def check_if_two_initial_neighbors_stay_apart(list_of_people_placed_on_the_row: list, current_index: int):
    for index in range(0, current_index):
        if list_of_people_placed_on_the_row[index] == list_of_people_placed_on_the_row[current_index]:
            return 0

    for index in range(1, current_index + 1):
        if abs(list_of_people_placed_on_the_row[index] - list_of_people_placed_on_the_row[index - 1]) <= 1:
            return 0
    return 1


def print_the_number_of_people_placed_on_the_row(list_of_people_placed_on_the_row, number_of_people):
    for i in range(0, number_of_people):
        print(list_of_people_placed_on_the_row[i], end=' ')
    print(' ', end="\n")


def generate_all_possibilities_to_place_people_iterative(list_of_people_placed_on_the_row: list, number_of_people: int):
    current_index = 0
    list_of_people_placed_on_the_row.append(0)
    while current_index > -1:
        if list_of_people_placed_on_the_row[current_index] < number_of_people:
            list_of_people_placed_on_the_row[current_index] += 1
            if check_if_two_initial_neighbors_stay_apart(list_of_people_placed_on_the_row, current_index):
                if current_index == number_of_people - 1:
                    print_the_number_of_people_placed_on_the_row(list_of_people_placed_on_the_row, number_of_people)

                else:
                    current_index += 1
                    list_of_people_placed_on_the_row.append(0)
        else:
            current_index -= 1
            list_of_people_placed_on_the_row.pop()


def generate_all_possibilities_to_place_people_recursive(list_of_people_placed_on_the_row: list, number_of_people: int, current_index: int):
    for index in range(1, number_of_people + 1):
        list_of_people_placed_on_the_row.append(index)
        if check_if_two_initial_neighbors_stay_apart(list_of_people_placed_on_the_row, current_index):
            if current_index == number_of_people - 1:
                print_the_number_of_people_placed_on_the_row(list_of_people_placed_on_the_row, number_of_people)
                if len(list_of_people_placed_on_the_row):
                    list_of_people_placed_on_the_row.pop()
            else:
                generate_all_possibilities_to_place_people_recursive(list_of_people_placed_on_the_row, number_of_people, current_index + 1)
        else:
            if len(list_of_people_placed_on_the_row):
                list_of_people_placed_on_the_row.pop()
    if len(list_of_people_placed_on_the_row):
        list_of_people_placed_on_the_row.pop()


solution_list = []
number_of_people_placed_on_the_row: int = int(input("Enter the number of people placed on the row: "))
option = int(input("Enter 1- Iterative version; 2- Recursive version: "))
if option == 1:
    # start=timeit.default_timer()
    generate_all_possibilities_to_place_people_iterative(solution_list, number_of_people_placed_on_the_row)
    # end=timeit.default_timer()
    # print(end-start)
else:
    generate_all_possibilities_to_place_people_recursive(solution_list, number_of_people_placed_on_the_row, 0)

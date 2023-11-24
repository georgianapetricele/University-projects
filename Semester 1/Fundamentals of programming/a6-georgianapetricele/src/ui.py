#
# This is the program's UI module. The user interface and all interaction with the user (print and input statements)
# are found here
#
"""
A math teacher needs a program to help students test different properties of complex numbers, provided in the a+bi form
(we assume a and b are integers for simplicity). Write a program that implements the functionalities exemplified.

- The UI module provides a command-based console user interface that accepts given commands exactly as stated
- Handle the case of incorrect user input by displaying error messages. The program must not crash regardless of user
 input.
- Use the built-in list or dict compound types to represent entities in the problem domain and access/modify them using
getter and setter functions
- Use Python's exception mechanism so that functions can signal that an exceptional situation, or error, has happened.
- Provide specifications for all non-UI functions (except getters and setters), and tests for all non-UI functions
 to functionalities (A) and (B)
- Have at least 10 randomly generated items in your application at program startup
"""

import functions
from copy import deepcopy


def ui_add_to_list(complex_number, list_of_complex_numbers):
    try:
        if len(complex_number) == 1:
            complex_number.append(0)
        functions.add_current_number_to_list(complex_number[0], complex_number[1], list_of_complex_numbers)
        print("Number added with success!")
    except:
        print("Wrong value!")


def ui_insert_to_a_position_in_list(positions_for_inserting, list_of_complex_numbers):
    try:
        if len(positions_for_inserting) == 2:
            positions_for_inserting.insert(0, 1)
        functions.insert_number_to_a_position_in_list(positions_for_inserting[0], positions_for_inserting[1], positions_for_inserting[2],
                                                      list_of_complex_numbers)
        print("Number inserted with success at", positions_for_inserting[2], "!")
    except Exception as err:
        print(err)


def ui_remove_element_at_a_position(position_for_removing, list_of_complex_numbers):
    try:
        functions.remove_element_at_a_position_in_list(position_for_removing[0], list_of_complex_numbers)
        print("Number removed with success from position", position_for_removing[0], "!")
    except Exception as err:
        print(err)


def ui_remove_element_from_position_start_to_position_end(positions_for_removing, list_of_complex_numbers):
    try:
        functions.remove_element_from_position_start_to_position_end(positions_for_removing[0], positions_for_removing[1],
                                                                     list_of_complex_numbers)
    except Exception as err:
        print(err)


def ui_replace_element_from_list_with_another_one(positions_for_replacing, list_of_complex_numbers):
    if len(positions_for_replacing) == 3:
        positions_for_replacing.append(0)
    functions.replace_element_from_list_with_another_one(positions_for_replacing[0], positions_for_replacing[1], positions_for_replacing[2], positions_for_replacing[3],
                                                         list_of_complex_numbers)


def ui_display_the_whole_list(list_of_complex_numbers):
    if len(list_of_complex_numbers) == 0:
        print("List is empty!")
    else:
        for current_number in list_of_complex_numbers:
            print(functions.convert_complex_number_to_string(current_number))


def ui_display_real_number_between_given_positions(parameters, list_of_complex_numbers):
    try:
        if len(parameters) < 2:
            raise ValueError("Wrong positions!")
        start_position = parameters[0]
        end_position = parameters[1]
        found_real_number = False
        if start_position > len(list_of_complex_numbers) or start_position > end_position:
            raise ValueError("Wrong positions!")
        for index in range(start_position, end_position + 1):
            if functions.get_imaginary_part(list_of_complex_numbers[index]) == 0:
                print(functions.convert_complex_number_to_string(list_of_complex_numbers[index]))
                found_real_number = True
        if not found_real_number:
            print("There is no real number between", start_position, "and", end_position)
    except ValueError as err:
        print(err)


def ui_display_numbers_with_given_property_for_modulo(commands, parameters, list_of_complex_numbers):
    try:
        if len(commands) < 3 or len(parameters) < 1:
            raise ValueError("Wrong values!")
        given_property = commands[2]
        given_number_for_property = parameters[0]
        found_number = False
        for current_number in list_of_complex_numbers:
            modulo_of_current_number = functions.determine_modulus_of_complex_number(current_number)
            if given_property == '<' and modulo_of_current_number < given_number_for_property:
                print(functions.convert_complex_number_to_string(current_number))
                found_number = True
            elif given_property == '>' and modulo_of_current_number > given_number_for_property:
                print(functions.convert_complex_number_to_string(current_number))
                found_number = True
            elif given_property == '=' and modulo_of_current_number == given_number_for_property:
                print(functions.convert_complex_number_to_string(current_number))
                found_number = True
        if not found_number:
            print("There is no number with given property!")
    except Exception as err:
        print(err)


def ui_filter_real_numbers(list_of_complex_numbers):
    try:
        functions.filter_real_numbers(list_of_complex_numbers)
    except Exception as err:
        print(err)


def ui_filter_numbers_with_given_property_for_modulo(commands, parameters, list_of_complex_numbers):
    try:
        if len(commands) < 3 or len(parameters) < 1:
            raise ValueError("Wrong values!")
        given_property = commands[2]
        given_value_for_comparison = parameters[0]
        functions.filter_numbers_with_given_property_for_modulo(given_property, given_value_for_comparison,
                                                                list_of_complex_numbers)
    except Exception as err:
        print(err)


def ui_undo_operation(list_after_every_command):
    try:
        if len(list_after_every_command) == 1:
            raise ValueError("There is nothing to undo here!")
        else:
            list_after_every_command.pop()
    except Exception as err:
        print(err)


def start():
    list_after_every_command = []
    commands = []
    parameters = []
    list_of_complex_numbers = functions.generate_complex_numbers(10)
    list_after_every_command.append(list_of_complex_numbers[:])

    while True:
        print("Choose one of the following options: ")
        print("1. Add a number: ")
        print("Add <number> / Insert <number> at <position>")
        print()
        print("2. Modify numbers:")
        print("Remove <position> / Remove <start position> to <end position> / Replace <old number> with <new number>")
        print()
        print("3. Display numbers having different properties: ")
        print("List / List real <start position> to <end position> / List modulo [ < | = | > ] <number>")
        print()
        print("4. Filter the list:")
        print("Filter real / Filter modulo [ < | = | > ] <number>")
        print()
        print("5.  Undo: ")
        list_of_complex_numbers = deepcopy(list_after_every_command[-1])
        user_command = input("Enter one of the above operations: ")
        try:
            commands, parameters = functions.process_user_command(user_command)
        except ValueError:
            print("Wrong command!")
        if commands[0] == "add":
            ui_add_to_list(parameters, list_of_complex_numbers)
        elif commands[0] == "insert":
            ui_insert_to_a_position_in_list(parameters, list_of_complex_numbers)
        elif commands[0] == "remove" and len(commands) == 1:
            ui_remove_element_at_a_position(parameters, list_of_complex_numbers)
        elif commands[0] == "remove" and commands[1] == "to":
            ui_remove_element_from_position_start_to_position_end(parameters, list_of_complex_numbers)
        elif commands[0] == "replace":
            ui_replace_element_from_list_with_another_one(parameters, list_of_complex_numbers)
        elif commands[0] == "list" and len(commands) == 1:
            ui_display_the_whole_list(list_of_complex_numbers)
        elif commands[0] == "list" and commands[1] == "real":
            ui_display_real_number_between_given_positions(parameters, list_of_complex_numbers)
        elif commands[0] == "list" and commands[1] == "modulo":
            ui_display_numbers_with_given_property_for_modulo(commands, parameters, list_of_complex_numbers)
        elif commands[0] == "filter" and commands[1] == "real":
            ui_filter_real_numbers(list_of_complex_numbers)
        elif commands[0] == "filter" and commands[1] == "modulo":
            ui_filter_numbers_with_given_property_for_modulo(commands, parameters, list_of_complex_numbers)
        elif commands[0] == "undo":
            if len(list_after_every_command) == 1:
                print("There is nothing to undo here!")
            else:
                list_after_every_command.pop()
        else:
            print("Wrong operation!")
        if commands[0] != "undo" and commands[0] != "list":
            list_after_every_command.append(list_of_complex_numbers[:])

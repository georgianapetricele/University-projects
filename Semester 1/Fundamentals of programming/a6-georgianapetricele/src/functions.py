#
# The program's functions are implemented here. There is no user interaction in this file, therefore no input/print
# statements. Functions here
# communicate via function parameters, the return statement and raising of exceptions.
#

import random
import math


def get_real_part(complex_number: list):  # add set functions
    return complex_number[0]


def get_imaginary_part(complex_number: list):
    return complex_number[1]


def set_real_part(real_part, complex_number: list):
    complex_number[0] = real_part


def set_imaginary_part(imaginary_part, complex_number: list):
    complex_number[1] = imaginary_part


def create_complex_number(real_part=0, imaginary_part=0):
    return [real_part, imaginary_part]


def check_if_complex_number_is_duplicate(complex_number, list_of_complex_numbers):
    for index in range(len(list_of_complex_numbers)):
        if complex_number == list_of_complex_numbers[index]:
            return False
    return True


def generate_complex_numbers(count):
    list_of_complex_numbers = []
    while count:
        real_part = random.randint(-20, 20)
        imaginary_part = random.randint(-20, 20)
        complex_number = create_complex_number(real_part, imaginary_part)
        if check_if_complex_number_is_duplicate(complex_number, list_of_complex_numbers):
            list_of_complex_numbers.append(complex_number)
            count -= 1
    return list_of_complex_numbers


def add_current_number_to_list(real_part_to_add, imaginary_part_to_add, list_of_complex_numbers):
    complex_number_to_add = create_complex_number(real_part_to_add, imaginary_part_to_add)
    list_of_complex_numbers.append(complex_number_to_add)


def insert_number_to_a_position_in_list(real_part_to_add, imaginary_part_to_add, on_which_position_to_insert_number
                                        , list_of_complex_numbers):
    complex_number_to_insert = create_complex_number(real_part_to_add, imaginary_part_to_add)

    if on_which_position_to_insert_number >= len(list_of_complex_numbers) or on_which_position_to_insert_number < 0:
        raise ValueError("Number can't be inserted!")
    list_of_complex_numbers.insert(on_which_position_to_insert_number, complex_number_to_insert)


def remove_element_at_a_position_in_list(from_which_position_to_remove_number, list_of_complex_numbers):
    if from_which_position_to_remove_number > len(list_of_complex_numbers) or from_which_position_to_remove_number < 0:
        raise ValueError("Number can't be removed!")
    list_of_complex_numbers.pop(from_which_position_to_remove_number)


def remove_element_from_position_start_to_position_end(on_which_position_to_start_removing_values,
                                                       on_which_position_to_end_removing_values,
                                                       list_of_complex_numbers):
    if on_which_position_to_end_removing_values < on_which_position_to_start_removing_values:
        raise ValueError("Numbers can't be removed!")
    else:
        how_many_numbers_to_remove = on_which_position_to_end_removing_values - on_which_position_to_start_removing_values + 1
        index_for_current_removing = on_which_position_to_start_removing_values
        while how_many_numbers_to_remove:
            list_of_complex_numbers.pop(index_for_current_removing)
            how_many_numbers_to_remove -= 1


def replace_element_from_list_with_another_one(real_part_for_first_number, imaginary_part_for_first_number,
                                               real_part_for_second_number, imaginary_part_for_second_number,
                                               list_of_complex_numbers):
    for current_number in list_of_complex_numbers:
        if current_number[0] == real_part_for_first_number and current_number[1] == imaginary_part_for_first_number:
            set_real_part(real_part_for_second_number, current_number)
            set_imaginary_part(imaginary_part_for_second_number, current_number)


def determine_modulus_of_complex_number(complex_number):
    # mod =sqrt(a^2+b^2)
    return math.sqrt(get_real_part(complex_number) ** 2 + get_imaginary_part(complex_number) ** 2)


def filter_real_numbers(list_of_complex_numbers):
    found_real_number = False
    length_of_list = len(list_of_complex_numbers)
    index = 0
    while index < length_of_list:
        current_number = list_of_complex_numbers[index]
        if get_imaginary_part(current_number) == 0:
            found_real_number = True
            index += 1
        else:
            list_of_complex_numbers.pop(index)
            length_of_list -= 1
        if index >= length_of_list:
            break
    if not found_real_number:
        raise ValueError("There is no real number here!")


def filter_numbers_with_given_property_for_modulo(given_property, given_value_for_comparison, list_of_complex_numbers):
    found_modulo_number = False
    length_of_list = len(list_of_complex_numbers)
    index = 0
    while index < length_of_list:
        current_number = list_of_complex_numbers[index]
        if given_property == '<' and determine_modulus_of_complex_number(current_number) < given_value_for_comparison:
            found_modulo_number = True
            index += 1
        elif given_property == '>' and determine_modulus_of_complex_number(current_number) > given_value_for_comparison:
            found_modulo_number = True
            index += 1
        elif given_property == '=' and determine_modulus_of_complex_number(
                current_number) == given_value_for_comparison:
            found_modulo_number = True
            index += 1
        else:
            list_of_complex_numbers.pop(index)
            length_of_list -= 1
        if index >= length_of_list:
            break
    if found_modulo_number == False:
        raise ValueError("There is no number here with given property!")


def convert_complex_number_to_string(complex_number):
    string_number = ''

    if get_real_part(complex_number):
        if int(get_imaginary_part(complex_number)) == get_imaginary_part(complex_number):
            string_number += str(int(get_real_part(complex_number))) + ' '
        else:
            string_number += str(get_real_part(complex_number)) + ' '

    if get_imaginary_part(complex_number):
        if get_imaginary_part(complex_number) < 0:
            if int(get_imaginary_part(complex_number)) == get_imaginary_part(complex_number):
                string_number += str(int(get_imaginary_part(complex_number))) + "i"
            else:
                string_number += str(get_imaginary_part(complex_number)) + "i"
        else:
            if int(get_imaginary_part(complex_number)) == get_imaginary_part(complex_number):
                string_number += "+" + str(int(get_imaginary_part(complex_number))) + "i"
            else:
                string_number += "+" + str(get_imaginary_part(complex_number)) + "i"

    return string_number


def process_user_command(user_command):
    list_of_words = []
    list_of_parameters = []
    user_command.strip()
    commands = user_command.split()
    # "add" "4+2i"
    # "insert" "4+2i" "at" "3"
    for current_command in commands:
        check_if_current_command_has_numbers_in_it = False
        for character in current_command:
            if character.isdigit():
                check_if_current_command_has_numbers_in_it = True
                break
        if not check_if_current_command_has_numbers_in_it:
            list_of_words.append(current_command)
        else:
            sign_of_current_number_in_command = 1
            number_for_constructing_parameter = ""
            if len(current_command) == 1:
                list_of_parameters.append(int(current_command[0]))
            else:
                for index in range(0, len(current_command)):
                    character = current_command[index]
                    if character == '-':
                        sign_of_current_number_in_command = -1
                    if character == "+":
                        sign_of_current_number_in_command = 1
                    elif character.isdigit():
                        number_for_constructing_parameter += character
                    if index == len(current_command) - 1 or (
                            current_command[index + 1] == "-" or current_command[index + 1] == "+" or
                            current_command[index + 1] == "i" or current_command[index + 1] == ' '):
                        if len(number_for_constructing_parameter) > 0:
                            list_of_parameters.append(
                                int(number_for_constructing_parameter) * sign_of_current_number_in_command)
                            number_for_constructing_parameter = ""
    return list_of_words, list_of_parameters

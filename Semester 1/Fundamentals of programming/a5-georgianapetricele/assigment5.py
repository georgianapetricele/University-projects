"""
Implement a menu-driven console application that provides the following functionalities:

Read a list of complex numbers (in z = a + bi form) from the console.
Display the entire list of numbers on the console.
Display on the console the sequence, subarray or numbers required by the properties that were assigned to you.
Length and elements of the longest subarray of numbers having the same modulus.
The length and elements of a maximum subarray sum, when considering each number's real part
Exit the application.
The source code will include:

Specifications for the functions related to point 3 above.
10 complex numbers already available at program startup

def function():

    try:
        function_to_try(info)
        assert(False)
    except

"""
import random
import math

#
# Write below this comment
# Functions to deal with complex numbers -- list representation
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#
"""
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
"""


# Write below this comment
# Functions to deal with complex numbers -- dict representation
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

def get_real_part(complex_number: dict):
    return complex_number["real_part"]


def get_imaginary_part(complex_number: dict):
    return complex_number["imaginary_part"]


def set_real_part(real_part, complex_number: dict):
    complex_number["real_part"] = real_part


def set_imaginary_part(imaginary_part, complex_number: dict):
    complex_number["imaginary_part"] = imaginary_part


def create_complex_number(real_part=0, imaginary_part=0):
    return {"real_part": real_part, "imaginary_part": imaginary_part}


#
# Write below this comment
# Functions that deal with the required functionalities properties
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

def check_if_complex_number_is_duplicate(complex_number, list_of_complex_numbers):
    for index in range(len(list_of_complex_numbers)):
        if complex_number == list_of_complex_numbers[index]:
            return 0
    return 1


def determine_modulus_of_complex_number(complex_number):
    # mod =sqrt(a^2+b^2)
    return math.sqrt(get_real_part(complex_number) ** 2 + get_imaginary_part(complex_number) ** 2)


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


def generate_complex_numbers(count: int):
    list_of_complex_numbers = []
    while count:
        real_part = random.randint(-20, 20)
        imaginary_part = random.randint(-20, 20)
        complex_number = create_complex_number(real_part, imaginary_part)
        if check_if_complex_number_is_duplicate(complex_number, list_of_complex_numbers):
            list_of_complex_numbers.append(complex_number)
            count -= 1
    return list_of_complex_numbers


def calculate_the_subarray_with_maximum_sum(list_of_real_parts):
    length_list_of_real_parts = len(list_of_real_parts)
    best_sum = 0
    partial_sum = 0
    partial_index = 0
    for index in range(0, length_list_of_real_parts):
        partial_sum += list_of_real_parts[index]
        if partial_sum < 0:
            partial_sum = 0
            partial_index = index
        if partial_sum > best_sum:
            best_sum = partial_sum
            beginning_index = partial_index
            ending_index = index
    length_of_subarray_with_maximum_sum = ending_index - beginning_index + 1
    return length_of_subarray_with_maximum_sum,beginning_index,ending_index

def calculate_longest_subarray_having_same_modulus(list_of_modulus_for_complex_numbers):
    # ex 1 2 2 3 4 4 4 5 6 => 4 4 4
    length_list_of_modulus = len(list_of_modulus_for_complex_numbers)
    length_of_subarray = 1
    maximum_length_of_subarray = -1
    index = 1
    beginning_index = 0
    beginning_index_for_maximum_subarray = 0
    while index < length_list_of_modulus - 1:
        if list_of_modulus_for_complex_numbers[index - 1] == list_of_modulus_for_complex_numbers[index]:
            length_of_subarray += 1
            if beginning_index == 0:
                beginning_index = index - 1
        else:
            if length_of_subarray > maximum_length_of_subarray:
                maximum_length_of_subarray = length_of_subarray
                beginning_index_for_maximum_subarray = beginning_index
            length_of_subarray = 1
            beginning_index = 0
        index += 1

    if list_of_modulus_for_complex_numbers[index - 1] == list_of_modulus_for_complex_numbers[index]:
        length_of_subarray += 1
        if beginning_index == 0:
            beginning_index = index - 1
    if length_of_subarray > maximum_length_of_subarray:
        maximum_length_of_subarray = length_of_subarray
        beginning_index_for_maximum_subarray = beginning_index

    ending_index = beginning_index_for_maximum_subarray + maximum_length_of_subarray
    return  maximum_length_of_subarray,beginning_index_for_maximum_subarray,ending_index


#
# Write below this comment
# UI section
# Write all functions that have input or print statements here
# Ideally, this section should not contain any calculations relevant to program functionalities
#

def read_list_of_complex_numbers(list_of_complex_numbers):
    list_to_add = []
    try:
        how_many_complex_numbers_to_add = int(input("Enter how many complex numbers do you want to add: "))
    except:
        print("Invalid value")
        return
    while how_many_complex_numbers_to_add:
        try:
            real_part = float(input("Enter the real part of the current complex number: "))
        except:
            print("Invalid value")
            return
        try:
            imaginary_part = float(input("Enter the imaginary part of the current complex number: "))
        except:
            print("Invalid value")
            return
        else:
            current_complex_number = create_complex_number()
            set_real_part(real_part, current_complex_number)
            set_imaginary_part(imaginary_part, current_complex_number)
            how_many_complex_numbers_to_add -= 1
            list_to_add.append(current_complex_number)

    list_of_complex_numbers += list_to_add


def display_list_of_complex_numbers(list_of_complex_numbers):
    if len(list_of_complex_numbers) == 0:
        print("There are no complex numbers in the list!")
    else:
        print("The list of complex numbers is: ")
        for current_complex_number in list_of_complex_numbers:
            print(convert_complex_number_to_string(current_complex_number))


def display_longest_subarray_having_same_modulus(list_of_complex_numbers):
    """
    :param: list_of_complex_numbers:
    :print: Length and elements of the longest subarray of numbers having the same modulus.
    """
    list_of_modulus_for_complex_numbers = []
    for current_complex_number in list_of_complex_numbers:
        list_of_modulus_for_complex_numbers.append(determine_modulus_of_complex_number(current_complex_number))

    length_of_subarray = 1
    beginning_index_for_maximum_subarray = 0
    maximum_length_of_subarray = -1
    ending_index=0
    maximum_length_of_subarray,beginning_index_for_maximum_subarray,ending_index=calculate_longest_subarray_having_same_modulus(list_of_modulus_for_complex_numbers)

    print("The length of longest subarray of numbers having the same modulus is: ", maximum_length_of_subarray)
    print("The longest subarray of numbers having the same modulus is: ",
          list_of_modulus_for_complex_numbers[beginning_index_for_maximum_subarray: ending_index + 2])


def display_subarray_with_maximum_sum(list_of_complex_numbers):
    """
    :param list_of_complex_numbers:
    :print: The length and elements of a maximum subarray sum, when considering each number's real part
    """
    list_of_real_parts = []
    for current_complex_number in list_of_complex_numbers:
        list_of_real_parts.append(get_real_part(current_complex_number))

    length_of_subarray_with_maximum_sum= beginning_index=ending_index=0
    length_of_subarray_with_maximum_sum,beginning_index,ending_index=calculate_the_subarray_with_maximum_sum(list_of_real_parts)

    print("The length of the subarray with maximum sum, when considering each number's real part is",
          length_of_subarray_with_maximum_sum)
    print("The subarray with maximum sum is:", list_of_real_parts[beginning_index:ending_index + 1])


def start():
    # This is the program's entry point
    # What do to here !!!???
    # 1. Print out main menu in a loop
    # 2. Keep the list of complex numbers
    # 3. Call the function corresponding to user choice
    # 4. Print out error messages coming from functions

    list_of_complex_numbers = generate_complex_numbers(10)
    print(list_of_complex_numbers)
    while True:
        print("1. Read a list of complex numbers (in z = a + bi form) from the console.")
        print()
        print("2. Display the entire list of numbers on the console.")
        print()
        print("3. Display the length and elements of a longest subarray of numbers having the same modulus.")
        print()
        print("4.Display the length and elements of a maximum subarray sum, when considering each number's real part")
        print()
        print("5. Exit the application.")
        operation = input("Enter the operation: ")
        if operation == "1":
            read_list_of_complex_numbers(list_of_complex_numbers)
        elif operation == "2":
            display_list_of_complex_numbers(list_of_complex_numbers)
        elif operation == "3":
            display_longest_subarray_having_same_modulus(list_of_complex_numbers)
        elif operation == "4":
            display_subarray_with_maximum_sum(list_of_complex_numbers)
        else:
            return


if __name__ == "__main__":
    start()

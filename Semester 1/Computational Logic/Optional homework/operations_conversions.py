"""
Author: Petricele Georgiana-Maria
Group: 915


The application must implement algorithms for:
 - arithmetic operations for positive integers: addition, subtraction, multiplication and division by one digit,
 in a base p in {2,3,...,9,10,16}

 -  conversions of natural numbers between two bases p,q in {2,3,...,9,10,16} using the substitution method or successive
  divisions and rapid conversions between two bases p,q in {2, 4, 8, 16}.

 - must have a menu such that all operations and conversion methods to be verified separately.
"""
import functions_for_operations
import functions_for_conversions


def print_result_for_addition_in_current_base(current_numeration_base,operand1,operand2):
    print("The addition result is: ",functions_for_operations.perform_addition_in_current_base(current_numeration_base,operand1,operand2))


def print_result_for_subtraction_in_current_base(current_numeration_base, operand1, operand2):
    print("The subtraction result is: ",functions_for_operations.perform_subtraction_in_current_base(current_numeration_base, operand1, operand2))


def print_result_for_multiplication_in_current_base(current_numeration_base, operand1, operand2):
    print("The multiplication result is: ",functions_for_operations.perform_multiplication_in_current_base(current_numeration_base, operand1, operand2))


def print_result_for_division_in_current_base(current_numeration_base, operand1, operand2):
    print("The division result is: ",functions_for_operations.perform_division_in_current_base(current_numeration_base, operand1, operand2))


def print_menu():
    print("Author: Petricele Georgiana-Maria")
    print("Group: 915")
    print()
    print("Choose your option:")
    print("1. Arithmetic operations for positive integers in a base p in {2,3,...,9,10,16}")
    print("2. Conversions of natural numbers between two bases p,q in {2,3,...,9,10,16}")


def start_application():
    while True:
        print_menu()
        option = int(input("Enter your option: "))
        if option == 1:
            print("Choose which operation do you want to execute: ")
            print("1. Addition")
            print("2. Subtraction")
            print("3. Multiplication")
            print("4. Division")
            option = int(input("Enter the operation do you want to execute: "))
            print("Enter the operands: ")
            operand1 = input("Enter the first operand: ")
            operand2 = input("Enter the second operand: ")
            if option == 1:
                print()
                print("Choose the numeration base p in {2,3,...,9,10,16} for addition")
                numeration_base=int(input("Enter the numeration base p: "))
                print_result_for_addition_in_current_base(numeration_base,operand1,operand2)
            elif option == 2:
                print()
                print("Choose the numeration base p in {2,3,...,9,10,16} for subtraction")
                numeration_base = int(input("Enter the numeration base p: "))
                print_result_for_subtraction_in_current_base(numeration_base, operand1, operand2)
            elif option == 3:
                print()
                print("Choose the numeration base p in {2,3,...,9,10,16} for multiplication")
                numeration_base = int(input("Enter the numeration base p: "))
                print_result_for_multiplication_in_current_base(numeration_base, operand1, operand2)
            elif option == 4:
                print()
                print("Choose the numeration base p in {2,3,...,9,10,16} for division")
                numeration_base = int(input("Enter the numeration base p: "))
                print_result_for_division_in_current_base(numeration_base, operand1, operand2)
        else:
            print("Choose the source base and the destination base: p,q in {2,3,...,9,10,16}")
            source_base = int(input("Enter the source base: "))
            destination_base= int(input("Enter the destination base: "))
            number_to_convert = input("Enter the number to convert: ")
            if source_base in [2, 4, 8, 16] and destination_base in [2, 4, 8, 16]:
                print("The number in base",destination_base,"is: ",functions_for_conversions.convert_number_with_rapid_conversions(source_base, destination_base,
                                                                                         number_to_convert))
            else:
                print("The number in base",destination_base,"is: ",functions_for_conversions.convert_operand_using_base_10_as_intermediate_base(source_base,
                                                                                    destination_base,number_to_convert))


start_application()









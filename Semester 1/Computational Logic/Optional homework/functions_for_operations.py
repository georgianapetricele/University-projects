"""
 This module contains the functions for arithmetic operations for positive integers: addition, subtraction,
  multiplication and division by one digit,
 in a base p in {2,3,...,9,10,16}
"""
import functions_for_conversions


def data_validation(first_number_to_check,second_number_to_check,numeration_base):
    for index in range(len(first_number_to_check)):
        if ord(first_number_to_check[index]) >= 65 and ord(first_number_to_check[index])-55 > numeration_base:
            return 0
        if ord(first_number_to_check[index]) < 65 and ord(first_number_to_check[index])- 48 > numeration_base:
            return 0
    for index in range(len(second_number_to_check)):
        if ord(second_number_to_check[index]) >= 65 and ord(second_number_to_check[index]) - 55 > numeration_base:
            return 0
        if ord(second_number_to_check[index]) < 65 and ord(second_number_to_check[index]) - 48 > numeration_base:
            return 0
    return 1


def perform_addition_in_current_base(current_numeration_base,operand1,operand2):

    if data_validation( operand1, operand2,current_numeration_base):
        result_of_addition = ""
        complete_with_zeros = ""
        # Fill the result with zeros if the numbers have different lengths

        length_difference = abs(len(operand1) - len(operand2))
        for index in range(1, length_difference + 1):
            complete_with_zeros += '0'
        if len(operand1) < len(operand2):
            operand1 = complete_with_zeros + operand1
        else:
            operand2 = complete_with_zeros + operand2

        # At first the carry is zero
        carry = 0
        max_length_between_to_numbers = max(len(operand1), len(operand2))

        # Perform the addition of the current last two digits from every number
        for index in range(max_length_between_to_numbers - 1, -1, -1):
            addition_result_of_current_digits = carry

            # Adding every digit to the partial addition result
            if ord(operand1[index]) >= 65:
                current_digit_of_first_number = ord(operand1[index]) - 55
            else:
                current_digit_of_first_number = ord(operand1[index]) - ord('0')
            if ord(operand2[index]) >= 65:
                current_digit_of_second_number = ord(operand2[index]) - 55
            else:
                current_digit_of_second_number = ord(operand2[index]) - ord('0')
            addition_result_of_current_digits = carry + current_digit_of_first_number + current_digit_of_second_number

            # Convert the partial result to current base and update the carry
            carry = addition_result_of_current_digits // current_numeration_base
            addition_result_of_current_digits %= current_numeration_base

            # Update the final addition result
            if addition_result_of_current_digits <= 9:
                result_of_addition = chr(addition_result_of_current_digits + ord('0')) + result_of_addition
            else:
                result_of_addition = chr(addition_result_of_current_digits + 55) + result_of_addition

        # Write the final carry if it exists
        if carry > 0:
            result_of_addition = chr(carry + ord('0')) + result_of_addition
        return result_of_addition.zfill(max_length_between_to_numbers)
    else:
        return "The operands aren't valid!"


def perform_subtraction_in_current_base(current_numeration_base, operand1, operand2):
    if data_validation(operand1, operand2, current_numeration_base):
        result_of_subtraction = ""
        complete_with_zeros = ""
        # Fill the result with zeros if the numbers have different lengths

        length_difference = abs(len(operand1) - len(operand2))
        for index in range(1, length_difference + 1):
            complete_with_zeros += '0'
        if len(operand1) < len(operand2):
            operand1 = complete_with_zeros + operand1
        else:
            operand2 = complete_with_zeros + operand2

        # At first the carry is zero
        carry = 0
        max_length_between_to_numbers = max(len(operand1), len(operand2))

        have_a_carry = False
        # Perform the addition of the current last two digits from every number
        for index in range(max_length_between_to_numbers - 1, -1, -1):
            have_a_carry=False
            subtraction_result_of_current_digits = carry

            # Adding every digit to the partial addition result
            if ord(operand1[index]) >= 65:
                current_digit_of_first_number = ord(operand1[index]) - 55
            else:
                current_digit_of_first_number = ord(operand1[index]) - ord('0')
            if ord(operand2[index]) >= 65:
                current_digit_of_second_number = ord(operand2[index]) - 55
            else:
                current_digit_of_second_number = ord(operand2[index]) - ord('0')

            if current_digit_of_first_number < current_digit_of_second_number:
                have_a_carry=True
                current_digit_of_first_number += current_numeration_base
            subtraction_result_of_current_digits = carry + current_digit_of_first_number - current_digit_of_second_number

            # Convert the partial result to current base and update the carry
            if have_a_carry == True:
                carry=-1
                subtraction_result_of_current_digits %= current_numeration_base
            else:
                carry = 0
            # Update the final subtraction result
            if subtraction_result_of_current_digits <= 9:
                result_of_subtraction = chr(subtraction_result_of_current_digits + ord('0')) + result_of_subtraction
            else:
                result_of_subtraction = chr(subtraction_result_of_current_digits + 55) + result_of_subtraction

        # Write the final carry if it exists
        if carry > 0:
            result_of_subtraction = chr(carry + ord('0')) + result_of_subtraction
        return result_of_subtraction.zfill(max_length_between_to_numbers)
    else:
        return "The operands aren't valid!"


def perform_multiplication_in_current_base(current_numeration_base, operand1, operand2):

    if data_validation(operand1, operand2, current_numeration_base):
        result_of_multiplication = ""
        complete_with_zeros = ""
        # Fill the result with zeros if the numbers have different lengths

        length_difference = abs(len(operand1) - len(operand2))
        if current_numeration_base == 2 and length_difference == 0:
            length_difference = 4 - len(operand1)
        for index in range(1, length_difference + 1):
            complete_with_zeros += '0'
        if current_numeration_base == 2:
            operand1 = complete_with_zeros + operand1
            operand2 = complete_with_zeros + operand2
        else:
            if len(operand1) < len(operand2):
                operand1 = complete_with_zeros + operand1
            else:
                operand2 = complete_with_zeros + operand2
        carry = 0
        max_length_between_to_numbers = max(len(operand1[:]), len(operand2))
        current_digit_of_second_number = ord(operand2[len(operand2) - 1]) - ord('0')
        # Perform the addition of the current last two digits from every number
        for index in range(max_length_between_to_numbers - 1, -1, -1):
            multiplication_result_of_current_digits = carry

            # Adding every digit to the partial multiplication result
            current_digit_of_first_number = ord(operand1[index]) - ord('0')

            multiplication_result_of_current_digits = carry + current_digit_of_first_number * current_digit_of_second_number
            # Convert the partial result to current base
            if current_numeration_base <= 10:
                multiplication_result_of_current_digits = functions_for_conversions.convert_operand_to_destination_base_smaller_than_source_base(
                    10, current_numeration_base, multiplication_result_of_current_digits)

            # Update partial digit and update the carry
            if len(multiplication_result_of_current_digits) > 1:
                carry = ord(multiplication_result_of_current_digits[0]) - ord('0')
                result_of_multiplication = multiplication_result_of_current_digits[1] + result_of_multiplication
            else:
                carry = 0
                result_of_multiplication = multiplication_result_of_current_digits[0] + result_of_multiplication

        if carry > 0:
            result_of_multiplication = chr(carry + ord('0')) + result_of_multiplication
        return result_of_multiplication.zfill(max_length_between_to_numbers)
    else:
        return "The operands aren't valid!"


def perform_division_in_current_base(current_numeration_base, operand1, operand2):

    result_of_division = ""
    complete_with_zeros = ""
    # Fill the result with zeros if the numbers have different lengths

    length_difference = abs(len(operand1) - len(operand2))
    if current_numeration_base == 2 and length_difference == 0:
        length_difference = 4 - len(operand1)
    for index in range(1, length_difference + 1):
        complete_with_zeros += '0'
    if current_numeration_base == 2:
        operand1 = complete_with_zeros + operand1
        operand2 = complete_with_zeros + operand2
    else:
        if len(operand1) < len(operand2):
            operand1 = complete_with_zeros + operand1
        else:
            operand2 = complete_with_zeros + operand2
    carry = 0
    max_length_between_to_numbers = max(len(operand1[:]), len(operand2))
    current_digit_of_second_number = ord(operand2[len(operand2) - 1]) - ord('0')
    # Perform the addition of the current last two digits from every number
    for index in range(max_length_between_to_numbers - 1, -1, -1):
        multiplication_result_of_current_digits = carry

        # Adding every digit to the partial addition result
        current_digit_of_first_number = ord(operand1[index]) - ord('0')

        multiplication_result_of_current_digits = carry + current_digit_of_first_number // current_digit_of_second_number
        # Convert the partial result to current base
        if current_numeration_base <= 10:
            multiplication_result_of_current_digits = functions_for_conversions.convert_operand_to_destination_base_smaller_than_source_base(
                10, current_numeration_base, multiplication_result_of_current_digits)

        # Update partial digit and update the carry
        if len(multiplication_result_of_current_digits) > 1:
            carry = ord(multiplication_result_of_current_digits[0]) - ord('0')
            result_of_division = multiplication_result_of_current_digits[1] + result_of_division
        else:
            carry = 0
            result_of_division = multiplication_result_of_current_digits[0] + result_of_division

    if carry > 0:
        result_of_division = chr(carry + ord('0')) + result_of_division
    return result_of_division.zfill(max_length_between_to_numbers)
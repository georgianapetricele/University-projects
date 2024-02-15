"""
 This module contains the functions for conversions of natural numbers between two bases
  p,q in {2,3,...,9,10,16} using the substitution method or successive divisions and rapid conversions between
  two bases p,q in {2, 4, 8, 16}.
"""


def determine_the_decimal_value_of_character(character):
    if character >= '0' and character <= '9':
        return ord(character) - ord('0')
    else:
        return ord(character) - ord('A') + 10


def convert_current_value_to_base_10(numeration_base,current_value):
    number_in_decimal=0
    power=1
    for index in range(len(current_value)-1,-1,-1):
        if determine_the_decimal_value_of_character(current_value[index]) >= numeration_base:
            return "Invalid number"
        number_in_decimal+= determine_the_decimal_value_of_character(current_value[index])*power
        power*= numeration_base
    return number_in_decimal


def convert_operand_using_base_10_as_intermediate_base(source_base, destination_base, number_to_convert):

     temporary_value = convert_current_value_to_base_10(source_base, number_to_convert)
     # Perform the successive divisions method for b>h
     if temporary_value != "Invalid number":
         auxiliary_number = temporary_value
         result = ""
         while auxiliary_number:
            current_digit =auxiliary_number % destination_base
            if current_digit <= 9:
                result = chr( current_digit + ord('0')) + result
            else:
                result = chr(current_digit + 55) + result
            auxiliary_number //= destination_base
         return result
     else:
        return "Invalid number"


def convert_number_with_rapid_conversions(source_base,destination_base,number_to_convert):

    # Perform the rapid conversions method for b, h in {2,4,8,16}
    number_after_conversion=""
    number_to_convert_int_representation = 0
    partial_result = 0
    complete_with_zeros = ""
    partial_result_in_str_representation=""
    if destination_base == 4:              # After every group of log2(destination_base) digits add the resulted number at final result
        length_of_group_of_digits = 2
    elif destination_base == 8:
        length_of_group_of_digits = 3
    else:
        length_of_group_of_digits = 4

    if source_base == 2:
        number_to_convert = str(number_to_convert)
    else:
        if source_base == 4:  # After every group of log2(destination_base) digits add the resulted number at final result
            length_of_group = 2
        elif source_base == 8:
            length_of_group = 3
        else:
            length_of_group = 4
        length_of_number_to_convert=len(number_to_convert)
        new_number_to_convert=""
        for index in range(length_of_number_to_convert):   # Transform the given number in binary
            if ord(number_to_convert[index])>= 65:
                digit_int_representation = ord(number_to_convert[index]) - 55
            else:
                digit_int_representation = ord(number_to_convert[index]) - ord('0')
            new_number_to_convert = new_number_to_convert+ bin(digit_int_representation)[2:]
        number_to_convert=new_number_to_convert
        if len(number_to_convert)%length_of_group_of_digits:
            length_of_number_to_convert=len(number_to_convert)    # Fill with zeros the binary number
            while length_of_number_to_convert%length_of_group_of_digits:
                length_of_number_to_convert+=1
                complete_with_zeros += '0'
            number_to_convert = complete_with_zeros +number_to_convert

    if destination_base !=2:
        position_of_current_digit = 0
        for index in range(len(number_to_convert)-1,-1,-1):
            if number_to_convert[index] == '1':
                partial_result += 2 ** position_of_current_digit
            if (position_of_current_digit+1)%length_of_group_of_digits== 0:
                partial_result_in_str_representation= str(partial_result)
                if destination_base == 16 and partial_result>9:
                    if partial_result_in_str_representation == '10':
                        partial_result_in_str_representation = 'A'
                    elif partial_result_in_str_representation == '11':
                        partial_result_in_str_representation = 'B'
                    elif partial_result_in_str_representation == '12':
                        partial_result_in_str_representation = 'C'
                    elif partial_result_in_str_representation == '13':
                        partial_result_in_str_representation = 'D'
                    elif partial_result_in_str_representation == '14':
                        partial_result_in_str_representation = 'E'
                    elif partial_result_in_str_representation == '15':
                        partial_result_in_str_representation = 'F'
                number_after_conversion = partial_result_in_str_representation + number_after_conversion
                partial_result = 0
                partial_result_in_str_representation=""
                position_of_current_digit = -1
            position_of_current_digit+=1
    else:
        number_after_conversion=new_number_to_convert
    return number_after_conversion



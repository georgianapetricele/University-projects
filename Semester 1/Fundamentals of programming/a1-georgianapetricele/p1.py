# Solve the problem from the first set here
"""Generate the largest prime number smaller than a given natural number n. If such a number does not exist,
a message should be displayed. """

import math


def is_prime(value_to_check):
    if value_to_check < 2:
        return False
    else:
        for number in range(2, int(math.sqrt(value_to_check))):
            if value_to_check % number == 0:
                return False
    return True


def generate_the_prime_number(upper_edge):
    number_to_find = -1
    for number in range(upper_edge - 1, 1, -1):
        if is_prime(number):
            number_to_find = number
            break
    return number_to_find


n = int(input("Enter the natural number: "))
prime_number = generate_the_prime_number(n)
if prime_number == -1:
    print("There is no prime number smaller than", n, "!")
else:
    print("The largest prime number smaller than", n, "is", prime_number, "!")

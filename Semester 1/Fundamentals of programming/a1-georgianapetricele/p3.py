# Solve the problem from the third set here
"""
Generate the largest perfect number smaller than a given natural number n. If such a number does not exist, a message
should be displayed. A number is perfect if it is equal to the sum of its divisors, except itself.
 (e.g. 6 is a perfect number, as 6=1+2+3).
"""
import math


def check_if_the_number_is_perfect(number):
    sum_of_divisors = 1
    for contor in range(2, int(math.sqrt(number) + 1)):
        if number % contor == 0:
            sum_of_divisors += contor + int(number / contor)
    if number == sum_of_divisors:
        return True
    else:
        return False


def find_the_largest_perfect_number_smaller_than_n(upper_bound):
    for x in range(upper_bound, 5, -1):
        if check_if_the_number_is_perfect(x):
            return x


n = int(input("Enter the natural number: "))
if n < 6:
    print("There is no perfect number smaller than", n, '!')
else:
    perfect_number = find_the_largest_perfect_number_smaller_than_n(n)
    print("The largest perfect number smaller than", n, "is", perfect_number, '!')

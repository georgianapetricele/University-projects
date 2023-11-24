# Solve the problem from the second set here
"""
Find the smallest number m from the Fibonacci sequence, defined by f[0]=f[1]=1, f[n]=f[n-1] + f[n-2], for n > 2, larger
than the given natural number n. (e.g. for n = 6, m = 8).
"""


def determine_the_fibonacci_number_greater_than_n(upper_bound):
    first_predecessor = 1
    second_predecessor = 1
    current_term = first_predecessor + second_predecessor
    while current_term <= upper_bound:
        first_predecessor = second_predecessor
        second_predecessor = current_term
        current_term = first_predecessor + second_predecessor
    return current_term


n = int(input("Enter the natural number: "))
fibonacci_number = determine_the_fibonacci_number_greater_than_n(n)
print("The smallest number from the Fibonacci sequence, larger than", n, "is", fibonacci_number, '!')

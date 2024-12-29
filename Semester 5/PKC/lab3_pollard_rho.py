# 2. Pollard’s ρ algorithm. The implicit function will be f(x) = x
# 2 + 1, but it will also allow the use
# of a function f given by the user

# Default f(x) = x^2 + 1 mod n
def default_f(x, n):
    return (x ** 2 + 1) % n


# GCD function
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


# Pollard's Rho Algorithm
def pollard(x0, n, f):
    d = 1
    xi = x2i = x0
    i = 0
    count = 0
    while d == 1 or d == n:
        xi = f(xi, n)  # Apply f(x) to xi
        x2i = f(f(x2i, n), n)  # Apply f(x) twice to x2i
        i += 2
        d = gcd(abs(x2i - xi), n)
        print(f'(|x{i} - x{i // 2}|, n) = {d}')

        count += 1
        if count > 1000:  # stop to not reach infinite loop
            print('Count reached 1000')
            break

    if d != 1 and d != n:
        print(f"Found a factor: {d}")
        print(f"Other factor: {n // d}")
    else:
        print("No factor found, try again.")


# Function to parse user input and create the function f(x)
def user_input_function():
    user_func = input("Enter the function f(x) in terms of x and n (e.g., x**2 + 1): ")

    def f(x, n):
        return eval(user_func) % n

    return f


def main():

    print("1. Use the default function f(x) = x^2 + 1 mod n")
    print("2. Enter a custom function for f(x)")

    choice = input("Enter your choice (1 or 2): ")

    # Set up initial values
    x0 = 2
    n = int(input("Enter the number n to factorize: "))

    if choice == "1":
        pollard(x0, n, f=default_f)
    elif choice == "2":
        user_defined_function = user_input_function()
        pollard(x0, n, f=user_defined_function)
    else:
        print("Invalid choice. Please select 1 or 2.")


if __name__ == '__main__':
    main()

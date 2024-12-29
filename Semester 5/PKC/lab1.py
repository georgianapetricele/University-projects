import time

def isDivisible(x, a):
    while x >= a:
        x -= a
    return x == 0


# GCD with substractions
def gcd_substractions(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    while a != b:
        if a > b:
            a = a - b
        else:
            b = b - a
    return a

# GCD with divisions
def gcd_divisions(a, b):
    while b != 0:
       r = a % b
       a = b
       b = r
    return a

#GCD naive aproach
def gcd_naive(a, b):
    gcd = min(a, b)
    while not isDivisible(a, gcd) or not isDivisible(b, gcd):
        gcd -= 1
    return gcd


if __name__ =='__main__':
    inputs = [(2,8),(6,14),(24,46),(40,82),(100,202),(200,240),(402,608),(1000,2100),(10**10,20**10),(3**30,6**20)]

    for input in inputs:
        a = input[0]
        b = input[1]
        print("\nFor a={} and b={}".format(a,b))

        print("GCD divisions")
        start = time.perf_counter()
        gcd = gcd_divisions(a,b)
        end = time.perf_counter()
        print("GCD is ", gcd)
        print("Time in seconds:", end-start)

        print("GCD substractions")
        start = time.perf_counter()
        gcd = gcd_substractions(a, b)
        end = time.perf_counter()
        print("GCD is ", gcd)
        print("Time:", end - start)

        print("GCD brute force")
        start = time.perf_counter()
        gcd = gcd_naive(a, b)
        end = time.perf_counter()
        print("GCD is ", gcd)
        print("Time:", end - start)











def f(a: bool, b: bool):
    return a or b

def assoc():
    values = [True, False]
    associative = True
    for a in values:
        for b in values:
            for c in values:
                test = (f(f(a, b), c) == f(a, f(b, c)))
                associative = associative and test
    return associative


def valid_solution(solution_list):
    pass



def generate_permutations(number_of_elements):
    index_of_permutation=1
    solution_list= [0]
    while index_of_permutation > -1:
        if solution_list[index_of_permutation]<number_of_elements:
            solution_list+=1
            if valid_solution(solution_list):
                if index_of_permutation == number_of_elements-1:




number_of_elements=int(input("Enter how many numbers to have in the set A: "))
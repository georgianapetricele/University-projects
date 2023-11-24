"""
Determine the longest common subsequence of two given sequences. Subsequence elements are not required to occupy
consecutive positions. For example, if X = "MNPNQMN" and Y = "NQPMNM", the longest common subsequence has length 4, and
can be one of "NQMN", "NPMN" or "NPNM". Determine and display both the length of the longest common
subsequence as well as at least one such subsequence.

MNPNQMN
NQPMNM

2,12 -assignment 5

"""


def lcs_of_the_two_sets_naive_solution(first_set_for_lcs, second_set_for_lcs, length_first_set, length_second_set,
                                       lcs_solution_set, frequency_solution_set):
    if length_first_set == 0 or length_second_set == 0:
        return 0
    elif first_set_for_lcs[length_first_set - 1] == second_set_for_lcs[length_second_set - 1]:
        if frequency_solution_set[length_first_set - 1] == 0:
            frequency_solution_set[length_first_set - 1] = 1
            lcs_solution_set.append(first_set_for_lcs[length_first_set - 1])
        return 1 + lcs_of_the_two_sets_naive_solution(first_set_for_lcs, second_set_for_lcs, length_first_set - 1,
                                                      length_second_set - 1, lcs_solution_set, frequency_solution_set)
    else:
        return max(lcs_of_the_two_sets_naive_solution(first_set_for_lcs, second_set_for_lcs, length_first_set,
                                                      length_second_set - 1, lcs_solution_set, frequency_solution_set),
                   lcs_of_the_two_sets_naive_solution(first_set_for_lcs, second_set_for_lcs, length_first_set - 1,
                                                      length_second_set, lcs_solution_set, frequency_solution_set))


def print_solution_set_for_lcs(first_set_for_lcs, second_set_for_lcs, lcs_matrix, index_first_set, index_second_set):
    if lcs_matrix[index_first_set][index_second_set]:
        if first_set_for_lcs[index_first_set - 1] == second_set_for_lcs[index_second_set - 1]:
            print_solution_set_for_lcs(first_set_for_lcs, second_set_for_lcs, lcs_matrix, index_first_set - 1,
                                       index_second_set - 1)
            print(first_set_for_lcs[index_first_set - 1], end='')
        else:
            if lcs_matrix[index_first_set - 1][index_second_set] > lcs_matrix[index_first_set][index_second_set - 1]:
                print_solution_set_for_lcs(first_set_for_lcs, second_set_for_lcs, lcs_matrix, index_first_set - 1,
                                           index_second_set)
            else:
                print_solution_set_for_lcs(first_set_for_lcs, second_set_for_lcs, lcs_matrix, index_first_set,
                                           index_second_set - 1)


def lcs_of_the_two_sets_dynamic_programming_solution(first_set_for_lcs, second_set_for_lcs, lcs_matrix,
                                                     length_first_set, length_second_set):
    for index1 in range(1, length_first_set + 1):
        for index2 in range(1, length_second_set + 1):
            if first_set_for_lcs[index1 - 1] == second_set_for_lcs[index2 - 1]:
                lcs_matrix[index1][index2] = lcs_matrix[index1 - 1][index2 - 1] + 1
            else:
                lcs_matrix[index1][index2] = max(lcs_matrix[index1 - 1][index2], lcs_matrix[index1][index2 - 1])

    print("The length of the lcs of", first_set_for_lcs, "and", second_set_for_lcs, "is: ", lcs_matrix[index1][index2])
    print("The longest common subsequence of the", first_set_for_lcs, "and", second_set_for_lcs, "is:")
    print_solution_set_for_lcs(first_set_for_lcs, second_set_for_lcs, lcs_matrix, length_first_set, length_second_set)
    print(' ', end="\n")
    print("The data structure used to memorize the intermediate results is: ")
    for index1 in range(1, length_first_set + 1):
        for index2 in range(1, length_second_set + 1):
            print(lcs_matrix[index1][index2], end=' ')
        print(' ', end="\n")


first_set_for_lcs = []
second_set_for_lcs = []

first_set_for_lcs = input("Enter the first sequence for searching the longest common subsequence: ")
second_set_for_lcs = input("Enter the second sequence for searching the longest common subsequence: ")
length_first_set = len(first_set_for_lcs)
length_second_set = len(second_set_for_lcs)

option = int(input("Enter the type of implementation: 1- Naive ; 2-Dynamic Programming: "))
if option == 1:
    lcs_solution_set = []
    frequency_solution_set = [0 for index1 in range(0, length_first_set + 1)]
    print("The length of the lcs of", first_set_for_lcs, "and", second_set_for_lcs, "is",
          lcs_of_the_two_sets_naive_solution(first_set_for_lcs, second_set_for_lcs, length_first_set, length_second_set,
                                             lcs_solution_set, frequency_solution_set))
    lcs_solution_set.reverse()
    print("The lcs is", lcs_solution_set)
else:
    lcs_matrix = [[0 for index1 in range(0, length_second_set + 1)] for index2 in range(0, length_first_set + 1)]
    lcs_of_the_two_sets_dynamic_programming_solution(first_set_for_lcs, second_set_for_lcs, lcs_matrix,
                                                     length_first_set, length_second_set)

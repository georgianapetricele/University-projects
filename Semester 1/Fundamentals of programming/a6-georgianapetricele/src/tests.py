"""
This function tests functionalities for A and B
"""

import ui
import functions


def test_add_functions():
    list_for_test = [[1, 1], [2, 1]]
    functions.add_current_number_to_list(0, 6, list_for_test)
    assert list_for_test == [[1, 1], [2, 1], [0, 6]]


def test_insert_functions():
    list_for_test = [[1, 1], [2, 1], [2, 2]]
    functions.insert_number_to_a_position_in_list(0, 6, 2, list_for_test)
    assert list_for_test == [[1, 1], [2, 1], [0, 6], [2, 2]]


def test_for_removing_number_at_a_position():
    list_for_test = [[1, 1], [2, 1], [2, 2]]
    functions.remove_element_at_a_position_in_list(1, list_for_test)
    assert list_for_test == [[1, 1], [2, 2]]


def test_for_removing_number_between_given_positions():
    list_for_test = [[1, 1], [2, 1], [2, 2], [2, 1], [1, 2]]
    functions.remove_element_from_position_start_to_position_end(1, 3, list_for_test)
    assert list_for_test == [[1, 1], [1, 2]]


def test_for_replacing_number_in_list_with_a_given_one():
    list_for_test = [[1, 1], [2, 1], [2, 2], [2, 1], [1, 2]]
    functions.replace_element_from_list_with_another_one(2, 1, 8, 8, list_for_test)
    assert list_for_test == [[1, 1], [8, 8], [2, 2], [8, 8], [1, 2]]

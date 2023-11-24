import unittest
from src.repository import *
from src.domain import *
from src.services import *


class Tests(unittest.TestCase):
    def setUp(self) -> None:
        self.__assignments = Repo()
        self._service = Service(self.__assignments)

    def test_add_assignment(self):
        self.__assignments.read_file()
        # self.__assignments.add_assignment_repo(Assignment("6","Georgi","I do the test"))
        self.assertEqual(self._service.count_assignments(), 8)

    def test_add_assignment_repo(self):
        self.__assignments.read_file()
        self.__assignments.add_assignment_repo(Assignment("6", "Georgi", "I do the test"))
        self.assertEqual(self._service.count_assignments(), 6)

    def test_check_duplicate(self):
        self.assertEqual(self._service.check_duplicate("1"),False)





from src.repository import *
from src.domain import *


class Service:
    def __init__(self,repo):
        self.__assignments = repo

    def __str__(self):
        return str(self.__assignments)

    def get_all(self):
        return self.__assignments.get_all()

    def check_dishonesty(self):
        pass

    def count_assignments(self):
        count = 0
        for assignment in self.__assignments.get_all():
            count+=1
        return count

    def check_duplicate(self,assignment_id):
        for assignment in self.__assignments.get_all():
            if assignment.id == assignment_id:
                return True
        return False

    def get_from_file(self):
        self.__assignments.read_file()

    def add_assignment(self,assignment_id,student_name,solution):
        if len(student_name) < 3:
            raise ValueError
        elif solution == "":
            raise ValueError
        elif assignment_id.isdigit() == False or self.check_duplicate(assignment_id):
            raise ValueError
        else:
            new_assignment = Assignment(assignment_id,student_name,solution)
            self.__assignments.add_assignment_repo(new_assignment)



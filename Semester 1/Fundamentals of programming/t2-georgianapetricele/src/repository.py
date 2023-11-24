from src.domain import *


class Repo:
    def __init__(self):
        self.__assignments = []

    def __str__(self):
        string = ""
        for assignment in self.__assignments:
            string += str(assignment)+ "\n"
        return string

    def get_all(self):
        return self.__assignments

    def check_dishonesty_repo(self):
        pass

    def add_assignment_repo(self,given_assignment):
        self.__assignments.append(given_assignment)
        self.write_in_file()

    def get_all_by_name_repo(self,string_in_name):
        self.__assignments = list(filter(lambda x: string_in_name in x.name, self.__assignments))
        self.__assignments.sort(key=lambda x: x.name)
        string = ""
        for student in self.__assignments:
            string += str(student) + "\n"
        return string

    def check_for_duplicate(self,given_id):
        for student in self.__assignments:
            if student.id == given_id:
                return True
        return False

    def read_file(self,file = "input.txt"):
        fin = open(file, "rt")
        lines = fin.readlines()
        for line in lines:
            line_list = line.split(",")
            id = line_list[0].strip()
            name = line_list[1].strip()
            solution= line_list[2].strip()
            assignment = Assignment(id,name,solution)
            self.add_assignment_repo(assignment)

    def write_in_file(self,file = "input.txt"):
        fout = open(file, "wt")
        fout.write(str(Repo.__str__(self)))


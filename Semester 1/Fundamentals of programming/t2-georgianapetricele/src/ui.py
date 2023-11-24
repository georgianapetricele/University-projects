from src.services import *


class Ui:
    def __init__(self,service):
        self.__assignments = service

    def add_assignment(self):
        assignment_id = input("Enter the id: ")
        student_name = input("Enter the name of the student: ")
        solution = input("Enter the solution: ")
        try:
            self.__assignments.add_assignment(assignment_id, student_name, solution)
        except ValueError:
            print("Can't add assignment!")

    def display_assignments(self):
        print(str(self.__assignments))

    def check_dishonesty(self):
        print(self.__assignments.check_dishonesty())

    def count_assignments(self):
        print(self.__assignments.count_assignments())

    def start(self):
        self.__assignments.get_from_file()
        print("1. Add")
        print("2. Display")
        while True:
            commands =  {"1":self.add_assignment,"2":self.display_assignments,"3":self.check_dishonesty}
            option = input("Enter your option: ")
            if option not in ["1","2","3"]:
                print("Wrong input!")
            else:
                commands[option]()


service = Service(Repo())
ui = Ui(service)
ui.start()

"""
1,Anna,I will implement layered architecture
2, John,The program is layered
3, Betty,I understand layered architecture
4, Georgi,I do the test
5,Vlad,My proposed solution have layers
"""







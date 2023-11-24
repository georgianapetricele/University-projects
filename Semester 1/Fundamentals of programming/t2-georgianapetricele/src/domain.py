
class Assignment:
    def __init__(self,id,student_name,solution):
        self.__id = id
        self.__student_name = student_name
        self.__solution = solution

    def __str__(self):
        return str(self.__id) + "," + str(self.__student_name) + "," + str(self.__solution)

    @property
    def id(self):
        return self.__id

    @id.setter
    def id(self,given_id):
        self.__id = given_id

    @property
    def student_name(self):
        return self.__student_name

    @student_name.setter
    def student_name(self, given_name):
        self.__student_name = given_name

    @property
    def solution(self):
        return self.__solution

    @solution.setter
    def solution(self, given_solution):
        self.__solution = given_solution
































class Student:
    def __init__(self,id,name,attendances,grade):
        self.__id = id
        self.__name = name
        self.__attendances =attendances
        self.__grade = grade

    def __str__(self):
        return str(self.id) + ", " + str(self.name) + ", " + str(self.attendances) + ", " + str(self.grade)

    @property
    def id(self):
        return self.__id

    @id.setter
    def id(self,given_id):
        self.__id = given_id

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, given_name):
        self.__name = given_name

    @property
    def attendances(self):
        return self.__attendances

    @attendances.setter
    def attendances(self, given_number):
        self.__attendances = given_number

    @property
    def grade(self):
        return self.__grade

    @grade.setter
    def grade(self, given_grade):
        self.__grade = given_grade


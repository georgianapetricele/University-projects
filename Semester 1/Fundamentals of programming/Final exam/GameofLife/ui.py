"""
Game of life
"""
from service import *

class UI:
    def __init__(self,service):
        self.ui = service

    def place_pattern(self,list):
        try:
            self.ui.place_pattern(list)
        except ValueError:
            print("Wrong input!")
        except PositionException:
            print("Position out of board!")
        except OutofboardException:
            print("Pattern overlap!")

    def tick(self,list):
        try:
            self.ui.tick(list)
        except:
            pass

    def start(self):
        print(self.ui.get_board())
        while True:
            command = input("Enter your command: ")
            list = command.split(' ')
            if list[0] == 'place':
                self.place_pattern(list)
                print(self.ui.get_board())
            elif list[0] == 'tick':
                self.tick(list)


if __name__ == "__main__":
    repository = Repo()
    service = Service(repository)
    ui = UI(service)
    ui.start()
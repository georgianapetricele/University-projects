from controller import *

class UI:
    def __init__(self,controller):
        self._controller = controller

    def start(self):
        print(self._controller.get_board())
        self._controller.place_stars()
        self._controller.place_endeavour()
        self._controller.place_blingons()
        print(self._controller.get_board())

        while True:
            print("You started the game!")
            command = input("Enter your command: ")
            words = command.split(' ')
            if words[0] == "cheat" and len(words) == 1:
                self._controller.switch()
                print(self._controller.get_board())




repo = Repo()
controller = Controller(repo)
ui = UI(controller)
ui.start()


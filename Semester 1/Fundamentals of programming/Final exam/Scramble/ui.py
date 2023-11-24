from controller import *

class UI:
    def __init__(self,controller):
        self._controller = controller

    def start(self):

        print("A new game")
        new_sentence, sentence= self._controller.start_game()
        print(new_sentence)
        while self._controller.get_score() and new_sentence != sentence:
            command = input("Enter the command: ")
            words = command.split(' ')
            try:
                self._controller.check_command(words)
                new_sentence = self._controller.play_game(words,new_sentence)
                print(new_sentence)
            except ValueError:
                print("Wrong command!")
        if new_sentence == sentence:
            print("CONGRATSSSSS")
        else:
            print("Game over")


repo = Repo()
controller = Controller(repo)
ui = UI(controller)
ui.start()


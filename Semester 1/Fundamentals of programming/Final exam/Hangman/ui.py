from controller import *

class UI:
    def __init__(self,controller):
        self.controller = controller

    def add_sentence(self):
        sentence = input("enter the sentence: ")
        try:
            self.controller.add_sentence(sentence)
        except ValueError:
            print("Wrong sentence!")
        except NumberofLettersException:
            print("Word too small!")
        except DuplicateException:
            print("Duplicate sentence!")

    def start_game(self):
        string,sentence = self.controller.start_game()
        print(string)
        while string != sentence or self.controller.get_hangman() == "hangman":
            letter = input("Enter your guess: ")
            if self.controller.search_letter(sentence,letter) == True:
                string = self.controller.convert_sentence(sentence)
                print(string)
            else:
                self.controller.update_hangman()
        if string == sentence:
            print("Congrats!")
        else:
            print("You loose")


    def start(self):
        while True:
            option = input("Enter your option: ")
            if option == '1':
                self.add_sentence()
            elif option == "2":
                self.start_game()



repo = Repo()
control = Controller(repo)
ui = UI(control)
ui.start()

"""
Welcome to my game
"""
from service import *


class UI:
    def __init__(self,service):
        self.ui = service

    def get_board(self):
        print(self.ui.get_board_service())

    def start(self):
        ui.get_board()
        print(" ")
        while True:
            line = input("Enter the line for move: ")
            col = input("Enter the column for move: ")
            symbol = input("Enter the symbol for move: ")
            try:
                self.ui.make_turn_service(line, col, symbol)
                ui.get_board()
                if self.ui.check_for_win(line, col, symbol) == True:
                    print("Order won!")
                    break
                if self.ui.get_number_of_moves() == 36:
                    print("Chaos won!")
                    break
                line,col,symbol = self.ui.make_move_ai()
                ui.get_board()
                if self.ui.check_for_win(line, col, symbol) == True:
                    print("Order won!")
                    break
                if self.ui.check_for_win(line, col, symbol) == True:
                    print("Order won!")
                    break
                if self.ui.get_number_of_moves() == 36:
                    print("Chaos won!")
                    break
            except ValueError:
                print("Invalid move!")
            except OutsideException:
                print("Illegal move!")
            except DuplicateException:
                print("Illegal move!")


if __name__ == "__main__":
    repo = Repo()
    service = Service(repo)
    ui = UI(service)
    ui.start()
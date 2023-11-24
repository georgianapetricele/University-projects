from domain import *
from game_service import *


class UI:
    def __init__(self, board):
        self._board = board

    def ui_human_vs_human(self):
        print("Player 1 has symbol: 🟡")
        print("Player 2 has symbol: 🔴")
        name_player1 = input("Player 1, please enter your name: ")
        player1 = Player("🟡", name_player1)
        name_player2 = input("Player 2, please enter your name: ")
        player2 = Player("🔴", name_player2)
        print(self._board)
        while not self._board._check_if_is_draw_between_players():
            position_player_1 = input(player1.name + ", please enter the column you want to move: ")

            while self._board._check_if_column_is_integer(position_player_1) == False:
                print("Value is not valid!")
                position_player_1 = input(player1.name + ", please enter a valid column: ")

            while not self._board._check_if_column_is_valid(position_player_1):
                print("Column is full or outside the board!")
                position_player_1 = input(player1.name + ", please enter a valid column: ")
                while not self._board._check_if_column_is_integer(position_player_1):
                    print("Value is not valid!")
                    position_player_1 = input(player1.name + ",  please enter a valid column: ")
            position_player_1 = int(position_player_1)
            self._board.move_symbol_on_board("🟡", position_player_1)
            print(str(self._board))

            if self._board._check_if_game_is_won():
                print("Congratulations!!! " + player1.name + " is the winner.")
                self._board._clear_board()
                break

            position_player_2 = input(player2.name + ", please enter the column you want to move: ")
            while not self._board._check_if_column_is_integer(position_player_2):
                print("Value is not valid!")
                position_player_2 = input(player2.name + ", please enter a valid column: ")

            while not self._board._check_if_column_is_valid(position_player_2):
                print("Column is full or outside the board!")
                position_player_2 = input(player2.name + ", please enter a valid column: ")
                while not self._board._check_if_column_is_integer(position_player_2):
                    print("Value is not valid!")
                    position_player_2 = input(player2.name + ", please enter a valid column: ")
            position_player_2 = int(position_player_2)
            self._board.move_symbol_on_board("🔴", position_player_2)
            print(str(self._board))

            if self._board._check_if_game_is_won():
                print("Congratulations!!! " + player2.name + " is the winner.")
                self._board._clear_board()
                break

    def ui_human_vs_computer(self):
        print("Player has symbol: 🟡")
        print("Computer has symbol: 🔴")
        name_player = input("Player, please enter your name: ")
        player1 = Player("🟡", name_player)
        player2 = AI("🟡", "🔴", 4)
        print(self._board)
        while not self._board._check_if_is_draw_between_players():
            position_player_1 = input(player1.name + ", please enter the column you want to move: ")

            while self._board._check_if_column_is_integer(position_player_1) == False:
                print("Value is not valid!")
                position_player_1 = input(player1.name + ", please enter a valid column: ")

            while not self._board._check_if_column_is_valid(position_player_1):
                print("Column is full or outside the board!")
                position_player_1 = input(player1.name + ", please enter a valid column: ")
                while not self._board._check_if_column_is_integer(position_player_1):
                    print("Value is not valid!")
                    position_player_1 = input(player1.name + ",  please enter a valid column: ")
            position_player_1 = int(position_player_1)
            self._board.move_symbol_on_board("🟡", position_player_1)
            print(str(self._board))
            if self._board._check_if_game_is_won():
                print("Congratulations!!! " + player1.name + " is the winner.")
                self._board._clear_board()
                break

            print("It's Computer's turn!")
            position_computer = int(player2.search_for_the_best_move_at_a_given_state(self._board._get_board()))
            self._board.move_symbol_on_board("🔴", position_computer)
            print(str(self._board))
            if self._board._check_if_game_is_won():
                print("Computer is the winner :(")
                self._board._clear_board()
                break

    @staticmethod
    def print_menu():
        print()
        print("Welcome to Connect4")
        print()
        print("Choose your option")
        print("1. Human vs Human")
        print("2. Human vs Computer")
        print("3. Exit the game")
        print()

    def start(self):
        commands = {"1": self.ui_human_vs_human, "2": self.ui_human_vs_computer}
        while True:
            UI.print_menu()
            option = input("Enter your option: ")
            if option not in ["1", "2"] and option != "3":
                print("Please enter a valid option!")
                option = input("Enter your new option: ")
            elif option == "3":
                print("You will exit the game!")
                break
            else:
                commands[option]()


service = GameService(Board())
ui = UI(service)
ui.start()

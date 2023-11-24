from game_repo import *
from domain import *


class GameService:
    def __init__(self,board):
        self.__board = board

    def __str__(self):
        return str(self.__board)

    def _check_if_is_draw_between_players(self):
        result = self.__board._check_if_is_draw_between_players_repo()
        return result

    def _check_if_column_is_integer(self,column):
        if column.isdigit():
            return True
        return False

    def _check_if_column_is_valid(self,column):
        result = self.__board._check_if_column_is_valid_repo(column)
        return result

    def _check_if_game_is_won(self):
        result = self.__board._check_if_game_is_won_repo()
        return result

    def _clear_board(self):
        self.__board._clear_board_repo()

    def move_symbol_on_board(self,given_symbol,given_column):
        self.__board._put_given_symbol_on_given_column_repo(given_symbol,given_column)

    def _get_board(self):
        return self.__board


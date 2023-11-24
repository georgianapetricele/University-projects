"""
Here I have the board
"""
import texttable


class ColumnIsFullException(Exception):
    pass

class ColumnOutsideException(Exception):
    pass

class Board:
    def __init__(self):
        self._board_matrix = [["│    " for column in range(8)] for line in range(6)]

    def __str__(self):
        self._board_string = "  1    2    3    4    5    6    7 \n"
        self._board_string += "------------------------------------\n"
        for line in range(6):
            for column in range(8):
                self._board_string += self._board_matrix[line][column]
            self._board_string += "\n------------------------------------\n"
        return self._board_string

    def _check_if_is_draw_between_players_repo(self):
        for line in range(6):
            for column in range(8):
                if self._board_matrix[line][column] == "│    ":
                    return False
        return True

    def _check_if_column_is_valid_repo(self,column):
        if int(column) not in [1, 2, 3, 4, 5, 6, 7]:
            return False
        if self._board_matrix[0][int(column)-1] != "│    ":
            return False
        return True

    def _check_if_game_is_won_repo(self):
        # Pe orizontala sa am 4 cercuri galbene sau rosii
        for line in range(6):
            for column in range(4):
                if self._board_matrix[line][column] != "│    ":
                    if self._board_matrix[line][column] == self._board_matrix[line][column+1]:
                        if self._board_matrix[line][column+1] == self._board_matrix[line][column+2]:
                            if self._board_matrix[line][column + 2] == self._board_matrix[line][column + 3]:
                                return True
        for column in range(8):
            for line in range(3):
                if self._board_matrix[line][column] != "│    ":
                    if self._board_matrix[line][column] == self._board_matrix[line+1][column]:
                        if self._board_matrix[line+1][column] == self._board_matrix[line+2][column]:
                            if self._board_matrix[line+2][column] == self._board_matrix[line+3][column]:
                                return True

        for line in range(3):
            for column in range(4):
                if self._board_matrix[line][column] != "│    ":
                    if self._board_matrix[line][column] == self._board_matrix[line+1][column+1]:
                        if self._board_matrix[line+1][column+1] == self._board_matrix[line+2][column+2]:
                            if self._board_matrix[line+2][column+2] == self._board_matrix[line+3][column+3]:
                                return True
        for line in range(3):
            for column in range(7,2,-1):
                if self._board_matrix[line][column] != "│    ":
                    if self._board_matrix[line][column] == self._board_matrix[line+1][column-1]:
                        if self._board_matrix[line+1][column-1] == self._board_matrix[line+2][column-2]:
                            if self._board_matrix[line+2][column-2] == self._board_matrix[line+3][column-3]:
                                return True
        return False

    def _put_given_symbol_on_given_column_repo(self,symbol,column):
        column -= 1
        for line in range(5,-1,-1):
            if self._board_matrix[line][column] == "│    ":
                self._board_matrix[line][column] = "│ " + str(symbol) + " "
                break

    def _clear_board_repo(self):
        for line in range(6):
            for column in range(8):
                self._board_matrix[line][column] = "│    "

    def _get_line_from_human_last_move(self,human_column):
        for line in range(6):
            if self._board_matrix[line][human_column] == "🟡":
                return line
        return 0









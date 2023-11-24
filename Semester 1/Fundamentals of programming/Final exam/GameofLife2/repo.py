from texttable import Texttable


class Board(object):
    def __init__(self):
        self._board = [[0 for j in range(8)] for i in range(8)]

    def __str__(self):
        board = Texttable()
        for row in self._board:
            board.add_row(['x' if element == 1 else ' ' for element in row])
        return board.draw()

    def get_board(self):
        return self._board

    def set_board(self, new_board):
        self._board = new_board


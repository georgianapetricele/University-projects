from repo import *
from random import randint,choice

class OutsideException(Exception):
    pass

class DuplicateException(Exception):
    pass


class Service:
    def __init__(self,repository):
        self.service = repository
        self.last_move_line = 0
        self.last_move_col = 0
        self.last_symbol = ''

    def get_board_service(self):
        return str(self.service)

    def check_values(self,line, col):
        if not line.isdigit() or not col.isdigit():
            return False
        return True

    def make_move_ai(self):
        l = int(self.last_move_line)
        c = int(self.last_move_col)
        line = choice([l,l+1,l-1])
        col = choice([c,c+1,c-1])
        if self.last_symbol == 'X':
            symbol = 'O'
        else:
            symbol = 'X'
        while self.service.check_duplicate(line,col) or not self.check_cell(line,col,symbol):
            line = choice([l, l + 1, l - 1])
            col = choice([c, c + 1, c - 1])
            if self.last_symbol == 'X':
                symbol = 'O'
            else:
                symbol = 'X'
        self.service.make_turn_repo(line,col,symbol)
        return line,col,symbol

    def get_number_of_moves(self):
        return self.service.get_number_of_moves()

    def check_cell(self,line,col,symbol):
        line = int(line)
        col = int(col)
        if line < 1 or line > 6 or col < 1 or col > 6:
            return False
        if symbol not in ['X','O']:
            return False
        return True

    def check_for_win(self,line,col,symbol):
        return self.service.check_for_win(line,col,symbol)

    def make_turn_service(self,line,col,symbol):
        if not self.check_values(line,col):
            raise ValueError
        elif not self.check_cell(line,col,symbol):
            raise OutsideException
        elif self.service.check_duplicate(line,col):
            raise DuplicateException
        else:
            self.last_move_line = line
            self.last_move_col = col
            self.last_symbol = symbol
            self.service.make_turn_repo(line,col,symbol)




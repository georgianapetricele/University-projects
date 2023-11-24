import random

from domain import *
from texttable import Texttable

class Repo:
    def __init__(self):
        self._board = [[' ' for j in range(cols)] for i in range(lines)]
        self.freepos = []
        self._cheat_board = [[' ' for j in range(cols)] for i in range(lines)]

    def __str__(self):
        board = Texttable()
        list = [0,1,2,3,4,5,6,7,8]
        board.header(list)
        letter = 'A'
        for i in range(lines):
            list = [letter]
            board.add_row(list+self._board[i])
            letter = ord(letter)
            letter += 1
            letter = chr(letter)
        return board.draw()

    def switch(self):
        self._board = self._cheat_board

    def str_cheat(self):
        board = Texttable()
        list = [0, 1, 2, 3, 4, 5, 6, 7, 8]
        board.header(list)
        letter = 'A'
        for i in range(lines):
            list = [letter]
            board.add_row(list + self._cheat_board[i])
            letter = ord(letter)
            letter += 1
            letter = chr(letter)
        return board.draw()

    def check_validity(self,pos_lines,pos_cols):
        for i in range(9):
            for j in range(i+1,10):
                if pos_lines[i] == pos_lines[j] and pos_cols[i] == pos_cols[j]:
                    return False
        aux_board = [[' ' for j in range(-1,9)] for i in range(-1,9)]
        dirx = [-1,-1,-1,1,1,1,0,0]
        diry = [-1,1,0,-1,1,0,-1,1]
        for i in range(10):
            line = pos_lines[i]
            col = pos_cols[i]
            aux_board[line][col] = '*'
        for line in range(8):
            for col in range(8):
                if aux_board[line][col] == '*':
                    for i in range(8):
                        if aux_board[line+dirx[i]][col+diry[i]] == '*':
                            return False
                else:
                    self.freepos.append([line,col])
        return True

    def place_endeavour(self):
        coord = random.choice(self.freepos)
        self.freepos.remove(coord)
        self._board[coord[0]][coord[1]] = 'E'

    def place_blingons(self):
        dirx = [-1, -1, -1, 1, 1, 1, 0, 0]
        diry = [-1, 1, 0, -1, 1, 0, -1, 1]

        c1 = random.choice(self.freepos)
        self.freepos.remove(c1)
        self._cheat_board[c1[0]][c1[1]] = 'B'

        c2 = random.choice(self.freepos)
        self.freepos.remove(c2)
        self._cheat_board[c2[0]][c2[1]] = 'B'

        c3 = random.choice(self.freepos)
        self.freepos.remove(c3)
        self._cheat_board[c3[0]][c3[1]] = 'B'

        for c in [c1,c2,c3]:
            for i in range(8):
                line = c[0] + dirx[i]
                col = c[1] + diry[i]
                if line >= 0 and line <= 7 and 0 <= col <= 7:
                    if self._board[line][col] == 'E':
                        self._board[c[0]][c[1]] = 'B'



    def place_stars(self):
        pos_lines = []
        pos_cols = []
        for i in range(10):
            pos_lines.append(random.randint(0,7))
            pos_cols.append(random.randint(0,7))
        while self.check_validity(pos_lines,pos_cols) == False:
            pos_lines = []
            pos_cols = []
            for i in range(10):
                pos_lines.append(random.randint(0, 7))
                pos_cols.append(random.randint(0, 7))
        for i in range(10):
            self._board[pos_lines[i]][pos_cols[i]] = '*'
        return self._board


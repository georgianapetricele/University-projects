from texttable import Texttable
from domain import *
from copy import deepcopy

class Repo:
    def __init__(self):
        self._board = [['0' for j in range(cols)] for i in range(lines)]
        self._patterns = []
        self.load_from_file()

    def __str__(self):
        board = Texttable()
        for i in range(lines):
            new_list = []
            for elem in self._board[i]:
                if elem == '0':
                    new_list.append(' ')
                else:
                    new_list.append(elem)
            board.add_row(new_list)
        return board.draw()

    def load_from_file(self):
        """
        block
        +---+---+
        | x | x |
        +---+---+
        |   |   |
        +---+---+
        """
        fin = open("input.txt","rt")
        lines = fin.readlines()
        pattern_line = []
        pattern_board = []
        current_pattern = {'name': ' ', 'board': []}
        pattern_name = lines[0].strip('\n')
        current_pattern['name'] = pattern_name
        for i in range(1, len(lines)):
            if lines[i][0] != '+' and lines[i][0] != '|':
                current_pattern['board'] = pattern_board
                self._patterns.append(current_pattern)
                current_pattern = {'name': ' ', 'board': []}
                pattern_name = lines[i].strip('\n')
                current_pattern['name'] = pattern_name
                pattern_line = []
                pattern_board = []
            elif lines[i][0] != '+':
                new_line = []
                new_line.clear()
                lines[i] = lines[i].strip('\n ')
                pattern_line = lines[i].split('|')
                for j in range(1, len(pattern_line) - 1):
                    if pattern_line[j].strip() == '':
                        new_line.append(' ')
                    else:
                        new_line.append(pattern_line[j].strip())
                pattern_board.append(deepcopy(new_line))
        current_pattern['board'] = pattern_board
        self._patterns.append(current_pattern)


    def check_for_overlap(self,line,col,dim):
        for i in range(line-1,line+dim):
            if self._board[i][col-1] != '0':
                return True
        for i in range(col-1,col+dim):
            if self._board[line-1][i] != '0':
                return True
        return False

    def get_patterns(self):
        list_of_names = []
        for pat in self._patterns:
            list_of_names.append(pat['name'])
        return list_of_names

    def get_dimension(self,pattern):
        for pat in self._patterns:
            if pat['name'] == pattern:
                return len(pat['board'][0])

    def get_board(self,pattern):
        for pat in self._patterns:
            if pat['name'] == pattern:
                return pat['board']

    def place_pattern(self,pattern,line,col,dim):
        board = self.get_board(pattern)
        for l in range(dim):
            for c in range(dim):
                self._board[line+l-1][col+c-1] = board[l][c]

    def tick(self,list):
        pass






board =Repo()
print(board._patterns)





from texttable import Texttable


class Repo:
    def __init__(self):
        self._board = [[' ' for j in range(6)] for i in range(6)]
        self.moves = []

    def read_from_file(self,filename = "input.txt"):
        fin = open(filename,"rt")

    def load_to_file(self,filename = "input.txt"):
         fout = open(filename,"wt")
         board = Texttable()
         for i in range(6):
             board.add_row(self._board[i])
         fout.write(board.draw())

    def check_duplicate(self,line,col):
        line = int(line) - 1
        col = int(col) - 1
        if [line,col] in self.moves:
            return True
        return False

    def get_number_of_moves(self):
        return self.moves

    def __str__(self):
        board = Texttable()

        for i in range(6):
            board.add_row(self._board[i])
        return board.draw()

    def make_turn_repo(self,line,col,symbol):
        line = int(line) - 1
        col = int(col) - 1
        self._board[line][col] = symbol
        self.moves.append([line,col])
        self.load_to_file()

    def check_for_win(self,line,col,symbol):
        line = int(line) - 1
        col = int(col) - 1
        #check col
        count=0
        for l in range(6):
            if self._board[l][col] == symbol:
                count+=1
        if count >=5:
            return True
        #check line
        count = 0
        for c in range(6):
            if self._board[line][c] == symbol:
                count += 1
        if count >= 5:
            return True
        """
         #above diag princ +diag princ
        for number in range(5):
            count = 1
            for l in range(5):
                for c in range(number,5):
                    if self._board[l][c] == self._board[l+1][c+1] and self._board[l][c] != ' ':
                        count+=1
            if count >=5:
                return True
        #below diag princ
        for number in range(2,5):
            count = 1
            for l in range(number,5):
                for c in range(5):
                    if self._board[l][c] == self._board[l + 1][c + 1] and self._board[l][c] != ' ':
                        count += 1
            if count >= 5:
                return True
        #above diag sec +diag sec
        for number in range(5,-1,-1):
            count =1
            for line in range(5):
                for column in range(number,0,-1):
                    if self._board[l][c] == self._board[l +1][c - 1] and self._board[l][c] != ' ':
                        count += 1
            if count >= 5:
                return True
        #below diag sec
        for number in range(2,5):
            count =1
            for line in range(number,5):
                for column in range(6,0,-1):
                    if self._board[l][c] == self._board[l +1][c - 1] and self._board[l][c] != ' ':
                        count += 1
            if count >= 5:
                return True
        """
        return False


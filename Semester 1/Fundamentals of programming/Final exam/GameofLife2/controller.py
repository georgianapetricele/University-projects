from copy import deepcopy


class Controller(object):
    def __init__(self, repo):
        self._repo = repo
        self._patterns = {}
        self.store_patterns()

    def __str__(self):
        return str(self._repo)

    def store_patterns(self):
        file = open('patterns.txt', 'r')
        lines = file.readlines()
        pattern = []
        for line in lines:
            line = line.strip('\n')
            if line[0] == '(':
                pattern_name = ''.join(line[1:-1])
                self._patterns.update({pattern_name: pattern})
                pattern = []
            else:
                if line[0] == '|':
                    new_line = [0 if line[i] == ' ' else 1 for i in range(2, len(line), 4)]
                    pattern.append(new_line)

    def add_pattern(self, pattern_name, pattern_x, pattern_y):
        if pattern_name not in self._patterns.keys():
            raise Exception(f'Pattern with name {pattern_name} does not exist.')
        pattern = self._patterns[pattern_name]
        new_board = deepcopy(self._repo.get_board())
        for i in range(len(pattern)):
            for j in range(len(pattern[i])):
                if pattern[i][j] == 1:
                    if pattern_x + i >= 8 or pattern_y + j >= 8:
                        raise Exception("Pattern can't place live cells out of the board")
                    elif new_board[pattern_x+i][pattern_y+j] == 1:
                        raise Exception("Live cells from the pattern can't overlap with those from the board")
                    new_board[pattern_x+i][pattern_y+j] = 1

        self._repo.set_board(new_board)

    def get_board(self):
        return self._repo.get_board()

    def tick(self, n=1):
        """
        this function modifies the board to show it after n generations
        :param n: number of generations
        :return:
        """
        for iteration in range(n):
            board = self._repo.get_board()
            new_board = []

            'the for in for nested loop build the board of the next generation'
            for i in range(len(board)):
                new_line = []
                for j in range(len(board[i])):
                    live_neighbours = -1 * board[i][j]
                    'we compute the live neighbours of current cell'
                    for pos_x in [-1, 0, 1]:
                        for pos_y in [-1, 0, 1]:
                            if 0 <= i+pos_x < 8 and 0 <= j+pos_y < 8:
                                live_neighbours += board[i+pos_x][j+pos_y]

                    'decide how the current cell will change based on the number of live neighbours and its current'
                    'state (dead or alive)'
                    if ((board[i][j] == 1) and (2 <= live_neighbours <= 3)) or \
                                    ((board[i][j] == 0) and live_neighbours == 3):
                        new_line.append(1)
                    else:
                        new_line.append(0)

                new_board.append(new_line)
            self._repo.set_board(new_board)

    def load_file(self, file_name):
        try:
            file = open(file_name, 'r')
        except:
            raise Exception(f"File {file_name} can't be found")
        lines = file.readlines()
        new_board = []
        for line in lines:
            line = line.strip('\n')

            if line[0] == '|':
                new_line = [0 if line[i] == ' ' else 1 for i in range(2, len(line), 4)]
                new_board.append(new_line)

        self._repo.set_board(new_board)

    def save_file(self, file_name):
        try:
            file = open(file_name, 'w')
        except:
            raise Exception(f"File {file_name} can't be found")

        file.write(str(self))



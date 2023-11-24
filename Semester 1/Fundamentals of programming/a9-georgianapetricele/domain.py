from game_repo import *


class Player:
    def __init__(self,symbol,name):
        self.__symbol = symbol
        self.__name = name

    @property
    def symbol(self):
        return self.__symbol

    @symbol.setter
    def symbol(self,given_symbol):
        self.__symbol = given_symbol

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self,given_name):
        self.__name = given_name

    def __str__(self):
        return "Player " + self.__name + " plays with " + self.__symbol

    def get_name(self):
        return self.__name


class AI:
    def __init__(self,player_symbol,computer_symbol,depth):
        self._player_symbol =player_symbol
        self._computer_symbol =computer_symbol
        self._depth = depth

    def get_symbol(self):
        return self._computer_symbol

    def check_if_column_is_not_full(self,board, column):
        for line in range(5,-1,-1):
            if board._board_matrix[line][column] == "│    ":
                return True
        return False

    def simulate_move_for_Minimax_algorithm(self,board_before_the_simulated_move:Board,symbol_introduced_in_the_move,given_column):
        board_after_the_simulated_move = Board()
        for line in range(6):
            for column in range(7):
                board_after_the_simulated_move._board_matrix[line][column] = board_before_the_simulated_move._board_matrix[line][column]
        board_after_the_simulated_move._put_given_symbol_on_given_column_repo(symbol_introduced_in_the_move,given_column+1)
        return board_after_the_simulated_move

    def search_for_the_best_move_at_a_given_state(self,board):
        valid_moves = {}
        for column in range(7):
            if self.check_if_column_is_not_full(board,column):
                board_after_the_simulated_move = self.simulate_move_for_Minimax_algorithm(board,self._computer_symbol,column)
                valid_moves[column] = -self.find_the_score_of_given_move(board_after_the_simulated_move,self._depth-1,self._player_symbol)

        best_score = -99999999
        best_move = None
        current_moves = valid_moves.items()
        for move_column,score in current_moves:
            if score > best_score:
                best_score = score
                best_move = move_column
        return best_move+1

    def find_the_score_of_given_move(self, board: Board, depth, symbol):
        valid_moves = []
        for column in range(7):
            if self.check_if_column_is_not_full(board, column):
                board_after_simulation = self.simulate_move_for_Minimax_algorithm(board,symbol, column)
                valid_moves.append(board_after_simulation)
        if depth == 0 or len(valid_moves) == 0 or board._check_if_game_is_won_repo():
            return self.find_value_of_a_given_configuration_of_board(board, symbol)

        if symbol == self._computer_symbol:
            player_symbol = self._player_symbol
        else:
            player_symbol = self._computer_symbol

        score = -99999999
        for current_board in valid_moves:
            score = max(score, -self.find_the_score_of_given_move(current_board,depth - 1, player_symbol))
        return score

    def find_value_of_a_given_configuration_of_board(self, board, symbol):
        if symbol == self._computer_symbol:
            player_symbol = self._player_symbol
        else:
            player_symbol = self._computer_symbol

        current_player_fours = self.determine_number_of_connections_of_length(board,symbol,4)
        current_player_threes = self.determine_number_of_connections_of_length(board, symbol, 3)
        current_player_twos = self.determine_number_of_connections_of_length(board, symbol, 2)
        adversar_fours = self.determine_number_of_connections_of_length(board,player_symbol, 4)
        adversar_threes = self.determine_number_of_connections_of_length(board, player_symbol, 3)
        adversar_twos = self.determine_number_of_connections_of_length(board, player_symbol, 2)

        if adversar_fours > 0:
            return -100000
        else:
            return current_player_fours*100000 + current_player_threes*100 + current_player_twos - adversar_threes*100 - adversar_twos

    def determine_number_of_connections_of_length(self,board,symbol,length):
        count_connections = 0
        for line in range(6):
            for column in range(7):
                if board._board_matrix[line][column] == "│ " + str(symbol) + " ":
                    count_connections += self.find_vertical_connections_for_position(board, line, column,length, board._board_matrix[line][column])
                    count_connections += self.find_horizontal_connections_for_position(board, line, column,length, board._board_matrix[line][column])
                    count_connections += self.find_diagonals_connections_for_position(board, line, column,length, board._board_matrix[line][column])
        return count_connections

    def find_vertical_connections_for_position(self,board,line,column,length,symbol):
        count_circles = 0
        if length-1 +line < 6:
            for current_length in range(length):
                if board._board_matrix[line+current_length][column] == str(symbol):
                    count_circles +=1
                else:
                    break
        if count_circles == length:
            return 1
        else:
            return 0

    def find_horizontal_connections_for_position(self, board, line, column, length, symbol):
        count_circles = 0
        if length - 1 + column < 7:
            for current_length in range(length):
                if board._board_matrix[line][column+current_length] == str(symbol):
                    count_circles += 1
                else:
                    current_length = length + 1
        if count_circles == length:
            return 1
        else:
            return 0

    def find_diagonals_connections_for_position(self, board, line, column, length, symbol):
        total_connections =0
        count_circles =0
        if column + length - 1 < 7 and line + length -1 <6:
            for current_length in range(length):
                if board._board_matrix[line+current_length][column+current_length] == str(symbol):
                    count_circles +=1
                else:
                    current_length = length +1
        if count_circles == length:
            total_connections +=1

        count_circles = 0
        if column + length - 1 < 7 and line - length + 1 > -1:
            for current_length in range(length):
                if board._board_matrix[line - current_length][column + current_length] == str(symbol):
                    count_circles += 1
                else:
                    current_length = length + 1
        if count_circles == length:
            total_connections += 1

        return total_connections









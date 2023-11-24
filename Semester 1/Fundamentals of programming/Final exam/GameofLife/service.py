from repo import *

class PositionException(Exception):
    pass

class OutofboardException(Exception):
    pass

class Service:
    def __init__(self,repo):
        self.service = repo

    def place_pattern(self,list):
        if len(list) != 3:
            raise ValueError
        elif list[1] not in self.service.get_patterns():
            raise ValueError
        else:
            pattern = list[1]
            word3 = list[2].split(',')
            line = int(word3[0])
            col = int(word3[1])
            dim = self.service.get_dimension(pattern)
            if line + dim > lines or col + dim > cols or line<1 or col <1:
                raise PositionException
            elif self.service.check_for_overlap(line, col, dim):
                raise OutofboardException
            else:
                self.service.place_pattern(pattern,line,col,dim)


    def get_board(self):
        return str(self.service)
from repository import *
from domain import *

class Controller:
    def __init__(self,repo):
        self._repo = repo

    def get_board(self):
        return str(self._repo)

    def switch(self):
        self._repo.switch()

    def place_endeavour(self):
        return self._repo.place_endeavour()

    def place_stars(self):
        return self._repo.place_stars()

    def place_blingons(self):
        return self._repo.place_blingons()
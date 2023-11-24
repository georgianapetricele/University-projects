import random

from repository import *

class Controller:
    def __init__(self,repo):
        self._repo = repo

    def read_file(self):
        return self._repo.read_from_file()

    def load_to_file(self):
        return self._repo.load_to_file()

    def harvest(self,planted):
        acres = self._repo.get_nr_acres()
        acres += planted
        self._repo.set_acres(acres)

    def process_grain(self, acres):
        """
        This function updates data introduced by user
        - update land price
        - update stock of grain
        """
        self._repo.set_acres(acres)
        price = random.randint(15,25)
        self._repo.set_price(price)
        grain = self._repo.get_grain_stocks()
        grain -= price * acres
        self._repo.set_grain_stocks(grain)

    def feed_population(self,grain):
        return self._repo.feed_population(grain)

    def get_population(self):
        return self._repo.get_population()

    def get_grain_stocks(self):
        return self._repo.get_grain_stocks()

    def get_land_price(self):
        return self._repo.get_land_price()

    def get_nr_acres(self):
        return self._repo.get_nr_acres()


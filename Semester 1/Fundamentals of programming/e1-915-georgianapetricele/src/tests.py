import unittest
from repository import *
from controller import *


class Test_function_for_year(unittest.TestCase):
    def setUp(self) -> None:
        self.repo = Repo()
        self.controller = Controller(self.repo)

    def test_update_grain_for_feeding_population(self):
        self.controller.update_grain_for_feeding_population(2000)
        self.assertEqual(self.repo.get_population_of_city(),100)
        self.assertEqual(self.repo.get_people_who_starved(),0)

    def test_set_grain_stocks(self):
        self.repo.set_grain_stocks(2000)
        self.assertEqual(self.controller.get_grain_stocks(),2000)

    def test_process_stock_grain_and_land_price(self):
        self.repo.set_grain_stocks(2800)
        self.controller.process_stock_grain_and_land_price(20)
        self.assertEqual(self.repo.get_grain_stocks(),2400)

    def test_update_grain_harvested(self):
        self.repo.set_grain_stocks(2000)
        self.controller.update_grain_harvested(800)
        self.assertEqual(self.repo.get_grain_stocks(),2800)
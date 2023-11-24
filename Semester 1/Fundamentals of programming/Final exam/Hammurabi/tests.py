import unittest
from repository import *
from controller import *

class Test(unittest.TestCase):
    def setUp(self) -> None:
        self._repo = Repo()
        self._controller = Controller(self._repo)
        self._repo.read_from_file()

    def test_process_grain(self):
        self._controller.process_grain(0)
        self.assertEqual(self._repo.get_grain_stocks(),2800)

    def test_feed_population(self):
        self._repo.feed_population(2000)
        self.assertEqual(self._repo.get_grain_stocks(),800)


from src.domain.domain import *
from src.services.service import *
from src.domain.validators import *
import unittest


class Tests_Repo(unittest.TestCase):
    def setUp(self) -> None:
        self.__validator = MovieValidator()
        self.__repo = Repository()

    def test_add_to_list_entity(self):
        movie = Movie("15","A Movie","Description...", "Action")
        self.__repo.add_entity_repo(movie)
        self.assertEqual(self.__repo.get_first_element(),movie)

    def test_update_entity(self):
        old_movie = Movie("15","A Movie","Description...", "Action")
        self.__repo.add_entity_repo(old_movie)
        new_movie = Movie("15","New Movie","Description...", "Action")
        self.__repo.update_entity(old_movie,new_movie)
        self.assertEqual(self.__repo.get_first_element(),new_movie)

    def test_delete_entity(self):
        movie = Movie("15", "A Movie", "Description...", "Action")
        movie1 = Movie("16", "A Movie", "Description...", "Action")
        movie2 =Movie("17", "A Movie", "Description...", "Action")
        self.__repo.add_entity_repo(movie)
        self.__repo.add_entity_repo(movie1)
        self.__repo.add_entity_repo(movie2)
        self.__repo.delete_entity_repo(movie)
        self.assertEqual(self.__repo.get_first_element().id,"16")
from src.domain.domain import *
from src.services.service import *
from src.domain.validators import *
from src.repository.base_repo import *
import unittest


class Tests_Movie_Service(unittest.TestCase):
    def setUp(self) -> None:
        self._movie_repo = Repository()
        self._movie_service = MovieService(self._movie_repo)

    def test_add_movie(self):
        self._movie_service.add_movie("15", "A Movie", "Description...", "Action")
        self._movie_service.add_movie("16", "Another Movie", "Description...", "Action")
        self.assertEqual(len(self._movie_repo),2)

    def test_delete_movie(self):
        self._movie_service.add_movie("15", "A Movie", "Description...", "Action")
        self._movie_service.add_movie("16", "Another Movie", "Description...", "Action")
        self._movie_service.remove_movie_with_given_id("15")
        self.assertEqual(len(self._movie_repo),1)

    def test_update_movie(self):
        self._movie_service.add_movie("15", "A Movie", "Description...", "Action")
        self._movie_service.update_movie_with_given_id("15","A new Movie","Description","Genre")
        self.assertEqual(self._movie_repo.get_first_element().title_of_movie,"A new Movie")


class Tests_Client_Service(unittest.TestCase):
    def setUp(self) -> None:
        self._client_repo = Repository()
        self._client_service = ClientService(self._client_repo)

    def test_add_client(self):
        self._client_service.add_client("10","Popescu Maria")
        self._client_service.add_client("11", "Popescu Marian")
        self.assertEqual(len(self._client_repo), 2)

    def test_delete_client(self):
        self._client_service.add_client("10", "Popescu Maria")
        self._client_service.add_client("11", "Popescu Marian")
        self._client_service.remove_client_with_given_id("10")
        self.assertEqual(len(self._client_repo), 1)

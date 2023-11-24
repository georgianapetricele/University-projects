from src.domain.domain import *
from src.domain.validators import *
from src.repository.base_repo import *
import unittest

class Tests_Domain(unittest.TestCase):
    def setUp(self) -> None:
        self._movie_validator = MovieValidator()
        self._client_validator = ClientValidator()
        self._rental_validator = RentalValidator()

    def test_client(self):
        client = Client("15","Popescu Maria")
        self.assertEqual(client.id_of_client,"15")
        self.assertEqual(client.name_of_client,"Popescu Maria")

        wrong_client = Client("","")
        with self.assertRaises(StoreExceptions) as se:
            self._client_validator.validate(wrong_client)
        self.assertEqual(str(se.exception), "Please enter a valid name!")


    def test_movie(self):
        movie = Movie("15","A Movie","Description...", "Action")
        self.assertEqual(movie.id,"15")
        self.assertEqual(movie.title_of_movie,"A Movie")
        self.assertEqual(movie.description_of_movie,"Description...")
        self.assertEqual(movie.genre_of_movie,"Action")

    def test_rental(self):
        rental = Rental("2","3","5","12 12 2022","22 12 2022")
        self.assertEqual(rental.rental_date,"12 12 2022")

        wrong_rental = Rental("1","2","3","43 02 2020","22 10 2022")
        with self.assertRaises(StoreExceptions) as se:
            self._rental_validator.validate(wrong_rental)
        self.assertEqual(str(se.exception), "Please enter a valid date!")


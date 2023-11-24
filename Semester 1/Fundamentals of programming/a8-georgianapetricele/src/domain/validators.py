import datetime
from src.domain.domain import *


class StoreExceptions(Exception):
    pass


class MovieValidator:
    @staticmethod
    def validate(movie):
        if movie.genre not in ["Action", "Comedy", "Drama", "Fantasy", "Horror", "Crime", "Romance", "SF",
                               "Thriller", "Animation","War","Christmas"]:
            raise StoreExceptions("Please enter a valid genre!")


class ClientValidator:
    @staticmethod
    def validate(client:Client):
        if any(char.isdigit() for char in client.name_of_client) or len(client.name_of_client) < 2:
            raise StoreExceptions("Please enter a valid name!")


class RentalValidator:
    @staticmethod
    def validate(rental:Rental):
        if bool(type(rental.rental_date) is datetime.datetime) is False:
            raise StoreExceptions("Please enter a valid date!")
        elif rental.return_date is not None:
            if bool(type(rental.rental_date) is datetime.datetime) is False:
                raise StoreExceptions("Please enter a valid date!")
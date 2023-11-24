import copy
import datetime
from collections import OrderedDict
from src.domain.domain import *
from src.repository.base_repo import *


class ClientService:
    def __init__(self, repo):
        self.__repo = repo

    def __str__(self):
        return str(self.__repo)

    def find_client_with_id(self,current_id):
        for client in self.__repo.get_all():
            if client.id_of_client == current_id:
                return client
        return None

    def add_client(self,id_of_client,name_of_client):
        new_client = Client(id_of_client,name_of_client)
        if self.find_client_with_id(id_of_client):
            raise ValueError("Duplicate Client!")
        else:
            self.__repo.add_entity_repo(new_client)

    def remove_client_with_given_id(self,id_of_client):
        current_client = self.find_client_with_id(id_of_client)
        self.__repo.delete_entity_repo(current_client)

    def update_client_with_given_id(self,id_of_client,name_of_client):
        old_client = self.find_client_with_id(id_of_client)
        new_client = Client(id_of_client,name_of_client)
        self.__repo.update_entity(old_client, new_client)

    def search_client(self,field_for_search):
        list_of_clients_with_given_field = []
        field_for_search=field_for_search.lower()
        for client in self.__repo.get_all():
            if field_for_search in client.id_of_client.lower():
                list_of_clients_with_given_field.append(str(client))
        for client in self.__repo.get_all():
            if field_for_search in client.name_of_client.lower():
                list_of_clients_with_given_field.append(str(client))
        return list_of_clients_with_given_field


class MovieService:
    def __init__(self,repo):
        self.__repo = repo

    def __str__(self):
        return str(self.__repo)

    def find_movie_with_id(self, current_id):
        for movie in self.__repo.get_all():
            if movie.id == current_id:
                return movie
        return None

    def add_movie(self,id_of_movie,title_of_movie,description_of_movie,genre_of_movie):
        new_movie = Movie(id_of_movie,title_of_movie,description_of_movie,genre_of_movie)
        if self.find_movie_with_id(id_of_movie):
            raise ValueError("Duplicate Movie!")
        else:
            self.__repo.add_entity_repo(new_movie)

    def remove_movie_with_given_id(self, id_of_movie):
        current_movie = self.find_movie_with_id(id_of_movie)
        self.__repo.delete_entity_repo(current_movie)

    def update_movie_with_given_id(self,id_of_movie,title,description,genre):
        old_movie = self.find_movie_with_id(id_of_movie)
        new_movie = Movie(id_of_movie,title,description,genre)
        self.__repo.update_entity(old_movie,new_movie)

    def search_movie(self,field_for_search):
        list_of_movies_with_given_field = []
        field_for_search = field_for_search.lower()
        for movie in self.__repo.get_all():
            if field_for_search in movie.id.lower():
                list_of_movies_with_given_field.append(str(movie))
        for movie in self.__repo.get_all():
            if field_for_search in movie.title_of_movie.lower():
                list_of_movies_with_given_field.append(str(movie))
        for movie in self.__repo.get_all():
            if field_for_search in movie.description_of_movie.lower():
                list_of_movies_with_given_field.append(str(movie))
        for movie in self.__repo.get_all():
            if field_for_search in movie.genre_of_movie.lower():
                list_of_movies_with_given_field.append(str(movie))
        return list_of_movies_with_given_field


class RentalService:
    def __init__(self, repo, client_repo, movie_repo):
        self.__repo = repo
        self.__client_repo = client_repo
        self.__movie_repo = movie_repo

    index_of_current_rental = 0

    def __str__(self):
        return str(self.__repo)

    def find_client_with_id(self,current_id):
        for client in self.__client_repo.get_all():
            if client.id_of_client == current_id:
                return client
        return None

    def find_movie_with_id(self, current_id):
        for movie in self.__movie_repo.get_all():
            if movie.id == current_id:
                return movie
        return None

    def check_if_client_and_movie_exist(self,client_id, movie_id):
        if self.find_client_with_id(client_id) is None:
            raise RepositoryException("The client doesn't exist!")
        elif self.find_movie_with_id(movie_id) is None:
            raise RepositoryException("The movie doesn't exist!")

    def get_rentals_by_client_id(self,client_id):
        # We return all the rentals of current client
        client_rentals = []
        for rental in self.__repo.get_all():
            if rental.client == client_id:
                client_rentals.append(rental)
        return client_rentals

    def get_clients_rental_by_movie_id(self,client_id,movie_id):
        rental_of_current_movie = None
        for rental in self.__repo.get_all():
            if rental.client == client_id and rental.movie == movie_id:
                rental_of_current_movie = rental
        return rental_of_current_movie

    def check_if_rental_is_possible(self,client_id):
        today = datetime.datetime.now()
        for rental in self.get_rentals_by_client_id(client_id):
            if rental.return_date is None and today > rental.due_date:
                raise RepositoryException("You have to return the movies you already rented!!!")

    def rent_movie(self,client_id,movie_id,rental_date):
        self.check_if_client_and_movie_exist(client_id,movie_id)
        self.check_if_rental_is_possible(client_id)
        self.index_of_current_rental += 1
        if rental_date == '':
            rental_date = datetime.datetime.now()
        else:
            rental_date = datetime.datetime.strptime(rental_date, "%d %m %Y")
        due_date = copy.deepcopy(rental_date)
        due_date += datetime.timedelta(days=30)
        new_rental = Rental(self.index_of_current_rental,movie_id,client_id,rental_date,due_date)
        self.__repo.add_entity_repo(new_rental)

    def check_the_rentals_for_given_client(self,client_id,movie_id):
        if len(self.get_rentals_by_client_id(client_id)) == 0:
            raise RepositoryException("Client doesn't have any rented movies!!!")

    def return_movie(self,client_id,movie_id,return_date):
        self.check_if_client_and_movie_exist(client_id, movie_id)
        self.check_the_rentals_for_given_client(client_id,movie_id)
        if return_date == '':
            return_date = datetime.datetime.now()
        else:
            return_date = datetime.datetime.strptime(return_date, "%d %m %Y")
        old_rental = self.get_clients_rental_by_movie_id(client_id,movie_id)
        new_rental = copy.deepcopy(old_rental)
        new_rental.return_date = return_date
        self.__repo.update_entity(old_rental,new_rental)

    def get_days_rented(self,current_rental):
        number_of_days_for_current_rental = 0
        today = datetime.datetime.now()
        if current_rental.return_date is None:  #daca inca nu a fost returnat => filmul e inchiriat pentru today-start zile
            number_of_days_for_current_rental += (today - current_rental.rental_date).days
        else:
            number_of_days_for_current_rental += (current_rental.return_date - current_rental.rental_date).days
        return number_of_days_for_current_rental

    def get_number_of_days_of_delay(self,current_rental:Rental):
        number_of_days_of_delay = 0
        today = datetime.datetime.now()
        if current_rental.return_date is None:   # Daca inca nu a returnat filmul scad today si data la care trebuia sa fie returnat
            number_of_days_of_delay += (today - current_rental.due_date).days
        elif current_rental.return_date.days >= current_rental.due_date.days:   # Altfel scad din data returnarii ca sa vad daca l- a returnat cu intarziere
            number_of_days_of_delay += (current_rental.return_date - current_rental.due_date).days
        return number_of_days_of_delay

    def sort_by_most_rented_movies(self):
        rented_movies = {}
        for current_rental in self.__repo.get_all():
            rented_movies[current_rental.movie] = 0
        for current_rental in self.__repo.get_all():  # parcurg fiecare rental
            rented_movies[current_rental.movie] += self.get_days_rented(current_rental)  # vad pentru fiecare rent[movie_id] de cate ori e inchiriat filmul

        rented_movies = OrderedDict(sorted(rented_movies.items(), key=lambda value: (value[1], value[0]), reverse=True))
        return rented_movies

    def sort_by_most_active_clients(self):
        active_clients = {}
        for current_rental in self.__repo.get_all():
            active_clients[current_rental.client] = 0
        for current_rental in self.__repo.get_all():
            active_clients[current_rental.client] += self.get_days_rented(current_rental)

        active_clients = OrderedDict(sorted(active_clients.items(), key=lambda value: (value[1], value[0]), reverse=True))
        return active_clients  # Return a dictionary dict[current_client] = number of days

    def sort_movies_by_their_delay_return_period(self):
        late_returned_movies = {}
        for current_rental in self.__repo.get_all():
            late_returned_movies[current_rental.movie] = 0
        for current_rental in self.__repo.get_all():  # parcurg fiecare rental
            late_returned_movies[current_rental.movie] += self.get_number_of_days_of_delay(current_rental)

        late_returned_movies = OrderedDict(sorted(late_returned_movies.items(), key=lambda value: (value[1],value[0]), reverse=True))
        return late_returned_movies

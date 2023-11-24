import datetime

from src.services.service import *
from src.repository.base_repo import *
from src.domain.validators import *


class UI:
    def __init__(self, client_service, movie_service, rental_service):
        self._client_service = client_service
        self._movie_service = movie_service
        self._rental_service = rental_service

    def ui_manage_clients_and_movies(self):
        self.print_submenu_option1()
        commands_manage = {"1": self.ui_add_client, "2": self.ui_add_movie, "3": self.ui_remove_client_with_given_id,
                           "4": self.ui_remove_movie_with_given_id, "5": self.ui_update_client_with_given_id,
                           "6": self.ui_update_movie_with_given_id, "7": self.ui_list_all_clients,
                           "8": self.ui_list_all_movies}
        option = input("Enter your option: ")
        try:
            commands_manage[option]()
        except KeyError as err:
            print(err, "Isn't a valid command. Try again!")

    def ui_add_client(self):
        id_of_current_client = input("Enter the id of the new client: ")
        name_of_current_client = input("Enter the name of the new client: ")
        try:
            self._client_service.add_client(id_of_current_client, name_of_current_client)
        except ValueError:
            print("Enter valid data!")
        except RepositoryException as exp:
            print(exp)
        except StoreExceptions as exp:
            print(exp)

    def ui_add_movie(self):
        id_of_current_movie = input("Enter the id of the new movie: ")
        name_of_current_movie = input("Enter the name of the new movie: ")
        description_of_current_movie = input("Enter the description of the new movie: ")
        genre_of_current_movie = input("Enter the genre of the new movie: ")
        try:
            self._movie_service.add_movie(id_of_current_movie, name_of_current_movie, description_of_current_movie,
                                          genre_of_current_movie)
        except ValueError as err:
            print(err)
        except RepositoryException as exp:
            print(exp)
        except StoreExceptions as exp:
            print(exp)

    def ui_remove_client_with_given_id(self):
        id_of_client_to_remove = input("Enter the id of the client to remove: ")
        try:
            self._client_service.remove_client_with_given_id(id_of_client_to_remove)
        except ValueError:
            print("Enter valid data!")
        except StoreExceptions as exp:
            print(exp)

    def ui_remove_movie_with_given_id(self):
        id_of_movie_to_remove = input("Enter the id of the movie to remove: ")
        try:
            self._movie_service.remove_movie_with_given_id(id_of_movie_to_remove)
        except ValueError:
            print("Enter valid data!")
        except RepositoryException as exp:
            print(exp)
        except StoreExceptions as exp:
            print(exp)

    def ui_update_client_with_given_id(self):
        id_of_client_to_update = input("Enter the id of the client to update: ")
        new_name_of_client_to_update = input("Enter the new name of the client to update: ")
        try:
            self._client_service.update_client_with_given_id(id_of_client_to_update, new_name_of_client_to_update)
        except ValueError:
            print("Enter valid data!")
        except RepositoryException as exp:
            print(exp)
        except StoreExceptions as exp:
            print(exp)

    def ui_update_movie_with_given_id(self):
        id_of_movie_to_update = input("Enter the id of the movie to update: ")
        new_name_of_movie = input("Enter the new name of the movie to update: ")
        new_description_of_movie = input("Enter the new description of the movie to update: ")
        new_genre_of_movie = input("Enter the new genre of the movie to update: ")
        try:
            self._movie_service.update_movie_with_given_id(id_of_movie_to_update, new_name_of_movie,
                                                           new_description_of_movie, new_genre_of_movie)
        except ValueError:
            print("Enter valid data!")
        except RepositoryException as exp:
            print(exp)
        except StoreExceptions as exp:
            print(exp)

    def ui_list_all_clients(self):
        print(str(self._client_service))

    def ui_list_all_movies(self):
        print(str(self._movie_service))

    def ui_rent_a_movie(self):
        client_id = input("Enter the id of the client: ")
        movie_id = input("Enter the id of the movie to rent: ")
        rental_date = input("Enter the day when the movie is rented: ")
        try:
            self._rental_service.rent_movie(client_id, movie_id, rental_date)
        except ValueError as err:
            print(err)
        except RepositoryException as err:
            print(err)
        except StoreExceptions as exp:
            print(exp)
        print(str(self._rental_service))

    def ui_return_a_movie(self):
        client_id = input("Enter the id of the client: ")
        movie_id = input("Enter the id of the movie to return: ")
        return_date = input("Enter the day when the movie is returned: ")
        try:
            self._rental_service.return_movie(client_id, movie_id, return_date)
        except ValueError as err:
            print(err)
        except RepositoryException as err:
            print(err)
        except StoreExceptions as exp:
            print(exp)

    def ui_rent_or_return_a_movie(self):
        self.print_submenu_option2()
        commands = {"1": self.ui_rent_a_movie, "2": self.ui_return_a_movie}
        option = input("Enter your option: ")
        try:
            commands[option]()
        except KeyError as err:
            print(err, "Isn't a valid command. Try again!")

    def ui_most_rented_movies(self):
        most_rented_movies = self._rental_service.sort_by_most_rented_movies()
        for movie_id in most_rented_movies.keys():
            print("-", self._movie_service.find_movie_with_id(movie_id).title_of_movie, "with ID:",
                  self._movie_service.find_movie_with_id(movie_id).id, "rented for:", most_rented_movies[movie_id],
                  "days")

    def ui_most_active_clients(self):
        most_active_clients = self._rental_service.sort_by_most_active_clients()
        for client_id in most_active_clients.keys():
            print("-", self._client_service.find_client_with_id(client_id).name_of_client, "with ID:",
                  self._client_service.find_client_with_id(client_id).id_of_client, "rented movies for: ", most_active_clients[client_id],"days" )

    def ui_late_rentals(self):
        movies_with_late_rentals = self._rental_service.sort_movies_by_their_delay_return_period()
        for movie_id in movies_with_late_rentals.keys():
            print("-",self._movie_service.find_movie_with_id(movie_id).title_of_movie,"has a return delay of", movies_with_late_rentals[movie_id],"days")

    def ui_create_statistics(self):
        self.print_submenu_option4()
        option = input("Enter your option: ")
        try:
            if option == "1":
                self.ui_most_rented_movies()
            elif option == "2":
                self.ui_most_active_clients()
            elif option == "3":
                self.ui_late_rentals()
            else:
                raise ValueError(option,"Isn't a valid command. Try again!")
        except ValueError as err:
            print(err)

    def ui_search_for_clients_or_movies(self):
        self.print_submenu_option3()
        option = input("Enter your option: ")
        field_for_search = input("Enter the field for searching: ")
        try:
            if option == "1":
                print(*self._client_service.search_client(field_for_search), sep="\n")
            elif option == "2":
                print(*self._movie_service.search_movie(field_for_search), sep="\n")
        except ValueError as err:
            print(err)

    def initialize_clients(self):
        self._client_service.add_client("1", "Client1")
        self._client_service.add_client("2", "Client2")
        self._client_service.add_client("3", "Client3")
        self._client_service.add_client("4", "Client4")
        self._client_service.add_client("5", "Client5")
        self._client_service.add_client("6", "Client6")
        self._client_service.add_client("7", "Client7")
        self._client_service.add_client("8", "Client8")
        self._client_service.add_client("9", "Client9")
        self._client_service.add_client("10", "Client10")

    def initialize_movies(self):
        self._movie_service.add_movie("1", "Interstelar",
                                      "Earth's future has been riddled by disasters, famines, and droughts. There is "
                                      "only one way to ensure mankind's survival: Interstellar travel. A newly "
                                      "discovered wormhole in the far reaches of our solar system allows a team of "
                                      "astronauts to go where no man has gone before, a planet that may have the "
                                      "right environment to sustain human life.",
                                      "SF")
        self._movie_service.add_movie("2", "Forrest Gump",
                                      "The presidencies of Kennedy and Johnson, the Vietnam War, the Watergate "
                                      "scandal and other historical events unfold from the perspective of an Alabama "
                                      "man with an IQ of 75, whose only desire is to be reunited with his childhood "
                                      "sweetheart.",
                                      "Drama")
        self._movie_service.add_movie("3", "Pulp Fiction",
                                      "The lives of two mob hitmen, a boxer, a gangster and his wife, and a pair of "
                                      "diner bandits intertwine in four tales of violence and redemption.",
                                      "Crime")
        self._movie_service.add_movie("4", "Spirited Away",
                                      "During her family's move to the suburbs, a sullen 10-year-old girl wanders "
                                      "into a world ruled by gods, witches, and spirits, and where humans are changed "
                                      "into beasts.",
                                      "Animation")
        self._movie_service.add_movie("5", "Harry Potter and the Philosopher's Stone",
                                      "An orphaned boy enrolls in a school of wizardry, where he learns the truth "
                                      "about himself, his family and the terrible evil that haunts the magical world.",
                                      "Fantasy")
        self._movie_service.add_movie("6", "Klaus",
                                      "When Smeerensburg's new postman, Jesper, befriends toymaker Klaus, their gifts "
                                      "melt an age-old feud and deliver a sleigh full of holiday traditions.",
                                      "Christmas")
        self._movie_service.add_movie("7", "Inglourious Basterds",
                                      "In Nazi-occupied France during World War II, a plan to assassinate Nazi "
                                      "leaders by a group of Jewish U.S. soldiers coincides with a theatre owner's "
                                      "vengeful plans for the same.",
                                      "War")
        self._movie_service.add_movie("8", "The Matrix",
                                      "When a beautiful stranger leads computer hacker Neo to a forbidding underworld, "
                                      "he discovers the shocking truth--the life he knows is the elaborate deception "
                                      "of "
                                      "an evil cyber-intelligence.",
                                      "SF")
        self._movie_service.add_movie("9", "Good Will Hunting",
                                      "Will Hunting, a janitor at M.I.T., has a gift for mathematics, but needs help "
                                      "from a psychologist to find direction in his life.",
                                      "Drama")
        self._movie_service.add_movie("10", "The Truman Show",
                                      "An insurance salesman discovers his whole life is actually a reality TV show.",
                                      "Comedy")

    @staticmethod
    def print_principal_menu():
        print()
        print("Welcome to my Movie Rental app!")
        print("Choose your option:")
        print("1. Manage clients and movies")
        print("  - Add client or movie")
        print("  - Remove client or movie")
        print("  - Update client or movie")
        print("  - List client or movie")
        print("2.Rent or return a movie")
        print("3.Search for clients or movies using any one of their fields (e.g. movies can be searched for using id,"
              " title, description or genre)")
        print("4.Create statistics")
        print("  - List most rented movies")
        print("  - List most active  clients")
        print("  - List late rentals")
        print("5.Exit")
        print()

    @staticmethod
    def print_submenu_option1():
        print("Here you can manage clients and movies!")
        print("1. Add a new client")
        print("2. Add a new movie")
        print("3. Remove the client with given id")
        print("4. Remove the movie with given id")
        print("5. Update the client with given id")
        print("6. Update the movie with given id")
        print("7. List the clients")
        print("8. List the movies")
        print()

    @staticmethod
    def print_submenu_option2():
        print("Here you can rent or return a movie!")
        print("1. Rent a movie (You have 30 days to return it!)")
        print("2. Return a movie")

    @staticmethod
    def print_submenu_option3():
        print("1. Search a client (by one of its fields)")
        print("2. Search a movie  (by one of its fields)")

    @staticmethod
    def print_submenu_option4():
        print("Here you can create statistics!")
        print("1.Most rented movies. This will provide the list of movies, sorted in descending order of the number "
              "of days they were rented.")
        print("2. Most active clients. This will provide the list of clients, sorted in descending order of the "
              "number of movie rental days they have (e.g. having 2 rented movies for 3 days each counts as 2 x 3 = 6 "
              "days).")
        print("3.Late rentals. All the movies that are currently rented, for which the due date for return has "
              "passed, sorted in descending order of the number of days of delay.")

    def start(self):
        commands = {"1": self.ui_manage_clients_and_movies, "2": self.ui_rent_or_return_a_movie,
                    "3": self.ui_search_for_clients_or_movies, "4": self.ui_create_statistics}
        self.initialize_clients()
        self.initialize_movies()
        while True:
            self.print_principal_menu()
            option = input("Enter your desired option: ")
            try:
                commands[option]()
            except KeyError as keyerr:
                print(keyerr, "Isn't a valid command. Try again!")


client_repo = Repository()
movie_repo = Repository()
client_service = ClientService(client_repo)
movie_service = MovieService(movie_repo)
rental_repo = Repository()
rental_service = RentalService(rental_repo, client_repo, movie_repo)
ui = UI(client_service, movie_service, rental_service)
ui.start()

class Client:
    def __init__(self,id_of_client,name_of_client):
        self.__id_of_client = id_of_client
        self.__name_of_client = name_of_client

    @property
    def id_of_client(self):
        return self.__id_of_client

    @property
    def name_of_client(self):
        return self.__name_of_client

    @id_of_client.setter
    def id_of_client(self,value_of_id):
        self.__id_of_client = value_of_id

    @name_of_client.setter
    def name_of_client(self,value_of_name):
        self.__name_of_client = value_of_name

    def __str__(self):
        return "Client with ID: " + str(self.__id_of_client) + " is " + str(self.__name_of_client)


class Movie:
    def __init__(self,id,title_of_movie,description_of_movie,genre_of_movie):
        self.__id = id
        self.__title_of_movie = title_of_movie
        self.__description_of_movie = description_of_movie
        self.__genre_of_movie = genre_of_movie

    @property
    def id(self):
        return self.__id

    @property
    def title_of_movie(self):
        return self.__title_of_movie

    @property
    def description_of_movie(self):
        return self.__description_of_movie

    @property
    def genre_of_movie(self):
        return self.__genre_of_movie

    @title_of_movie.setter
    def title_of_movie(self,value_of_title):
        self.__title_of_movie = value_of_title

    @description_of_movie.setter
    def description_of_movie(self, value_of_description):
        self.__description_of_movie = value_of_description

    @genre_of_movie.setter
    def genre_of_movie(self, value_of_genre):
        self.__genre_of_movie = value_of_genre

    def __str__(self):
        return "-> Movie with ID: " + str(self.__id) + " is " + " << " +str(self.__title_of_movie)+ " >>" + "\n  Genre: " + str(self.__genre_of_movie) + "\n  Description: " + str(self.__description_of_movie)


class Rental:
    def __init__(self, rental_id,  movie,client, rental_date, due_date, return_date=None):
        self.__rental_id = rental_id
        self.__client = client
        self.__movie = movie
        self.__rental_date = rental_date
        self.__due_date = due_date
        self.__return_date = return_date

    @property
    def rental_id(self):
        return self.__rental_id

    @property
    def client(self):
        return self.__client

    @property
    def movie(self):
        return self.__movie

    @property
    def rental_date(self):
        return self.__rental_date

    @property
    def due_date(self):
        return self.__due_date

    @property
    def return_date(self):
        return self.__return_date

    @movie.setter
    def movie(self, value):
        self.__movie = value

    @client.setter
    def client(self, value):
        self.__client = value

    @rental_date.setter
    def rental_date(self, value):
        self.__rental_date = value

    @due_date.setter
    def due_date(self, value):
        self.__due_date = value

    @return_date.setter
    def return_date(self, value):
        self.__return_date = value

    def __str__(self):
        rental_string=""
        rental_string+= "-> Rental: " + str(self.rental_id) + "\n  Movie: " + str(self.movie) + "\n  Client: " + str(
            self.client) + "\n  Period: " + self.__rental_date.strftime("%d %m %Y") + " to " + self.__due_date.strftime("%d %m %Y")
        return rental_string

# print(str(Movie("12","ad","dervbt","dcerbbtrvdsafvbtr")))
#print(Rental("1",Client("1","Popescu"),Movie("12","ad","dervbt","dcerbbtrvdsafvbtr"),))
from src.domain import Book


class Service:
    def __init__(self,repo):
        self.__books_list = repo
        undo_list=[]
        # self.__book_list nu i o lista e un obiect de tip repo, repo are o lista

    @property
    def books(self):
        return self.__books_list

    def add_book(self,given_isbn,given_title,given_author):
        new_book = Book(given_isbn,given_title,given_author)
        self.__books_list.add_book_repo(new_book)

    def undo_last_operation(self):
        self.__books_list.undo_last_operation_repo()

    def get_all(self):
        return str(self.__books_list)

    def __str__(self):
        return str(self.__books_list)

    def delete_book_whose_title_starts_with_word(self,given_first_word_of_title):
        self.__books_list.delete_book_whose_title_starts_with_word_repo(given_first_word_of_title)



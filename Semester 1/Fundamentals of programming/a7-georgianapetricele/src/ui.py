"""
Manage a list of books. Each book has an isbn (string, unique), an author and a title (strings). Provide the following
features:

Add a book. Book data is read from the console.
Display the list of books.
Filter the list so that book titles starting with a given word are deleted from the list.
Undo the last operation that modified program data. This step can be repeated. The user can undo only those operations
 made during the current run of the program.
"""

from src.repos import *
from src.service import *
import copy


class UI:
    def __init__(self, service):
        self._books = service

    def ui_add_book(self):
        isbn_of_current_book = input("Enter the isbn of current book: ")
        title_of_current_book = input("Enter the title of current book: ")
        author_of_current_book = input("Enter the author of current book: ")
        try:
            self._books.add_book(isbn_of_current_book, title_of_current_book, author_of_current_book)
        except ValueError as err:
            print(err)

    def ui_display_all_books(self):
        # create function
        print(self._books.get_all())

    def ui_delete_book_whose_title_starts_with_word(self):
        given_word = input("Enter the first word of the title from the book to delete: ")
        self._books.delete_book_whose_title_starts_with_word(given_word)

    def ui_undo_last_operation(self):
        try:
            self._books.undo_last_operation()
            print("Operation successfully undone!")
        except Exception as err:
            print(err)

    @staticmethod
    def print_menu():
        print("1. Add the chosen book")
        print("2. Display the list of books")
        print("3. Delete the books whose title starts with given word ")
        print("4. Undo the last operation that modified data")

    def start(self):
        while True:
            UI.print_menu()
            try:
                option = int(input("Enter your option: "))
                if option == 1:
                    self.ui_add_book()
                elif option == 2:
                    self.ui_display_all_books()
                elif option == 3:
                    self.ui_delete_book_whose_title_starts_with_word()
                elif option == 4:
                    self.ui_undo_last_operation()
            except ValueError:
                print("Wrong option!")

    # UI.start()


current_repo = TextFileRepo()
chosen_service = Service(current_repo)
ui = UI(chosen_service)
ui.start()

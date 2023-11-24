from src.domain import *
from src.repos import *
from src.service import *
import unittest


class Tests_Domain(unittest.TestCase):
    def setUp(self) -> None:
        pass

    def test_book(self):
        book = Book("1", "A book", "An author")
        self.assertEqual(book.title, "A book")

        book = Book("1", "Another book", "An author")
        self.assertEqual(book.title, "Another book")


class Tests_Service(unittest.TestCase):
    def setUp(self) -> None:
        self._repo = MemoryRepo()
        self._service = Service(self._repo)

    def test_add_book(self):
        self._service.add_book("10", "Title", "Author")
        self._service.add_book("11", "Title1", "Author1")
        self.assertEqual(len(self._repo), 11)

    def test_delete_book(self):
        self._service.add_book("10", "Book 1", "Author")
        self._service.add_book("11", "Book 2", "Author")
        self.assertEqual(len(self._repo), 11)
        self._service.delete_book_whose_title_starts_with_word("Book")
        self.assertEqual(len(self._repo), 9)

    def test_undo_book(self):
        self._service.add_book("10", "Title", "Author")
        self.assertEqual(len(self._repo), 10)
        self._service.undo_last_operation()
        self.assertEqual(len(self._repo), 9)


class Tests_Repo(unittest.TestCase):
    def setUp(self) -> None:
        self._repo = MemoryRepo()

    def test_add_book_repo(self):
        book = Book("1", "A book", "An author")
        self._repo.add_book_repo(book)
        self.assertEqual(len(self._repo), 10)

    def test_delete_book(self):
        book1 = Book("10", "book 1", "An author")
        book2 = Book("20", "book 2", "An author")
        self._repo.add_book_repo(book1)
        self._repo.add_book_repo(book2)
        self.assertEqual(len(self._repo), 11)
        self._repo.delete_book_whose_title_starts_with_word_repo("book")
        self.assertEqual(len(self._repo), 9)

    def test_undo_last_operation_repo(self):
        book1 = Book("10", "book 1", "An author")
        book2 = Book("20", "book 2", "An author")
        self._repo.add_book_repo(book1)
        self._repo.add_book_repo(book2)
        self.assertEqual(len(self._repo), 11)
        self._repo.undo_last_operation_repo()
        self.assertEqual(len(self._repo), 10)
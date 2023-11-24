import copy

from src.domain import Book
import pickle


class MemoryRepo(object):
    def __init__(self):
        self._books_repo = [Book("978-1-60309-502-1", "Pride and Prejudice", "Jane Austen"),
                            Book("978-1-60309-502-2", "Harry Potter and the Chamber of Secrets", "J. K. Rowling"),
                            Book("978-1-60309-502-3", "The Da Vinci Code", "Dan Brown	"),
                            Book("978-1-60309-502-4", "The Hunger Games", "Suzanne Collins"),
                            Book("978-1-60309-502-5", "Nineteen Eighty-Four", "George Orwell"),
                            Book("978-1-60309-502-6", "One Hundred Years of Solitude", "Gabriel García Márquez"),
                            Book("978-1-60309-502-7", "The Fault in Our Stars", "John Green"),
                            Book("978-1-60309-502-8", "The Lost Symbol", "Dan Brown"),
                            Book("978-1-60309-502-9", "Hard-Boiled Wonderland and the End of the World",
                                  "Haruki Murakami")]
        self._undo_history_list =[['list', self._books_repo.copy()]]

    def undo_last_operation_repo(self):
        assert len(self._undo_history_list) != 0, "ERROR: There is nothing to undo!"
        if self._undo_history_list[-1][0] == 'add' or self._undo_history_list[-1][0] == 'delete':
            self._undo_history_list.pop()
            self._books_repo = self._undo_history_list[-1][1]

    def add_book_repo(self, new_book: Book):
        for index in range(len(self._books_repo)):
            if self._books_repo[index].isbn == new_book.isbn:
                raise ValueError("Duplicate book!")
        self._books_repo.append(new_book)
        self._undo_history_list.append(['add', self._books_repo[:]])  # adaug tipul operatiei si lg listei pana acum

    def delete_book_whose_title_starts_with_word_repo(self, given_first_word_of_title):
        self._books_repo = list(filter(lambda x: x.first_word_title != given_first_word_of_title, self._books_repo))
        self._undo_history_list.append(['delete', self._books_repo[:]])

    def get(self, book_isbn):
        return self._books_repo[book_isbn]

    def __str__(self):
        list_of_str_books = ""
        for current_book in self._books_repo:
            list_of_str_books += str(current_book) + "\n"
        return list_of_str_books

    def get_all(self):
        return str(self._books_repo.__str__())

    def return_list(self):
        return self._books_repo

    def __len__(self):
        return len(self._books_repo)

    def __copy__(self):
        return copy.deepcopy(self)


class TextFileRepo(MemoryRepo):
    def __init__(self, file_name="books.txt"):
        super().__init__()
        self._file_name = file_name
        self.read_from_file()

    def read_from_file(self):
        # open a text file for reading
        # t - text file mode, r - reading
        fin = open(self._file_name, "rt")
        try:
            lines = fin.readlines()
            fin.close()
            for line in lines:
                current_line = line.split(" ")
                new_book = Book(current_line[0].strip(), current_line[1].strip(), current_line[2].strip())
        except EOFError:
            pass
        except IndexError:
            pass

    def add_book_repo(self, new_book: Book):
        # call the add() method on the super class
        # we want to do everything the superclass add() already does
        # NOTE call super() so that we don't write the file we're reading from
        self.read_from_file()
        super().add_book_repo(new_book)
        self._save_file()

    def delete_book_whose_title_starts_with_word_repo(self, given_word):
        self.read_from_file()
        super().delete_book_whose_title_starts_with_word_repo(given_word)
        self._save_file()

    def undo_last_operation_repo(self):
        self.read_from_file()
        super().undo_last_operation_repo()
        self._save_file()

    def _save_file(self):
        fout = open(self._file_name, "wt")
        fout.write(str(MemoryRepo.__str__(self)))
        fout.close()


class BinaryFileRepo(MemoryRepo):
    def __init__(self, file_name= "books.bin"):
        super().__init__()
        self._file_name = file_name

    def _read_from_file(self):
        # r - read mode, b - binary file
        fin = open(self._file_name, "rb")
        try:
            self._book_repo = pickle.load(fin)
        except EOFError:
            pass

    def add_book_repo(self, new_book: Book):
        super().add_book_repo(new_book)
        self._read_from_file()
        self._save_file()
        # self.__append_to_file(new_book)

    def delete_book_whose_title_starts_with_word_repo(self, given_first_word_of_title):
        super().delete_book_whose_title_starts_with_word_repo(given_first_word_of_title)
        self._read_from_file()
        self._save_file()

    def undo_last_operation_repo(self):
        super().undo_last_operation_repo()
        self._read_from_file()
        self._save_file()

    def __append_to_file(self,new_book):
        fout = open(self._file_name, "wb")
        pickle.dump(new_book, fout)

    def _save_file(self):
        # w - write mode, b - binary file
        fout = open(self._file_name, "wb")
        # serialize, marshal with pickle -> write to a binary file, or
        # to a network socket, or some remote procedure call (RPC)
        pickle.dump(self._books_repo, fout)
        fout.close()
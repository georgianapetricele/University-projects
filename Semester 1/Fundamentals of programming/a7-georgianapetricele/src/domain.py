
# Regular methods take as the first argument the instance
"""
   def apply_raise(self):
    self._pay = self.pay+ self.raise
"""
# Class methods take the class as the first argument
"""
    @classmethod
    def set_raise_amount(cls, amount):
       cls.raise_amount = amount
"""
# Static methods don't take the class or the instance as the first argument
"""
    @staticmethod
    def set_raise_amount(cls, amount):
       cls.raise_amount = amount
"""

# Aici lucrez cu obiectul

class Book:
    def __init__(self,isbn:str,title:str,author:str):
        self.__isbn = isbn
        self.__title = title
        self.__author = author
        words_of_title = self.__title.split(' ')
        self.__first_word_title = words_of_title[0]

    def __str__(self):
        return "Book " + str(self.__title) + " with isbn " + str(self.__isbn) + " is written by " + str(self.__author)

    @property
    def isbn(self):
        return self.__isbn

    @property
    def title(self):
        return self.__title

    @property
    def author(self):
        return self.__author

    @property
    def first_word_title(self):
        return self.__first_word_title

    @isbn.setter
    def isbn(self,current_book_isbn):
        self.__isbn= current_book_isbn


    @title.setter
    def title(self,current_book_title):
        self.__title = current_book_title



    @author.setter
    def author(self,current_book_author):
        self.__author = current_book_author


carte = Book("123","sdnj","dhwk jd ksjk")
print(carte.first_word_title)



import random

from repository import *

class NumberofLettersException(Exception):
    pass

class DuplicateException(Exception):
    pass

class Controller:
    def __init__(self,repo):
        self.repo = repo
        self.letters = []
        self.hangman = "hangman"
        self.final = ""
        self.pos = 0

    def check_words(self,words):
        for word in words:
            if len(word) < 3:
                return False
        return True

    def convert_sentence(self,sentence):
        string = ""
        for i in sentence:
            if i in self.letters or i == ' ':
                string += str(i)
            else:
                string += '_'
        return string

    def start_game(self):
        self.final = ""
        self.letters = []
        self.pos = 0
        list_sentences = self.repo.get_sentences()
        sentence = random.choice(list_sentences)
        words = sentence.split(' ')
        for word in words:
            self.letters.append(word[0])
            self.letters.append(word[len(word)-1])
        string = self.convert_sentence(sentence)
        return string,sentence

    def search_letter(self,sentence,letter):
        for i in sentence:
            if i == letter:
                self.letters.append(i)
                return True
        return False

    def get_hangman(self):
        return self.final

    def update_hangman(self):
        if self.final != self.hangman:
            self.final += self.hangman[self.pos]
            self.pos += 1

    def add_sentence(self,sentence):
        words = sentence.split(' ')
        if len(words) <1:
            raise ValueError
        elif self.check_words(words) == False:
            raise NumberofLettersException
        elif self.repo.check_duplicate(sentence):
            raise DuplicateException
        else:
            self.repo.add_sentence(sentence)

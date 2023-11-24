import random


class Repo:
    def __init__(self):
        self.sentence= []
        self.list_lines = []
        self.read_file()

    def get_sentences(self):
        return self.list_lines

    def read_file(self):
        fin = open("input.txt", "rt")
        lines = fin.readlines()
        for line in lines:
            self.list_lines.append(line.strip('\n'))


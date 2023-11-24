
class Repo:
    def __init__(self):
        self.repo = []
        self.read_from_file()

    def read_from_file(self):
        fin = open("sentences.txt","rt")
        lines = fin.readlines()
        for line in lines:
            self.repo.append(line.strip('\n'))

    def get_sentences(self):
        return self.repo

    def check_duplicate(self,sentence):
        fin = open("sentences.txt", "rt")
        lines = fin.readlines()
        for line in lines:
            line = line.strip('\n ')
            if line == sentence:
                return True
        return False

    def add_sentence(self,sentence):
        self.repo.append(sentence)

from repository import *
import random

class Controller:
    def __init__(self,repo):
        self._repo = repo
        self.positions = []
        self.pos_in_word = []
        self.score = 1

    def suffle_letters(self,sentence):
        """
        Suffles letters between words with property
        Updates the score
        :param sentence:
        :return: The new sentence
        """
        for pos in range(len(sentence) - 1):
            if pos and pos!= len(sentence)-1 and sentence[pos] != ' ' and sentence[pos + 1] != ' ' and sentence[pos - 1] != ' ':
                self.positions.append(pos)
        new_sentence = ""
        pos = 0
        self.score = 1
        for pos in range(len(sentence)-1):
            if sentence[pos] != ' ':
                self.score +=1
            if pos and pos!= len(sentence)-1 and sentence[pos] != ' ' and sentence[pos + 1] != ' ' and sentence[pos - 1] != ' ':
                new_index = random.choice(self.positions)
                self.positions.remove(new_index)
                new_letter = sentence[new_index]
                new_sentence += new_letter
            else:
                new_sentence += sentence[pos]
        new_sentence += sentence[pos+1]
        return new_sentence

    def get_score(self):
        return self.score

    def start_game(self):
        """
        Select random sentence from file
        :return: The suffled sentence
        """
        sentence = random.choice(self._repo.get_sentences())
        words = sentence.split(' ')
        count = -1
        self.pos_in_word = [[0 for j in range(len(words[i]))] for i in range(len(words))]
        for word in words:
            count += 1
            self.pos_in_word[count] = []
            word = word.strip(' ')
            for pos in range(len(word)):
                if pos and pos != len(word)-1:
                    self.pos_in_word[count].append(pos)
        new_sentence = self.suffle_letters(sentence)
        return new_sentence,sentence

    def check_command(self,words):
        if len(words) != 6 or words[0] != "swap" or int(words[1]) > len(words) or int(words[4]) > len(words):
            raise ValueError
        if words[2].isdigit():
            words[2] = int(words[2])
        else:
            raise ValueError
        if words[5].isdigit():
            words[5] = int(words[5])
        else:
            raise ValueError
        if words[2] not in self.pos_in_word[int(words[1])]:
            raise ValueError
        if words[5] not in self.pos_in_word[int(words[4])]:
            raise ValueError

    def play_game(self,words,new_sentence):
        """
        aux1 = letter from first word on given pos
        aux2 = letter from second word on given pos
        :param words:
        :param new_sentence:
        :return:
        """
        poscuv1 = int(words[1])
        poscuv2 = int(words[4])
        poslit1= int(words[2])
        poslit2 = int(words[5])
        new_word1 = ""
        new_word2 =""
        aux1 = 0
        aux2 = 0
        words_sentence = new_sentence.split(' ')
        countcuv = 0
        countword = -1
        for pos in range(len(new_sentence)):
            countword += 1
            if new_sentence[pos] == ' ':
                countword = -1
                countcuv +=1
            elif countcuv == poscuv1 and countword == poslit1:
                aux1 = pos
            elif countcuv == poscuv2 and countword == poslit2:
                aux2 = pos
        new_sentence1 = ""
        auxx = ""
        for pos in range(len(new_sentence)):
            if pos == aux1:
                new_sentence1 += new_sentence[aux2]
            elif pos == aux2:
                new_sentence1 += new_sentence[aux1]
            else:
                new_sentence1 += new_sentence[pos]
        self.score -= 1
        return new_sentence1






"""
control = Controller(Repo())
print(control.start_game())
"""


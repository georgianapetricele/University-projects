import random


class Repo:
    def __init__(self):
        self.config = []
        self.population_starve = 0
        self.new_people = 0

    def read_from_file(self):
        fin = open("input.txt","rt")
        lines = fin.readlines()
        for line in lines:
            words = line.split(' ')
            for word in words:
                word = word.strip('.')
                word = word.strip(',')
                word = word.strip('\n')
                if word.isdigit():
                    self.config.append(int(word))

    def load_to_file(self):
        fout = open("input.txt", "wt")
        string = "In year " + str(int(self.config[0]) + 1) + ", " + str(self.population_starve) + " people starved."+ "\n"
        string += str(self.new_people) + " people came to the city" + "\n"
        string += "City population is " + str(self.config[3]) + "\n"
        string += "City owns " + str(self.config[4]) + " acres of land" + "\n"
        string += "Harvest was " + str(self.config[5]) + " per acre" + "\n"
        string += "Rats ate " + str(self.config[6]) + " units" + "\n"
        string += "Land price is " + str(self.config[7]) + " per acre" + "\n"
        string += "Grain stocks are " + str(self.config[8]) + " units" + "\n"
        fout.write(string)

    def feed_population(self,grain_to_feed):
        """
        :param grain_to_feed:
        :return: False if half of people starve
            True otherwise
            Update: - grain stocks
                    - population
        """
        initial_grain = self.get_grain_stocks()
        initial_grain -= grain_to_feed
        population_starve = 0
        self.set_grain_stocks(initial_grain)
        if grain_to_feed < 20*self.get_population():
            population_to_feed = grain_to_feed//20
            grain_to_feed -= 20 *population_to_feed
            population_starve = self.get_population() - population_to_feed
            if population_starve >= self.get_population()//2:
                return False
            elif population_starve == 0:
                new_people = random.randint(0,10)
                self.new_people = new_people
                population = self.get_population()
                population+=new_people
                self.set_population(population)
        else:
            grain_to_feed -= 20*self.get_population()
        self.population_starve = population_starve
        return True


    def get_grain_stocks(self):
        return self.config[8]

    def set_grain_stocks(self,grain):
        self.config[8] =grain

    def get_land_price(self):
        return self.config[7]

    def get_nr_acres(self):
        return self.config[4]

    def get_price_per_acre(self):
        return self.config[8]

    def get_population(self):
        return self.config[3]

    def set_acres(self,acres):
        self.config[4] += acres

    def set_price(self,price):
        self.config[7] = price

    def set_population(self,population):
        self.config[3] = population




"""
config = Repo()
print(config.config)
"""

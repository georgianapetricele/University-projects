import random

from repository import *
class PopulationStarvingException(Exception):
    pass

class Controller:
    def __init__(self,repo):
        self.repo = repo

    def increase_year(self):
        self.repo.increase_year()

    def get_message(self):
        return self.repo

    def get_population_of_city(self):
        return self.repo.get_population_of_city()

    def get_acres_of_land(self):
        return self.repo.get_acres_of_land()

    def update_grain_harvested(self,acres_planted):
        """
        3)
        :param acres_planted:
         Update : -grain stocks
                    - new random harvest unit per acre
        """

        harvest_surface = acres_planted * self.repo.get_harvest_units_per_acre()
        how_much_acres_can_villager_plant = acres_planted // self.repo.get_old_population()

        new_grain_stock = self.repo.get_grain_stocks() + how_much_acres_can_villager_plant*self.repo.get_old_population()
        self.repo.set_grain_stocks(new_grain_stock)

        new_harvest_unit_per_acre = random.randint(1,6)
        self.repo.set_harvest_units_per_acre(new_harvest_unit_per_acre)

    def update_grain_for_feeding_population(self,units_grain_to_feed):
        """
        2) Update grain stocks for feeding population
        :param units_grain_to_feed:
        :return:
        """
        new_stock_of_grain = self.get_grain_stocks() - units_grain_to_feed
        self.repo.set_grain_stocks(new_stock_of_grain)

        population_fed_with_given_grain = units_grain_to_feed//20
        if population_fed_with_given_grain < self.get_population_of_city()//2:
            raise PopulationStarvingException
        elif population_fed_with_given_grain == self.get_population_of_city():

            new_people = random.randint(0,10)
            self.repo.set_new_people_number(new_people)
            population_updated = population_fed_with_given_grain +new_people
            self.repo.set_population(population_updated)
        else:
            self.repo.set_old_population(self.get_population_of_city())
            people_who_starved = self.get_population_of_city() - population_fed_with_given_grain
            self.repo.set_people_who_starved(people_who_starved)
            population_updated = population_fed_with_given_grain
            self.repo.set_population(population_updated)


    def process_stock_grain_and_land_price(self,acres_land):
        """
        1) Process stock grain and updates land price
        :param acres_land:
        :return:
        """
        price = self.get_land_price_per_acre()*acres_land
        new_price = self.get_grain_stocks() - price
        self.repo.set_grain_stocks(new_price)

        land_price = random.randint(15,25)
        self.repo.set_land_price_per_acre(land_price)

    def get_year(self):
        return self.repo.get_year()

    def update_grain_eaten_by_rats(self):
        self.repo.set_grain_eaten_by_rats(0)

    def get_grain_stocks(self):
        return self.repo.get_grain_stocks()

    def get_harvest_units_per_acre(self):
        self.repo.get_harvest_units_per_acre()

    def get_land_price_per_acre(self):
        return self.repo.get_land_price_per_acre()

    def update_grain_eaten_by_rats(self,value):
        self.repo.set_grain_eaten_by_rats(value)


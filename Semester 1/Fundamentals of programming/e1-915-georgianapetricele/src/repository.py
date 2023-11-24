

class Repo:
    def __init__(self):
        self.year = 0
        self.people_starved = 0
        self.new_people = 0
        self.population = 100
        self.acres_land = 1000
        self.harvest_units_per_acre = 3
        self.grain_eaten = 200
        self.old_population = 100
        self.land_price_per_acre = 20
        self.grain_stocks = 2800

    def get_land_price_per_acre(self):
        return self.land_price_per_acre

    def get_people_who_starved(self):
        return self.people_starved

    def increase_year(self):
        self.year +=1

    def get_old_population(self):
        return self.old_population

    def set_old_population(self,number_old_population):
        self.old_population = number_old_population

    def get_population_of_city(self):
        return self.population

    def get_grain_stocks(self):
        return self.grain_stocks

    def get_acres_of_land(self):
        return self.acres_land

    def get_harvest_units_per_acre(self):
        return self.harvest_units_per_acre

    def set_harvest_units_per_acre(self,new_harvest_unit_per_acre):
        self.harvest_units_per_acre = new_harvest_unit_per_acre

    def set_grain_stocks(self, new_stock):
        self.grain_stocks = new_stock

    def set_land_price_per_acre(self,new_price_per_acre):
        self.land_price_per_acre = new_price_per_acre

    def get_year(self):
        if self.year < 5:
            return False
        else:
            return True

    def set_population(self,population_updated):
        self.population = population_updated

    def set_grain_eaten_by_rats(self,value):
        self.grain_eaten = value

    def set_new_people_number(self,number_new_people):
        self.new_people = number_new_people

    def set_people_who_starved(self,number_people_who_starved):
        self.people_starved = number_people_who_starved

    def __str__(self):
        string  = "In year " + str(self.year)+ ","  + str(self.people_starved)+ " people starved." + "\n"
        string += str(self.new_people) + " people came to the city." + "\n"
        string += "City population is " + str(self.population) + "\n"
        string += "City owns " + str(self.acres_land) + " acres of land." + "\n"
        string += "Harvest was " + str(self.harvest_units_per_acre) + " units per acre." + "\n"
        string += "Rats ate " + str(self.grain_eaten) + " units. " + "\n"
        string += "Land price is " + str(self.land_price_per_acre) + " units per acre." + "\n"
        string+= "\n"
        string += "Grain stocks are " + str(self.grain_stocks) + " units."
        return string


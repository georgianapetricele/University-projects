from controller import *


class UI:
    def __init__(self, controller):
        self.controller = controller

    def start(self):
        game_over = False
        for count in range(5):
            print()
            self.controller.increase_year()
            print(self.controller.get_message())
            print()
            if count == 4:
                break
            acres_land = input("Acres to buy/sell (+/-): ")
            while acres_land.isdigit() == False:
                try:
                    if int(acres_land) < 0:
                        break
                except ValueError:
                    print("Enter a number!!!")
                acres_land = input("Acres to buy/sell (+/-): ")
            acres_land = int(acres_land)
            if acres_land > 0 and int(self.controller.get_land_price_per_acre())*acres_land > int(self.controller.get_grain_stocks()):
                    print("You can't do this!!!")
                    break
            elif acres_land < 0 and self.controller.get_acres_of_land() < acres_land:
                    print("You can't do this!!!")
                    break
            else:
                self.controller.process_stock_grain_and_land_price(acres_land)

            units_grain_to_feed = input("Units to feed the population: ")
            while units_grain_to_feed.isdigit() == False:
                print("Enter a number!!!")
                units_grain_to_feed = input("Units to feed the population: ")
            units_grain_to_feed = int(units_grain_to_feed)
            if int(self.controller.get_grain_stocks()) < units_grain_to_feed:
                    print("You can't do this!!!")
                    break
            else:
                try:
                    self.controller.update_grain_for_feeding_population(units_grain_to_feed)
                except PopulationStarvingException:
                    print("GAME OVER!!! People starved!!!")
                    game_over = True
                    break

            acres_planted = input("Acres to plant: ")
            while acres_planted.isdigit() == False:
                acres_planted = input("Acres to plant: ")
            acres_planted = int(acres_planted)
            if int(self.controller.get_acres_of_land()) < acres_planted:
                print("You can't do this!!!")
            self.controller.update_grain_harvested(acres_planted)

            if self.controller.get_year() == False:
                self.controller.update_grain_eaten_by_rats(0)

        if game_over == False:
            if int(self.controller.get_population_of_city()) >= 100 and int(self.controller.get_acres_of_land()) >= 1000:
                print("CONGRATS!!!")
            else:
                print("GAME OVER!!! You did not do very well!!!")





repo = Repo()
controller = Controller(repo)
ui = UI(controller)
ui.start()


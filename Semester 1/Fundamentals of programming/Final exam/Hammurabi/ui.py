from controller import *

class UI:
    def __init__(self,controller):
        self._controller = controller

    def start(self):
        for count in range(5):
            print("A new year!")
            self._controller.read_file()
            acres = input("Enter nr of acres to buy/sell: ")
            while acres.isdigit() == False:
                if int(acres) < 0:
                    break
                acres = input("Enter nr of acres to buy: ")
            acres = int(acres)
            if acres < 0:
                while abs(acres) > self._controller.get_nr_acres():
                    print("You can't do this!")
                    acres = input("Enter nr of acres to sell: ")
            else:
                while acres*self._controller.get_land_price() > int(self._controller.get_grain_stocks()):
                    print("You can't do this!")
                    acres = input("Enter nr of acres to buy: ")

            grain = input("Enter units of grain: ")
            while grain.isdigit() == False:
                grain = input("Enter units of grain: ")
            grain =int(grain)
            while grain > int(self._controller.get_grain_stocks()):
                print("You can't do this!")
                grain = input("Enter units of grain: ")

            planted = input("Enter how many acres are planted: ")
            while planted.isdigit() == False:
                planted = input("Enter how many acres are planted: ")
            planted = int(planted)
            while planted > int(self._controller.get_nr_acres()):
                print("You can't do this!")
                planted = input("Enter how many acres are planted: ")
                planted = int(planted)

            self._controller.process_grain(acres)
            if self._controller.feed_population(grain) == False:
                print("GAME OVER!!!")
                break
            self._controller.harvest(planted)
            self._controller.load_to_file()
        if int(self._controller.get_population()) > 100 and int(self._controller.get_nr_acres()) > 1000:
            print("Congrats!!!")
        else:
            print("Game OVER. You did not do very well!")



repo = Repo()
control = Controller(repo)
ui = UI(control)
ui.start()
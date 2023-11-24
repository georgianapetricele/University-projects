class UI(object):
    def __init__(self, controller):
        self._controller = controller

    def print_board(self):
        print(str(self._controller))

    def call_ui(self):

        while True:
            self.print_board()
            command = input('>')
            command = command.split(' ')

            if command[0] == 'place' and len(command) == 3:
                try:
                    pattern_name = command[1]
                    pattern_coord = (int(command[2][0]), int(command[2][2]))
                    if not 1 <= pattern_coord[0] <= 8 or not 1 <= pattern_coord[1] <= 8:
                        raise Exception('Pattern coordinate out of board')
                    self._controller.add_pattern(pattern_name, pattern_coord[0]-1, pattern_coord[1]-1)
                except Exception as error:
                    print(error)

            elif command[0] == 'tick':
                if len(command) == 1:
                    self._controller.tick()
                else:
                    try:
                        num_of_ticks = int(command[1])
                        self._controller.tick(num_of_ticks)
                    except Exception as error:
                        print(error)

            elif command[0] == 'save' and len(command) == 2:
                try:
                    file_name = command[1]
                    self._controller.save_file(file_name)
                except Exception as error:
                    print(error)

            elif command[0] == 'load' and len(command) == 2:
                try:
                    file_name = command[1]
                    self._controller.load_file(file_name)
                except Exception as error:
                    print(error)








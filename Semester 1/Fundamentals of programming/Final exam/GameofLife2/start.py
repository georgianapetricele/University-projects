from repo import Board
from controller import Controller
from ui import UI

board = Board()
controller = Controller(board)
ui = UI(controller)

ui.call_ui()
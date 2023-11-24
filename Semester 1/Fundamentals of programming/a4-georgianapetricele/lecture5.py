"""
Create a calculator program for rational numbers with the following functionalities:
    + add a rational number to the calculator
    u undo the last operation
    x exit
"""
import random

# ----------------------#
# Non-UI functions here #
# ----------------------#

def get_num(q):
    # return q[0]
    return q["num"]


def get_den(q):
    # return q[1]
    return q["den"]



def to_str(q):
    if get_den(q) == 1:
        return str(get_num(q))
    return str(get_num(q)) + "/" + str(get_den(q))


# -----------------------#
# Only UI functions here #
# -----------------------#

def create_rectangle(x1,x2,y1,y2):
    rectangle=[]
    rectangle.append(x1)

def generate_rectangles(count):
    rectangles=[]
    while count>0:
        x1 = random.randint(-20, 20)
        y1 = random.randint(-20, 20)
        x2 =x1+ random.randint(-20, 20)
        y2 =y1+ random.randint(-20, 20)
        new_rect=create_rectangle(x1, x2, y1, y2)
        flag = True
        for rect in rectangles:
            if equal_rect(rect, new_rect) is True:
                flag = False
        if flag:
            rectangles.append(new_rect)
            count -= 1
    return rectangles

def add_rectangle(rectangles_list):

    if x1 <= x2 or y1 <= y2:
        return
    rectangle = create_rectangle(x1,x2,y1,y2)
    rectangles_list.append(rectangle)

def delete_rectangle(rectangle_list,rectangle,x1,y1,x2,y2):


def show_all_rectangles(rectangle_list):
    return rectangle_list


def show_rectangles_that_intersect_the_given_one(rectangles_list):





if __name__ == "__main__":
    start()
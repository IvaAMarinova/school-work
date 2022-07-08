'draws rectangles and circles'

import turtle
import math

class Point:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y

    def get_x(self):
        return self.__x

    def get_y(self):
        return self.__y

    def __str__(self):
        return f"Point({self.x}, {self.y})"


class Rectangle():
    def __init__(self, start_point, width, height, rotation, color):
        self.__start_pt = start_point
        self.__color = color
        self.__width = width
        self.__height = height
        self.__rotation = rotation
        self.__pen = turtle.Turtle()

    def print_rectangle(self):
        print("{0}, {1}, {2}, {3}".format(self.a, self.b, self.c, self.d))

    def draw(self):
        self.__pen.penup()
        self.__pen.goto(self.__start_pt.get_x(), self.__start_pt.get_y())
        self.__pen.pendown()
        self.__pen.left(self.__rotation)

        self.__pen.begin_fill()
        self.__pen.color(self.__color)
        self.__draw_side(self.__width)
        self.__draw_side(self.__height)
        self.__draw_side(self.__width)
        self.__draw_side(self.__height)
        self.__pen.end_fill()
        self.__pen.hideturtle()

    def __draw_side(self, side_length):
        self.__pen.forward(side_length)
        self.__pen.right(90)

    
class Circle():
    def __init__(self, start_point, r, color):
        self.__start_pt = start_point
        self.__r = r
        self.__color = color
        self.__pen = turtle.Turtle()
    
    def draw(self):
        self.__pen.penup()
        self.__pen.goto(self.__start_pt.get_x(), self.__start_pt.get_y())
        self.__pen.pendown()
     
        self.__pen.begin_fill()
        self.__pen.color(self.__color)
        self.__pen.circle(self.__r)
        self.__pen.end_fill()
        self.__pen.hideturtle()



array = list()
array = list()

array.append(Rectangle(Point(100, 50), 80, 40, 20, 'yellow'))
array.append(Rectangle(Point(120, 70), 200, 20, 120, 'blue'))
array.append(Rectangle(Point(-120, -60), 180, 40, 120, 'green'))
array.append(Circle(Point(10, -80), 140, 'pink'))
array.append(Circle(Point(10, -70), 110, 'blue'))
array.append(Circle(Point(10, -60), 80, 'purple'))

for shape in array:
    shape.draw()


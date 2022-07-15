'Simple class using abc'

import turtle
from abc import ABC, abstractmethod

class Point:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y

    @property
    def x(self):
        return self.__x

    @property
    def y(self):
        return self.__y

    def __str__(self):
        return f"Point({self.x}, {self.y})"

class Shape:
    def __init__(self, start_point, color):
        self._color = color
        self._start_point = start_point
        self._pen = turtle.Turtle()
        self._pen.color(color)

    @abstractmethod
    def draw():
        pass

class Rectangle(Shape):
    def __init__(self, start_point, width, height, rotation_angle, color):
        Shape.__init__(self, start_point, color)
        self.__width = width
        self.__height = height
        self.__rotation_angle = rotation_angle
        
    def draw(self):
        self._pen.penup()
        self._pen.goto(self._start_point.x, self._start_point.y)
        self._pen.pendown()
        self._pen.left(self.__rotation_angle)
        self._pen.begin_fill()
        self.__draw_side(self.__width)
        self.__draw_side(self.__height)
        self.__draw_side(self.__width)
        self.__draw_side(self.__height)
        self._pen.end_fill()
        self._pen.color("black")
        self._pen.write("Area", font=("Arial", 16, "normal"))

    def __draw_side(self, side_length):
        self._pen.forward(side_length)
        self._pen.left(90)


class Circle(Shape):
    def __init__(self, start_point, radius, color):
        Shape.__init__(self, start_point, color)
        self.__radius = radius

    def draw(self):
        self._pen.penup()
        self._pen.goto(self._start_point.x, self._start_point.y)
        self._pen.pendown()
        self._pen.begin_fill()
        self._pen.circle(self.__radius)
        self._pen.end_fill()


if __name__ == "__main__":
    rect_list = list()
    rect_list.append(Rectangle(Point(100, 200), 150, 200, 0, "blue"))
    rect_list.append(Rectangle(Point(-100, -200), 250, 50, 30, "orange"))
    rect_list.append(Rectangle(Point(0, 0), 250, 20, 45, "green"))
  
    for rect in rect_list:
        rect.draw()

    circle_list = list()
    circle_list.append(Circle(Point(100, -200), 75, "red"))
    circle_list.append(Circle(Point(-200, -200), 75, "pink"))

    for circle in circle_list:
        circle.draw()

    turtle.done()
"""
Turtle module
"""
import turtle

class Point:
    "Class for Point"
    def __init__(self, x_coordinate, y_coordinate):
        self.__x = x_coordinate
        self.__y = y_coordinate

    @property
    def x(self):
        "Returns value of x"
        return self.__x

    @property
    def y(self):
        "Returns value of y"
        return self.__y

    def __str__(self):
        return f"Point({self.__x}, {self.__y})"


class Polyline:
    "Class for Polyline"
    def __init__(self, points):
        self.__points = points
        self.__pen = turtle.Turtle()

    @property
    def points(self):
        "Used to return value of points"
        return self.__points

    def add_point(self, point):
        "Adds a normal point to list"
        self.__points.append(point)

    def add_special_point(self, position, point):
        "Adds special point to list"
        self.__points.insert(position, point)

    def delete_special_point(self, position):
        "Deletes special point from list"
        self.__points.pop(position)


    def __str__(self):
        string = "These are the points that you gave me: \n"
        counter = 0
        for i in self.__points:
            string += f"{i} \n"
            counter = counter + 1
        return string

    def draw(self):
        "Draws with turtle"
        count = 0
        self.__pen.penup()
        while count < len(self.__points):
            self.__pen.goto(self.__points[count].x, self.__points[count].y)
            self.__pen.pendown()
            count+=1


if __name__ == '__main__':
    'Draws shapes usign Turtle module'
    poly = Polyline([Point(100, 150), Point(150, 200), Point(200, -50)])

    print(poly)

    poly.add_special_point(2, Point(50, 50))
    print(poly)

    poly.delete_special_point(2)
    print(poly)

    poly.add_point(Point(150, 150))
    print(poly)

    poly.draw()

    turtle.done()
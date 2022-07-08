from abc import ABC, abstractclassmethod
import random
from datetime import date

class Vehicle(ABC):
    "Abstract class that all vehicles get"
    def __init__(self, type_vehicle, model, speed):
        self._type_vehicle = type_vehicle
        self._model = model
        self._speed = speed

    @abstractclassmethod
    def type_and_model(self):
        "Prints vehicle's Type and Model"
        pass

    @abstractclassmethod
    def sofia_to_burgas(self):
        "Returns the time that the vehicle will need to reach Burgas from Sofia"
        pass


class Car(Vehicle):
    "Class for vehicle Car"
    def __init__(self, type, model, speed):
        Vehicle.__init__(self, type, model, speed)

    def type_and_model(self):
        "Prints vehicle's Type and Model"
        print(f'Type: {self._type_vehicle}, Model: {self._model}')
  
    def sofia_to_burgas(self):
        "Returns the time that the vehicle will need to reach Burgas from Sofia"
        return 360 / self._speed

    def police(self):
        n = random.randint(0, 10)
        if n < 5:
            print('The police stopped them!')


class Plane(Vehicle):
    "Class for vehicle Plane"
    def __init__(self, type_vehicle, model, speed):
        Vehicle.__init__(self, type_vehicle, model, speed)

    def type_and_model(self):
        "Prints vehicle's Type and Model"
        print(f'Type: {self._type_vehicle}, Model: {self._model}')
   
    def sofia_to_burgas(self):
        "Returns the time that the vehicle will need to reach Burgas from Sofia"
        return 360 / self._speed

    def latest_model(self):
        return f"This company's latest plane model is {self._type_vehicle} {date.today().year}"


class Bike(Vehicle):
    "Class for vehicle Bike"
    def __init__(self, type_vehicle, model, speed):
        Vehicle.__init__(self, type_vehicle, model, speed)

    def type_and_model(self):
        "Prints vehicle's Type and Model"
        print(f'Type: {self._type_vehicle}, Model: {self._model}')
   
    def sofia_to_burgas(self):
        "Returns the time that the vehicle will need to reach Burgas from Sofia"
        return 360 / self._speed


class Motorbike(Vehicle):
    "Class for vehicle Motorbike"
    def __init__(self, type_vehicle, model, speed, color):
        Vehicle.__init__(self, type_vehicle, model, speed)
        self.__color = color
  
    def type_and_model(self):
        "Prints vehicle's Type and Model"
        print(f'Type: {self._type_vehicle}, Model: {self._model}')
  
    def sofia_to_burgas(self):
        "Returns the time that the vehicle will need to reach Burgas from Sofia"
        return 360 / self._speed

    def tire_color(self):
        "Return color of tire based on my opinion"
        if self.__color == 'Black':
            return 'White'

        if self.__color == 'White':
            return 'Black with white spots'

        if self.__color == 'Green':
            return 'Black'

        return 'Brown'


class Autopark:
    "Contains all vehicles"
    def __init__(self):
        self.__all_vehicles = []

    def add_vehicle(self, vehicle):
        "Adds vehicle to list of vehicles"
        self.__all_vehicles.append(vehicle)
  
    def remove_vehicle(self, vehicle):
        "Removes vehicle to list of vehicles"
        i = 0
        for item in self.__all_vehicles:
            if item == vehicle:
                self.__all_vehicles.pop(i)
                i += 1

    def __str__(self):
        str_all = ''
        for vehicle in self.__all_vehicles:
           str_all += f'Model: {vehicle._model}, Type: {vehicle._type_vehicle}, Speed: {vehicle._speed}\n'
        return str_all

    
if __name__ == '__main__':
    park = Autopark()
    bike1 = Bike("Planobeg", "3000", 10)
    bike2 = Bike("weBike", "4", 15)
    car1 = Car("Tesla", "4", 250)
    car2 = Car("BWM", "8", 300)
    plane1 = Plane("AirFlier", "17", 10000)
    plane2 = Plane("Airstriker", "2", 11000)
    motorbike1 = Motorbike("Old but gold", "Limited", 30, "Blue")
    motorbike2 = Motorbike("New and better", "Unreal", 31, "Black")

    bike1.type_and_model()
    print(bike1.sofia_to_burgas())
    print('\n')
    car1.type_and_model()
    print(car1.sofia_to_burgas())
    car1.police()
    print('\n')
    plane1.type_and_model()
    print(plane1.sofia_to_burgas())
    print(plane1.latest_model())
    print('\n')
    bike1.type_and_model()
    print(motorbike1.sofia_to_burgas())
    print(motorbike1.tire_color())
    print('\n')

    park.add_vehicle(bike1)
    print(park)
    park.remove_vehicle(bike1)

    park.add_vehicle(bike1)
    park.add_vehicle(car1)
    park.add_vehicle(car2)
    park.add_vehicle(plane1)
    park.add_vehicle(plane2)
    park.add_vehicle(motorbike1)
    park.add_vehicle(motorbike2)

    print(park)

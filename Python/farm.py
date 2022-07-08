from abc import ABC, abstractclassmethod

class Animal(ABC):
    def __init__(self, name):
        self._name = name

    @abstractclassmethod
    def name(self):
        pass

    @abstractclassmethod
    def sound(self):
        pass


class Farm():
    def __init__(self):
        self._all_animals = []
    
    def add_animal(self, new_animal):
        self._all_animals.append(new_animal)
    
    def __str__(self):
        sound = ''
        for animal in self._all_animals:
            sound += f'{animal.name()} -> {animal.sound()} \n'
        return sound


class Cat(Animal):
    def __init__(self, name):
        Animal.__init__(self, name)

    def name(self):
        return self._name
    
    def sound(self):
        return 'MEOW'


class Unicorn(Animal):
    def __init__(self, name):
        Animal.__init__(self, name)

    def name(self):
        return self._name
    
    def sound(self):
        return 'Hi sisters'


class Kangaroo(Animal):
    def __init__(self, name):
        Animal.__init__(self, name)

    def name(self):
        return self._name
    
    def sound(self):
        return '*hop**hop*'


if __name__ == '__main__':
    Fermata = Farm()
    u = Unicorn("Iva")
    k = Kangaroo("Kari")
    k2 = Kangaroo("Kolyo")
    c = Cat("Katy")
    c2 = Cat("Sashka")

    Fermata.add_animal(u)
    Fermata.add_animal(k)
    Fermata.add_animal(c)
    Fermata.add_animal(k2)
    Fermata.add_animal(c2)

    print(Fermata)
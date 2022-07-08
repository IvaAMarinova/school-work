class Weapon:
    def __init__(self, type, damage, critical_strike_percent):
        self.__type = type
        self.__damage = damage
        self.__critical_strike_percent = critical_strike_percent

    def critical_hit(self):
        if self.__critical_strike_percent >= 1:
            return True
        return False


class Entity:
    def __init__(self, name, health, damage):
        self._health = health
        self._name = name
        self._damage = damage
        self._given_health = health
        self._weapon = 0

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, new_name):
        self._name = new_name 

    def get_health(self):
        return self._health

    def is_alive(self):
        if self._health > 0:
            return True
        else: 
            return False

    def take_healing(self, healing_points):
        if self._health == 0:
            return False

        self._health = self._health + healing_points

        if self._health > self._given_health:
            self._health = self._given_health
    
        return True 

    def take_damage(self , damage_points):
        self._health = self._health - damage_points
        if self._health < 0:
            self._health = 0
        return 'ouch'

    def has_weapon(self):
        if self._weapon != 0:
            return True
        return False

    def equip_weapon(self, weapon):
        self._weapon = weapon

    def attack(self):
        if self._weapon == 0:
            return 0
        return self._damage

class Hero(Entity):
    def __init__(self, name, health, nickname, damage):
        Entity.__init__(self, name, health, damage)
        self.__nickname = nickname

    @property
    def nickname(self):
        return self.__nickname

    @property
    def health(self):
        return self._health 

    def __str__(self):
        return f'{self._name} the {self.__nickname}'    

class Orc(Entity):
    def __init__(self, name, health, berserk_factor, damage):
        Entity.__init__(self, name, health, damage)
        self.__berserk_factor = berserk_factor

    @property
    def health(self):
        return self._health

    @property
    def berserk_factor(self):
        return self.__berserk_factor 

    def attack(self):
        if self._weapon == 0:
            return 0
        return self._damage * self.__berserk_factor

if __name__ == '__main__':
    h = Hero("Bron", 100, "DragonSlayer", 150)
    o = Orc("Shrek", 300, 3, 200)
    axe = Weapon("Mighty Axe", 25, 0)

    h.equip_weapon(axe)
    print(h.attack())
    o.equip_weapon(axe)
    print(o.attack())
    
    print("---------> HERO:")
    print("name =             ", h.name)
    print("nickname =         ", h.nickname)
    print("health =           ", h.health)
    print("h =                ", h)
    print("is_alive =         ", h.is_alive())
    print("get_health =       ", h.get_health())
    print("take_damage(33) =  ", h.take_damage(33))
    print("health =           ", h.health)
    print("take_healing(33) = ", h.take_healing(33))
    print("health =           ", h.health)

    print("---------> ORC:")
    print("name =             ", o.name)
    print("berserk_facto =    ", o.berserk_factor)
    print("health =           ", o.health)
    print("is_alive =         ", o.is_alive())
    print("get_health =       ", o.get_health())
    print("take_damage =      ", o.take_damage(100))
    print("health =           ", o.health)
    print("take_healing     = ", o.take_healing(100))
    print("health =           ", o.health)
    print("output_damage =    ", o.attack())

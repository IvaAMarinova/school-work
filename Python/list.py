class MyList:
    def __init__(self):
        self.__start = None
    
    @property
    def start(self):
        return self.__start

    def add(self, value):
        current = self.__start
        if current == None:
            self.__start = Element(value)
        else: 
            while current.next != None:
                current = current.next
            current.next = Element(value) 

    def pop(self, value):
        current = self.__start
        if current.value == value:
            self.__start =self.__start.next
        else:
            while current.next.value != value:
                current = current.next
            print(f'popped {current.next}')
            current.next = current.next.next
                
    def print(self):
        current = self.__start
        while current != None:
            print(current.value)
            current = current.next

    def __getitem__(self, index):
        current = self.__start
        i = 0
        while i < index:
            current = current.next
            i += 1
        return current.value

    def __setitem__(self, key, value): 
        current = self.__start
        i = 0
        while i < key:
            current = current.next
            i += 1
        current.value = value
        

class Element:
    def __init__(self, value):
        self.value = value
        self.next = None

    def __repr__(self):
        return f'{self.value!r}'
        

def bubble_sort(elements):
    current = elements
    n = 0
    while current.next != None:
        n += 1
    swapped = False
    for i in range(n - 1):
        for j in range(0, n- i - 1):
            if elements[j] > elements[j + 1]:
                swapped = True
                elements[j], elements[j + 1] = elements[j + 1], elements[j]       
        if not swapped:
            return



list = MyList()

list.add(1)
list.print()
print('\n')
list.add(4)
list.print()
print('\n')
list.add(3)
print('\n')
list.print()

list.pop(2)
list.print()  

print(f'index {list[2]}')
list[2] = 2
list.print()

bubble_sort(list)
list.print()



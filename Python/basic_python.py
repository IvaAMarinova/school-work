def sum_of_digits(number):
    result = 0
    number = abs(number)

    while number != 0:
        result = result + number % 10
        number = number // 10

    return result


print(sum_of_digits(-221))
print(sum_of_digits(162364))
print(sum_of_digits(11111))
print(sum_of_digits(3))
print(sum_of_digits(0))



'checks for identical lists'
def are_there_double(lists):
    l = len(lists)
    i = 0
    j = 0

    for i in range(l):  # and (j, length)
        for j in range(i, l - 1):
            if sorted(lists[i]) == sorted(lists[j + 1]) :  # and i != j + 1
                print("these two lists are the same:", i, j + 1)


print("example 1") 
are_there_double([[1, 1, 2, 3], [4, 5, 6], [3, 2, 1], [5, 6, 4]])
print("example 2") 
are_there_double([[1, 2, 3], [4, 5, 6], [3, 2, 1]])
print("example 3") 
are_there_double([[1, 0, 3], [4, 5, 6], [3, 7, 1], [5, 7, 4]]) 



'returns digits of number in a list'
def to_digits(number):
    result = []
    number = abs(number)

    while number != 0:
        result.append(number % 10) 
        number = number // 10

    return result


number = int(input("Enter a number:"))
print(to_digits(number))



'returns number of digits in a list'
def to_number(digits):
    result = 0

    for i in range(0, len(digits)):
        result = result * 10
        result = result + digits[i]

    return result
        

list = [1, 2, 3, 4]
print(to_number(list))



'checks if number is balanced'
def is_number_balanced(number):
    lenght = len(number)
    left = 0
    right = 0
    odd_number = 0

    for j in range(0, lenght // 2):
        left = left + int(number[j])

    if (lenght % 2 != 0):
        odd_number = 1

    for i in range(((lenght + odd_number) // 2), lenght ):
        right = right + int(number[i])

    if left == right:
        return True
    else: 
        return False


number = input("Enter a number:")
if(is_number_balanced(number) == True):
    print("True")
else:
    print("False")



'Checks if digits in number are decreasing'
def is_decreasing(number):
    lenght = len(number)
    isnt_dec = 0
    
    for i in range(0, lenght - 1):
        if (int(number[i]) <= int(number[i + 1])):
            isnt_dec = 1
            break
        
    if isnt_dec == 1:
        return False
    else:
        return True


number = input("Enter a number:")

if(is_decreasing(number) == True):
    print("True")
else:
    print("False")


'counts words and saves result in a dictionary'
def count_words(arr):
    dict = {}

    for i in arr:
        if not i in dict:
            dict[i] = 1
        else:
            dict[i] +=1

    return dict


print(count_words(["apple", "banana", "apple", "pie"]))



'checks if a word is an anagram'
def is_anagram(first_word, second_word):
    dict1 = {}
    dict2 = {}

    def check_word(word):
        result_dictionary = {}

        for c in word.lower():
            if not result_dictionary.get(c):
                result_dictionary[c] = 1
            else:
                result_dictionary[c] = result_dictionary[c] + 1

        return result_dictionary


    dict1 = check_word(first_word)
    dict2 = check_word(second_word)

    return dict1 == dict2


print(is_anagram('abv', 'bav'))



'returns the expansion of NaN that many times.'
def nan_expand(num):
    sentence = ""

    for i in range(num):
        sentence += 'Not a '

    if num > 0:
        sentence += 'NaN'

    return sentence


print(nan_expand(2))
print(nan_expand(7))



'sums all numbers in a given string ignoring other characters'
def Sum_of_numbers(str):
    count = "0"
    Sum = 0

    for character in str:
        if (character.isdigit()):
            count = count + character
        else:
            Sum = Sum + int(count)
            count = "0"

    return Sum + int(count)


print(Sum_of_numbers("1h6g2"))



'a gas station basically'
def gas_station(distance, tank_size, stations):
    gas_station_to_visit = []
    last_station_visited = 0

    if stations[0] > tank_size:
        return "oops, not enough fuel, where are the horses when we need them"

    for i in range(len(stations) - 1):
        last_station_visited = stations[i]
        gas_station_to_visit.append(last_station_visited)

    if distance - last_station_visited > tank_size:
        gas_station_to_visit.append(stations[-1])

    return gas_station_to_visit


distance = 300
tank_size = 90
stations = [100, 80, 140, 180, 220, 290]

print(gas_station(distance, tank_size, stations))



'prints two list at the same time together'
def print_two_lists(list1, list2):
    len2, len1 = len(list1), len(list2)

    if len1 < len2:
        length = len1
    else:
        length = len2

    j = len2 - 1

    for i in range(length):
        print(list1[i], list2[j])
        j -= 1


print_two_lists([10, 20, 30, 40], [100, 200, 300, 400])
print(".")
print_two_lists([10, 20, 30], [100, 200, 300, 400])
print(".")
print_two_lists([10], [100])



'permutates two lists'
def permutation_list(list1, list2):
    new_list = []
    len2, len1 = len(list1), len(list2)

    if len1 < len2:
        length = len1
    else:
        length = len2

    for i in range(length):
        for j in range(length):
            temp_list = []
            temp_list.append(list1[i])
            temp_list.append(list2[j])
            new_list.append(temp_list)
            
    print(new_list)


permutation_list(["Hello", "take"], ["Dear", "Sir"])
permutation_list(["take", "Hello"], ["Dear", "Sir"])

    

'returns searched elements from dict in a new dict'
def searched_elements(dict, keys):
    new_dict = {k: dict[k] for k in keys}
    print(new_dict)

searched_elements({
    "name": "Kelly",
    "age": 25,
    "salary": 8000,
    "city": "New York"
}, ["name", "salary"])

print(".")

searched_elements({
    "name": "Kelly",
    "age": 25,
    "salary": 8000,
    "city": "New York"
}, ["city", "salary"])



'prints lowest value from dict'
def min_value(sample_dict):
    min = int(list(sample_dict.values())[0])

    for value in sample_dict.values():
        if value < min:
            min = value

    for key,value in sample_dict.items():
        if value == min:
         print(key)

if __name__ == '__main__':
    min_value({
        'Physics' : 82,
        'Math': 65,
        'history': 75
    })
    print(".")
    min_value({
        'Physics' : 80,
        'Math': 90,
        'history': 80
    })
    min_value({ 
        'Physics' : 0,
        'Math': 212230,
        'history': 120
    })



'prints numbers from tuple'
def print_single(t):
    (a, b, c, d) = t

    print(a)
    print(b)
    print(c)
    print(d)

if __name__ == '__main__':
    print_single((10, 20, 30, 40))
    print(".")
    print_single((129273, -1, 320, 410))
    

'sorts a tuple'
def sort_tuple(tuple1):
    tuple1 = tuple(sorted(list(tuple1), key=lambda x: x[1]))
    print(tuple1)


sort_tuple((('a', 23), ('b', 37), ('c', 11), ('d', 29)))
sort_tuple((('a', 2023), ('b', 32347), ('c', 12341), ('d', 29234), ('d', 39234)))
sort_tuple((('a', 1), ('b', 0), ('c', 1), ('d', 2)))



'turns a list into a set'
def list_to_set(list, set):
    set.update(list)
    print(set)

list_to_set(["Blue", "Green", "Red"], {"Yellow", "Orange", "Black"})
list_to_set(["Blue"], {"Black"})
list_to_set(["Iva", "is", "writing"], {"her homework", "the same", "day", "in", "which", "she has to", "turn it in"})


'returns a set with duplicate numbers'
def identical_items(set1, set2):
    new_set = set1.intersection(set2)
    if new_set == set():
        print("No duplicates")
    else: 
        print(new_set)
   

identical_items({10, 20, 30, 40, 50}, {30, 40, 50, 60, 70})
identical_items({10, 20, 30}, {30, 40, 50, 60, 70})
identical_items({10}, {30, 40, 50, 60, 70})
    

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



'reads from a text file and writes in another file every line that has a given string (alse reverses said line)'
def reverse(s):
    return s[::-1]


def searched_word(given_str):
    f1 = open("text.txt", "r")
    f2 = open(given_str + ".txt", "w")

    for line in f1:
        if given_str in line:
            if line[-1] == "\n":
                line = line[:-1]

            f2.write(reverse(line))
            f2.write("\n\n")

    f1.close()
    f2.close()


searched_word(input("Find me: ")) 



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




'bubble sort'
def b_sort(array):
    print(array)
    lenght = len(array)
 
    for i in range(lenght):
        for j in range(lenght - 1 - i):
            if array[j] > array[j + 1] :
                array[j], array[j + 1] = array[j + 1], array[j]
    return array


array = [10, 3, 2]
print(b_sort(array))
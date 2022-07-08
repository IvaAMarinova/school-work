'copy one file to another'
def copy_file():
    f1 = open("text.txt", "r")
    f2 = open("new_file.txt", "w")
 
    for line in f1:
        f2.write(line)
    


'creates new file and writes every "n" line'
def lines(name, n):
    f1 = open("text.txt", "r")
    f2 = open("new_file1.txt", "a")
    cnt = 0

    for line in f1:
        if line[-1] == "\n":
            if cnt % n == 0:
                f2.write(line)
                f2.write("\n")
            cnt = cnt + 1
            
    f1.close()
    f2.close()
    

lines("text.txt", 2)



'prints all lines from a file that contains searched word'
def searched_word(given_str):
    f1 = open("text.txt", "r")

    for line in f1:
        for word in line.split():
            if word == given_str:
                print(line)

    f1.close()


searched_word(input())



'writes dict in a file'
def write_dict(name):
    f1 = open(name, "w")
    details={
        'Name' : "your mom",
        'Adress' : "my bed",
        'Age' : "28",
        'telefonen nomer' : 12344512}

    for key, value in details.items(): 
        f1.write('%s: %s\n' % (key, value))

name = input()
write_dict(name)



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


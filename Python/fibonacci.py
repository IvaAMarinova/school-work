def fibonacci(n):
    if n < 0:
        print("Number must be > 0")
        return 
    if n in {0, 1}:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)


print(fibonacci(0))
print(fibonacci(1))
print(fibonacci(2))
print(fibonacci(3))
print(fibonacci(19))
print(fibonacci(-3))
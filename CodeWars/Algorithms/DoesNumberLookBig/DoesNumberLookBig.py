
def narcissistic(value):
    return sum([int(x)**len(str(value)) for x in list(str(value))]) == value


print(narcissistic(7))
print(narcissistic(371))
print(narcissistic(112))
print(narcissistic(4887))

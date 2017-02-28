from math import factorial


def colorChoice(m, n):
    for i in range(n):
        if (factorial(n)/(factorial(i)*(factorial(n-i)))) == m:
            return i

    return -1


print(colorChoice(6, 4))
print(colorChoice(35, 7))

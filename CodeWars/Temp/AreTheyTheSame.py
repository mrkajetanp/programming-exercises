from math import sqrt, pow

def comp (a, b):
    a = sorted(a)
    b = sorted(b)
    for i, x in enumerate(a):
        if (pow(x, 2) != b[i]):
            return False
    return True

a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]

print(comp(a, b))

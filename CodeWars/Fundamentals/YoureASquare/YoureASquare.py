from math import sqrt


def is_square(n):
    return n > 0 and sqrt(n).is_integer()


print(is_square(16))
print(is_square(15))
print(is_square(4))

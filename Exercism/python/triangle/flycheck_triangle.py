def triangle(a, b, c):
    return not (a <= 0 or b <= 0 or c <= 0 or
      a + b < c or b + c < a or c + a < b)


def equilateral(sides):
    a, b, c = sides
    return triangle(a, b, c) and (a == b == c)


def isosceles(sides):
    a, b, c = sides
    return triangle(a, b, c) and (a == b or b == c or a == c)


def scalene(sides):
    a, b, c = sides
    return triangle(a, b, c) and (a != b != c)

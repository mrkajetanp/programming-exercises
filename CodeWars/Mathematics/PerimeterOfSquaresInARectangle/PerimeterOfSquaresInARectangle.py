import unittest


# Basic
def fib_list(n):
    fib = [0, 1]

    for i in range(1, n):
        fib.append(fib[i] + fib[i-1])

    fib.remove(0)
    return fib


# Generator
def fib_list_gen(n):
    a, b = 0, 1

    yield b
    for i in range(1, n):
        a, b = b, a+b
        yield b


# Iterator
class Fibonacci:
    def __init__(self, n):
        self.count = 0
        self.end = n
        self.curr = 0
        self.next = 1

    def __iter__(self):
        return self

    def __next__(self):
        if self.count == self.end:
            raise StopIteration()

        new_next = self.curr + self.next
        self.curr = self.next
        self.next = new_next

        self.count += 1
        return self.curr


def perimeter(n):
    return sum(Fibonacci(n+1)) * 4


class TestExercise(unittest.TestCase):
    def test_perimeter(self):
        self.assertEqual(perimeter(5), 80)
        self.assertEqual(perimeter(7), 216)
        self.assertEqual(perimeter(20), 114624)
        self.assertEqual(perimeter(30), 14098308)


if __name__ == '__main__':
    unittest.main()

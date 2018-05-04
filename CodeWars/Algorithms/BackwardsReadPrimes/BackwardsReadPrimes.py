import unittest


def is_prime(n):
    return all([n % i != 0 for i in range(2, int(n**.5)+1)])

# def is_prime(n):
#     if n <= 3:
#         return True

#     if n%2 == 0 or n%3 == 0:
#         return False

#     i = 5
#     w = 2

#     while i**2 <= n:
#         if n%i == 0:
#             return False
#         i += w
#         w = 6-w

#     return True


def backwards_prime(start, stop):
    def is_good(x):
        x2 = int(str(x)[::-1])
        return x != x2 and is_prime(x) and is_prime(x2)

    return [x for x in range(start, stop+1) if is_good(x)]


class TestExercise(unittest.TestCase):
    def test_basic(self):
        a = [13, 17, 31, 37, 71, 73, 79, 97]
        self.assertEqual(backwards_prime(1, 100), a)
        a = [13, 17, 31]
        self.assertEqual(backwards_prime(1, 31), a)


if __name__ == '__main__':
    unittest.main()

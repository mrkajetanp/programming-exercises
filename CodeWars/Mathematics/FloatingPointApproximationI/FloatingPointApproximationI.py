import unittest

from math import sqrt, fabs


def f(x):
    return x / (sqrt(x+1) + 1)


def assertFuzzyEquals(actual, expected, msg=""):
    # max error
    merr = 1e-12
    if expected == 0:
        inrange = fabs(actual) <= merr
    else:
        e = fabs((actual - expected) / expected)
        inrange = e <= merr
    if msg == "":
        msg = msg.format(expected, actual, e)
    return inrange


class TestExercise(unittest.TestCase):
    def test_f(self):
        self.assertTrue(assertFuzzyEquals(f(2.6e-08), 1.29999999155e-08))
        self.assertTrue(assertFuzzyEquals(f(1.4e-09), 6.999999997549999e-10))


if __name__ == '__main__':
    unittest.main()

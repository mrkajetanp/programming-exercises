import unittest


def max_ball(v0):
    g = 9.81

    t = 0
    curr = 0
    prev = 0

    while True:
        prev = curr
        curr = (v0/36)*t - 0.5*g*(t/10)**2

        if curr < prev:
            break

        t += 1

    return t - 1


class TestExercise(unittest.TestCase):
    def test_gap(self):
        self.assertEqual(max_ball(37), 10)
        self.assertEqual(max_ball(45), 13)


if __name__ == '__main__':
    unittest.main()

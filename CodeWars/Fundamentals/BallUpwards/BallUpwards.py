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


def max_ball_2(v0):
    return round((v0 / 3.6) / 0.981)


class TestExercise(unittest.TestCase):
    def test_max_ball(self):
        self.assertEqual(max_ball(37), 10)
        self.assertEqual(max_ball(45), 13)

    def test_max_ball_2(self):
        self.assertEqual(max_ball_2(37), 10)
        self.assertEqual(max_ball_2(45), 13)


if __name__ == '__main__':
    unittest.main()

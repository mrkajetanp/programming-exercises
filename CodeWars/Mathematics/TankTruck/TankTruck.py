import unittest
from math import acos, sin, pi, floor


def tankvol(h, d, vt):
    r = d/2

    sector_angle = 2.0 * acos(1.0-(h/r))
    segment_area = (r**2 * (sector_angle - sin(sector_angle)))/2
    cylinder_length = vt / (r**2 * pi)

    return floor(segment_area * cylinder_length)


class TestExercise(unittest.TestCase):
    def test_tank_vol(self):
        self.assertEqual(tankvol(5, 7, 3848), 2940)
        self.assertEqual(tankvol(5, 7, 3848), 2940)
        self.assertEqual(tankvol(2, 7, 3848), 907)
        self.assertEqual(tankvol(2, 8, 5026), 982)
        self.assertEqual(tankvol(4, 9, 6361), 2731)


if __name__ == '__main__':
    unittest.main()

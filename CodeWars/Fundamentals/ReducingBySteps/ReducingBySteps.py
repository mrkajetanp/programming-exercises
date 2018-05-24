import unittest


def gcdi(a, b):
    pass


def lcmu(a, b):
    pass


def som(a, b):
    pass


def maxi(a, b):
    pass


def mini(a, b):
    pass


def oper_array(fct, arr, init):
    pass


class TestExercise(unittest.TestCase):
    def test_som(self):
        self.assertEqual(oper_array(som, [18, 69, -90, -78, 65, 40], 0),
                         [18, 87, -3, -81, -16, 24])

    def test_lcmu(self):
        self.assertEqual(oper_array(lcmu, [18, 69, -90, -78, 65, 40], 18),
                         [18, 414, 2070, 26910, 26910, 107640])

    def test_maxi(self):
        self.assertEqual(oper_array(maxi, [18, 69, -90, -78, 65, 40], 18),
                         [18, 69, 69, 69, 69, 69])

    def test_gcdi(self):
        self.assertEqual(oper_array(gcdi, [18, 69, -90, -78, 65, 40], 18),
                         [18, 3, 3, 3, 1, 1])


if __name__ == '__main__':
    unittest.main()

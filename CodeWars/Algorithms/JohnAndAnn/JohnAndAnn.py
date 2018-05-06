import unittest

def john(n):
    pass

def ann(n):
    pass

def sum_john(n):
    pass

def sum_ann(n):
    pass

class TestExercise(unittest.TestCase):
    def test_john(self):
        s = [0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6]
        self.assertEqual(john(11), s)
        s = [0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 7, 8]
        self.assertEqual(john(14), s)

    def test_ann(self):
        s = [1, 1, 2, 2, 3, 3]
        self.assertEqual(ann(6), s)
        s = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9]
        self.assertEqual(ann(15), s)

    def test_sum_john(self):
        self.assertEqual(sum_john(75), 1720)
        self.assertEqual(sum_john(78), 1861)

    def test_sum_ann(self):
        self.assertEqual(sum_ann(115), 4070);
        self.assertEqual(sum_ann(150), 6930);


if __name__ == '__main__':
    unittest.main()

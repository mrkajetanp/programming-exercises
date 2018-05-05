import unittest


def length_sup_u_k(n, k):
    pass


def comp(n):
    pass


class TestExercise(unittest.TestCase):
    def test_length_sup_u_k(self):
        self.assertEqual(length_sup_u_k(50, 25), 2)
        self.assertEqual(length_sup_u_k(3332, 973), 1391)
        self.assertEqual(length_sup_u_k(2941, 862), 1246)
        self.assertEqual(length_sup_u_k(3177, 573), 2047)

    def test_comp(self):
        self.assertEqual(comp(74626), 37128)
        self.assertEqual(comp(71749), 35692)
        self.assertEqual(comp(56890), 28281)
        self.assertEqual(comp(60441), 30054)


if __name__ == '__main__':
    unittest.main()

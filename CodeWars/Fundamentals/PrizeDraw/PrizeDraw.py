import unittest


def rank_name(name):
    len(name) + sum(ord('c') - ord('a') + 1 for c in name.lower())


def rank(st, we, n):
    pass


class TestExercise(unittest.TestCase):
    def test_rank(self):
        name = rank("Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin",
                    [4, 2, 1, 4, 3, 1, 2], 4)
        self.assertEqual(name, "Benjamin")

        name = rank("Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden",
                    [1, 3, 5, 5, 3, 6], 2)
        self.assertEqual(name, "Matthew")

        name = rank("Aubrey,Olivai,Abigail,Chloe,Andrew,Elizabeth",
                    [3, 1, 4, 4, 3, 2], 4)
        self.assertEqual(name, "Abigail")

        name = rank("Lagon,Lily", [1, 5], 2)
        self.assertEqual(name, "Lagon")


if __name__ == '__main__':
    unittest.main()

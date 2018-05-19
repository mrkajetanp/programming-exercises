import unittest
from functools import cmp_to_key


def cmp(x, y):
    return (x > y) - (x < y)


def rank(st, we, n):
    if not st:
        return "No participants"

    if n > len(st.split(",")):
        return "Not enough participants"

    names = [(s, (len(s) + sum([ord(c) - ord('a') + 1 for c in s.lower()]))*i)
             for s, i in zip(st.split(','), we)]

    names.sort(key=cmp_to_key(
        lambda a, b: cmp(a[0], b[0]) if a[1] == b[1] else cmp(b[1], a[1])
    ))

    return names[n-1][0]


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

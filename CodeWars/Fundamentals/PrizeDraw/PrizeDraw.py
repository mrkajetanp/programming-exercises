import unittest
from functools import cmp_to_key


def rank_name(name):
    return len(name) + sum([ord(c) - ord('a') + 1 for c in name.lower()])


def cmp(x, y):
    return (x > y) - (x < y)


def key_cmp(p1, p2):
    return cmp(p1[0], p2[0]) if p1[1] == p2[1] else cmp(p2[1], p1[1])


def rank(st, we, n):
    if not st:
        return "No participants"

    if n > len(st.split(",")):
        return "Not enough participants"

    names = [(s, rank_name(s)*i) for s, i in zip(st.split(','), we)]
    names.sort(key=cmp_to_key(key_cmp))
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

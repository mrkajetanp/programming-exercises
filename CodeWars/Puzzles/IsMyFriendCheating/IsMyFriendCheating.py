import unittest


def removNb(n):
    s = n*(n+1)/2

    return [(x, (s-x)/(x+1)) for x in range(1, n+1)
            if (s-x) % (x+1) == 0 and (s-x)/(x+1) <= n]


class TestExercise(unittest.TestCase):
    def test_removNb(self):
        self.assertEqual(removNb(26), [(15, 21), (21, 15)])
        self.assertEqual(removNb(100), [])
        self.assertEqual(removNb(101), [(55, 91), (91, 55)])
        self.assertEqual(removNb(102), [(70, 73), (73, 70)])


if __name__ == '__main__':
    unittest.main()

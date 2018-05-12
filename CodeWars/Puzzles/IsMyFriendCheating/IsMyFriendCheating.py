import unittest


def removNb(n):
    result = []
    s = sum(range(1, n+1))

    for a in range(1, n+1):
        b = (s-a)/(a+1)

        if b == round(b) and b < n:
            result.append((a, b))

    return result


class TestExercise(unittest.TestCase):
    def test_removNb(self):
        self.assertEqual(removNb(26), [(15, 21), (21, 15)])
        self.assertEqual(removNb(100), [])
        self.assertEqual(removNb(101), [(55, 91), (91, 55)])
        self.assertEqual(removNb(102), [(70, 73), (73, 70)])


if __name__ == '__main__':
    unittest.main()

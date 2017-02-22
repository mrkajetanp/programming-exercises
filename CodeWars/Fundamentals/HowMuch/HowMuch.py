import unittest


def howmuch(m, n):
    if m > n: m, n = n, m
    results = []

    for i in range(m, n + 1):
        c = (i - 1) / 9.0
        b = (i - 2) / 7.0
        if c.is_integer() and b.is_integer():
            temp = []
            temp.append("M: " + str(int(i)))
            temp.append("B: " + str(int(b)))
            temp.append("C: " + str(int(c)))
            results.append(temp)

    return results


class TestStringMethods(unittest.TestCase):
    def testHowMuch(self):
        self.assertEquals(howmuch(2950, 2950), [])
        expected = [["M: 37", "B: 5", "C: 4"], ["M: 100", "B: 14", "C: 11"]]
        self.assertEquals(howmuch(1, 100), expected)
        expected = [["M: 20008", "B: 2858", "C: 2223"],
                    ["M: 20071", "B: 2867", "C: 2230"]]
        self.assertEquals(howmuch(20000, 20100), expected)


suite = unittest.TestLoader().loadTestsFromTestCase(TestStringMethods)
unittest.TextTestRunner(verbosity=2).run(suite)

# test.assert_equals(howmuch(20000, 20100), )

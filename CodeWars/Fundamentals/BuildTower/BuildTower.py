import unittest

def towerBuilder(nFloors):
    res = []
    for i in range (nFloors):
        res.append(" " * (nFloors-i-1) + "*" * (i*2+1) + " " * (nFloors-i-1))

    return res


class TestTowerBuilder(unittest.TestCase):
    def testTowerBuild (self):
        expected = ["*"]
        self.assertEquals(towerBuilder(1), expected)

        expected = [" * ", "***"]
        self.assertEquals(towerBuilder(2), expected)

        expected = ["  *  ", " *** ", "*****"]
        self.assertEquals(towerBuilder(3), expected)


suite = unittest.TestLoader().loadTestsFromTestCase(TestTowerBuilder)
unittest.TextTestRunner(verbosity=2).run(suite)

towerBuilder (3)






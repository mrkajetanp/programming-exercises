import unittest
from math import floor


def fold_array(array, runs):
    res = []
    i = 0
    j = len(array)-1
    while i < floor(len(array)/2):
        res.append(array[i] + array[j])
        i += 1
        j -= 1

    if len(array) % 2 != 0:
        res.append(array[int(floor(len(array)/2))])

    if runs == 1:
        return res
    else:
        return fold_array(res, runs-1)


class FoldArrayTests(unittest.TestCase):
    def testFoldArray(self):
        self.assertEquals(fold_array([1, 2, 3, 4, 5], 1), [6, 6, 3])


suite = unittest.TestLoader().loadTestsFromTestCase(FoldArrayTests)
unittest.TextTestRunner(verbosity=2).run(suite)

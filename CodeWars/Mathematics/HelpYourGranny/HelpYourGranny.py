import unittest
import math

def tour(friends, friend_towns, dist):
    fvec = [s for s in friends if any(x[0] == s for x in friend_towns)]
    fr_twns = {x[0]:x[1] for x in friend_towns}
    d_sum = dist[fr_twns[fvec[0]]]

    for i in range(0, len(fvec)-1):
        d1 = dist[fr_twns[fvec[i+1]]]
        d1 **= 2;

        d2 = dist[fr_twns[fvec[i]]]
        d2 **= 2;

        d_sum += math.sqrt(d1 - d2)

    d_sum += dist[fr_twns[fvec[len(fvec)-1]]]

    return math.floor(d_sum)

class TestExercise(unittest.TestCase):
    def test_basic(self):
        friends1 = ["A1", "A2", "A3", "A4", "A5"]
        fTowns1 = [["A1", "X1"], ["A2", "X2"], ["A3", "X3"], ["A4", "X4"]]
        distTable1 = {"X1": 100.0, "X2": 200.0, "X3": 250.0, "X4": 300.0}
        self.assertEqual(tour(friends1, fTowns1, distTable1), 889)

if __name__ == '__main__':
    unittest.main()

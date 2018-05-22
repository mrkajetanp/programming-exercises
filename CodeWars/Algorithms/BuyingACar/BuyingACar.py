import unittest


def nb_months(old, new, saving, perc):
    if old >= new:
        return [0, old-new]

    month = 1
    account = 0

    while True:
        if month%2 == 0:
            perc += .5

        old -= old * (perc/100)
        new -= new * (perc/100)
        account += saving

        if account + old >= new:
            break

        month += 1

    return [month, round(account+old-new)]


class TestExercise(unittest.TestCase):
    def test_nb_months(self):
        self.assertEqual(nb_months(2000, 8000, 1000, 1.5), [6, 766])
        self.assertEqual(nb_months(12000, 8000, 1000, 1.5), [0, 4000])
        self.assertEqual(nb_months(8000, 12000, 500, 1.0), [8, 597])
        self.assertEqual(nb_months(18000, 32000, 1500, 1.25), [8, 332])
        self.assertEqual(nb_months(7500, 32000, 300, 1.55), [25, 122])


if __name__ == '__main__':
    unittest.main()

import unittest


def arrange(string):
    pass


class TestExercise(unittest.TestCase):
    def test_gap(self):
        self.assertEqual(arrange("who hit retaining The That a we taken"),
                         "who RETAINING hit THAT a THE we TAKEN")
        self.assertEqual(arrange("on I came up were so grandmothers"),
                         "i CAME on WERE up GRANDMOTHERS so")
        self.assertEqual(arrange("way the my wall them him"),
                         "way THE my WALL him THEM")
        self.assertEqual(arrange("turn know great-aunts aunt look A to back"),
                         "turn GREAT-AUNTS know AUNT a LOOK to BACK")


if __name__ == '__main__':
    unittest.main()

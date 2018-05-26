import unittest


def arrange(string):
    words = [s for s in string.split()]

    if len(words) == 0 or len(words) == 1:
        return " ".join(words)

    ln = len(words)
    for i in range(len(words)-1):
        if i % 2 == 0:
            if not (len(words[i]) <= len(words[i+1])):
                words[i], words[i+1] = words[i+1], words[i]
            words[i] = words[i].lower()
        else:
            if not (len(words[i]) >= len(words[i+1])):
                words[i], words[i+1] = words[i+1], words[i]
            words[i] = words[i].upper()

    words[ln-1] = words[ln-1].upper() if ln % 2 == 0 else words[ln-1].lower()
    return " ".join(words)


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

import unittest


def validBraces(string):
    pass


class TestExercise(unittest.TestCase):
    def test_validBraces(self):
        self.assertEqual(True, validBraces("()"))
        self.assertEqual(False, validBraces("[(])"))
        self.assertEqual(True, validBraces("(){}[]"))
        self.assertEqual(False, validBraces("(}"))
        self.assertEqual(False, validBraces("[(])"))
        self.assertEqual(True, validBraces("([{}])"))


if __name__ == '__main__':
    unittest.main()

import unittest


def validBraces(string):
    stack = []
    braces = {"(": ")", "[": "]", "{": "}"}

    for c in string:
        if c in braces.keys():
            stack.append(c)
        else:
            if not stack or braces[stack.pop()] != c:
                return False

    return not len(stack)


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

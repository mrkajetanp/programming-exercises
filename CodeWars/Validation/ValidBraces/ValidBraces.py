import unittest


def validBraces(string):
    brackets = []

    for c in string:
        if c == '(' or c == '{' or c == '[':
            brackets.append(c)
        if c == ')':
            if brackets.pop() != '(':
                return False
        if c == '}':
            if brackets.pop() != '{':
                return False
        if c == ']':
            if brackets.pop() != '[':
                return False

    return not len(brackets)


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

import unittest

def revrot(string, size):
    return ""

class TestExercise(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(revrot("1234", 0), "")
        self.assertEqual(revrot("", 0), "")
        self.assertEqual(revrot("1234", 5), "")
        s = "733049910872815764"
        a = "330479108928157"
        self.assertEqual(revrot(s, 5), a)
        s = 73304991087281576455176044327690580265896
        a = 1994033775182780067155464327690480265895
        self.assertEqual(revrot(s, 8), a)

if __name__ == '__main__':
    unittest.main()

import unittest

def backwards_prime(start, stop):
    pass

class TestExercise(unittest.TestCase):
    def test_basic(self):
        a = [13, 17, 31, 37, 71, 73, 79, 97]
        self.assertEqual(backwards_prime(1, 100), a)
        a = [13, 17, 31];
        self.assertEqual(backwards_prime(1, 31), a)

if __name__ == '__main__':
    unittest.main()

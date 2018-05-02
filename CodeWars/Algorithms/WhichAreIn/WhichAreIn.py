import unittest

def in_array(arr1, arr2):
    return sorted({s for s in arr1 if any(s in t for t in arr2)})


class TestExercise(unittest.TestCase):
    def test_in_array(self):
        a1 = ["live", "arp", "strong"]
        a2 = ["lively", "alive", "harp", "sharp", "armstrong"]
        r = ['arp', 'live', 'strong']
        self.assertEqual(in_array(a1, a2), r)

if __name__ == '__main__':
    unittest.main()

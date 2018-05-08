import unittest
import math

def n_prime(n):
    result = 0

    for i in range(2, math.floor(math.sqrt(n))+1):
        while n%i == 0:
            result += 1
            n /= i

    if n > 1:
        result += 1

    return result

def consec_kprimes(k, arr):
    pass

class TestExercise(unittest.TestCase):
    def test_basic(self):
        a = [10081, 10071, 10077, 10065, 10060,10070, 10086, 10083, 10078,
             10076, 10089, 10085, 10063, 10074, 10068, 10073, 10072, 10075]
        self.assertEqual(consec_kprimes(2, a), 2)

        a = [10064]
        self.assertEqual(consec_kprimes(6, a), 0)

        a = [10054, 10039, 10053, 10051, 10047, 10043, 10037, 10034]
        self.assertEqual(consec_kprimes(1, a), 0)

        a = [10158, 10182, 10184, 10172, 10179,
         10168, 10156, 10165, 10155, 10161, 10178, 10170]
        self.assertEqual(consec_kprimes(3, a), 5)

        a = [10110, 10102, 10097,10113,10123,
             10109, 10118, 10119, 10117, 10115, 10101, 10121, 10122]
        self.assertEqual(consec_kprimes(2, a), 7)


if __name__ == '__main__':
    unittest.main()

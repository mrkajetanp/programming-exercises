import unittest


def length_sup_u_k(n, k):
    fibos = [1, 1]
    count = 0

    for i in range(3, n+1):
        curr = fibos[i - fibos[i-1-1] - 1] + fibos[i - fibos[i-2-1] - 1]

        if curr >= k:
            count += 1

        fibos.append(curr)

    return count


def comp(n):
    fibos = [1, 1]
    sum = 0

    for i in range(3, n+1):
        curr = fibos[i - fibos[i-1-1] - 1] + fibos[i - fibos[i-2-1] - 1]

        if curr < fibos[len(fibos)-1]:
            sum += 1

        fibos.append(curr)

    return sum


class TestExercise(unittest.TestCase):
    def test_length_sup_u_k(self):
        self.assertEqual(length_sup_u_k(50, 25), 2)
        self.assertEqual(length_sup_u_k(3332, 973), 1391)
        self.assertEqual(length_sup_u_k(2941, 862), 1246)
        self.assertEqual(length_sup_u_k(3177, 573), 2047)

    def test_comp(self):
        self.assertEqual(comp(74626), 37128)
        self.assertEqual(comp(71749), 35692)
        self.assertEqual(comp(56890), 28281)
        self.assertEqual(comp(60441), 30054)


if __name__ == '__main__':
    unittest.main()

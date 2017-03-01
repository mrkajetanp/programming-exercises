from collections import Counter


def find_it(seq):
    c = Counter(seq)
    c = dict(c)
    for key, val in c.items():
        if val % 2 != 0:
            return key
    return None


print(find_it([20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5]))


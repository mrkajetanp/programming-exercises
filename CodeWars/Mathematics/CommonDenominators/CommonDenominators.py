from fractions import gcd


def lcm(a, b):
    return (a*b)/gcd(a, b)


def listLcm(lst):
    curr = lst[0][1]
    for i in range(1, len(lst)):
        curr = lcm(curr, lst[i][1])
    return curr


def convertFracts(lst):
    res = []
    den = int(listLcm(lst))
    for v in lst:
        res.append([int(v[0]*(den/v[1])), den])
    return res


a = [[1, 2], [1, 3], [1, 4]]
b = [[6, 12], [4, 12], [3, 12]]
c = [[27115, 5262], [87546, 11111111], [43216, 255689]]
print(convertFracts(c))

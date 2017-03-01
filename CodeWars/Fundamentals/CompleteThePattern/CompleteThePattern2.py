def pattern(n):
    if n < 1:
        return ""
    res = ""
    for i in range(0, n):
        for j in range(n, i, -1):
            res += str(j)
        res += '\n'
    if res.endswith('\n'):
        res = res[:-1]
    return res


print(pattern(4))
print(pattern(11))

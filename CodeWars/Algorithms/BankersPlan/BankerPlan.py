
def fortune (f0, p, c0, n, i):
    p /= 100.0
    i /= 100.0
    while f0 > 0 and n > 0:
        f0 += (f0*p)-c0
        c0 += (c0*i)
        n -= 1

    if n == 0:
        return True
    else:
        return False

def tests ():
    assert fortune (100000, 1, 2000, 15, 1) == True, "wrong!"
    assert fortune (100000, 1, 10000, 10, 1) == True, "wrong!"
    assert fortune (100000, 1, 9185, 12, 1) == False, "wrong!"
    assert fortune (6722682, 6.5, 448916, 24, 2.6) == True, "wrong!"

tests ()

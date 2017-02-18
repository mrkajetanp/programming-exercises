from math import pow

def isGood (a):
    nums = [int(x) for x in str(a)]
    counter = 1
    result = 0
    for x in nums:
        result += pow (x, counter)
        counter+=1
    if a == int(result):
        return True
    else:
        return False

def sum_dig_pow(a, b):
    result = []
    for i in range(a, b+1):
        if (isGood(i)):
            result.append (i)
    return result

print(sum_dig_pow(1, 1000000))

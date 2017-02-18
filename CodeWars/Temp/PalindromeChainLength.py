
def palindrome_chain_length (n):
    steps = 0

    while True:
        nums = [x for x in str(n)]
        nums.reverse()
        nums = int("".join(nums))
        if nums == n:
            return steps
        n += nums
        steps += 1

def testme (a, count = 0):
    print (a, count)
    if (count != 5):
        testme (a, count+1)

print(palindrome_chain_length(0))
testme (10)

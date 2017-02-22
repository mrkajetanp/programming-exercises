import unittest


def dirReduc (arr):
    i = 0
    while i != len(arr)-1:
        if arr == []:
            return arr
        if len(arr) == 1:
            break;
        if arr[i] == "NORTH" and arr[i+1] == "SOUTH" or \
           arr[i] == "SOUTH" and arr[i+1] == "NORTH" or \
           arr[i] == "WEST" and arr[i+1] == "EAST" or \
           arr[i] == "EAST" and arr[i+1] == "WEST":
            del arr[i:i+2]
            i = 0
            continue
        i += 1

    return arr



# class TestDirReduction(unittest.TestCase):
#     def testDirRed (self):
#         a = ["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]
#         self.assertEquals(dirReduc(a), ['WEST'])
#         u=["NORTH", "WEST", "SOUTH", "EAST"]
#         self.assertEquals(dirReduc(u), ["NORTH", "WEST", "SOUTH", "EAST"])

# suite = unittest.TestLoader().loadTestsFromTestCase(TestDirReduction)
# unittest.TextTestRunner(verbosity=2).run(suite)

a = ['NORTH', 'SOUTH', 'SOUTH', 'EAST', 'WEST', 'NORTH']
print ("Result: ", dirReduc(a));




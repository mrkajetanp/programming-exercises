
def simplify(poly):

    print("Result: {}".format(poly))
    return poly

assert(simplify("dc+dcba") == "cd+abcd")
assert(simplify("2xy-yx") == "xy")
assert(simplify("-a+5ab+3a-c-2a") == "-c+5ab")

assert(simplify("-abc+3a+2ac") == "3a+2ac-abc")
assert(simplify("xyz-xz") == "-xz+xyz")

assert(simplify("a+ca-ab") == "a-ab+ac")
assert(simplify("xzy+zby") == "byz+xyz")

assert(simplify("-y+x") == "x-y")
assert(simplify("y-x") == "-x+y")


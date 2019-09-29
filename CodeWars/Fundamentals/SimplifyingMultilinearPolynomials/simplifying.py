
def simplify(poly):
    import re

    matches = re.findall(r'([+\-]?)(\d*)([a-z]+)', poly)
    print(matches)

    expanded = [[int(i[0] + (i[1] if i[1] != "" else "1")),
                 ''.join(sorted(i[2]))] for i in matches]
    print(expanded)

    variables = sorted(list(set(i[1] for i in expanded)), key=lambda x: (len(x), x))
    print(variables)

    return poly

# Tests

assert(simplify("dc+dcba") == "cd+abcd")
assert(simplify("2xy-yx") == "xy")
assert(simplify("-a+5ab+3a-c-2a") == "-c+5ab")

assert(simplify("-abc+3a+2ac") == "3a+2ac-abc")
assert(simplify("xyz-xz") == "-xz+xyz")

assert(simplify("a+ca-ab") == "a-ab+ac")
assert(simplify("xzy+zby") == "byz+xyz")

assert(simplify("-y+x") == "x-y")
assert(simplify("y-x") == "-x+y")

    # get the sum of coefficients (located in expanded) for each variable
    # coefficients = {v:sum(i[0] for i in expanded if i[1] == v) for v in variables}
    # clean-up: join them with + signs, remove '1' coefficients, and change '+-' to '-'
    # return '+'.join(str(coefficients[v]) + v for v in variables if coefficients[v] != 0).replace('1','').replace('+-','-')


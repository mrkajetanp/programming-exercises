
def leap_year(year):
    factor = lambda x: year%x == 0
    return factor(4) and (not factor(100) or factor(400))

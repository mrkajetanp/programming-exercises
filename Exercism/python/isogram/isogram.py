
def is_isogram(string):
    letters = set()

    for c in string.lower():
        if c in '_- ':
            continue

        if c in letters:
            return False

        letters.add(c)

    return True

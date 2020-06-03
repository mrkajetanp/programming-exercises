
def abbreviate(words):
    parts = [w[0] for w in words.replace("_", "").replace("-", " ").split()]
    return "".join(parts).upper()

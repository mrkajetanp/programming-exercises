
def is_pangram(sentence):
    return len({ x for x in sentence.lower() if x.isalpha() }) == 26

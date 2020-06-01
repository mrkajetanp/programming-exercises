import re

def count_words(sentence):
    result = {}

    pattern = re.compile(r"((?:\w|['-]\w)+)")
    for word in re.findall(pattern, sentence.lower().replace("_", " ")):
        word = word[1:] if word.startswith("'") else word
        result[word] = result[word] + 1 if word in result else 1

    return result

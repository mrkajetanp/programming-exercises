
def is_anagram(word, x):
    return (sorted(list(word.lower())) == sorted(list(x.lower())))

def find_anagrams(word, candidates):
    return [w for w in candidates if is_anagram(word, w) and w.lower() != word.lower()]

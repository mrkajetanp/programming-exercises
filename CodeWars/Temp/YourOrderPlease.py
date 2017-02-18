
def getNum (word):
    for c in word:
        if c.isdigit():
            return int(c)

def order (sentence):
    dic1 = {}
    result = []
    words = sentence.split()
    # print (" ".join(words))
    for s in words:
        dic1[getNum(s)] = s
    for i in range (1, len(dic1)+1):
        result.append(dic1[i])
    return " ".join(result)

print(order("is2 Thi1s T4est 3a"))

test = {1: "ok", 2: "okk"}

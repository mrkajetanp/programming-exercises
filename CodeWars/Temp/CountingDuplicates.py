import collections

def duplicate_count (text):
    cnt = 0
    chsd = collections.Counter ([c for c in text])
    for key, value in chsd.most_common():
        if value > 1:
            cnt += 1
    return cnt

res = duplicate_count ("aaabbcde")
print (res)

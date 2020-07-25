def verse(x):
    if x == 0:
        return [
            "No more bottles of beer on the wall, no more bottles of beer.",
            "Go to the store and buy some more, 99 bottles of beer on the wall.",
        ]

    if x == 1:
        return [
            "1 bottle of beer on the wall, 1 bottle of beer.",
            "Take it down and pass it around, no more bottles of beer on the wall.",
        ]

    return [
        "{0} bottles of beer on the wall, {0} bottles of beer.".format(x),
        "Take one down and pass it around, {0} bottle{1} of beer on the wall."
        .format(x-1, "" if x == 2 else "s")
    ]


def recite(start, take=1):
    result = []

    while take > 0:
        result += verse(start)
        result.append("")
        start -= 1
        take -= 1

    return result[:-1]

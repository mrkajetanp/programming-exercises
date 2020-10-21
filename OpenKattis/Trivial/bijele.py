#!/usr/bin/env python
# -*- coding: utf-8 -*-

# king queen 2 rooks 2 bishops 2 knights 8 pawns
def bijele(data):
    numbers = [1, 1, 2, 2, 2, 8]
    result = [str(numbers[i] - int(x)) for i, x in enumerate(data.split())]
    return " ".join(result)

print(bijele(input()))

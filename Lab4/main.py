#!/bin/python3

import os
import sys


#
# Complete the findStrings function below.
#
def findStrings(w, queries):
    S1 = []
    for w1 in w:
        # print(w1)
        # print(len(w1))
        for i in range(len(w1)):
            t = 0
            y = i + 1
            # print(i)
            while y <= len(w1):
                # print(w1[t:y])
                if (w1[t:y] in S1) == 0:
                    S1.append(w1[t:y])
                t += 1
                y += 1
    S1.sort()
    # print(S1)
    ret=[]
    for q in queries:
        if q > (len(S1) + 1):
            #print("--INVALID--")
            ret.append("INVALID")
        else:
            #print(S1[2])
            ret.append(S1[q - 1])
    return ret

w_count = int(input())

w = []

for _ in range(w_count):
    w_item = input()
    w.append(w_item)

queries_count = int(input())

queries = []

for _ in range(queries_count):
    queries_item = int(input())
    queries.append(queries_item)

result = findStrings(w, queries)

print('\n'.join(result))
print('\n')


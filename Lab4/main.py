#!/bin/python3

import os
import sys


#
#
# """
# 1
# abracadabra
# 1
# 1
# """
# Complete the findStrings function below.
#
def suffix_array(w):
    suffix = []
    for i in range(len(w)):
        suf_id = sorted(range(len(w[i])), key=lambda x: w[i][x:])
        for j in suf_id:
            suffix.append(w[i][suf_id[j]:len(w[i])])
    return sorted(list(set(suffix)))


def lcp_array(suffix):
    lcp = [0] * len(suffix)
    for i in range(len(suffix) - 1):
        j = 0
        # while suffix[i][j] == suffix[i + 1][j]:
        #     j += 1
        #     lcp[i] += 1
        if len(suffix[i]) <= len((suffix[i + 1])):
            for k in range(len(suffix[i]) - 1, 0):
                if suffix[i + 1].startwitn(suffix[i][0:k]):
                    lcp[i] = k + 1
        else:
            for k in range(len(suffix[i + 1]) - 1, 0):
                if suffix[i].startwitn(suffix[i + 1][0:k]):
                    lcp[i] = k + 1
    return lcp


def findStrings(w, queries):
    w = list(map(lambda x: x + '$', w))
    suffix = suffix_array(w)
    lcp = lcp_array(suffix)
    subcnt = 1 - len(suffix)
    for i in range(1, len(suffix)):
        subcnt += len(suffix[i]) - lcp[i - 1]
    ret = []
    for i in range(len(queries)):
        if queries[i] > subcnt:
            ret.append("invalid")
            continue
        index = 0
        j = 1
        while index + len(suffix[j]) - 1 - lcp[j-1] < queries[i]:
            index += len(suffix[j]) - 1 - lcp[j-1]
            j += 1
        ret.append(suffix[j][0:queries[i] - index + lcp[j - 1]])
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

#!/bin/python3
import math
import os
import random
import re
import sys


# Complete the bfs function below.
def bfs(n, m, edges, s):
    ret = []
    graph = [[0 for i in range(n)] for i in range(n)]
    for i in range(m):
        t = edges[i][0] - 1
        f = edges[i][1] - 1
        graph[t][f] = 1
        graph[f][t] = 1

    dist = [-1] * n
    dist[s - 1] = 0

    visited = [False] * n
    queue = [s - 1]
    visited[s - 1] = True
    k = 0
    while queue:
        u = queue.pop(0)
        k += 6
        for i in range(n):
            if not visited[i] and graph[u][i]:
                queue.append(i)
                visited[i] = True
                dist[i] = dist[u] + 6
    for i in (x for x in range(len(dist)) if x != s - 1):
        ret.append(dist[i])
    return ret


q = int(input())

for q_itr in range(q):
    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    edges = []

    for _ in range(m):
        edges.append(list(map(int, input().rstrip().split())))

    s = int(input())

    result = bfs(n, m, edges, s)

    print(' '.join(map(str, result)))
    print('\n')

print()

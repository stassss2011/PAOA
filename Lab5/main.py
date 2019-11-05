#!/bin/python3

import os
import sys
import math


# Complete the solve function below.
def solve(x, y, r, t1, t2, t3):
    tr = [t1, t2, t3]
    for i in range(3):
        x1 = tr[i][0]
        x2 = tr[(i+1) % len(tr)][0]
        y1 = tr[i][1]
        y2 = tr[(i+1) % len(tr)][1]
        a = (x2 - x1) ** 2 + (y2 - y1) ** 2
        b = 2.0 * ((x2 - x1) * (x1 - x) + (y2 - y1) * (y1 - y))
        c = x ** 2 + y ** 2 + x1 ** 2 + y1 ** 2 - 2 * (x * x1 + y * y1) - r ** 2
        d = b ** 2 - 4 * a * c
        if d == 0.0:
            u = -b / (2 * a)
            if 0.0 <= u <= 1.0:
                return "YES"
        if d > 0.0:
            u1 = (-b + math.sqrt(d)) / (2 * a)
            u2 = (-b - math.sqrt(d)) / (2 * a)
            if (0.0 <= u1 <= 1.0) or (0.0 <= u2 <= 1.0):
                return "YES"
    return "NO"


t = int(input())

for t_itr in range(t):
    xyr = input().split()

    x = int(xyr[0])

    y = int(xyr[1])

    r = int(xyr[2])

    t1 = list(map(int, input().rstrip().split()))

    t2 = list(map(int, input().rstrip().split()))

    t3 = list(map(int, input().rstrip().split()))

    result = solve(x, y, r, t1, t2, t3)

    print(result + '\n')

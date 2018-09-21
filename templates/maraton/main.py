#!/usr/bin/env python3
# import re

while True:
    occurrences = 0
    try:
        n = int(input())
        needle = input()
        haystack = input()
    except Exception:
        break
    if (n > len(haystack)):
        continue
    # for i in (m.start() for m in re.finditer(needle, haystack)):
    #     print(i)
    i = 0
    anterior = 0
    for i in range(0, len(haystack)):
        actual = haystack.find(needle)
        if actual < 0:
            break
        elif (anterior == actual + i):
            continue
        # print("[actual, anterior]", actual + i, anterior - 1)
        if anterior - 1 != actual + i:
            print(actual + i)
        haystack = haystack[1:]
        i += 1
        anterior = actual + i

    print("")

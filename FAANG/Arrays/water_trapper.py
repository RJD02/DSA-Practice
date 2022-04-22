def brute_force_solve():
    ht = [int(i) for i in input().split(',')]
    total = 0
    maxL, maxR = 0, 0
    for i, hti in enumerate(ht):
        # Check left max ht
        for j in range(i, -1, -1):
            maxL = max(maxL, ht[j]) if j >= 0 else 0

        # Check right max ht
        for j in range(i + 1, len(ht)):
            maxR = max(maxR, ht[j]) if j < len(ht) else 0

        curr_water = min(maxL, maxR) - hti
        total += max(curr_water, 0)
    return total


print(brute_force_solve())

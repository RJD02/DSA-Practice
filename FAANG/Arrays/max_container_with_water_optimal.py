def solve():
	ht = list(map(int, input().split(',')))

	left = 0
	right = len(ht) - 1
	max_area = -float('inf')

	while left < right:
		max_area = max(max_area, (right - left) * min(ht[left], ht[right]))
		if ht[left] > ht[right]: right -= 1
		else: left += 1

	return max_area

def brute():
	# ht = list(map(int, input().split(',')))
	ht = [int(i) for i in input().split(',')]
	max_area = -float('inf')

	for i in range(len(ht)):
		for j in range(i + 1, len(ht)):
			max_area = max(max_area, (j - i) * min(ht[i], ht[j] ))

	return max_area

print(solve())
# print(brute())

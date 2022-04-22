'''
We need to find the area for each pair of heights list
so 
max_area = -float('inf')
for i in range(len(heights)):
	for j in range(i + 1, len(heights)):
		max_area = max((j - i) * min(heights[i], heights[j]), max_area)

return max_area
'''

def solve():
	heights = list(map(int, input().split(',')))
	max_area = -float('inf')

	for i in range(len(heights)):
		for j in range(i + 1, len(heights)):
			max_area = max((j - i) * min(heights[i], heights[j]), max_area)
	return max_area

print(solve())
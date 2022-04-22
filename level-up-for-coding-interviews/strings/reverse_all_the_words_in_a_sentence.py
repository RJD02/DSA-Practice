# Time Complexity: O(N) 
# Space Complexity: O(1)
# We are just reading input and outputting it in reverse way
# We are not using any variable to store anything.
def solve():
	for i in input().split()[::-1]: # O(N) to split and reverse...And since we are doing it one after other, so overall O(N)
		print(i, end=' ')

solve()
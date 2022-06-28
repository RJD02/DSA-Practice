def solve():
	n, k = input().split()
	n, k = int(n), int(k)
	
	l = list(range(1, n + 1))

	for i in range(k % n):
		l = l[::2] + l[1::2]

	for i in l:
		print(i, end=' ')

t = int(input())
for i in range(t):
	solve()
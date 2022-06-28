def solve():
	n, d = list(map(int, input().split()))
	if n == 0 or n == 1:
		print(n)
	if d < 11:
		if n < pow(2, d):
			print(n)
		else:
			print(pow(2, d))
	else:
		if n < 3 * (d - 10) * 1024:
			print(n)
		else:
			print(3 * (d - 10) * 1024)

tc = int(input())
for i in range(tc):
	solve()
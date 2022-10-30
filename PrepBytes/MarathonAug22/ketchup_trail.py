def solve():
	x1, y1, x2, y2, x3, y3 = [int(i) for i in input().split()]
	x21 = x2 - x1
	x32 = x3 - x2
	if x21 == 0:
		slope1 = float('inf')
	else:
		slope1 = (y2 - y1) / x21
	if x32 == 0:
		slope2 = float('inf')
	else:
		slope2 = (y3 - y2) / x32
	if slope1 == slope2:
		print('YES')
	else:
		print('NO')

def main():
	t = int(input())
	while t:
		solve()
		t -= 1

main()
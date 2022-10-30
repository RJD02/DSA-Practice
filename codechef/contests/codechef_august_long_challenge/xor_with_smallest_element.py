import heapq as h

def solve():
	n, x, y = [int(i) for i in input().split()]
	if n == 1:
		a = int(input())
		if y % 2 == 0:
			print(a)
		else:
			print(a ^ x)
	else:
		arr = [int(i) for i in input().split()]
		h.heapify(arr)
		i = 0
		while i < y:
			b = h.heappop(arr)
			c = b ^ x
			h.heappush(arr, c)
			d = h.heappop(arr)
			i += 1
			if d == c:
				if (y - i) % 2 == 0:
					h.heappush(arr, d)
				else:
					h.heappush(arr, b)
				break
			else:
				h.heappush(arr, d)
		arr.sort()
		print(*arr)

t = int(input())
while t != 0:
	solve()
	t -= 1

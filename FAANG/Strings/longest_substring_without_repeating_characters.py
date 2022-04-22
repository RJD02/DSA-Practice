def solve():
	s = input()
	count = -float('inf')
	for i in range(len(s)):
		l = []
		for j in range(i, len(s)):
			if s[j] not in l:
				l.append(s[j])
			else:
				break
		count = max(count, len(l))
	print(count)

t = int(input())
for i in range(t):
	solve()
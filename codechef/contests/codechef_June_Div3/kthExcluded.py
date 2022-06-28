n, q = map(int, input().split())
l = list(map(int, input().split()))
# res = [x for x in range(10000) if x not in l]
for j in range(q):
	qu = int(input())
	count = qu - 1
	i = 1
	while(count >= 0):
		if i not in l:
			count -= 1
		i += 1
		# print(i)
	print(i - 1)
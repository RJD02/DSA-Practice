def solve():
	inarr, instr = [i for i in input().split(',')], input()
	res = []
	for word in inarr:
		l = [int(instr.count(letter) >= word.count(letter)) if letter in instr else 0 for letter in set(word)]
		res.append(word) if min(l) == 1 else 0
	print(','.join(res))

solve()
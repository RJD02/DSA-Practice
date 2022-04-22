def is_palindrome(s):
	left = 0
	right = len(s) - 1
	while left < right:
		if s[left] != s[right]:
			return False
		left += 1
		right -= 1
	return True

def solve():
	s = input()
	# print('hello')
	left = 0
	right = len(s) - 1
	ans = True
	while left < right:
		# print('hello')
		if s[left] != s[right]:
			ans = max(is_palindrome(s[left : right]), is_palindrome(s[left + 1: right + 1] ))
			print(ans)
			return
		left += 1
		right -= 1
	print(ans)

def main():
	t = int(input())
	for _ in range(t):
		solve()

main()
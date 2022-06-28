a, b, c = map(int, input().split())
# if pow(a, c) < pow(b, c):
# 	print('<')
# elif pow(a, c) > pow(b, c):
# 	print('>')
# else:
# 	print('=')
if a > 0 and b > 0:
	if a > b:
		print('>')
	elif a < b:
		print('<')
	else:
		print('=')
elif a < 0 and c % 2 == 0:
	if -a > b:
		print('>')
	elif -a < b:
		print('<')
	else:
		print('=')
elif b < 0 and c % 2 == 0:
	if a > -b:
		print('>')
	elif a < -b:
		print('<')
	else:
		print('=')
else:
	if a > b:
		print('>')
	elif a < b:
		print('<')
	else:
		print('=')
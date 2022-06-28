bins = ['10', '11', '101', '111', '1011', '1101']

tc = int(input())
for i in range(tc):
	bin_string = input()

	for i in bins:
		if i in bin_string:
			print('yes')
			break
	else:
		print('no')


def two_sum(nums, target):
	res = []
	d = {}
	for i in range(len(nums)):
		if nums[i] in d.keys():
			res.append(i)
			res.append(d[nums[i]])
		else:
			d[target - nums[i]] = i

	return res

print(two_sum([2,7,11,15], 9))
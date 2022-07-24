# https://www.codewars.com/kata/515de9ae9dcfc28eb6000001/

def solution(s):
    res = []
    for i in range(0, len(s), 2):
        res.append(s[i: i + 2])
    if len(res) > 0 and len(res[-1]) == 1:
        res[-1] = res[-1] + '_'
    return res
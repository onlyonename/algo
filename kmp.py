#! /usr/bin/python3

# coding:utf-8


def create_next(pattern, size, Next):
	Next.append(-1)
	j = 0
	k = -1
	while(j < size - 1):
		if(k == -1 or pattern[j] == pattern[k]):
			j = j + 1
			k = k + 1
			Next.append(k)
		else:
			k = Next[k]
		
		
#找到了返回下标,没找到返回-1
def search(src, src_len, pattern, pattern_len):
	Next = []
	create_next(pattern, pattern_len, Next)
	
	i = 0
	j = 0
	while(i < src_len and j < pattern_len):
		if(j == -1 or src[i] == pattern[j]):
			i = i + 1
			j = j + 1
		else:
			j = Next[j]

	if(j == pattern_len):
		return i - j

	return -1


	
		
		
src = 'abcabdabeabcdabad'
pattern = 'abcdab'

ret = search(src, len(src), pattern, len(pattern))
print(ret)






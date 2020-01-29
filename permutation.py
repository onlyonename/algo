#! /usr/bin/python3

# coding:utf-8


import itertools

a = [1,2,3,4]

#4个序列的排序
for i in itertools.permutations(a, 4):
    print (i)

#3个序列的排序
for i in itertools.permutations(a, 3):
    print (i)


for i in itertools.repeat('a', 4):
    print (i)





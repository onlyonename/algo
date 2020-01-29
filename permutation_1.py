#! /usr/bin/python3

# coding:utf-8

#强行翻译c++的做法,写的很不python



def permutation(src, item, result):
    if len(src) == len(item):
        print("find one item: %s" % item)
        tmp = item.copy()
        result.append(tmp)
        print("result id:%d, content:%s" % (id(result), result))
        return
    
    for i in src:
        if(i in item):
            continue
        
        item.append(i)
        
        permutation(src, item, result)
    
        item.pop()



src = [1, 2, 3]
result = []
item = []

permutation(src, item, result)

print(result)


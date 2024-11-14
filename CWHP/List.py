lis=[1,3,4,5,6,3]
print(lis)

lis.append(8)
print(lis)

# return the index of vaule and not the value at the index.
# the second integre denotes the nth occurance of the first value
print(lis.index(3))
print(lis.index(3,2))


print("count is ", lis.count(3))

# here the list is not sorted so we cannoto reverse the list and hence get "NONE" as output
print(lis.reverse())

lis.sort()
print(lis)

# it seems that reverse only sorted list
lis.reverse()
print(lis)

lis.insert(3,5)
print(lis)
x=(34,43,4565,56,6554,34, False, "Tuple")
'''
this is a tuple and we know it because it has parenthesis and not square brackets
we cannot change values in a tuple but still can access it.
'''
print(x)
print(type(x))

if 3 in x:
    print("It is present in tuple and we just accessed an element in tuple.")

print(x[:3])

print(x.index(34))
print(x.count(34))
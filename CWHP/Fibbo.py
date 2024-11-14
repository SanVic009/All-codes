def fibbo(n):
    '''This will return the nth term of fibbonacci series. This statement is calle the doctype of the function and is technically not a comment.'''
    if n==1:
        return 0
    elif n==2:
        return 1
    else:
        return fibbo(n-1)+fibbo(n-2)


print(fibbo.__doc__)
print(fibbo(7))
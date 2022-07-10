def mypow(b, a):
    if (a == 0):
        return 1
    else:
        return b * mypow(b, a - 1)


print(mypow(1,10))
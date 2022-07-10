## https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem

arr = [1,2,3,4,5]
print(arr)
arlen = len(arr)
shift = 4
newarr = [0]*arlen

for i in range(arlen):
    newidx = (i - shift) % arlen
    newarr[newidx] = arr[i]

print(newarr)
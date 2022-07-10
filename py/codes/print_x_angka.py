import sys

n = 6

for i in range(1,n+1):
    for j in range(1,n+1):
        if i == j or (n - i - j + 1) == 0:
            sys.stdout.write("{}".format(j))
        else:
            sys.stdout.write(" ")
    print(" ")

#m = n    
#for i in range(1,n+1):
#    for j in range(1,n+1):
#        if i == j or (j == m):
#            sys.stdout.write("%s" % j)
#        else:
#            sys.stdout.write(" ")            
#    m = m - 1
#    print(" ")
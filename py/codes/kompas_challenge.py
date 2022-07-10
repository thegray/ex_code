import sys

n = int(input().strip())
n2 = n/2
for i in range(n+1):
    for j in range(n+1):
        if i <= n2:
            if i <= j and (i+j <= n):
                sys.stdout.write("*")
            else:
                sys.stdout.write(" ")
        else:
            if i >= j and (i+j >= n):
                sys.stdout.write("*")
            else:
                sys.stdout.write(" ")
    #sys.stdout.write("    {}\n".format(i))
    sys.stdout.write("\n")
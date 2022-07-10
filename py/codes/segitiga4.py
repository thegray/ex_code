import sys

n = 5

for i in range(1,n+1):
    for j in range(1,n+1):
        if j+i >= n+1:
            sys.stdout.write("*")
        else:
            sys.stdout.write(" ")
    print("")

  #
 ##
###
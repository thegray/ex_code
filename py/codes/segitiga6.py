import sys

n = 7

for i in range(n):
    for j in range(n*2):
        if j > i and j+i < n*2:
            sys.stdout.write("*")
        else:
            sys.stdout.write(" ")
    print("")


#####
 ### 
  #  
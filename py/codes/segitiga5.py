import sys

n = 6

for i in range(n+1):
    for j in range(n*2):
        if j+i >= n+1 and j-i < n:
            sys.stdout.write("*")
        else:
            sys.stdout.write(" ")
    print("")


   #   
  ###  
 ##### 
#######
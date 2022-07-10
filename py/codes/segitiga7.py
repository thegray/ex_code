  #
 ### 
#####
 ###
  #

import sys

n = 7
m = int(n/2)

for i in range(1,n+1):
    for j in range(1,n+1):
        if i <= m:
            if j+i > m+1 and j-i <= m:
                sys.stdout.write("*")
            else:
                sys.stdout.write(" ")
        else:
            if i-j <= m and n*2-1 > i+j:
                sys.stdout.write("*")
            else:
                sys.stdout.write(" ")
    print("")


  ##  
 ####
######
######
 ####
  ##
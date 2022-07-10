import sys

n = 5

for i in range(1, n+1):
    for j in range((n+1-i)):
        sys.stdout.write("*")
    print("")

###
##
#
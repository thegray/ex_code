
year = 2000

leap = False

if year % 4 == 0 and (year % 400 == 0 or year % 100 != 0):
    leap = True
    
#if (year % 400) != 0:
#    if (year % 4) == 0:
#        if (year % 100) != 0:
#            leap = True
#else:
#    leap = True

print(leap)

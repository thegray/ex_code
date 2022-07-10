n = 600851475143

def checkPrime(x):  #from wikipedia
    if x <= 1:
        return False
    elif x <= 3:
        return True
    elif x % 2 == 0 or x % 3 == 0:
        return False
    j = 5
    while j ** j <= x:
        if x % j == 0 or x % (j + 2) == 0:
            return False
        j = j + 6
    return True

angka = 0
checkThis = 0
i = 2
while True:
    print(i)
    if n % i == 0:
        angka = i
        checkThis = n/angka
        #print("angka: {} | checkThis:{}".format(angka, checkThis))
        if checkPrime(checkThis):
            print("largest prime")
            break
    elif i == n:
        break
    else:
        i = i + 1

print(checkThis)
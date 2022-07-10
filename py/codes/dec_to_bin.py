def toBinary(x):
    y = 0
    if x <= 1:
        print(x)
    else:
        y = x % 2
        toBinary(x / 2)
        print(y)

def toBinary2(x):
    count = 0
    while x > 1:
        if x % 2 == 1:
            count = count + 1
        x = x / 2
    print("count 1 : {}".format(count))

def soal(n):
    c = 0
    cmax = c
    buf = -1
    while n > -1:
        #print("1 buf: {}, n: {}".format(buf, n))
        if buf == 1:
            c = c + 1
            #print("c: {}".format(c))
        elif buf == 0:
            c = 0
        if cmax < c:
            cmax = c
        if n == 0:
            n = -1
        else:
            buf = n % 2
            n = n / 2
        #print("2 buf: {}, n: {}".format(buf, n))
    print("count 1 : {}".format(cmax))

def main():
    z = 5
    toBinary(z)
    #toBinary2(z)
    soal(z)

if __name__ == '__main__':
    main()
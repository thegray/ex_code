n = input()

if n % 4 != 0:
    if n % 400 != 0 and n % 100 == 0:
        print("tidak kabisat")
    else:
        print("kabisat")
else:
    print("kabisat")
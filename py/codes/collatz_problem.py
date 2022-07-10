def collatz(number):
    res = 0
    if number % 2 == 0:
        res = number // 2
    else:
        res = 3 * number + 1
    print(res)
    return res

print("masukkan sebuah integer:")
angka = int(input())

while True:
    angka = collatz(angka)
    if angka == 1:
        break

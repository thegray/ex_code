import random
secretNumber = random.randint(1, 20)

print("tebak nomer 1 ~ 20")

guess = 0
attempt = 0

while guess != secretNumber:
    print("coba tebak")
    guess = int(input())
    attempt += 1
    if guess < secretNumber:
        print("kekecilan")
    elif guess > secretNumber:
        print("kegedean")
    else:
        break

print("berhasil nebak dalam {} percobaan".format(attempt))
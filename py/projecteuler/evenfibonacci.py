a = 1
b = 2
c = 0
sum = 0
while c < 4000000:
    if b % 2 == 0:
        sum = sum + b
    c = a + b
    a = b
    b = c
print(sum)
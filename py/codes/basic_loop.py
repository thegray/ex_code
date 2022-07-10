str = ""

for i in [1,2,3,4,5]:
    for j in [1,2,3,4,5]:
        if i == j:
            str += "*"
        else:
            str += " "
    str += '\n'

print(str)

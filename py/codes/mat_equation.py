num = "0123456789"
op1 = "*/"
op2 = "+-"

inp = "1+8/4-3"

ln = []
lo = []

if (inp[0]) not in num:
    print("error")
else:
    i = 1
    while(i < len(inp)):
        if inp[i] in op1:
            ln.append()
        i += 2
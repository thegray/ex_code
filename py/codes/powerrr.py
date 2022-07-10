n = 100

hasil = 0
for x in range(1, (n+1)):
    #print(x)
    #print("hasil sebelom: {} ".format(hasil) )
    if x>9:
        hasil *= 10
    elif x>99:
        hasil *= 10000
    if x == 200:
        print("hasil sebelom: {} ".format(hasil) )   
    opo = 10**(n-x) * x
    print(opo)
    hasil += opo
    if x == 200:
        print("hasil sesudah: {} ".format(hasil) )    
    #print("hasil sesudah: {} ".format(hasil) )
    
#print(hasil)
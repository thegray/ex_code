#single quote
print('P"casso')

#double quotes
print("P'casso")

#triple quotes
print('''...Picasso...''')

#escape characters
print("P\ti\nca\Osso")

#raw strings
print(r"C:\myscript.py")

#byte strings
print(b'Picas\x01so')

type(b'Picas\x01so')

type('normal_strings')

#unicode strings
S = 'A\u00c4B\U000000e8C'
print(S)
len(S)

#same use
aa = 'Picasso', "Picasso"
print(aa)
a2 = 'Mozart"s', "Mozart's"
print(a2)

masters = "Mozart " 'and' " Picasso"
print(masters)

#use ',' will create tuple
a3 = "Mozart\"s", 'Picasso\'s'
print(a3)

#escape sequences
a4 = 'a\nb\tc'
print(a4)
print(len(a4))

#raw string keep the escape sequences a char
#example use for path to a file
##myfile1 = open(r'C:\new\text.txt','w')
#or, without raw string, use double backslash
##myfile2 = open('C:\\new\\text.txt', 'w')

#triple quotes for multiline block strings
Python = """Python aims to combine
"remarkable power
with very clear syntax", and..."""
print(Python)

#string in slice objects
#S[::x]
a5 = 'Edsger Dijkstra'
print(a5[1:10:2]) #get 1 to 9 per 2 step
print(a5[::2])

#negative stride to indicate slicing direction from right to left
#to reverse the sequence
print('negative stride 1: ' + a5[::-1])

#if using negative stride, the bound must be reversed too
print('negative stride 2: ' + a5[10:0:-1])
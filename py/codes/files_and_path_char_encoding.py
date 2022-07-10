### http://www.bogotobogo.com/python/python_files.php

#character encoding
fileA = open('mydir/alone.txt')
fileA.mode
print(fileA.mode)
fileA.name
print(fileA.name)
fileA.encoding
print(fileA.encoding)
print('----')
#specify the encoding
fileB = open('mydir/alone.txt', encoding='utf-8')
print(fileB.encoding)

strB = fileB.read()
print(strB)

str2 = fileB.read() #this will return empty string
print("str2: '" + str2 +"'")

fileB.seek(0) #move to byte position in the file

print(fileB.read(15))
print(fileB.read(1))
print(fileB.read(10))
print(fileB.tell())

fileB.close()
# fileB.read() crash, file closed
# fileB.seek(0) crash, file closed
# fileB.tell() crash, file closed
print(fileB.closed)

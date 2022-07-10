### http://www.bogotobogo.com/python/python_files.php

myimg = open('mydir/python_image.png', mode='rb')
print(myimg.mode)
print(myimg.name)
# print(myimg.encoding) binary has no have encoding

print(myimg.tell())
imgdata = myimg.read(5)
print(imgdata)

print(type(imgdata))

print(myimg.tell())
print(myimg.seek(0))
imgdata = myimg.read()
print(len(imgdata))
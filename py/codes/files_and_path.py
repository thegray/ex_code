### http://www.bogotobogo.com/python/python_files.php

import os
import glob
import time
import io
import sys

print(os.getcwd())

#os.chdir('../gg') #change current working dir
#os.chdir('gg')
#print(os.getcwd())

print(os.path.join('/test/', 'myfile')) #concatenate strings, add /

#the slash on the 2nd parameter specify to use absolute path, resulting override the path before
print(os.path.join('/test/', '/myfile'))

print(os.path.expanduser('~')) #get current user home dir, very useful

print(os.path.join(os.path.expanduser('~'), 'dir', 'subdir', 'k.py'))

pathname = "/Users/PBK/dir/subdir/pbk.py"
print(os.path.split(pathname))

(dirname, filename) = os.path.split(pathname)
print(dirname)
print(filename)

(shortname, extension) = os.path.splitext(filename)
print(shortname)
print(extension)

# import glob # move to top

print(glob.glob('subdir/*.py'))

os.chdir('subdir')
print(os.getcwd())

metadata = os.stat('11.py') # read the metada of the file
print(metadata.st_mtime)

# import time # move to top
print(time.localtime(metadata.st_mtime)) # format the time to something useful

print(metadata.st_size) # size of the file

print(os.path.realpath('11.py'))

# insert variable to environment
os.environ['SUBDIR'] = 'subdir'
print(os.path.expandvars('/home/users/K/$SUBDIR'))
os.chdir('..')
print(os.getcwd())
myfile = open(os.path.join(os.getcwd(), 'mydir/myfile.txt'), 'w')
print("myfile : ")
print(myfile)

####
#### encoding part in other file
####

with open('mydir/hellow.py') as file: #keyword with to guarantee file closed
    file.seek(0)
    strWith = file.read()
    print("inside 'with' : " + strWith)

# read line by line
lineCount = 0
with open('mydir/alone.txt', encoding='utf-8') as file:
    for line in file:
        lineCount += 1
        print('{:<1} {}'.format(lineCount, line.rstrip()))

print("----")

# write to file, open file with specified mode
with open('mydir/myfile.txt', mode='a', encoding='utf-8') as file:
    file.write('Wolololololo lolololo.')

with open('mydir/myfile.txt', encoding='utf-8') as file:
    print(file.read())

with open('mydir/myfile.txt', mode='a', encoding='utf-8') as file:
    file.write('\nAdd lagiii lol.')

with open('mydir/myfile.txt', encoding='utf-8') as file:
    print(file.read())
print('---- ')
# read()
# import io # move to top
mystr = 'C is quirky, flawed, and an enormous success. - Dennis Ritchie (1941-2011)'
myfile1 = io.StringIO(mystr) # StringIO class to treat strings as file
print(myfile1.read())
print(myfile1.read()) # empty
print(myfile1.seek(0))
print(myfile1.read(10))
print(myfile1.tell())
print(myfile1.seek(10))
print(myfile1.read())

# stdout stderr
# import sys # move to top
class StdoutRedirect:
    def __init__(self, newOut):
        self.newOut = newOut
    
    def __enter__(self):
        self.oldOut = sys.stdout
        sys.stdout = self.newOut

    def __exit__(self, *args):
        sys.stdout = self.oldOut

print('X')
with open('output', mode='w', encoding='utf-8') as my_file:
    with StdoutRedirect(my_file):
        print('Y')
print('Z')


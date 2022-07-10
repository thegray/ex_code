import os
print(os.getcwd()) #os.getcwd() get current working dir

#os.chdir('../gg') #change current working dir
#os.chdir('gg')
#print(os.getcwd())

print(os.path.join('/test/', 'myfile')) #concatenate strings, add /

print(os.path.expanduser('~')) #get current user home dir, very useful

print(os.path.join(os.path.expanduser('~'), 'dir', 'subdir', 'k.py'))


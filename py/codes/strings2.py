s1 = 'black holes are where God divided by zero'
s2 = 'sample.txt'
#capitalize first char
print(s1.capitalize())

#center a string
print(s1.center(50, "$")) #default is a space

#count occurences of a substring in string
print(s1.count('i'))
print(s1.count('hole'))

#find if string end with a substring
print(s1.endswith('ero'))
print(s2.endswith('txt'))

#find substring
where = s1.find('God')
where2 = s1.find(' are')
s2 = s1[:where2] + s1[where2+1:where]
print(s2)

#index : like find but with exception ValueError when not found
ind = s1.index('God')
print('index: %d' % ind)
#not found example, will raise exception
#ind2 = s1.index('god')

#partition : split string at first occurence of substring, return 3 tuple
s3 = s1.partition('are')
print(s3)

stop = 'haha'

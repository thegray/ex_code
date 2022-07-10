s1 = 'I am using %s %d.%d' %('Python', 3, 2)

print(s1)

binari = "binary: {0:b}".format(10)

print(binari)

n = 6789
a = "...%d...%-6d...%06d" %(n,n,n)

print(a)

m = 9.87654321
b = '%e | %E | %f | %g' %(m,m,m,m)

print(b)

c = '%6.2f | %05.2f | %+06.1f' %(m,m,m)
print(c)

d = '%s' % m, str(m)
print(d)

e = '%f, %.3f, %.*f' % (9.87654321, 9.87654321, 4, 9.87654321) #4 specify the precision to corresponding *
print(e)

#formatting dictionary
f = '%(m)d %(w)s' %{'m':101, 'w':'Freeway'}
print(f)

greetings = '''
Hello %(name)s!
Merry Christmas.
I hope %(year)d will be a good year.
'''

replace = {'name' : 'Scala', 'year' : 2017}
print(greetings % replace)

lang = 'Python'
version = 320
paw = 'GG'
vars()
{'lang':'Python', '__builtins__': None, 'paw': 'GG',
'__package__': None, 'version': 320, '__name__': '__main__', '__doc__': None}

g = '%(lang)s %(version)d %(paw)s' % vars()
print(g)

#template
h = '{Month}, {Day}, {Year}'
h1 = h.format(Month='Dec', Day='29', Year='2013')
print(h)
print(h1)

i = '{0}, {1}, {2}'
i1 = i.format('Dec', '29', '2013')
print(i)
print(i1)

i2 = '{Year}, {Month}, {0}'
i3 = i2.format('29', Year='2013', Month='Dec')
print(i2)
print(i3)

i4 = '{Month}, {Year}, {0}\n'.format('29', Month=['Nov', 'Dec'], Year='2013')	  
print(i4)

import sys

j = 'My {0[Machine]} is running {1.platform}\n'.format({'Machine': 'notebook'}, sys)
print(j)

j1 = 'My {config[Machine]} is running {sys.platform}'.format(config={'Machine':'notebook'}, sys=sys)
print(j1)

#Formatting dictionary strings
s1 = '%(m)d %(w)s' %{'m':101, 'w':'Freeway'}
print(s1)

#neat dictionary example
greetings = '''
Hello %(name)s!
Merry Christmas.
I hope %(year)d will be a good year.
'''
replace = {'name':'Scala', 'year':2017}
print(greetings % replace)
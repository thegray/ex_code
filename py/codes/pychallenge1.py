# map
from string import maketrans

str = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."

intab = "abcdefghijklmnopqrstuvwxyz"
outab = "cdefghijklmnopqrstuvwxyzab"
transtab = maketrans(intab, outab)

print(str.translate(transtab))

str2 = "http://www.pythonchallenge.com/pc/def/map.html"

print(str2.translate(transtab))

str2 = ""
for c in str:
    str2 = str2 + chr(ord(c)+2)
#print(str2)
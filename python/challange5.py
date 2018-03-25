import binascii
import itertools

def xor(s, key):
    key = key * (len(s) / len(key) + 1)
    return ''.join(chr(ord(x) ^ ord(y)) for (x,y) in itertools.izip(s, key)) 


token = binascii.unhexlify("cb421db012e76884d9")
key = xor(token, "isAdmin=0")
print(binascii.hexlify(xor("isAdmin=1",key)))

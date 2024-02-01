# import numpy as np

a = int(input())
b = 1

cont = 0

while ( abs(a - b*b) > 0.000000000001):
    b = (b*b + a)/(2*b)
    print(b)
    print(b*b)
    cont+=1

print (cont)
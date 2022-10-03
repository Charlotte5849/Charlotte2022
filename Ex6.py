#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 15 19:19:15 2021

@author: chenpeian
"""


'''
每層之間的疏密程度
print"" -> 單純換行
print("\n") -> 行與行之間空一行
print("\n\n") -> 行與行之間空兩行，以此類推
'''

#n= int(input('請輸入數字：'))
a=11
b=21
c=31
d=41


for i in range(1,6):
    print(" "*(21-i)+"*"*(2*i-1))

for i in reversed(range(3,5)):
    print(" "*(21-i)+"*"*(2*i-1))


for x in range(5,b,2):
    S = int((b-x)/2) #x=5 b=21 S=8 #x=7 b=21 S=7
    for y in range(int(10)+S): #y1 = 18 #y1=17
        print(" ",end='') 
    for z in range(x): #z=5 #z=7
        print("*",end='')
#    for y2 in range(S): #y2=8 
#        print(" ",end='')
    print("")

for x in range(11,c,2):
    S = int((c-x)/2)
    for y in range(int(5)+S):
        print(" ",end='')
    for z in range(x):
        print("*",end='')
#    for y2 in range(S):
#        print(" ",end='')
    print("")
    
for x in range(19,d,2):
    S = int((d-x)/2)
    for y in range(S):
        print(" ",end='')
    for z in range(x):
        print("*",end='')
#    for y2 in range(S):
#        print(" ",end='')
    print("")

sum=0
if sum <= 5:
    print(("               %%%%%%%%%%%"+"\n")*int(5))
    sum += 1

'''
for x in range(3,a,2):
    S = int((a-x)/2)
    for y1 in range(int(15)+S):
        print(" ",end='')
    for z in range(x):
        print("*",end='')
    for y2 in range(S):
        print(" ",end='')
    print("")
'''
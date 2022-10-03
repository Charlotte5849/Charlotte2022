#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 15 19:08:48 2021

@author: chenpeian
"""

text = input('Enter the upper bound k : ')
print(text)
k = int(text)

sum = 0
for i in range(1,k+1,1):
    sum = sum + i
print(sum)
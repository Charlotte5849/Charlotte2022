#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 10 14:00:27 2021

@author: chenpeian
"""

#計算時間
import time 
def now():
    moment = time.asctime()
    print(moment)
    
Start_Time = time.time()
now()

import math
import random

g = 0  #guess_time
c = random.randrange(1,100) #correct answer
guess_big = [100]
guess_small = [1]
guess=[1]
#print(c)


def check(number):
    g=1
#    number = float(input("請輸入一個介於 1 到 100 的數字： "))
    while number != c :
        if number == -1 :
            print("Present time is : ", time.asctime()[11:19])
            End_Time=time.time()
            break
        
        elif number > c  :
            g+=1
            guess_big.append(number)
            number = float(input("太大了 請輸入介於 %d 到 %d 的數字： " %(guess_small[-1],guess_big[-1])))
            guess.append(number)
            
            #print(guess,g)
        elif number < c  :
            g+=1
            guess_small.append(number)
            number = float(input("太小了 請輸入介於 %d 到 %d 的數字： " %(guess_small[-1],guess_big[-1])))
            guess.append(number)
            
            #print(guess,g)

        else:
            break
    print("Bingo! The answer is %d" %guess[-1])
    print("Number of guess : ", g, "!")
          
while True:
    g = 0
    number = float(input("請輸入一個介於 1 到 100 的數字： "))
    try:
        if number == -1 :
            print("Present time is : ", time.asctime()[11:19])
            End_Time=time.time()
            break
        elif number < 1 or number > 100:
            raise ValueError
            print("Present time is : ", time.asctime()[11:19])
            End_Time=time.time()
        else:
            g=1
            guess.append(number)
            print(guess,g)
            check(number)
            break
    except ValueError:
        print("Please enter again")


print("Present time is : ", time.asctime()[11:19])
End_Time=time.time()
print("It costs %d seconds." %(End_Time-Start_Time))
input("Please press <ENTER> to end the program!")


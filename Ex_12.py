#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 27 16:26:22 2021

@author: chenpeian
"""




#open input file
inputfile=open('input_Ex12.txt','r')

#get the next answer from input file
line=inputfile.readline()
answer=line.rstrip()
length=len(answer)

print("Hello! 歡迎來玩猜字遊戲！ 請根據提示猜單字，每猜對一次就可以得到 150 分，猜中字數多的題目可以得到 BOnus 的 50 分！猜錯一次則倒扣 50 分，試著得到最高的分數吧！",end='')
ready = input("Are you ready? 請輸入 y/n ")
C=0
W=0
S=0
#the game
while ready =='y':
   
    reply = input('Enter a len %d word start with %s: ' % (length, answer[0]))
    if reply == 'stop':
        print("Number of correct guesses: ", C ," times")
        print("Number of wrong guesses: ", W ," times")
        print("Your Final Score : ",S,end='\n')
        print("See you next time!")
        break
    elif reply.isdigit():
        print('Bad!')
        W+=1
        S-=50
    elif answer == reply and length > 4 :
        C+=1
        S+=200
        print('Congratulations! Answer is %s!' %answer)
        #get the next answer from input file
        line=inputfile.readline()
        if line!='':
            answer=line.rstrip()
            length=len(answer)
        else:
            print("Number of correct guesses: ", C ," times")
            print("Number of wrong guesses: ", W ," times")
            print("Your Final Score : ",S,end='\n')
            print("Game over! No more words to guess! See you next time!")
            break
    elif answer == reply and length <= 4 :
        C+=1
        S+=150
        print('Congratulations! Answer is %s!' %answer)
        #get the next answer from input file
        line=inputfile.readline()
        if line!='':
            answer=line.rstrip()
            length=len(answer)
        else:
            print("Number of correct guesses: ", C ," times")
            print("Number of wrong guesses: ", W ," times")
            print("Your Final Score : ",S,end='\n')
            print("See you next time!")
            break
    else:
        W+=1
        S-=50
        for i in range(length):
            if reply[i]==answer[i]:
                print (answer[i],end='')
            else:
                print('*',end='')
        print()
print('Bye!')

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov  4 00:08:37 2021

@author: chenpeian
"""


#open input file
inputfile=open('input.txt','r')

#get the next answer from input file
line=inputfile.readline()
answer=line.rstrip()
length=len(answer)

#define variables

C=0
W=0
S=0
M=0
default_score = 0

#Ask questions
name = input('Please enter your name: ' )
number = input('Please enter your Student ID: ')

#define functions
def Name(name):
#    print('Hello! ',name, '! ')
    return name

def intro(name, number):
    print('您的姓名：',name,'您的學號：',number)
    return name, number
    
def add_score_independent(s=default_score, class_sroces=None):
    if class_scores is None:
        class_scores = []
    class_scores.append(s)
    return class_scores
        
def Bye():
    print('Bye!');

#Greeting
print('Hello!',Name(name),'!')
intro(name, number);
print("歡迎來玩猜字遊戲！ 請根據提示猜單字，每猜對一次就可以得到 150 分，猜中字數多的題目可以得到 Bonus 的 50 分！猜錯一次則倒扣 50 分，試著得到最高的分數吧！",end='')
ready = input("Are you ready? 請輸入 y/n ")
    
#the game
while ready =='y':
   
    reply = input('Enter a len %d word start with %s: ' % (length, answer[0]))
    if reply == 'stop':
        print("Number of correct guesses: ", C ," times")
        print("Number of wrong guesses: ", W ," times")
        print("Final Score of",name,'is',S,'!',end='\n')
        print("See you next time!")
        break
    elif reply.isdigit():
        print('Bad!')
        W+=1
        S-=50
        M+=1
        S-=10*M
        print("Ohh.... minus",add_score_independent(50+10*M),"points !")
    elif answer == reply and length > 4 :
        C+=1
        S+=200
        print("You got",add_score_independent(200),"points !")
        print('Congratulations! Answer is %s!' %answer)
        #get the next answer from input file
        line=inputfile.readline()
        if line!='':
            answer=line.rstrip()
            length=len(answer)
        else:
            print("Number of correct guesses: ", C ," times")
            print("Number of wrong guesses: ", W ," times")
            print("Final Score of",name,'is',S,'!',end='\n')
            print("Game over! No more words to guess! See you next time!")
            break
    elif answer == reply and length <= 4 :
        C+=1
        S+=150
        print("You got",add_score_independent(150),"points !")
        print('Congratulations! Answer is %s!' %answer)
        #get the next answer from input file
        line=inputfile.readline()
        if line!='':
            answer=line.rstrip()
            length=len(answer)
        else:
            print("Number of correct guesses: ", C ," times")
            print("Number of wrong guesses: ", W ," times")
            print("Final Score of",name,'is',S,'!',end='\n')
            print("See you next time!")
            break
    else:
        W+=1
        S-=50
        
        M+=1
        S-=10*M
        print("Ohh.... minus",add_score_independent(50+10*M),"points !")
     
        for i in range(length):
            if reply[i]==answer[i]:
                print (answer[i],end='')
                
            else:
                print('*',end='')
        print()
    
Bye();
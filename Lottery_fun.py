# FUNCTIONS
import random
def lotto_seven(lotto_list):
    lotto_list.extend(random.sample(range(1, 50), 7))
    return lotto_list

def user_lotto(user_list):
    while True:
        try:
            i1, i2, i3, i4, i5, i6, i7 = map(int, input("請輸入 7 個 1 ~ 49 （含）間的數字，最後一個為特別號。").split()) 
            user_list.extend([i1, i2, i3, i4, i5, i6, i7])
            global i 
            global ur_luckynum
            ur_luckynum = int(i7)
            i = int(1)
            break
        except:
            i = int(0)
            print('請輸入正確的數字個數。', i)
            pass
    return i, user_list, ur_luckynum

def check_repeat(user_list):
    global i
    if len(list(set(user_list)))<7:
        i = int(0)
        # print(list(set(user_list)))
        print('請輸入不重複的 7 個數字。')
    else:
        i = int(1)
    return i, user_list

def check_range(user_list):
    global i
    i = int(1)
    for k in range(len(user_list)):
        if user_list[k] < int(1) or user_list[k] > int(49):
            i = int(0) 
            print('請輸入正確的數字範圍（1~49）。')
        else:
            continue
            # i = int(1)
    return i, user_list

def check_lottery(user_list, sorted_userlist, lotto_list, sorted_lotto):
    global z
    if user_list[-1]==lotto_list[-1]:
        z+=5
    else:
        z+=0
    for k in range(6):
        if sorted_userlist[k] in  sorted_lotto:
            z+=1
    if z == int(10):
        print('您對中當期獎號之任五碼＋特別號，恭喜得到『貳獎』')
    elif z == int(9):
        print('您對中當期獎號之任四碼＋特別號，恭喜得到『肆獎』')
    elif z == int(8):
        print('您對中當期獎號之任三碼＋特別號，恭喜得到『陸獎』')
    elif z == int(7):
        print('您對中當期獎號之任兩碼＋特別號，恭喜得到『柒獎』')
    elif z == int(6): 
        print('您所選支號碼與當期六個獎號完全相同，恭喜得到『頭獎』')
    elif z == int(5):  
        print('您對中當期獎號之任五碼，恭喜得到『參獎』')
    elif z == int(4):          
        print('您對中當期獎號之任四碼，恭喜得到『伍獎』')
    elif z == int(3):
        print('您對中當期獎號之任三碼，恭喜得到『普獎』')
    else :
        print('銘謝惠顧，下次再來！')   

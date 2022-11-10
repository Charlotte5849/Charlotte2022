# EXECUTION
import random
global lotto_list
lotto_list = []

global user_list
user_list = []
ur_luckynum = int(0)
i = int(1) 

# 使用者選數字
global user_list
user_list = []
ur_luckynum = int(0)
i = int(1) 

while True:
    user_list = []
    user_lotto(user_list)
    check_range(user_list)
    if i == int(1):
        check_repeat(user_list)
        if i == int(1):
            break
        else:
            print('mistake1',i) 
            pass
    else:
        print('mistake2',i) 
        pass
    
lotto_seven(lotto_list)
sorted_lotto = sorted(lotto_list[:-1])

sorted_userlist = sorted(user_list[:-1])

print('您下注的號碼依序為：', sorted_userlist[0], end='')
for j in range(1, len(sorted_userlist)):
    print(',', sorted_userlist[j], end='') 
print('，', '特別號：', user_list[-1])

print('本期中獎號碼依序為：', sorted_lotto[0], end='')
for i in range(1, len(sorted_lotto)):
    print(',', sorted_lotto[i], end='') 
print('，', '特別號：', lotto_list[-1])

check_lottery(user_list, sorted_userlist, lotto_list, sorted_lotto)

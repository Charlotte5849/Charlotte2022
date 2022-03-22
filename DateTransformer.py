import re
def time_transform(s):
  s = input("請輸入你想轉換的國曆日期 \n格式為：YYY 年 MM 月 DD 日 上午/下午 HH 時 MM 分 SS 秒：")
  timee = re.compile(r'\d+') 
  timee1 = timee.findall(s) 
  for i in s:
    if str(i)=="下":
      timee1[3] = int(timee1[3])+12
  timee1[0] = int(timee1[0])+1911
  slash = "/"
  print(timee1)
  print(f"{timee1[0]}{slash}{timee1[1]}{slash}{timee1[2]}")

time_transform(s)

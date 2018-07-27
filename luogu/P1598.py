s1=input()
s2=input()
s3=input()
s4=input()
s=s1+s2+s3+s4
dic=[0 for i in range(26)]
for i in s:
    if  i.isalpha()==False:
        continue
    num=ord(i)-ord('A')
    dic[num]+=1
maxx=max(dic)
for i in range(maxx,0,-1):
    for j in range(26):
        if(dic[j]==i):
            print('*',end=' ')
            dic[j]-=1
        else:
            print(' ',end=' ')
    print()
for i in range(26):
    print(chr(i+ord('A')),end=' ')
print()

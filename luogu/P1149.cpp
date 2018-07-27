a=[6,2,5,5,4,5,6,3,7,6]
b=[]
for i in range(1001):
    s=str(i)
    sum=0
    for j in s:
        num=int(j)
        sum+=a[num]
    b.append(sum)
n=int(input())
sum=0
for i in range(1000):
    for j in range(1000):
        if(i+j<=1000 and b[i]+b[j]+b[i+j]+4==n):
            sum+=1
print(sum)

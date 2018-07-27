import math
n=int(input())
m=math.log10(2.0)
num=math.ceil(n*m)
mod=10**500
ans=pow(2,n,mod)-1
ans=str(ans).zfill(500)
print(num)
for i in range(10):
    print(ans[50*i:50*i+50])

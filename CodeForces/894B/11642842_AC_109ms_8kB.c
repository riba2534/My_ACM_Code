a,b,c=list(map(int,input().split()))
if c==-1 and (a+b)%2!=0:
    print(0)
else:
    print(pow(2,a*b-a-b+1,1000000007))
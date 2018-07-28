def power_mod(a,b,c):
    a=a%c
    ans=1
    while b!=0:
        if(b&1):
            ans=ans*a%c
        a=a*a%c
        b=b>>1
    return ans
        

while True:
    try:
        a,b,c=map(int,input().split())
        print(power_mod(a,b,c))
    except EOFError:
        break
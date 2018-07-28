def find(x,pre):
    if x==pre[x]:
        return x
    else:
        pre[x]=find(pre[x],pre)
        return pre[x]
def mix(x,y,pre):
    fx=find(x,pre)
    fy=find(y,pre)
    if(fx!=fy):
        pre[fy]=fx

n,m=map(int,input().split())
a=[int(x) for x in input().split()]
pre=[i for i in range(n)]
for case in range(m):
    x,y=map(int,input().split())
    mix(x-1,y-1,pre)
for i in range(n):
    r=find(i,pre)
    a[r]=min(a[r],a[i])
sum=0
for i in range(n):
    if i==find(i,pre):
        sum+=a[i]
print(sum)


n=int(input())
i = '110'
p=1
while int(i,2)<=n:
  if n%int(i,2)==0:
    p=int(i,2)
  i='1'+i+'0'
print(p)
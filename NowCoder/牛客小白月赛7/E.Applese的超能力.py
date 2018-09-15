def calc(n, m):
    while n >= m:
        mod = n % m
        div = n//m
        n = div+mod
    if n == 1:
        return 'Yes'
    else:
        return 'No'
 
 
n, m = map(int, input().split())
if m == 1 and n == 1:
    print('Yes')
elif m == 1 and n > m:
    print('No')
else:
    print(calc(n, m))

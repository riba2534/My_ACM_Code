n = int(input())
k = -1
a = []
A = set()
if n == 1:
    a.append(list(map(int, input().split())))
    print(1)
    exit()

for i in range(n):
    a.append(list(map(int, input().split())))
    A.add(sum(a[i]))
    if k == -1:
        for j in range(n):
            if a[i][j] == 0:
                k = i
                l = j

if len(A) > 2:
    print(-1)
    exit()
elif len(A) == 2:
    d = max(A) - min(A)
    a[k][l] = d
else:
    len(A)  == 1
    print(-1)
    exit()
A.clear()
s = 0
s2 = 0
for i in range(n):
    A.add(sum(a[i]))
    s += a[i][i]
    s2 += a[i][n-1-i]
A.add(s)
A.add(s2)
#b = []
b = list(zip(*a))
#print(b)
for i in range(n):
    A.add(sum(b[i]))
if len(A) > 1:
    print(-1)
else:
    print(d)
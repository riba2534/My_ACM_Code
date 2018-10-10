def calc(num):
    if num == 0:
        return 0
    sum = 0
    s = str(num)
    for ch in s:
        sum += int(ch)
    return sum


def g9(n):
    sn = str(n)
    tn = ''
    for i in range(len(sn)-1):
        tn += '9'
    if tn != '':
        return int(tn)
    else:
        return 0


ans = []
n = int(input())
ans.append(calc(n//2)+calc(n-(n//2)))
if n//2-1 >= 0:
    ans.append(calc(n//2-1)+calc(n-(n//2-1)))
num = g9(n)
ans.append(calc(num)+calc(n-num))
print(max(ans))

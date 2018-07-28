s = input()
slen = len(s)
cnt1 = s.count('o')
cnt2 = slen - cnt1
if cnt1 == 0:
    print('YES')
else:
    if (cnt2 % cnt1 == 0):
        print('YES')
    else:
        print('NO')

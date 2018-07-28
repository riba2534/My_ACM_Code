k = int(input().strip().split()[0])
sp = 3
answer = "YES"
for _ in range(k):
    i = int(input().strip().split()[0])
    if i == sp:
        answer = "NO"
        break
    else:
        sp = 6 - i - sp
print(answer)
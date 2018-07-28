s=input()
ans = 0
for i in range(len(s)):
  if s[i] == 'A':
    ans += s[:i].count('Q') * s[i:].count('Q')
print(ans)
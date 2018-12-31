def pd(y, b, r, yy, bb, rr):
    if y >= yy and b >= bb and r >= rr:
        return True
    return False


y, b, r = map(int, input().split())
ans = 0
if pd(y, b, r, y, y+1, y+2) == True:
    ans = max(ans, y+y+1+y+2)
if pd(y, b, r, b-1, b, b+1) == True:
    ans = max(ans, 3*b)
if pd(y, b, r, r-2, r-1, r) == True:
    ans = max(ans, 3*r-3)
print(ans)

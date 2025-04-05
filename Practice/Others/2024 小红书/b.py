import math

n = int(input())
a = [0] + list(map(int, input().split()))  # Read input and store it in a list
ans = 0
for i in range(1, n + 1):
    flag = False
    for j in range(i - 1, 0, -1):
        for k in range(j + 1, i):
            if math.gcd(j, k) != 1:
                flag = True
        if flag:
            ans = max(ans, i - j)
            break
    if not flag:
        ans = max(ans, i)
print(ans)


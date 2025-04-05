n = int(input())
a = [0] + list(map(int, input().split()))
f = [[-10 ** 9 for _ in range(n + 1)] for _ in range(n + 1)]
f[1][n] = 0
p = 0
for length in range(n, 1, -1):
    p = p ^ 1
    for r in range(length, n + 1):
        l = r - length + 1
        if p:
            if a[l] >= a[r]:
                f[l + 1][r] = max(f[l + 1][r], f[l][r])
            else:
                f[l][r - 1] = max(f[l][r - 1], f[l][r])
        else:
            f[l + 1][r] = max(f[l + 1][r], f[l][r] + a[l])
            f[l][r - 1] = max(f[l][r - 1], f[l][r] + a[r])
p = p ^ 1
ans = 0
for i in range(1, n + 1):
    if p:
        ans = max(ans, f[i][i])
    else:
        ans = max(ans, f[i][i] + a[i])
print(sum(a) - ans, ans)
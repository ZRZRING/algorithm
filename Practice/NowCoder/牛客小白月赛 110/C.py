ans = [3, 5, 9, 15, 21, 25, 27]

def solve():
    n = int(input()) - 1
    print(n // 7 * 30 + ans[n % 7])

T = int(input())
for _ in range(T):
    solve()